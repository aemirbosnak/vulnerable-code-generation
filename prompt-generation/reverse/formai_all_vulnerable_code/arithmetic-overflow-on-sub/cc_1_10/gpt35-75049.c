//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

// Define the website(s) to monitor
const char *urls[] = {"http://www.google.com", "http://www.yahoo.com"};

int main(void) {
  CURL *curl;
  CURLcode res;
  double time_taken;
  struct timespec start_time, end_time;

  // Set up curl with default options
  curl = curl_easy_init();

  if(curl) {
    for(int i = 0; i < sizeof(urls)/sizeof(urls[0]); i++) {
      // Set the URL to check
      curl_easy_setopt(curl, CURLOPT_URL, urls[i]);

      // Perform the HTTP request
      clock_gettime(CLOCK_REALTIME, &start_time);
      res = curl_easy_perform(curl);
      clock_gettime(CLOCK_REALTIME, &end_time);

      // Calculate the time taken for the request
      time_taken = (end_time.tv_sec - start_time.tv_sec) + 
                   (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

      // Check for errors
      if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", 
                curl_easy_strerror(res));
        printf("Website %s is down\n", urls[i]);
      } else {
        printf("Website %s is up\n", urls[i]);
      }

      // Print the time taken to make the request
      printf("Time taken: %f seconds\n", time_taken);
    }
  }

  // Cleanup
  curl_easy_cleanup(curl);

  return 0;
}