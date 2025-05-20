//FormAI DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 30
#define MASTER_USERNAME "admin"
#define MASTER_PASSWORD "123456"

typedef struct {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} Account;

int num_accounts = 0;
Account account_list[MAX_ACCOUNTS];

/* Function declarations */
void clear_buffer(void);
void change_master_password(void);
void display_all_accounts(void);
void add_account(void);
void delete_account(void);
void search_account(void);
void login(void);

/* Entry point */
int main(void) {
  login();
  int choice;
  do {
    printf("\nMenu\n");
    printf("1. Change Master Password\n");
    printf("2. Display All Accounts\n");
    printf("3. Add Account\n");
    printf("4. Delete Account\n");
    printf("5. Search Account\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        change_master_password();
        break;
      case 2:
        display_all_accounts();
        break;
      case 3:
        add_account();
        break;
      case 4:
        delete_account();
        break;
      case 5:
        search_account();
        break;
      case 6:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 6);

  return 0;
}

/* Function to clear input buffer */
void clear_buffer(void) {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

/* Function to change the master password */
void change_master_password(void) {
  char current_password[MAX_PASSWORD_LENGTH];
  char new_password[MAX_PASSWORD_LENGTH];
  char confirm_password[MAX_PASSWORD_LENGTH];

  printf("Enter current master password: ");
  scanf("%s", current_password);
  clear_buffer();

  if (strcmp(current_password, MASTER_PASSWORD) != 0) {
    printf("Incorrect password!\n");
    return;
  }

  printf("Enter new password: ");
  scanf("%s", new_password);
  clear_buffer();

  printf("Confirm new password: ");
  scanf("%s", confirm_password);
  clear_buffer();

  if (strcmp(new_password, confirm_password) == 0) {
    strcpy(MASTER_PASSWORD, new_password);
    printf("Master password changed successfully!\n");
  } else {
    printf("Passwords do not match!\n");
  }
}

/* Function to display all accounts */
void display_all_accounts(void) {
  printf("\nAll Accounts\n");
  printf("-------------\n");
  for (int i = 0; i < num_accounts; i++) {
    printf("%d. Username: %s\n   Password: %s\n", i + 1, account_list[i].username, account_list[i].password);
  }
}

/* Function to add a new account */
void add_account(void) {
  if (num_accounts == MAX_ACCOUNTS) {
    printf("Maximum number of accounts reached!\n");
    return;
  }

  Account new_account;
  printf("Enter username: ");
  scanf("%s", new_account.username);
  clear_buffer();

  printf("Enter password: ");
  scanf("%s", new_account.password);
  clear_buffer();

  account_list[num_accounts] = new_account;
  num_accounts++;
  printf("Account added successfully!\n");

  printf("Number of accounts: %d\n", num_accounts);
}

/* Function to delete an existing account */
void delete_account(void) {
  printf("Enter username of account to delete: ");
  char username[MAX_USERNAME_LENGTH];
  scanf("%s", username);
  clear_buffer();

  int index = -1;
  for (int i = 0; i < num_accounts; i++) {
    if (strcmp(account_list[i].username, username) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Account not found!\n");
  } else {
    for (int i = index; i < num_accounts - 1; i++) {
      account_list[i] = account_list[i + 1];
    }
    num_accounts--;
    printf("Account deleted successfully!\n");

    printf("Number of accounts: %d\n", num_accounts);
  }
}

/* Function to search for an account */
void search_account(void) {
  printf("Enter username of account to search: ");
  char username[MAX_USERNAME_LENGTH];
  scanf("%s", username);
  clear_buffer();

  int index = -1;
  for (int i = 0; i < num_accounts; i++) {
    if (strcmp(account_list[i].username, username) == 0) {
      index = i;
      printf("Account found!\n");
      printf("Username: %s\n", account_list[i].username);
      printf("Password: %s\n", account_list[i].password);
      break;
    }
  }

  if (index == -1) {
    printf("Account not found!\n");
  }
}

/* Function to print a paranoid message */
void paranoid_message(void) {
  printf("There are people watching you!\n");
}

/* Function for user login */
void login(void) {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];

  do {
    paranoid_message();
    printf("Enter username: ");
    scanf("%s", username);
    clear_buffer();
    paranoid_message();
    printf("Enter password: ");
    scanf("%s", password);
    clear_buffer();
  } while (strcmp(username, MASTER_USERNAME) != 0 || strcmp(password, MASTER_PASSWORD) != 0);

  printf("Login successful!\n");
}