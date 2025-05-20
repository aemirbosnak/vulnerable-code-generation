//FormAI DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

void encrypt(char*, int);
void decrypt(char*, int);

int main()
{
   char str[MAX_SIZE];
   int key, choice;

   printf("\nWelcome to the C File Encryptor Program!\n\n");
   printf("Please enter a string to encrypt: ");
   fgets(str, sizeof(str), stdin);
   printf("Please enter a key to use for encryption: ");
   scanf("%d", &key);

   printf("\nChoose an option:\n");
   printf("1. Encrypt the string\n");
   printf("2. Decrypt the string\n");
   printf("Your choice: ");
   scanf("%d", &choice);

   switch(choice)
   {
      case 1:
         encrypt(str, key);
         printf("\nEncrypted string: %s\n", str);
         break;
      case 2:
         decrypt(str, key);
         printf("\nDecrypted string: %s\n", str);
         break;
      default:
         printf("\nInvalid option, please try again.\n");
   }

   return 0;
}

void encrypt(char* str, int key)
{
   int i;
   char ch;

   for(i = 0; i < strlen(str); i++)
   {
      ch = str[i];

      if(ch >= 'a' && ch <= 'z')
         str[i] = ((ch - 'a' + key) % 26) + 'a';
      else if(ch >= 'A' && ch <= 'Z')
         str[i] = ((ch - 'A' + key) % 26) + 'A';
   }
}

void decrypt(char* str, int key)
{
   int i;
   char ch;

   for(i = 0; i < strlen(str); i++)
   {
      ch = str[i];

      if(ch >= 'a' && ch <= 'z')
         str[i] = (((ch - 'a' - key) + 26) % 26) + 'a';
      else if(ch >= 'A' && ch <= 'Z')
         str[i] = (((ch - 'A' - key) + 26) % 26) + 'A';
   }
}