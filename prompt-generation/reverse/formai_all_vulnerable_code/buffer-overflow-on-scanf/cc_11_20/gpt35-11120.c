//FormAI DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct BankRecord {
  int account_number;
  char name[50];
  float balance;
} BankRecord;

int main() {
  int choice, num_records = 0, account_num, i;
  float deposit_amount, withdrawal_amount;

  BankRecord *records = NULL;

  printf("Welcome to C Banking Record System\n");

  do {
    printf("\nPlease choose an option:\n");
    printf("1. Add a new record\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Display all records\n");
    printf("5. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        num_records++;
        records = (BankRecord*)realloc(records, num_records * sizeof(BankRecord));

        printf("\nEnter account number: ");
        scanf("%d", &records[num_records-1].account_number);

        printf("Enter name: ");
        scanf("%s", records[num_records-1].name);

        printf("Enter balance: ");
        scanf("%f", &records[num_records-1].balance);

        printf("Record added successfully.\n");

        break;

      case 2:
        printf("\nEnter account number: ");
        scanf("%d", &account_num);

        for (i = 0; i < num_records; i++) {
          if (records[i].account_number == account_num) {
            printf("Enter deposit amount: ");
            scanf("%f", &deposit_amount);

            records[i].balance += deposit_amount;

            printf("Deposit successful. New balance is %.2f.\n", records[i].balance);
            break;
          }
        }

        if (i == num_records) {
          printf("Record not found.\n");
        }

        break;

      case 3:
        printf("\nEnter account number: ");
        scanf("%d", &account_num);

        for (i = 0; i < num_records; i++) {
          if (records[i].account_number == account_num) {
            printf("Enter withdrawal amount: ");
            scanf("%f", &withdrawal_amount);

            if (records[i].balance >= withdrawal_amount) {
              records[i].balance -= withdrawal_amount;
              printf("Withdrawal successful. New balance is %.2f.\n", records[i].balance);
            } else {
              printf("Insufficient balance.\n");
            }

            break;
          }
        }

        if (i == num_records) {
          printf("Record not found.\n");
        }

        break;

      case 4:
        printf("\nAccount Number\tName\tBalance\n");

        for (i = 0; i < num_records; i++) {
          printf("%d\t\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
        }

        break;

      case 5:
        printf("\nThank you for using C Banking Record System.\n");

        break;

      default:
        printf("\nInvalid choice. Please try again.\n");
    }

  } while (choice != 5);

  free(records);

  return 0;
}