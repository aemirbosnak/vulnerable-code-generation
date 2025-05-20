//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 200
#define MAX_FAILURES 3

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: ./website_monitor <URL_1> [<URL_2> ...]\n");
    return 1;
  }

  int num_urls = argc - 1;
  char **urls = malloc(num_urls * sizeof(char *));
  if (!urls) {
    perror("Error allocating memory for URLs");
    return 1;
  }

  // Copy URLs from command line arguments
  for (int i = 0; i < num_urls; i++) {
    urls[i] = malloc(MAX_URL_LEN);
    if (!urls[i]) {
      perror("Error allocating memory for URL");
      return 1;
    }
    strncpy(urls[i], argv[i+1], MAX_URL_LEN - 1);
  }

  int failures[num_urls];
  memset(failures, 0, num_urls * sizeof(int));

  CURL *curl_handle;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);

  while (1) {
    for (int i = 0; i < num_urls; i++) {
      curl_handle = curl_easy_init();
      if (!curl_handle) {
        printf("Error initializing cURL.\n");
        return 1;
      }
      curl_easy_setopt(curl_handle, CURLOPT_URL, urls[i]);
      curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);

      res = curl_easy_perform(curl_handle);
      if (res != CURLE_OK) {
        failures[i]++;
        printf("Error accessing URL %s: %s\n", urls[i], curl_easy_strerror(res));
        if (failures[i] >= MAX_FAILURES) {
          printf("Failed to access URL %s %d times, exiting.\n", urls[i], MAX_FAILURES);
          return 1;
        }
      } else {
        failures[i] = 0;
        printf("Accessed URL %s successfully.\n", urls[i]);
      }

      curl_easy_cleanup(curl_handle);
    }
    sleep(60);
  }

  for (int i = 0; i < num_urls; i++) {
    free(urls[i]);
  }
  free(urls);

  curl_global_cleanup();
  
  return 0;
}