//FormAI DATASET v1.0 Category: Banking Record System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account { 
  int acc_num;
  char name[50];
  float balance;
} acc;

void create_account() {
  FILE *fp;
  fp = fopen("accounts.txt", "ab+");
  printf("Enter account number: ");
  scanf("%d", &acc.acc_num);
  printf("Enter name: ");
  getchar();
  fgets(acc.name, 50, stdin);
  printf("Enter initial balance: ");
  scanf("%f", &acc.balance);
  fwrite(&acc, sizeof(acc), 1, fp);
  fclose(fp);
  printf("Account created successfully!\n");
}

void display_account(int acc_num) {
  FILE *fp;
  fp = fopen("accounts.txt", "rb");
  int found = 0;
  while (fread(&acc, sizeof(acc), 1, fp) == 1) {
    if (acc.acc_num == acc_num) {
      found = 1;
      printf("Account number: %d \nName: %sBalance: $%.2f\n", acc.acc_num, acc.name, acc.balance);
    }
  }
  fclose(fp);
  if (!found) {
    printf("Account not found\n");
  }
}

void modify_account(int acc_num) {
  FILE *fp, *temp;
  fp = fopen("accounts.txt", "rb");
  temp = fopen("temp.txt", "wb+");
  int found = 0;
  while (fread(&acc, sizeof(acc), 1, fp) == 1) {
    if (acc.acc_num == acc_num) {
      found = 1;
      printf("Enter new name: ");
      getchar();
      fgets(acc.name, 50, stdin);
      printf("Enter new balance: ");
      scanf("%f", &acc.balance);
    }
    fwrite(&acc, sizeof(acc), 1, temp);
  }
  fclose(fp);
  fclose(temp);
  remove("accounts.txt");
  rename("temp.txt", "accounts.txt");
  if (found) {
      printf("Account modified successfully!\n");
    } else {
      printf("Account not found\n");
    }
}

void delete_account(int acc_num) {
  FILE *fp, *temp;
  fp = fopen("accounts.txt", "rb");
  temp = fopen("temp.txt", "wb+");
  int found = 0;
  while (fread(&acc, sizeof(acc), 1, fp) == 1) {
    if (acc.acc_num == acc_num) {
      found = 1;
    } else {
      fwrite(&acc, sizeof(acc), 1, temp);
    }
  }
  fclose(fp);
  fclose(temp);
  remove("accounts.txt");
  rename("temp.txt", "accounts.txt");
  if (found) {
      printf("Account deleted successfully!\n");
    } else {
      printf("Account not found\n");
    }
}

void display_all() {
  FILE *fp;
  fp = fopen("accounts.txt", "rb");
  while (fread(&acc, sizeof(acc), 1, fp) == 1) {
    printf("Account number: %d \nName: %sBalance: $%.2f\n\n", acc.acc_num, acc.name, acc.balance);
  }
  fclose(fp);
}

int main() {
  int choice, acc_num;
  printf("1. Create account\n2. Display account\n3. Modify account\n4. Delete account\n5. Display all accounts\n6. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  while (choice != 6) {
    switch(choice) {
      case 1:
        create_account();
        break;
      case 2:
        printf("Enter account number: ");
        scanf("%d", &acc_num);
        display_account(acc_num);
        break;
      case 3:
        printf("Enter account number: ");
        scanf("%d", &acc_num);
        modify_account(acc_num);
        break;
      case 4:
        printf("Enter account number: ");
        scanf("%d", &acc_num);
        delete_account(acc_num);
        break;
      case 5:
        display_all();
        break;
      default:
        printf("Invalid choice\n");
    }
    printf("Enter your choice: ");
    scanf("%d", &choice);
  }
  printf("Goodbye!\n");
  return 0;
}