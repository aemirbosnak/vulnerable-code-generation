//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
// Fair Verona, where we lay our scene,
// Where love and fate entwine, a tragic theme.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Characters from Shakespeare's timeless play
const char *romeo = "Romeo";
const char *juliet = "Juliet";

// Constants for password generation
const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
const int min_length = 8;
const int max_length = 16;

// Balcony whispers, where secrets are exchanged
void generatePassword(int length) {
  // A secret meeting at night, under the moon's light
  srand(time(NULL));

  // A tapestry of characters, woven into a secure string
  char password[length + 1];
  for (int i = 0; i < length; i++) {
    password[i] = chars[rand() % strlen(chars)];
  }
  password[length] = '\0'; // Seal the vows with a null terminator

  // A whispered promise, a password to embrace
  printf("Thy password, fair one: %s\n", password);
}

int main() {
  // A grand ball, where secrets unfold,
  // As Romeo and Juliet's love story is told.

  // The Friar's wisdom, guiding us to encryption's art
  int choice;
  while (1) {
    // "What's in a name? That which we call a rose,
    // By any other word would smell as sweet."
    printf("Choose thy password length, fair maiden or brave youth (8-16): ");
    scanf("%d", &choice);

    // A true love's kiss, sealing the password's trust
    if (choice >= min_length && choice <= max_length) {
      break;
    } else {
      printf("Alas, thy choice is too short or long. Try again, gentle soul.\n");
    }
  }

  // The balcony scene, where love and security intertwine
  printf("Hark! A password worthy of thy love's shrine:\n");
  generatePassword(choice);

  // The parting of ways, but the password remains,
  // A symbol of love, forever entwined in their veins.
  return 0;
}