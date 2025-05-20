//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define INTERVAL 60 // check website every minute

// function to make HTTP GET request
int curl_get_response_code(char* url) {
  CURL *curl;
  CURLcode res;
  long response_code = 0;

  // initialize curl
  curl = curl_easy_init();
  if(curl) {
    // set url
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // set request method
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");

    // follow redirects
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // get response code
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
    res = curl_easy_perform(curl);
    if (res == CURLE_OK)
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // cleanup curl
    curl_easy_cleanup(curl);
  }

  return response_code;
}

// main function
int main() {
  int response_code;
  char url[100];

  // get website url from user
  printf("Enter website url: ");
  scanf("%s", url);

  // check website uptime every minute
  while (1) {
    response_code = curl_get_response_code(url);
    if (response_code == 200) {
      printf("Website %s is up\n", url);
    } else {
      printf("Website %s is down. Response code: %d\n", url, response_code);
    }
    sleep(INTERVAL);
  } 

  return 0;
}