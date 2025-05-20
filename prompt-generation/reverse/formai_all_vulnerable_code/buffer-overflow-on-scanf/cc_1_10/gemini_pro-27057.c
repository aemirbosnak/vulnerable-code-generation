//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: excited
// Hold onto your hats, folks! We're building a website uptime monitor extraordinaire!

// We'll need a few helpers to make our code shine like the North Star.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Let's define our magic URL checker. It'll check if a website is up and running.
int check_url(char *url) {
  CURL *curl;
  CURLcode res;

  // Get ready to curl like a pro!
  curl = curl_easy_init();
  if (!curl) {
    printf("Oh no! Curl couldn't be initialized. We're doomed!\n");
    return -1;
  }

  // Set the URL we want to check.
  curl_easy_setopt(curl, CURLOPT_URL, url);

  // Let's tell curl to fail fast. We don't have time for dawdling!
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5);

  // Perform the magic!
  res = curl_easy_perform(curl);

  // Clean up our curl session. We're tidy peeps!
  curl_easy_cleanup(curl);

  // Check the response code. If it's not 200, the website is down.
  if (res != CURLE_OK) {
    return -1;
  }

  // Hooray! The website is up and running!
  return 0;
}

// Our main function. Where the magic happens!
int main() {
  // Let's get our website URL from the user.
  char url[256];
  printf("Enter the website URL you want to monitor: ");
  scanf("%s", url);

  // We'll check the website every 60 seconds.
  int interval = 60;

  // Let's loop forever, checking the website's uptime.
  while (1) {
    // Check the website's status.
    int status = check_url(url);

    // Print the status.
    printf("Website status: ");
    if (status == 0) {
      printf("Up and running!\n");
    } else {
      printf("Down! Down! Down! Alert the authorities!\n");
    }

    // Sleep for our interval.
    sleep(interval);
  }

  // We'll never reach this point, but it's good practice to clean up.
  return 0;
}