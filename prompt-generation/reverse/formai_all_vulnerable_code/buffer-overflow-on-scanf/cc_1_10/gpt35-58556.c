//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_BUFFER 4096

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if (mem->memory == NULL) {
    printf("Out of memory!\n");
    return 0;
  }

  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

int main(void) {
  CURL *curl_handle;
  CURLcode res;
  struct MemoryStruct chunk;

  chunk.memory = malloc(1);
  chunk.size = 0;

  curl_global_init(CURL_GLOBAL_ALL);

  char username[MAX_BUFFER];
  char password[MAX_BUFFER];
  char server[MAX_BUFFER];
  char mailbox[MAX_BUFFER];
  printf("Enter your IMAP username: ");
  scanf("%s", username);
  printf("Enter your IMAP password: ");
  scanf("%s", password);
  printf("Enter your IMAP server: ");
  scanf("%s", server);
  printf("Enter your IMAP mailbox: ");
  scanf("%s", mailbox);

  char url[MAX_BUFFER];
  snprintf(url, MAX_BUFFER, "imaps://%s:%s@%s/%s", username, password, server, mailbox);

  curl_handle = curl_easy_init();

  if(curl_handle) {
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

    res = curl_easy_perform(curl_handle);

    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    else {
      printf("%lu bytes retrieved\n", (unsigned long)chunk.size);
      printf("%s\n", chunk.memory);
    }

    curl_easy_cleanup(curl_handle);
  }

  free(chunk.memory);

  curl_global_cleanup();

  return 0;
}