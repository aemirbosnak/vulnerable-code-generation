//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h> // for standard input/output functions
#include <string.h> // for strlen() function

// function prototype declarations
char* encrypt(char str[], int shift);
char* decrypt(char str[], int shift);

int main()
{
  char str[100]; // input string
  int shift;     // number of positions to shift the characters
  
  // greet the user
  printf("Hello there! Let's encrypt your string using the Caesar Cipher technique.\n");
  
  // get user input
  printf("Enter your string: ");
  gets(str);
  printf("Enter the number of positions to shift the characters: ");
  scanf("%d", &shift);
  
  // encrypt the string
  char* encrypted_str = encrypt(str, shift);
  
  // print the encrypted string
  printf("Your encrypted string is: %s\n", encrypted_str);
  
  // decrypt the string
  char* decrypted_str = decrypt(encrypted_str, shift);
  
  // print the decrypted string
  printf("Decrypted string: %s", decrypted_str);
  
  return 0;
}

// function to encrypt the string using Caesar Cipher technique
char* encrypt(char str[], int shift)
{
  int i;
  
  for(i=0; i<strlen(str); i++)
  {
    if(str[i]>='a' && str[i]<='z')
    {
      str[i] = (str[i]+shift-'a')%26 + 'a';
    }
    else if(str[i]>='A' && str[i]<='Z')
    {
      str[i] = (str[i]+shift-'A')%26 + 'A';
    }
  }
  
  return str;
}

// function to decrypt the string
char* decrypt(char str[], int shift)
{
  int i;
  
  for(i=0; i<strlen(str); i++)
  {
    if(str[i]>='a' && str[i]<='z')
    {
      str[i] = (str[i]-shift-'a'+26)%26 + 'a';
    }
    else if(str[i]>='A' && str[i]<='Z')
    {
      str[i] = (str[i]-shift-'A'+26)%26 + 'A';
    }
  }
  
  return str;
}