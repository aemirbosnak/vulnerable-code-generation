//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// The Crazy Encryption Function
void encode(char* message, int key) {

  // Loop through each character in the message
  for(int i = 0; i < strlen(message); i++) {

    // Check if the character is a space
    if(message[i] == ' ') {
      printf("space!!!"); // I always get excited when I see a space
      continue; // Don't encode spaces
    }

    // Add the key to the character value
    int encoded = message[i] + key;

    // Check if the encoded character is greater than z
    if(encoded > 'z') {

      // Go back to 'a' and count the remaining steps
      int steps = encoded - 'z' - 1;

      // Wrap around to 'a' and continue counting
      encoded = 'a' + steps;

      // LOL! This is crazy
      printf("Wrap around to 'a'\n");

    }

    // Print the encoded character
    printf("%c", (char) encoded);

  }

}

int main() {

  // Ask for the message to encode
  printf("Enter the message to encode: ");
  char message[100];
  fgets(message, 100, stdin);

  // Ask for the encryption key
  printf("Enter the encryption key: ");
  int key;
  scanf("%d", &key);

  // Encode the message
  printf("Crazy Translation: ");
  encode(message, key);

  return 0;
}