//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* sanitizeURL(char* url){

  char *clean = malloc(strlen(url) + 1); //allocate memory for the cleaned URL

  int x = 0;
  int y = 0;
  int len = strlen(url);

  while(x < len){

    if(url[x] == ':'){ // h t t p s : /

      if(x+2 < len && url[x+1] == '/' && url[x+2] == '/'){
          //handles case where string begins with http:// or https://
        clean[y++] = url[x++];
        clean[y++] = url[x++];
        while(x < len && url[x] != '/'){
          x++;
        }

      }else{
          //handles case where string contains a : but does not have http:// or https:// prefix
        clean[y++] = url[x++];
      }
    }else if(url[x] == '&'){ // & a m p ;
      clean[y++] = url[x++];
      clean[y++] = url[x++];
      while(x < len && url[x] != ';'){
        x++;
      }
    }else if(url[x] == '<'){ // & l t ;
      clean[y++] = url[x++];
      clean[y++] = url[x++];
      while(x < len && url[x] != ';'){
        x++;
      }
    }else if(url[x] == '>'){ // & g t ;
      clean[y++] = url[x++];
      clean[y++] = url[x++];
      while(x < len && url[x] != ';'){
        x++;
      }
    }else if(url[x] == '\"'){ // & q u o t ;
      clean[y++] = url[x++];
      clean[y++] = url[x++];
      while(x < len && url[x] != ';'){
        x++;
      }
    }else if(url[x] == '\''){ // & a p o s ;
      clean[y++] = url[x++];
      clean[y++] = url[x++];
      while(x < len && url[x] != ';'){
        x++;
      }
    }else{
      clean[y++] = url[x++];
    }
  }

  clean[y] = '\0';

  return clean;
}

int main(){

  char test1[] = "https://www.google.com/search?q=c%20code%20snippets&rlz=1C1GCEU_enUS832US832&oq=C+code+snippets&aqs=chrome.0.0j69i60l3j35i39l2j0.3009j0j7&sourceid=chrome&ie=UTF-8";
  char test2[] = "https://www.gutenberg.org/files/4363/4363-h/4363-h.htm#link2HCH0001";
  char test3[] = "https://www.youtube.com/watch?v=jNQXAC9IVRw&t=235s";
  char test4[] = "http://mywebsite.com/index.php?name=John+Doe&age=25&gender=male&occupation=Programmer";

  printf("Original URL: %s\n", test1);
  printf("Cleaned URL: %s\n\n", sanitizeURL(test1));

  printf("Original URL: %s\n", test2);
  printf("Cleaned URL: %s\n\n", sanitizeURL(test2));

  printf("Original URL: %s\n", test3);
  printf("Cleaned URL: %s\n\n", sanitizeURL(test3));

  printf("Original URL: %s\n", test4);
  printf("Cleaned URL: %s\n\n", sanitizeURL(test4));

  return 0;
}