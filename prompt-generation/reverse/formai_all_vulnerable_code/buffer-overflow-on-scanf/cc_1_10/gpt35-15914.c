//FormAI DATASET v1.0 Category: Banking Record System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

#define MAX_RECORDS 100

struct bank_record {
  char name[50];
  int account_number;
  float balance;
};

struct bank_record records[MAX_RECORDS];
int num_records = 0;

void display_menu() {
  printf("\nBanking Record System\n");
  printf("--------------------------\n");
  printf("1. Add a Record\n");
  printf("2. Delete a Record\n");
  printf("3. Update a Record\n");
  printf("4. Search a Record\n");
  printf("5. Display all Records\n");
  printf("6. Exit\n");
}

void add_record() {
  if(num_records >= MAX_RECORDS) {
    printf("Error: Maximum number of records reached!\n");
    return;
  }
  printf("\nEnter name: ");
  scanf("%s", records[num_records].name);
  printf("Enter account number: ");
  scanf("%d", &records[num_records].account_number);
  printf("Enter balance: ");
  scanf("%f", &records[num_records].balance);
  num_records++;
}

void delete_record() {
  int account_number, i, j, flag = 0;
  printf("\nEnter account number to be deleted: ");
  scanf("%d", &account_number);
  for(i = 0; i < num_records; i++) {
    if(records[i].account_number == account_number) {
      flag = 1;
      for(j = i; j < num_records - 1; j++) {
        records[j] = records[j+1];
      }
      num_records--;
      printf("Record deleted successfully!\n");
      break;
    }
  }
  if(flag == 0) {
    printf("Error: Record not found!\n");
  }
}

void update_record() {
  int account_number, i, flag = 0;
  float balance;
  printf("\nEnter account number to be updated: ");
  scanf("%d", &account_number);
  for(i = 0; i < num_records; i++) {
    if(records[i].account_number == account_number) {
      flag = 1;
      printf("Enter new balance: ");
      scanf("%f", &balance);
      records[i].balance = balance;
      printf("Record updated successfully!\n");
      break;
    }
  }
  if(flag == 0) {
    printf("Error: Record not found!\n");
  }
}

void search_record() {
  int account_number, i, flag = 0;
  printf("\nEnter account number to be searched: ");
  scanf("%d", &account_number);
  for(i = 0; i < num_records; i++) {
    if(records[i].account_number == account_number) {
      flag = 1;
      printf("\nRecord found:\n");
      printf("Name: %s\n", records[i].name);
      printf("Account number: %d\n", records[i].account_number);
      printf("Balance: %.2f\n", records[i].balance);
      break;
    }
  }
  if(flag == 0) {
    printf("Error: Record not found!\n");
  }
}

void display_records() {
  int i;
  if(num_records == 0) {
    printf("No records to display!\n");
    return;
  }
  printf("\nBank Records:\n");
  printf("-----------------------------------\n");
  for(i = 0; i < num_records; i++) {
    printf("Name: %s\n", records[i].name);
    printf("Account number: %d\n", records[i].account_number);
    printf("Balance: %.2f\n", records[i].balance);
    printf("-----------------------------------\n");
  }
}

int main() {
  int choice;
  while(1) {
    display_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1: add_record(); break;
      case 2: delete_record(); break;
      case 3: update_record(); break;
      case 4: search_record(); break;
      case 5: display_records(); break;
      case 6: exit(0); break;
      default: printf("Invalid choice! Please try again.\n");
    }
  }
  return 0;
}