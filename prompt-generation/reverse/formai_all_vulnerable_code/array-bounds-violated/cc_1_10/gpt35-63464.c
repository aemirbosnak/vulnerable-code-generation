//FormAI DATASET v1.0 Category: Encryption ; Style: surprised
//Wow, I cannot believe I am about to show you this unique C encryption program! 
//This is going to be the coolest program you have ever seen.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Here I am defining the key that will be used for the encryption
#define KEY "sup3rS3cr3tKeY"

// This is the main function
int main(void) {

  // First, let's ask the user to enter a message that we will encrypt
  char message[1000];
  printf("Enter a message to encrypt: ");
  fgets(message, 1000, stdin);
  
  // Next, we will get the length of the message so we can loop through it later
  int messageLen = strlen(message) - 1;

  // We will also get the length of the key so that we can loop through it as well
  int keyLen = strlen(KEY);

  // Now, let's create a new char array to store the encrypted message
  char encrypted[1000];

  // Let's loop through the message and encrypt each character
  for (int i = 0; i < messageLen; i++) {

    // First, we will get the ASCII value of the current message character
    int asciiVal = (int) message[i];

    // Next, we will get the corresponding ASCII value of the key character
    int keyVal = (int) KEY[i % keyLen];

    // Now, we will add the two ASCII values together
    int sum = asciiVal + keyVal;

    // Finally, we will store the encrypted character in the encrypted array
    encrypted[i] = (char) sum;
  }

  // Let's add a null character to the end of the encrypted array so that we know where the string ends
  encrypted[messageLen] = '\0';

  // Now, let's print the encrypted message to the screen
  printf("Encrypted message: %s\n", encrypted);

  // Okay, now let's decrypt the message and print it to the screen
  char decrypted[1000];
  for (int i = 0; i < messageLen; i++) {

    // First, we will get the ASCII value of the current encrypted character
    int asciiVal = (int) encrypted[i];

    // Next, we will get the corresponding ASCII value of the key character
    int keyVal = (int) KEY[i % keyLen];

    // Now, we will subtract the key value from the encrypted value to get the original message character
    int sum = asciiVal - keyVal;

    // Finally, we will store the decrypted character in the decrypted array
    decrypted[i] = (char) sum;
  }

  // Let's add a null character to the end of the decrypted array so that we know where the string ends
  decrypted[messageLen] = '\0';

  // Now, let's print the decrypted message to the screen
  printf("Decrypted message: %s\n", decrypted);

  // And that's it! Wasn't that the coolest C encryption program you've ever seen?!
  return 0;
}