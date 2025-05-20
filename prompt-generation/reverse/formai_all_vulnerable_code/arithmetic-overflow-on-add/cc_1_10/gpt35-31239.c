//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

double download_speed;
double upload_speed;
long total_time;

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
  return size * nmemb;
}
void test_speed(char* url)
{
  CURL *curl_handle;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);

  curl_handle = curl_easy_init();
  if (curl_handle) {
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    res = curl_easy_perform(curl_handle);

    double download_size = 5242880; //5 MB file
    curl_easy_getinfo(curl_handle, CURLINFO_SPEED_DOWNLOAD, &download_speed);
    curl_easy_getinfo(curl_handle, CURLINFO_SPEED_UPLOAD, &upload_speed);
    curl_easy_getinfo(curl_handle, CURLINFO_TOTAL_TIME, &total_time);

    curl_easy_cleanup(curl_handle);
  }
  curl_global_cleanup();
}

int main(int argc, char *argv[])
{
  char* url;
  
  if (argc != 2) {
    printf("Please provide a URL to test speed.\n");
    return 1;
  } else {
    url = argv[1];
  }

  printf("Testing speed from URL: %s\n", url);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("Test started at: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

  test_speed(url);

  printf("Download speed: %f MB/s\n", download_speed / 1000000);
  printf("Upload speed: %f MB/s\n", upload_speed / 1000000);
  printf("Total time: %ld seconds\n", total_time);

  t = time(NULL);
  tm = *localtime(&t);
  printf("Test ended at: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

  return 0;
}