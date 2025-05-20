//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORDS 50
#define PASSWORD_LENGTH 20

/* Function to generate SHA-512 hash of a password */
char *generate_hash(char *password) {
  char *hash = calloc(1, SHA512_DIGEST_LENGTH+1);
  SHA512(password, strlen(password), hash);
  return hash;
}

/* Function to get a password from the user and store it */
void add_password(char passwords[MAX_PASSWORDS][PASSWORD_LENGTH], char *master_password) {
  char password[PASSWORD_LENGTH];
  printf("Enter the password you want to store: ");
  scanf("%s", password);

  /* Encrypt password with master password */
  char *encrypted_password = generate_hash(password);
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    passwords[MAX_PASSWORDS-1][i] = encrypted_password[i];
  }

  printf("Password added successfully!\n");
}

/* Function to decrypt and print a stored password */
void get_password(char passwords[MAX_PASSWORDS][PASSWORD_LENGTH], char *master_password) {
  char password_num_str[10];
  printf("Enter the number of the password you want to retrieve: ");
  scanf("%s", password_num_str);
  int password_num = atoi(password_num_str);

  /* Decrypt password with master password */
  char encrypted_password[PASSWORD_LENGTH];
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    encrypted_password[i] = passwords[password_num-1][i];
  }
  char *password = generate_hash(master_password);
  if (strcmp(password, encrypted_password) == 0) {
    printf("Password: %s\n", password);
  } else {
    printf("Incorrect master password!\n");
  }
}

int main() {
  char passwords[MAX_PASSWORDS][PASSWORD_LENGTH];
  char master_password[PASSWORD_LENGTH];

  /* Prompt user to set master password */
  printf("Please enter your master password: ");
  scanf("%s", master_password);
  char *master_password_hash = generate_hash(master_password);

  while (1) {
    char choice_str[10];
    printf("Choose an option:\n 1. Add password\n 2. Get password\n 3. Exit\n");
    scanf("%s", choice_str);
    int choice = atoi(choice_str);

    if (choice == 1) {
      add_password(passwords, master_password_hash);
    } else if (choice == 2) {
      get_password(passwords, master_password_hash);
    } else if (choice == 3) {
      break;
    } else {
      printf("Invalid choice!\n");
    }
  }

  return 0;
}