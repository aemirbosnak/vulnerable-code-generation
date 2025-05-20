//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char url[2048];
   char sanitized_url[2048] = "";
   int i, j, n;
   int flag = 0; // flag to indicate if URL is valid
   
   printf("Enter a URL: ");
   fgets(url, 2048, stdin); // read URL
   
   n = strlen(url);
   
   // check for suspicious characters in URL
   for(i=0; i<n; i++) {
      if(url[i] == ' ') {
         flag = 1;
         break;
      }
      else if(url[i] == ';') {
         flag = 1;
         break;
      }
      else if(url[i] == '|') {
         flag = 1;
         break;
      }
   }
   
   if(flag == 1) {
      printf("Invalid URL! The URL contains suspicious characters.\n");
   }
   else {
      // remove trailing spaces
      while (url[n-1] == ' ') {
         n--;
      }
      
      // sanitize URL
      for(i=0, j=0; i<n; i++) {
         if(url[i] == '/') {
            sanitized_url[j] = url[i];
            j++;
            
            // check for double slashes
            if(url[i+1] == '/') {
               i++;
            }
         }
         else if(url[i] == '?') {
            sanitized_url[j] = url[i];
            j++;
            break;
         }
         else {
            sanitized_url[j] = url[i];
            j++;
         }
      }
      
      printf("Sanitized URL: %s\n", sanitized_url);
   }
   
   return 0;
}