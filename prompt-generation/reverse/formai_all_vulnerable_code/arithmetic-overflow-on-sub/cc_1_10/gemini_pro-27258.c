//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024
#define INTERVAL 600

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *url = argv[1];
  char *response = malloc(MAX_RESPONSE_LENGTH);
  if (response == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  while (1) {
    time_t start = time(NULL);

    // Send a GET request to the URL
    FILE *fp = fopen(url, "r");
    if (fp == NULL) {
      perror("fopen");
      fprintf(stderr, "Failed to open URL: %s\n", url);
      continue;
    }

    int bytes_read = fread(response, 1, MAX_RESPONSE_LENGTH, fp);
    if (bytes_read < 0) {
      perror("fread");
      fprintf(stderr, "Failed to read response from URL: %s\n", url);
      continue;
    }

    fclose(fp);

    time_t end = time(NULL);

    // Check if the response is valid
    if (bytes_read == 0) {
      fprintf(stderr, "Received empty response from URL: %s\n", url);
      continue;
    }

    // Print the response time
    printf("Response time: %ld seconds\n", end - start);

    // Sleep for the specified interval
    sleep(INTERVAL);
  }

  free(response);

  return EXIT_SUCCESS;
}