//FormAI DATASET v1.0 Category: Modern Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char str[], int key) {
   int n = strlen(str);
   for(int i = 0; i < n; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
         str[i] = (str[i] + key - 'a') % 26 + 'a';
      }
      else if(str[i] >= 'A' && str[i] <= 'Z') {
         str[i] = (str[i] + key - 'A') % 26 + 'A';
      }
      else if(str[i] >= '0' && str[i] <= '9') {
         str[i] = (str[i] + key - '0') % 10 + '0';
      }
   }
}

void decrypt(char str[], int key) {
   int n = strlen(str);
   for(int i = 0; i < n; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
         str[i] = (str[i] - key - 'a' + 26) % 26 + 'a';
      }
      else if(str[i] >= 'A' && str[i] <= 'Z') {
         str[i] = (str[i] - key - 'A' + 26) % 26 + 'A';
      }
      else if(str[i] >= '0' && str[i] <= '9') {
         str[i] = (str[i] - key - '0' + 10) % 10 + '0';
      }
   }
}

int main() {
   char str[100];
   int key;

   printf("Enter a string:\n");
   scanf("%s", str);
   printf("Enter the key (0-25):\n");
   scanf("%d", &key);

   encrypt(str, key);

   printf("Encrypted string: %s\n", str);

   decrypt(str, key);

   printf("Decrypted string: %s\n", str);

   return 0;
}