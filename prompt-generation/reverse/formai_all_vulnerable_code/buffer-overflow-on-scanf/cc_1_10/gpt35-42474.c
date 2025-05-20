//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: excited
#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h> 
#include <time.h> 

#define MIN_LEN 8 
#define MAX_LEN 20 
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ" 
#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz" 
#define DIGITS "0123456789" 
#define SPECIAL_CHARS "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~" 

/**
* Function to generate a secure password
* @param length - Length of the password to be generated
* @return - Generated password
*/
char* generatePassword(int length)
{
  // characters to be used in the password
  char* valid_chars = malloc(sizeof(char) * (strlen(UPPERCASE_CHARS) + strlen(LOWERCASE_CHARS) + strlen(DIGITS) + strlen(SPECIAL_CHARS)));
  strcpy(valid_chars, UPPERCASE_CHARS);
  strcat(valid_chars, LOWERCASE_CHARS);
  strcat(valid_chars, DIGITS);
  strcat(valid_chars, SPECIAL_CHARS);

  // seed the random number generator using current time
  srand((unsigned int)time(NULL));

  // allocate memory for password
  char* password = malloc(sizeof(char) * (length + 1));
  password[length] = '\0';

  // generate random password
  for (int i = 0; i < length; i++)
  {
    password[i] = valid_chars[rand() % strlen(valid_chars)];
  }

  // free allocated memory
  free(valid_chars);

  return password;
}

int main()
{
  int len = 0;

  // prompt user for password length
  printf("Enter the length of the password (minimum %d, maximum %d): ", MIN_LEN, MAX_LEN);
  scanf("%d", &len);

  // check if password length is within range
  if (len < MIN_LEN || len > MAX_LEN)
  {
    printf("Invalid password length! Password must be between %d and %d characters long.", MIN_LEN, MAX_LEN);
  }

  // generate password and display to user
  else
  {
    char* password = generatePassword(len);
    printf("\nYour secure password is: %s\n", password);
    free(password);
  }

  return 0;
}