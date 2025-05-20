//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define MAX_LEN 100

void check_website(char *url);

int main() {
   char urls[MAX_URLS][MAX_LEN];
   int total_urls;
   int i;

   // Get user input for website URLs to monitor
   printf("Enter website URLs to monitor:\n");

   for (i = 0; i < MAX_URLS; i++) {
      printf("URL %d: ", i+1);
      fgets(urls[i], MAX_LEN, stdin);

      // Remove newline character added by fgets
      urls[i][strlen(urls[i]) - 1] = '\0';

      // Stop taking input when user enters nothing
      if (strlen(urls[i]) == 0) {
         break;
      }
   }

   total_urls = i;

   // Continuously check website uptime for all specified URLs
   while (1) {
      for (i = 0; i < total_urls; i++) {
         check_website(urls[i]);
      }

      // Sleep for 5 seconds before checking again
      sleep(5);
   }

   return 0;
}

void check_website(char *url) {
   CURL *curl;
   CURLcode res;

   curl = curl_easy_init();

   if (curl) {
      // Set the URL to check
      curl_easy_setopt(curl, CURLOPT_URL, url);

      // Don't output anything to stdout
      curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

      // Check website for 5 seconds
      curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

      // Perform the request to check website
      res = curl_easy_perform(curl);

      if (res != CURLE_OK) {
         printf("%s is DOWN\n", url);
      } else {
         printf("%s is UP\n", url);
      }

      curl_easy_cleanup(curl);
   }
}