//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

// Constants
#define MAX_URLS 100
#define MAX_URL_LENGTH 256
#define CHECK_INTERVAL 60 // in seconds

// Data structures
typedef struct {
  char url[MAX_URL_LENGTH];
  time_t last_checked;
  bool is_up;
} website;

// Global variables
website websites[MAX_URLS];
int num_websites = 0;

// Function declarations
void add_website(char *url);
void remove_website(char *url);
void check_websites();
void print_report();

// Main function
int main() {
  // Initialize the CURL library
  curl_global_init(CURL_GLOBAL_DEFAULT);

  // Add some example websites
  add_website("www.google.com");
  add_website("www.facebook.com");
  add_website("www.twitter.com");

  // Run the website monitoring loop forever
  while (true) {
    // Check the websites
    check_websites();

    // Print the report
    print_report();

    // Sleep for the specified interval
    sleep(CHECK_INTERVAL);
  }

  // Cleanup the CURL library
  curl_global_cleanup();

  return 0;
}

// Function to add a website to the list
void add_website(char *url) {
  if (num_websites < MAX_URLS) {
    strcpy(websites[num_websites].url, url);
    websites[num_websites].last_checked = time(NULL);
    websites[num_websites].is_up = true;
    num_websites++;
  } else {
    printf("Error: Maximum number of websites reached.\n");
  }
}

// Function to remove a website from the list
void remove_website(char *url) {
  for (int i = 0; i < num_websites; i++) {
    if (strcmp(websites[i].url, url) == 0) {
      for (int j = i + 1; j < num_websites; j++) {
        websites[j - 1] = websites[j];
      }
      num_websites--;
      break;
    }
  }
}

// Function to check the websites
void check_websites() {
  CURL *curl;
  CURLcode res;

  for (int i = 0; i < num_websites; i++) {
    // Check if the website has been checked recently
    time_t now = time(NULL);
    if (now - websites[i].last_checked < CHECK_INTERVAL) {
      continue;
    }

    // Initialize the CURL handle
    curl = curl_easy_init();
    if (!curl) {
      printf("Error: Failed to initialize CURL.\n");
      continue;
    }

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, websites[i].url);

    // Set the timeout
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Perform the request
    res = curl_easy_perform(curl);

    // Check the result
    if (res != CURLE_OK) {
      websites[i].is_up = false;
    } else {
      websites[i].is_up = true;
    }

    // Cleanup the CURL handle
    curl_easy_cleanup(curl);

    // Update the last checked time
    websites[i].last_checked = now;
  }
}

// Function to print the report
void print_report() {
  printf("Website Uptime Report\n");
  printf("---------------------\n");
  for (int i = 0; i < num_websites; i++) {
    printf("%s: %s\n", websites[i].url, websites[i].is_up ? "Up" : "Down");
  }
  printf("\n");
}