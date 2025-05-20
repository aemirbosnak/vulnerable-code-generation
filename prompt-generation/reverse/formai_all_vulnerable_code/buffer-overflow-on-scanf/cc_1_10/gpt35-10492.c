//FormAI DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 100

//Encryption function
void encrypt(char *plaintext, int key)
{
   int i;
   char ch;

   for(i = 0; i < strlen(plaintext); ++i){
      ch = plaintext[i];

      //Alphabets Encryption
      if(ch >= 'a' && ch <= 'z'){
         ch = (ch + key - 'a') % 26 + 'a';
      }
      else if(ch >= 'A' && ch <= 'Z'){
         ch = (ch + key - 'A') % 26 + 'A';
      }

      plaintext[i] = ch;
   }
}

//Decryption function
void decrypt(char *ciphertext, int key)
{
   int i;
   char ch;

   for(i = 0; i < strlen(ciphertext); ++i){
      ch = ciphertext[i];

      //Alphabets Decryption
      if(ch >= 'a' && ch <= 'z'){
         ch = (ch - key + 'a') % 26 + 'a';
      }
      else if(ch >= 'A' && ch <= 'Z'){
         ch = (ch - key + 'A') % 26 + 'A';
      }

      ciphertext[i] = ch;
   }
}

int main()
{
   char plaintext[MAX_LEN], ciphertext[MAX_LEN];
   int key;

   //Getting input from User
   printf("Enter plaintext: ");
   fgets(plaintext, MAX_LEN, stdin);

   printf("Enter key: ");
   scanf("%d", &key);

   //Encrypting and Decrypting the plaintext based on given key
   encrypt(plaintext, key);
   printf("Encrypted plaintext: %s\n", plaintext);

   decrypt(plaintext, key);
   printf("Decrypted ciphertext: %s\n", plaintext);

   return 0;
}