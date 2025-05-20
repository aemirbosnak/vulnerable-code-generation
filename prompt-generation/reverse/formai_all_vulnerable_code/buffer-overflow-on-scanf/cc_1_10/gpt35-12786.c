//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>
#include<time.h>

int main(){
  CURL *curl_handle;
  CURLcode res;
  FILE *fp;
  time_t start_time, end_time;
  char url[100];
  char filename[50];
  int status_code;
  
  printf("Welcome to the Happy Website Uptime Monitor! \n");
  printf("Enter the URL of the website you wish to monitor: \n");
  scanf("%s", &url);
  
  printf("Enter the name of the text file you wish to save the response in: \n");
  scanf("%s", &filename);
  
  fp = fopen(filename, "w");
  
  time(&start_time);
  
  curl_global_init(CURL_GLOBAL_ALL);
  
  curl_handle = curl_easy_init();
  
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);
  
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, fwrite);
  
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, fp);
  
  res = curl_easy_perform(curl_handle);
  
  curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &status_code);
  
  if(res != CURLE_OK){
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
  }
  else{
    printf("Website response code: %d\n", status_code);
    printf("Website content has been saved in file: %s\n", filename);
  }
  
  curl_easy_cleanup(curl_handle);
  
  curl_global_cleanup();
  
  fclose(fp);
  
  time(&end_time);
  
  double time_taken = difftime(end_time, start_time);
  
  printf("Website response time: %f seconds\n", time_taken);
  
  printf("Thank you for using the Happy Website Uptime Monitor!");
  
  return 0;
}