//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 10

typedef struct Record {
  char name[20];
  int account_no;
  double balance;
} Record;

Record records[MAX_RECORDS];

void add_record() {
  Record new_record;

  printf("Enter name: ");
  scanf("%s", new_record.name);

  printf("Enter account number: ");
  scanf("%d", &new_record.account_no);

  printf("Enter balance: ");
  scanf("%lf", &new_record.balance);

  for (int i = 0; i < MAX_RECORDS; i++) {
    if (records[i].account_no == new_record.account_no) {
      printf("Account number already exists.\n");
      return;
    }
  }

  records[MAX_RECORDS - 1] = new_record;
  printf("Record added successfully.\n");
}

void search_record() {
  char search_name[20];

  printf("Enter name: ");
  scanf("%s", search_name);

  for (int i = 0; i < MAX_RECORDS; i++) {
    if (strcmp(records[i].name, search_name) == 0) {
      printf("Name: %s\n", records[i].name);
      printf("Account Number: %d\n", records[i].account_no);
      printf("Balance: %.2lf\n", records[i].balance);
    }
  }

  printf("Record not found.\n");
}

int main() {
  int choice;

  printf("Enter 1 to add a record, 2 to search a record: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      add_record();
      break;
    case 2:
      search_record();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}