//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  char output[100];
  char search[20];
  char replace[20];
  int i, j, k, len1, len2, len3, found;

  //Take input from user
  printf("Enter a string: ");
  fgets(input, 100, stdin);
  
  //Remove newline character from input
  len1 = strlen(input);
  if(input[len1-1] == '\n') {
    input[len1-1] = '\0';
  }
  
  //Take search and replace string from user
  printf("Enter search string: ");
  scanf("%s", search);
  printf("Enter replace string: ");
  scanf("%s", replace);
  
  len2 = strlen(search);
  len3 = strlen(replace);
  
  //Replace all occurrences of search string with replace string
  i = 0;
  while(input[i] != '\0') {
    j = 0;
    found = 0;
    while(input[i+j] == search[j]) {
      j++;
      if(j == len2) {
        found = 1;
        break;
      }
    }
    
    if(found) {
      for(k=0; k<len3; k++) {
        output[i+k] = replace[k];
      }
      i += len2;
    }
    else {
      output[i] = input[i];
      i++;
    }
  }
  output[i] = '\0';
  
  printf("Input string: %s\n", input);
  printf("Output string: %s\n", output);

  return 0;
}