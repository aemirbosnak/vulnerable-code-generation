//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

// function to download a file and calculate its download speed
double speedtest() {
  CURL *curl;
  CURLcode res;
  double speed = 0.0;
  char url[] = "http://speedtest.tele2.net/1MB.zip";
  char outfilename[FILENAME_MAX] = "speedtest_file.bin";
  FILE *outfile;
  long response_code;
  double download_time;
  
  curl = curl_easy_init();
  if(curl) {
    outfile = fopen(outfilename, "wb");
    if(outfile) {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, outfile);
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
      res = curl_easy_perform(curl);
      if(res == CURLE_OK) {
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &download_time);
        if(response_code == 200) {
          fseek(outfile, 0L, SEEK_END);
          double file_size = ftell(outfile);
          speed = file_size / download_time;
          printf("Downloaded %.0f bytes in %.3f seconds, speed = %.2f KB/s\n", file_size, download_time, speed/1024);
        } else {
          printf("Error: HTTP response code %ld\n", response_code);
        }
      } else {
        printf("Error: curl_easy_perform failed: %s\n", curl_easy_strerror(res));
      }
      fclose(outfile);
    }
    curl_easy_cleanup(curl);
  }
  return speed;
}

int main() {
  printf("Starting Internet Speed Test Application...\n");
  double speed = speedtest();
  printf("Your Internet Speed is %.2f KB/s\n", speed/1024);
  return 0;
}