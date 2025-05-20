//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record
{
  char name[50];
  int account_number;
  double balance;
  struct Record* next;
} Record;

void create_record(Record** head)
{
  Record* new_record = malloc(sizeof(Record));
  new_record->next = NULL;

  printf("Enter name: ");
  scanf("%s", new_record->name);

  printf("Enter account number: ");
  scanf("%d", &new_record->account_number);

  printf("Enter balance: ");
  scanf("%lf", &new_record->balance);

  *head = new_record;
}

void print_records(Record* head)
{
  while (head)
  {
    printf("Name: %s\n", head->name);
    printf("Account Number: %d\n", head->account_number);
    printf("Balance: %.2lf\n", head->balance);
    printf("\n");
    head = head->next;
  }
}

int main()
{
  Record* head = NULL;

  // Create a new record
  create_record(&head);

  // Print all records
  print_records(head);

  return 0;
}