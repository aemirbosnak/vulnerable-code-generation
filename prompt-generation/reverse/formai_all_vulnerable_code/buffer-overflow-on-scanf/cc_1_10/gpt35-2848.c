//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str, int key);
void decrypt(char *str, int key);

int main() {
  char string[100];
  int key, choice;
  
  printf("Welcome to curious C Encryption program! \n\n");
  printf("Enter the string you want to encrypt: ");
  fgets(string, 100, stdin);
  
  printf("\nEnter the key (must be a positive integer): ");
  scanf("%d", &key);
  
  printf("\nSelect an option: \n");
  printf("1. Encrypt the string \n");
  printf("2. Decrypt the string \n");
  printf("Option: ");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      encrypt(string, key);
      printf("\nEncrypted string: %s\n", string);
      break;
      
    case 2:
      decrypt(string, key);
      printf("\nDecrypted string: %s\n", string);
      break;
      
    default:
      printf("\nInvalid option.\n");
      break;
  }
  
  return 0;
}

void encrypt(char *str, int key) {
  int length = strlen(str);
  int i;
  
  for(i = 0; i < length; i++) {
    if(isalpha(str[i])) {
      if(isupper(str[i])) {
        str[i] = ((str[i] - 'A' + key) % 26) + 'A';
      }
      else {
        str[i] = ((str[i] - 'a' + key) % 26) + 'a';
      }
    }
    else if(isdigit(str[i])) {
      str[i] = ((str[i] - '0' + key) % 10) + '0';
    }
    else {
      str[i] = str[i];
    }
  }
}

void decrypt(char *str, int key) {
  int length = strlen(str);
  int i;
  
  for(i = 0; i < length; i++) {
    if(isalpha(str[i])) {
      if(isupper(str[i])) {
        str[i] = (((str[i] - 'A' - key) + 26) % 26) + 'A';
      }
      else {
        str[i] = (((str[i] - 'a' - key) + 26) % 26) + 'a';
      }
    }
    else if(isdigit(str[i])) {
      str[i] = (((str[i] - '0' - key) + 10) % 10) + '0';
    }
    else {
      str[i] = str[i];
    }
  }
}