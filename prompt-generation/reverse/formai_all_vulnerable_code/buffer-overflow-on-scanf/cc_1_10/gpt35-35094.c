//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 100
#define MAX_KEY_LEN 16

void encrypt(char *text, char *key);
void decrypt(char *text, char *key);

int main() {
   char text[MAX_TEXT_LEN], key[MAX_KEY_LEN];
   int choice;

   printf("Enter the text to encrypt or decrypt: ");
   fgets(text, MAX_TEXT_LEN, stdin);

   printf("Enter the key: ");
   fgets(key, MAX_KEY_LEN, stdin);

   do {
       printf("\nChoose the operation:\n1. Encrypt\n2. Decrypt\n3. Exit\n");
       scanf("%d", &choice);

       switch(choice) {
           case 1: encrypt(text, key);
                   printf("Encrypted text: %s\n", text);
                   break;
           case 2: decrypt(text, key);
                   printf("Decrypted text: %s\n", text);
                   break;
           case 3: printf("Exiting...\n"); 
                   break;
           default: printf("Invalid choice\n");
                    break;
       }
   } while(choice != 3);

   return 0;
}

void encrypt(char *text, char *key) {
   int i, j, len = strlen(text);
   char temp, k;

   for(i = 0, j = 0; i < len; ++i, ++j) {
       if(j == strlen(key))
           j = 0;

       k = key[j];
       temp = text[i];

       text[i] = (temp + k) % 128;
   }
}

void decrypt(char *text, char *key) {
   int i, j, len = strlen(text);
   char temp, k;

   for(i = 0, j = 0; i < len; ++i, ++j) {
       if(j == strlen(key))
           j = 0;

       k = key[j];
       temp = text[i];

       text[i] = (temp - k + 128) % 128;
   }
}