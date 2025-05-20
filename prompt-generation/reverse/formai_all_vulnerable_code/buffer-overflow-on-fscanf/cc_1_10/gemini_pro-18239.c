//GEMINI-pro DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Let's say we have a secret message to hide.
  char secretMessage[] = "Meet me at the park at midnight.";

  // We need a place to store our secret message. Let's use a file for this.
  FILE *secretFile = fopen("secret.txt", "w");
  if (secretFile == NULL) {
    // Oops! Something went wrong. Let's print an error message.
    printf("Error: Could not open the secret file for writing.\n");
    return -1;
  }

  // Now, let's write our secret message to the file.
  fprintf(secretFile, "%s\n", secretMessage);

  // We're done with the file now, so let's close it.
  fclose(secretFile);

  // Now, let's imagine a spy has intercepted our secret file. They want to know what's inside.

  // The spy opens the file for reading.
  secretFile = fopen("secret.txt", "r");
  if (secretFile == NULL) {
    // Oops! Something went wrong again. Let's print an error message.
    printf("Error: Could not open the secret file for reading.\n");
    return -1;
  }

  // The spy reads the secret message from the file.
  char interceptedMessage[100];
  fscanf(secretFile, "%s", interceptedMessage);

  // The spy now knows our secret message!
  printf("The spy has intercepted our secret message: %s\n", interceptedMessage);

  // We're done with the file again, so let's close it.
  fclose(secretFile);

  // But wait! We don't want the spy to know our secret message. Let's encrypt it before we write it to the file.
  // We'll use a simple XOR encryption for this.

  // Let's create a key for our encryption.
  char key[] = "supersecretkey";

  // Let's encrypt our secret message.
  for (int i = 0; i < strlen(secretMessage); i++) {
    secretMessage[i] ^= key[i % strlen(key)];
  }

  // Now, let's write the encrypted message to the file.
  secretFile = fopen("secret.txt", "w");
  if (secretFile == NULL) {
    // Oops! Something went wrong yet again. Let's print an error message.
    printf("Error: Could not open the secret file for writing.\n");
    return -1;
  }

  // We write the encrypted message to the file.
  fprintf(secretFile, "%s\n", secretMessage);

  // We're done with the file, so let's close it.
  fclose(secretFile);

  // Now, let's imagine the spy intercepts our encrypted message.

  // The spy opens the file for reading.
  secretFile = fopen("secret.txt", "r");
  if (secretFile == NULL) {
    // Oops! Something went wrong yet again. Let's print an error message.
    printf("Error: Could not open the secret file for reading.\n");
    return -1;
  }

  // The spy reads the encrypted message from the file.
  char interceptedEncryptedMessage[100];
  fscanf(secretFile, "%s", interceptedEncryptedMessage);

  // The spy doesn't know the key, so they can't decrypt the message.

  // Let's decrypt our secret message.
  for (int i = 0; i < strlen(secretMessage); i++) {
    secretMessage[i] ^= key[i % strlen(key)];
  }

  // We now have our original secret message back.

  // We're done with the file, so let's close it.
  fclose(secretFile);

  // We've successfully protected our secret message from the spy!
  printf("The spy has intercepted our encrypted secret message: %s\n", interceptedEncryptedMessage);
  printf("But they can't decrypt it without the key!\n");

  return 0;
}