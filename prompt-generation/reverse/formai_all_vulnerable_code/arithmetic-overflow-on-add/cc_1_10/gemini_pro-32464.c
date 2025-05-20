//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

#define URL "http://example.com"

int main(void) {
  CURL *curl;
  CURLcode res;
  char error_buffer[CURL_ERROR_SIZE];

  // Initialize the curl session.
  curl = curl_easy_init();
  if (curl == NULL) {
    printf("Error initializing curl session.\n");
    return EXIT_FAILURE;
  }

  // Set the URL to fetch.
  curl_easy_setopt(curl, CURLOPT_URL, URL);

  // Set the error buffer to receive any error messages.
  curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer);

  // Set the timeout value for the request.
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);

  // Perform the HTTP GET request.
  res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    printf("Error performing HTTP GET request: %s\n", error_buffer);
    curl_easy_cleanup(curl);
    return EXIT_FAILURE;
  }

  // Get the response code.
  long response_code;
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
  printf("Response code: %ld\n", response_code);

  // Get the response body.
  long content_length;
  curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &content_length);
  char *response_body = malloc(content_length + 1);
  if (response_body == NULL) {
    printf("Error allocating memory for response body.\n");
    curl_easy_cleanup(curl);
    return EXIT_FAILURE;
  }
  size_t read_bytes = curl_easy_recv(curl, response_body, content_length, NULL);
  if (read_bytes != content_length) {
    printf("Error reading response body.\n");
    free(response_body);
    curl_easy_cleanup(curl);
    return EXIT_FAILURE;
  }
  response_body[content_length] = '\0';

  // Print the response body.
  printf("Response body:\n%s\n", response_body);

  // Cleanup the curl session.
  curl_easy_cleanup(curl);

  // Free the memory allocated for the response body.
  free(response_body);

  return EXIT_SUCCESS;
}