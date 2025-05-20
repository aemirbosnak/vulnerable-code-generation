//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

/* The desired website to monitor */
#define WEBSITE "https://example.com"

/* The path to the file where the results will be stored */
#define RESULT_FILE "results.txt"

/* The desired interval, in seconds, between checks */
#define INTERVAL 60

/* The maximum number of consecutive failures before alerting */
#define MAX_CONSECUTIVE_FAILURES 5

/* The buffer size for the curl response */
#define CURL_BUF_SIZE 1024

/* Struct to store the curl response */
struct curl_response {
  char *buf;
  size_t size;
};

/* Callback function to handle the curl response */
static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
  struct curl_response *resp = (struct curl_response *) userdata;
  size_t total_size = size * nmemb;

  resp->buf = realloc(resp->buf, resp->size + total_size + 1);
  if (resp->buf == NULL) {
    perror("realloc");
    exit(EXIT_FAILURE);
  }

  memcpy(resp->buf + resp->size, ptr, total_size);
  resp->size += total_size;
  resp->buf[resp->size] = '\0';

  return total_size;
}

/* Function to check the website and return 1 if successful, 0 if not */
static int check_website()
{
  CURL *curl;
  CURLcode res;
  struct curl_response resp = { .buf = NULL, .size = 0 };

  curl = curl_easy_init();
  if (curl == NULL) {
    perror("curl_easy_init");
    exit(EXIT_FAILURE);
  }

  curl_easy_setopt(curl, CURLOPT_URL, WEBSITE);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &resp);

  res = curl_easy_perform(curl);

  if (res != CURLE_OK || resp.size == 0) {
    curl_easy_cleanup(curl);
    free(resp.buf);
    return 0;
  }

  curl_easy_cleanup(curl);
  free(resp.buf);
  return 1;
}

int main()
{
  FILE *fp;
  time_t last_alert = 0;
  int consecutive_failures = 0;

  while (1) {
    int status = check_website();

    if (status == 1) {
      consecutive_failures = 0;
      printf("%s: OK\n", WEBSITE);
    } else {
      consecutive_failures++;
      printf("%s: FAIL\n", WEBSITE);
    }

    fp = fopen(RESULT_FILE, "a");
    if (fp == NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    if (consecutive_failures >= MAX_CONSECUTIVE_FAILURES && now - last_alert >= INTERVAL) {
      fprintf(fp, "%s: ALERT\n", WEBSITE);
      last_alert = now;
    } else {
      fprintf(fp, "%s: %s\n", WEBSITE, status ? "OK" : "FAIL");
    }

    fclose(fp);

    sleep(INTERVAL);
  }

  return 0;
}