//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

#define URL "http://speedtest.net/speedtest-scripts/random1000000.jpg"

struct curl_data {
  size_t length;
  char *memory;
};

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
  struct curl_data *data = userdata;
  size_t realsize = size * nmemb;
  data->memory = realloc(data->memory, data->length + realsize + 1);
  if (data->memory) {
    memcpy(&(data->memory[data->length]), ptr, realsize);
    data->length += realsize;
    data->memory[data->length] = 0;
  }
  return realsize;
}

int main(int argc, char **argv) {
  CURL *curl;
  CURLcode res;
  struct curl_data data;
  clock_t start, end;
  double time_spent;
  double speed;

  curl = curl_easy_init();
  if (curl) {
    data.length = 0;
    data.memory = malloc(1);  
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    start = clock();
    res = curl_easy_perform(curl);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    if (res == CURLE_OK) {
      speed = (double)data.length / time_spent;
      printf("Internet speed: %.2f MB/s\n", speed / 1024.0 / 1024.0);
    } else {
      printf("Error: %s\n", curl_easy_strerror(res));
    }
    free(data.memory);
    curl_easy_cleanup(curl);
  }
  return 0;
}