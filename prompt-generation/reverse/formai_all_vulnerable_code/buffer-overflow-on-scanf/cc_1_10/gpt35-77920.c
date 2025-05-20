//FormAI DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length allowed for a password
#define MAX_PASSWORD_LEN 20

// Structure to store user information
struct user {
  char username[MAX_PASSWORD_LEN];
  char password[MAX_PASSWORD_LEN];
};

// Function to get a username and password from the user
void get_user(struct user *u) {
  printf("Please enter your username: ");
  scanf("%s", u->username);
  
  printf("Please enter your password (maximum %d characters): ", MAX_PASSWORD_LEN);
  scanf("%s", u->password);
}

// Function to check if a password is strong enough
int check_strength(char *password) {
  int i, len = strlen(password);
  
  // Check for minimum length
  if (len < 8) {
    printf("Your password is too short. Please choose one that is at least 8 characters long.\n");
    return 0;
  }
  
  // Check for complex characters
  for (i = 0; i < len; i++) {
    if (!(password[i] >= 'a' && password[i] <= 'z')
     && !(password[i] >= 'A' && password[i] <= 'Z')
     && !(password[i] >= '0' && password[i] <= '9')) {
      printf("Your password should contain only letters (A-Z, a-z) and numbers (0-9).\n");
      return 0;
    }
  }
  
  return 1;
}

// Function to store user information in a file
void save_user(struct user *u) {
  FILE *fp;
  
  fp = fopen("users.txt", "a");
  fprintf(fp, "%s %s\n", u->username, u->password);
  fclose(fp);
}

// Function to authenticate a user
int authenticate_user(char *username, char *password) {
  FILE *fp;
  char buf[MAX_PASSWORD_LEN*2];
  char saved_username[MAX_PASSWORD_LEN], saved_password[MAX_PASSWORD_LEN];
  
  fp = fopen("users.txt", "r");
  
  while (fgets(buf, MAX_PASSWORD_LEN*2, fp)) {
    sscanf(buf, "%s %s", saved_username, saved_password);
    if (strcmp(username, saved_username) == 0 && strcmp(password, saved_password) == 0) {
      fclose(fp);
      return 1;
    }
  }
  
  fclose(fp);
  return 0;
}

int main() {
  struct user u;
  int success;
  
  printf("Please create your account by entering a username and password:\n");
  do {
    get_user(&u);
  } while (!check_strength(u.password));
  
  save_user(&u);
  
  printf("Account created successfully. Please log in.\n");
  do {
    get_user(&u);
    success = authenticate_user(u.username, u.password);
    if (!success) {
      printf("Invalid username or password. Please try again.\n");
    }
  } while (!success);
  
  printf("Login successful.\n");
  
  return 0;
}