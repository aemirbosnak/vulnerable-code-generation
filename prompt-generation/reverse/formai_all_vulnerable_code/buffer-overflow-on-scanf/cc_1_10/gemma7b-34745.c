//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct BankRecord {
  char name[50];
  int accountNo;
  double balance;
  struct BankRecord* next;
};

void createRecord(struct BankRecord** head) {
  struct BankRecord* newRecord = (struct BankRecord*)malloc(sizeof(struct BankRecord));
  printf("Enter name: ");
  scanf("%s", newRecord->name);
  printf("Enter account number: ");
  scanf("%d", &newRecord->accountNo);
  printf("Enter balance: ");
  scanf("%lf", &newRecord->balance);
  *head = newRecord;
}

void displayRecord(struct BankRecord* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Account number: %d\n", head->accountNo);
    printf("Balance: %.2lf\n", head->balance);
    printf("\n");
    head = head->next;
  }
}

void searchRecord(struct BankRecord* head, int accountNo) {
  if (head) {
    if (head->accountNo == accountNo) {
      printf("Name: %s\n", head->name);
      printf("Account number: %d\n", head->accountNo);
      printf("Balance: %.2lf\n", head->balance);
    } else {
      searchRecord(head->next, accountNo);
    }
  }
}

int main() {
  struct BankRecord* head = NULL;
  createRecord(&head);
  createRecord(&head);
  createRecord(&head);
  displayRecord(head);
  searchRecord(head, 123);
  return 0;
}