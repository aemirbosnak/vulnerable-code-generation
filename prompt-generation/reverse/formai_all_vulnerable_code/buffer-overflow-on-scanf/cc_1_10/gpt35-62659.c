//FormAI DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <string.h>

// Function to encrypt password
void encrypt(char password[]) {
  int length = strlen(password);

  for (int i = 0; i < length; i++) {
    password[i] = password[i] + 10;
  }
}

// Function to decrypt password
void decrypt(char password[]) {
  int length = strlen(password);

  for (int i = 0; i < length; i++) {
    password[i] = password[i] - 10;
  }
}

int main() {
  char filename[] = "passwords.txt";
  FILE *file = fopen(filename, "a+");

  // If the file doesn't exist, create it
  if (file == NULL) {
    printf("Error creating file.\n");
    return 1;
  }

  // Prompt user to enter new password
  printf("Enter a password to save: ");
  char password[50];
  scanf("%s", password);

  // Encrypt the password before saving it
  encrypt(password);

  // Write the password to the file
  fprintf(file, "%s\n", password);

  // Close the file
  fclose(file);

  // Prompt user to enter a password to retrieve
  printf("Enter a password to retrieve: ");
  char search_password[50];
  scanf("%s", search_password);

  char buffer[50];

  // Decrypt and print out the matching password from the file
  while (fgets(buffer, 50, file)) {
    decrypt(buffer);
    if (strcmp(buffer, search_password) == 0) {
      printf("Your password is: %s\n", buffer);
      break;
    }
  }

  // Close the file
  fclose(file);

  return 0;
}