//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankRecord {
  char name[50];
  char account_number[10];
  float balance;
  float interest_rate;
};

void display_record(struct BankRecord record) {
  printf("Name: %s\n", record.name);
  printf("Account Number: %s\n", record.account_number);
  printf("Balance: %f\n", record.balance);
  printf("Interest Rate: %f%%\n", record.interest_rate);
}

void update_record(struct BankRecord *record, float amount) {
  record->balance += amount;
}

int main() {
  struct BankRecord record;
  char name[50];
  char account_number[10];
  float balance;
  float interest_rate;

  printf("Enter name: ");
  scanf("%s", name);
  printf("Enter account number: ");
  scanf("%s", account_number);
  printf("Enter balance: ");
  scanf("%f", &balance);
  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);

  strcpy(record.name, name);
  strcpy(record.account_number, account_number);
  record.balance = balance;
  record.interest_rate = interest_rate;

  display_record(record);

  printf("Enter amount to deposit: ");
  float amount;
  scanf("%f", &amount);
  update_record(&record, amount);

  printf("New Balance: %f\n", record.balance);

  return 0;
}