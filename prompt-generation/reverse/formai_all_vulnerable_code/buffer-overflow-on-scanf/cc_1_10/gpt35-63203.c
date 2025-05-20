//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(void) {
  CURL *curl;
  CURLcode res;
  
  printf("What's up, HTTP Client fans? It's your boy, CURLy!\n");
  curl = curl_easy_init();
  if(curl) {
    printf("Alright, let's get cracking. Where do you want to send your HTTP request today?\n");
    char url[256];
    scanf("%s", url);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    printf("Sweet, we're sending an HTTP request to %s. Now, what kind of request do you want to send? GET? POST? PUT? DELETE?\n", url);
    char method[10];
    scanf("%s", method);
    if(strcmp(method, "GET") == 0) {
      printf("GET it is! You're a classicist, I like it.\n");
      curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
    }
    else if(strcmp(method, "POST") == 0) {
      printf("POST, huh? Bold move, let's do this.\n");
      curl_easy_setopt(curl, CURLOPT_POST, 1L);
    }
    else if(strcmp(method, "PUT") == 0) {
      printf("PUT, eh? You're a real go-getter.\n");
      curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    }
    else if(strcmp(method, "DELETE") == 0) {
      printf("DELETE, really? You're hardcore, my friend.\n");
      curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    }
    else {
      printf("I'm sorry, I don't recognize that method. I'll just assume you want a GET request.\n");
    }
    printf("Alright, last question. Do you want to see the response? Y/N?\n");
    char response[2];
    scanf("%s", response);
    if(strcmp(response, "Y") == 0) {
      printf("Get ready for some juicy response action!\n");
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
    }
    else {
      printf("Suit yourself, mystery man. I won't ask any questions.\n");
    }
    printf("And we're off! Let's send that request...\n");
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      fprintf(stderr, "Oh no! CURLy has failed us with error code %s\n",curl_easy_strerror(res));
    }
    printf("Phew! That was intense. Thanks for using CURLy's HTTP Client. Don't forget to tip your waiter!\n");
    curl_easy_cleanup(curl);
  }
  return 0;
}