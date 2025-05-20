#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  char key[] = "supersecret";
  char message[] = "Hello, world!";
  int encrypted_message_length = encrypt(key, message, strlen(message));
  char encrypted_message[encrypted_message_length];
  encrypt(key, encrypted_message, encrypted_message_length);
  printf("%s", encrypted_message);
  return 0;
}

int encrypt(char *key, char *message, int message_length)
{
  int key_length = strlen(key);
  int encrypted_message_length = message_length + 1;
  char *encrypted_message = malloc(encrypted_message_length);
  for (int i = 0; i < message_length; i++)
  {
    encrypted_message[i] = message[i] ^ key[i % key_length];
  }
  encrypted_message[message_length] = '\0';
  return encrypted_message_length;
}
