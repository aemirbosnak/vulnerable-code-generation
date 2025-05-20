//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
//The Adventure of the Website Uptime

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

//Function to check website status
int check_site(char *url) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    
    res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      curl_easy_cleanup(curl);
      return (int)response_code;
    }
  }
  curl_easy_cleanup(curl);
  return 0;
}

//Main function to monitor website uptime
int main() {
  char url[100];
  int response_code, flag = 0;
  time_t current_time;
  
  printf("Enter the URL to monitor: ");
  scanf("%s", url);
  
  while(1) {
    response_code = check_site(url);
    
    if(response_code != 0) {
      printf("Website is up and running! Response Code: %d\n", response_code);
      flag = 1;
    }
    else {
      if(flag == 1) {
        time(&current_time);
        printf("Website went down at: %s", ctime(&current_time));
        flag = 0;
      }
    }
    sleep(30); //Check website status every 30 seconds
  }

  return 0;
}