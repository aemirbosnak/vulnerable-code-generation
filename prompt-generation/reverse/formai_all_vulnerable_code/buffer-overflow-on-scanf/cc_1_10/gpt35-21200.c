//FormAI DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

/*
  _____       _        _____ _
 |_   _|     | |      /__   \ |
   | |  _ __ | |_ ______ ) | |_ __ ___   __ _
   | | | '_ \| __|______/ / | | '_ ` _ \ / _` |
  _| |_| | | | |_      / /_ | | | | | | | (_| |
 |_____|_| |_|\__|    |____||_|_| |_| |_|\__, |
                                          __/ |
                                         |___/
*/

int main(void) {
  
  printf("\nWelcome to the Cryptic Email Client!\n\n");

  // Email account credentials
  char username[20] = "*********"; // Please enter your email username
  char password[20] = "*********"; // Please enter your email password
  
  // Email recipient and subject
  char recipient[30];
  char subject[50];
  
  // Email message body
  char message[500];
  
  printf("Enter the recipient's email address: ");
  scanf("%s", recipient);
  
  printf("Enter the subject of your email: ");
  scanf(" %[^\n]s", subject);
  
  printf("Enter the message you want to send: ");
  scanf(" %[^\n]s", message);
  
  // Encryption algorithm
  int key = 7; // Please choose an encryption key between 1 to 10
  char encrypted_message[500];
  int i;
  for(i = 0; message[i] != '\0'; ++i) {
    encrypted_message[i] = message[i] + key;
  }
 
  // Connection to email server
  printf("\nConnecting to email server...\n");
  printf("Username and password verified.\n\n");

  // Sending email
  printf("Preparing to send email...\n");
  printf("Encrypting message for maximum security...\n");
  printf("Message encrypted with key %d.\n\n", key);
  printf("Sending email to %s...\n", recipient);
  printf("Subject: %s\n", subject);
  printf("Message: %s\n\n", encrypted_message);
  printf("Email sent successfully!\n");
  
  return 0;
}