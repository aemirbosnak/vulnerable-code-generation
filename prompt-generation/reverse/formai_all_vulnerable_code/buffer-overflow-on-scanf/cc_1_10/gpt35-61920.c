//FormAI DATASET v1.0 Category: Browser Plugin ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024

static bool parse_url(const char* input_url, char* output_url) {
  if(strncmp(input_url, "http://", 7) != 0 &&
     strncmp(input_url, "https://", 8) != 0) {
      return false;
  }

  int i = 0;
  while(input_url[i] != '\0') {
    output_url[i] = input_url[i];
    ++i;
    if(i == MAX_URL_LENGTH - 1) {
      break;
    }
  }

  output_url[i] = '\0';
  return true;
}

static size_t write_callback(void* ptr, size_t size, size_t nmemb, void* data) {
  size_t new_len = strlen(data) + size * nmemb;
  char* data_to_write = malloc(new_len + 1);

  if(data_to_write == NULL) {
    return 0;
  }

  memcpy(data_to_write, data, strlen(data));
  memcpy(data_to_write + strlen(data), ptr, size * nmemb);
  data_to_write[new_len] = '\0';

  free(data);
  data = data_to_write;

  return size * nmemb;
}

void handle_url(const char* url) {
  CURL* curl;
  CURLcode res;
  
  curl = curl_easy_init();
  
  if(curl) {
    char* data = malloc(1);
    *data = '\0';
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } else {
      printf("%s\n", data);
    }

    curl_easy_cleanup(curl);
  }
}

int main() {
  char input_url[MAX_URL_LENGTH];
  
  printf("Enter URL: ");
  scanf("%s", input_url);

  char output_url[MAX_URL_LENGTH];
  bool url_valid = parse_url(input_url, output_url);

  if(url_valid) {
    printf("URL is valid.\n");
    handle_url(output_url);
  } else {
    printf("URL is invalid.\n");
  }

  return 0;
}