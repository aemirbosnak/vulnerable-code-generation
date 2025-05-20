//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

void check_website_status(char* url)
{
  CURL *curl;
  CURLcode res;
  int status_code;
  
  curl = curl_easy_init();
  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    
    res = curl_easy_perform(curl);
    if(res == CURLE_OK)
    {
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
      if(status_code >= 200 && status_code < 400)
      {
        printf("%s is up and running! Response code: %d\n", url, status_code);
      }
      else
      {
        printf("%s is down. Response code: %d\n", url, status_code);
      }
    }
    else
    {
      printf("Could not reach %s. Error: %s\n", url, curl_easy_strerror(res));
    }
    
    curl_easy_cleanup(curl);
  }
}

int main()
{
  char url[100];
  int interval;
  
  printf("Enter website URL to monitor: ");
  scanf("%s", url);
  
  printf("Enter monitoring interval in seconds: ");
  scanf("%d", &interval);
  
  printf("\nStarting website uptime monitor for %s...\n", url);
  
  while(1)
  {
    check_website_status(url);
    sleep(interval);
  }
  
  return 0;
}