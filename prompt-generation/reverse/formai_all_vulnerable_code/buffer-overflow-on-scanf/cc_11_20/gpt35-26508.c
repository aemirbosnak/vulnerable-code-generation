//FormAI DATASET v1.0 Category: String manipulation ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGTH 100

int main(){
  char string[MAX_STR_LENGTH];
  char substring[MAX_STR_LENGTH];
  char replace[MAX_STR_LENGTH];
  int choice;
  int i, j, k;

  printf("Enter a string: ");
  fgets(string, MAX_STR_LENGTH, stdin);
  printf("Enter a substring: ");
  fgets(substring, MAX_STR_LENGTH, stdin);

  // Remove newline characters from user input
  for(i = 0; i < MAX_STR_LENGTH; i++){
    if(string[i] == '\n'){
      string[i] = '\0';
      break;
    }
  }
  for(i = 0; i < MAX_STR_LENGTH; i++){
    if(substring[i] == '\n'){
      substring[i] = '\0';
      break;
    }
  }

  printf("Select an operation:\n");
  printf("1. Find substring\n");
  printf("2. Replace substring\n");
  scanf("%d", &choice);
  
  if(choice == 1){
    if(strstr(string, substring)){
      printf("'%s' found in '%s'\n", substring, string);
    }
    else{
      printf("'%s' not found in '%s'\n", substring, string);
    }
  }
  else if(choice == 2){
    printf("Enter replacement string: ");
    scanf(" %[^\n]", replace);

    // Find all occurrences of substring and replace with replace string
    for(i = 0; string[i] != '\0';){
      j = 0;
      k = i;

      while(string[k] == substring[j]){
        j++;
        k++;
      }

      if(substring[j] == '\0'){
        // Shift remaining characters in string to make room for replace string
        for(k = i + strlen(substring); string[k] != '\0'; k++){
          string[k + strlen(replace) - strlen(substring)] = string[k];
        }

        // Insert replace string
        for(k = 0; replace[k] != '\0'; k++){
          string[i + k] = replace[k];
        }

        i += strlen(replace);
      }
      else{
        i++;
      }
    }

    printf("Modified string: %s", string);
  }
  else{
    printf("Invalid choice\n");
  }

  return 0;
}