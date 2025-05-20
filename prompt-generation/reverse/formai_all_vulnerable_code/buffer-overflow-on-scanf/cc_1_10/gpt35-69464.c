//FormAI DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024
#define URL_MAX_LENGTH 200

struct MemoryStruct {
  char *memory;
  size_t size;
};

static void *Realloc(void *ptr, size_t size) {
  if(ptr)
    return realloc(ptr, size);
  else
    return malloc(size);
}

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  mem->memory = (char *)Realloc(mem->memory, mem->size + realsize + 1);
  if(mem->memory == NULL) {
    /* out of memory! */ 
    printf("error: not enough memory (realloc returned NULL)\n");
    return 0;
  }

  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

static char *FetchPage(const char *url) {
  CURL *curl_handle;
  CURLcode res;

  struct MemoryStruct chunk;

  chunk.memory = (char *)malloc(1);
  chunk.size = 0;

  curl_global_init(CURL_GLOBAL_ALL);

  curl_handle = curl_easy_init();
 
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
 
  res = curl_easy_perform(curl_handle);
 
  if(CURLE_OK == res) {
    char *page_data = strdup(chunk.memory);
    free(chunk.memory);
    curl_easy_cleanup(curl_handle);
    return page_data;
  } else {
    printf("error: curl easy perform error %d\n", res);
    free(chunk.memory);
    curl_easy_cleanup(curl_handle);
    return NULL;
  }
}

int main() {
  char input_url[URL_MAX_LENGTH];
  char *page_data = NULL;

  printf("Enter URL to fetch: ");
  scanf("%s", input_url);

  page_data = FetchPage(input_url);

  if(page_data) {
    printf("Fetched page successfully! (first %d bytes)\n", BUFFER_SIZE);
    printf("=============================================\n");
    printf("%.*s...\n", BUFFER_SIZE, page_data);
    free(page_data);
  } else {
    printf("Failed to fetch page. :(\n");
  }

  return 0;
}