//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  char account[20];
  double balance;
} account_t;

int main() {
  account_t accounts[100];
  int num_accounts = 0;

  // Read in the accounts from a file
  FILE *fp = fopen("accounts.txt", "r");
  if (fp == NULL) {
    perror("Error opening accounts file");
    return EXIT_FAILURE;
  }

  while (fscanf(fp, "%s %s %lf", accounts[num_accounts].name, accounts[num_accounts].account, &accounts[num_accounts].balance) != EOF) {
    num_accounts++;
  }

  fclose(fp);

  // Display the accounts
  printf("Accounts:\n");
  for (int i = 0; i < num_accounts; i++) {
    printf("%s %s %.2lf\n", accounts[i].name, accounts[i].account, accounts[i].balance);
  }

  // Get the user's input
  char input[100];
  while (1) {
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Parse the input
    char *command = strtok(input, " ");
    char *args = strtok(NULL, " ");

    // Execute the command
    if (strcmp(command, "quit") == 0) {
      break;
    } else if (strcmp(command, "deposit") == 0) {
      // Get the account number and amount
      char *account_number = strtok(args, " ");
      double amount = atof(strtok(NULL, " "));

      // Find the account
      int account_index = -1;
      for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account, account_number) == 0) {
          account_index = i;
          break;
        }
      }

      // If the account was found, deposit the amount
      if (account_index != -1) {
        accounts[account_index].balance += amount;
      } else {
        printf("Account not found\n");
      }
    } else if (strcmp(command, "withdraw") == 0) {
      // Get the account number and amount
      char *account_number = strtok(args, " ");
      double amount = atof(strtok(NULL, " "));

      // Find the account
      int account_index = -1;
      for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account, account_number) == 0) {
          account_index = i;
          break;
        }
      }

      // If the account was found, withdraw the amount
      if (account_index != -1) {
        accounts[account_index].balance -= amount;
      } else {
        printf("Account not found\n");
      }
    } else if (strcmp(command, "balance") == 0) {
      // Get the account number
      char *account_number = strtok(args, " ");

      // Find the account
      int account_index = -1;
      for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account, account_number) == 0) {
          account_index = i;
          break;
        }
      }

      // If the account was found, display the balance
      if (account_index != -1) {
        printf("%.2lf\n", accounts[account_index].balance);
      } else {
        printf("Account not found\n");
      }
    } else {
      printf("Invalid command\n");
    }
  }

  // Write the accounts to a file
  fp = fopen("accounts.txt", "w");
  if (fp == NULL) {
    perror("Error opening accounts file");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < num_accounts; i++) {
    fprintf(fp, "%s %s %.2lf\n", accounts[i].name, accounts[i].account, accounts[i].balance);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}