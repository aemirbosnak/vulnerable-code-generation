//FormAI DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  int option, length;
  
  printf("Welcome to the C String Manipulation Program!\n");
  
  do {
    printf("\nPlease select an option:\n");
    printf("1. Reverse a string\n");
    printf("2. Remove a substring\n");
    printf("3. Replace a character in a string\n");
    printf("4. Exit\n");
    printf("Option: ");
    scanf("%d", &option);
    
    switch(option) {
      case 1:
        printf("Enter a string: ");
        scanf("%s", str);
        length = strlen(str);
        for(int i=0; i<length/2; i++) {
          char temp = str[i];
          str[i] = str[length-i-1];
          str[length-i-1] = temp;
        }
        printf("Reversed string: %s\n", str);
        break;
      
      case 2:
        printf("Enter a string: ");
        scanf("%s", str);
        printf("Enter a substring: ");
        char sub[100];
        scanf("%s", sub);
        char *occurrence = strstr(str, sub);
        if(occurrence) {
          int index = occurrence - str;
          memmove(&str[index], &str[index + strlen(sub)], strlen(str) - index);
          printf("Final string after removing substring: %s\n", str);
        }
        else
          printf("Substring not found in string.\n");
        break;
        
      case 3:
        printf("Enter a string: ");
        scanf("%s", str);
        printf("Enter a character to replace: ");
        char old;
        scanf(" %c", &old);
        printf("Enter a new character: ");
        char new;
        scanf(" %c", &new);
        for(int i=0; str[i]!='\0'; i++) {
          if(str[i] == old)
            str[i] = new;
        }
        printf("Final string after replacing character: %s\n", str);
        break;
        
      case 4:
        printf("Exiting program. Thank you for using!\n");
        break;
        
      default:
        printf("Invalid option selected. Please try again.\n");
    }
  } while(option != 4);
  
  return 0;
}