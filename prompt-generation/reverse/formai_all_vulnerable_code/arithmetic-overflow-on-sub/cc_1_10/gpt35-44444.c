//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curl/curl.h>
#include <regex.h>

#define BUFFER_SIZE 4096

struct string_buffer {
  char *ptr;
  size_t len;
};

void init_buffer(struct string_buffer *buffer) {
  buffer->len = 0;
  buffer->ptr = malloc(buffer->len + 1);
  if (buffer->ptr == NULL) {
    fprintf(stderr, "Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  buffer->ptr[0] = '\0';
}

size_t write_buffer(void *ptr, size_t size, size_t nmemb, struct string_buffer *buffer) {
  size_t new_len = buffer->len + size * nmemb;
  buffer->ptr = realloc(buffer->ptr, new_len + 1);
  if (buffer->ptr == NULL) {
    fprintf(stderr, "Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  memcpy(buffer->ptr + buffer->len, ptr, size * nmemb);
  buffer->ptr[new_len] = '\0';
  buffer->len = new_len;

  return size * nmemb;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <email> <password>", argv[0]);
    exit(EXIT_FAILURE);
  }

  CURL *curl;
  CURLcode res;
  struct curl_slist *list = NULL;
  struct string_buffer buffer;
  char buffer_reader[BUFFER_SIZE];
  memset(buffer_reader, 0, BUFFER_SIZE);

  // Set CURL options
  curl = curl_easy_init();
  if (curl == NULL) {
    fprintf(stderr, "Unable to initialize CURL");
    exit(EXIT_FAILURE);
  }

  char url[BUFFER_SIZE];
  sprintf(url, "imaps://%s", argv[1]);

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_PORT, 993L);
  curl_easy_setopt(curl, CURLOPT_USERNAME, argv[2]);
  curl_easy_setopt(curl, CURLOPT_PASSWORD, argv[3]);
  curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_buffer);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

  // Connect and login to server
  res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "Unable to connect to server: %s", curl_easy_strerror(res));
    exit(EXIT_FAILURE);
  }

  // Parse SERVERCAPABILITY response
  char *p = buffer.ptr;
  const char *re_search = "^\\* (\\w+)(.*)$";
  regex_t re;
  regmatch_t rm[3];
  int reti = regcomp(&re, re_search, REG_EXTENDED | REG_NEWLINE);
  int match_found;

  if (reti) {
    fprintf(stderr, "Could not compile regex");
    exit(EXIT_FAILURE);
  }

  while (*p != '\0') {
    reti = regexec(&re, p, 3, rm, 0);
    if (reti == 0) {
      match_found = 1;
      char *result[3] = {
        strndup(p + rm[1].rm_so, rm[1].rm_eo - rm[1].rm_so),
        strndup(p + rm[2].rm_so, rm[2].rm_eo - rm[2].rm_so),
      };

      printf("%s: %s\n", result[0], result[1]);

      free(result[0]);
      free(result[1]);
      p += rm[0].rm_eo;
    } else if (reti == REG_NOMATCH) {
      match_found = 0;
      p++;
    } else {
      regerror(reti, &re, buffer_reader, BUFFER_SIZE);
      fprintf(stderr, "Regex match failed: %s\n", buffer_reader);
      exit(EXIT_FAILURE);
    }
  }

  // Cleanup
  regfree(&re);
  curl_easy_cleanup(curl);
  free(buffer.ptr);
  return EXIT_SUCCESS;
}