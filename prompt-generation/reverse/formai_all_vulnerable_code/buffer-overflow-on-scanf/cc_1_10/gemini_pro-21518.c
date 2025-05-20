//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Retro-inspired ASCII art for title screen
void titleScreen() {
  printf("\n\n");
  printf("██████╗  ██████╗ ███╗   ██╗████████╗\n");
  printf("██╔══██╗██╔═══██╗████╗  ██║╚══██╔══╝\n");
  printf("██████╔╝██║   ██║██╔██╗ ██║   ██║   \n");
  printf("██╔══██╗██║   ██║██║╚██╗██║   ██║   \n");
  printf("██║  ██║╚██████╔╝██║ ╚████║   ██║   \n");
  printf("╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   \n\n");
}

//Retro-inspired ASCII art for help screen
void helpScreen() {
  printf("\nCommands:\n");
  printf(" - 'e' to encrypt a message\n");
  printf(" - 'd' to decrypt a message\n");
  printf(" - 'h' to display this help screen\n");
  printf(" - 'q' to quit the program\n\n");
}

//Encrypts a message using a simple substitution cipher
void encryptMessage() {
  char message[100];
  char encryptedMessage[100];
  int key;

  printf("Enter the message you want to encrypt: ");
  scanf("%s", message);

  printf("Enter the encryption key (0-25): ");
  scanf("%d", &key);

  for (int i = 0; i < strlen(message); i++) {
    encryptedMessage[i] = message[i] + key;
  }

  printf("Encrypted message: %s\n", encryptedMessage);
}

//Decrypts a message using a simple substitution cipher
void decryptMessage() {
  char encryptedMessage[100];
  char decryptedMessage[100];
  int key;

  printf("Enter the encrypted message you want to decrypt: ");
  scanf("%s", encryptedMessage);

  printf("Enter the decryption key (0-25): ");
  scanf("%d", &key);

  for (int i = 0; i < strlen(encryptedMessage); i++) {
    decryptedMessage[i] = encryptedMessage[i] - key;
  }

  printf("Decrypted message: %s\n", decryptedMessage);
}

int main() {
  char choice;

  titleScreen();

  do {
    printf("Enter your choice (e/d/h/q): ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'e':
        encryptMessage();
        break;
      case 'd':
        decryptMessage();
        break;
      case 'h':
        helpScreen();
        break;
      case 'q':
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 'q');

  return 0;
}