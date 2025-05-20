//FormAI DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Encryption function
void encrypt(char* message, int key)
{
   char ch;
   int i;

   for(i = 0; message[i] != '\0'; ++i){
      ch = message[i];

      // Encrypt only alphabets
      if(ch >= 'a' && ch <= 'z'){
         ch = ch + key;
         if(ch > 'z'){
            ch = ch - 'z' + 'a' - 1;
         }
         message[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z'){
         ch = ch + key;
         if(ch > 'Z'){
            ch = ch - 'Z' + 'A' - 1;
         }
         message[i] = ch;
      }
   }
}

// Decryption function
void decrypt(char* message, int key)
{
   char ch;
   int i;

   for(i = 0; message[i] != '\0'; ++i){
      ch = message[i];

      // Decrypt only alphabets
      if(ch >= 'a' && ch <= 'z'){
         ch = ch - key;
         if(ch < 'a'){
            ch = ch + 'z' - 'a' + 1;
         }
         message[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z'){
         ch = ch - key;
         if(ch < 'A'){
            ch = ch + 'Z' - 'A' + 1;
         }
         message[i] = ch;
      }
   }
}

int main()
{
   char message[100];
   int key, choice;

   printf("Enter message to encrypt:");
   fgets(message, sizeof(message), stdin);

   printf("Enter key:");
   scanf("%d", &key);

   printf("Enter 1 for encryption, and 2 for decryption:");
   scanf("%d", &choice);

   if(choice == 1){
      encrypt(message, key);
      printf("Encrypted message: %s\n", message);
   }
   else if(choice == 2){
      decrypt(message, key);
      printf("Decrypted message: %s\n", message);
   }
   else{
      printf("Invalid choice!\n");
   }

   return 0;
}