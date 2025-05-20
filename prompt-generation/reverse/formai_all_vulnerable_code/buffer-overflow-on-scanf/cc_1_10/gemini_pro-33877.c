//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int account_number;
  char name[50];
  double balance;
} Account;

Account accounts[100];
int num_accounts = 0;

void create_account() {
  printf("Yay! Let's create an account for you!\n");
  printf("What's your name, friend? ");
  scanf("%s", accounts[num_accounts].name);
  printf("Okay, %s, what's your account number? ", accounts[num_accounts].name);
  scanf("%d", &accounts[num_accounts].account_number);
  printf("Excellent! Your balance is 0 to start. We're sure you'll make it grow!\n");
  accounts[num_accounts].balance = 0;
  num_accounts++;
}

void deposit() {
  int account_number;
  double amount;
  printf("Hey there! Let's put some money in your account!\n");
  printf("What's your account number, buddy? ");
  scanf("%d", &account_number);
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Found your account! How much are we depositing today? ");
      scanf("%lf", &amount);
      accounts[i].balance += amount;
      printf("Ta-da! Your new balance is %.2lf\n", accounts[i].balance);
      return;
    }
  }
  printf("Sorry, couldn't find your account. Maybe try again with the right number!");
}

void withdraw() {
  int account_number;
  double amount;
  printf("Oh no, you need to take some money out? Here, let's do it!\n");
  printf("What's your account number, pal? ");
  scanf("%d", &account_number);
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Found your account! How much are we taking out today? ");
      scanf("%lf", &amount);
      if (amount > accounts[i].balance) {
        printf("Sorry, you don't have that much money in your account. Try a smaller amount!");
      } else {
        accounts[i].balance -= amount;
        printf("Here you go! Your new balance is %.2lf\n", accounts[i].balance);
      }
      return;
    }
  }
  printf("Sorry, couldn't find your account. Maybe try again with the right number!");
}

void check_balance() {
  int account_number;
  printf("Want to know how much you have? We'll show you!\n");
  printf("What's your account number, buddy? ");
  scanf("%d", &account_number);
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Found your account! Your balance is %.2lf\n", accounts[i].balance);
      return;
    }
  }
  printf("Sorry, couldn't find your account. Maybe try again with the right number!");
}

int main() {
  int choice;
  do {
    printf("\nBangarang! Welcome to the best banking system ever!\n");
    printf("What do you want to do today?\n");
    printf("1. Create an account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Check balance\n");
    printf("5. Quit\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        create_account();
        break;
      case 2:
        deposit();
        break;
      case 3:
        withdraw();
        break;
      case 4:
        check_balance();
        break;
      case 5:
        printf("Bye-bye! Thanks for banking with us!\n");
        break;
      default:
        printf("Invalid choice. Please try again!\n");
    }
  } while (choice != 5);
  return 0;
}