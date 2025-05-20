//FormAI DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  char address[100];
  char phone[20];
  double balance;
} Record;

void printRecord(Record r) {
  printf("Name:\t\t%s\n", r.name);
  printf("Address:\t%s\n", r.address);
  printf("Phone:\t\t%s\n", r.phone);
  printf("Balance:\t%.2lf\n", r.balance);
}

int main() {
  int size = 10;
  Record bankRecords[size];
  int numRecords = 0;

  while(1) {
    char option;
    printf("Enter option: (a)dd record, (p)rint all records, (q)uit\n");
    scanf(" %c", &option);

    if(option == 'a') {
      if(numRecords >= size) {
        printf("Error: Too many records\n");
        continue;
      }

      Record newRecord;
      printf("Enter name: ");
      scanf(" %[^\n]", newRecord.name);
      printf("Enter address: ");
      scanf(" %[^\n]", newRecord.address);
      printf("Enter phone: ");
      scanf(" %[^\n]", newRecord.phone);
      printf("Enter balance: ");
      scanf(" %lf", &newRecord.balance);

      bankRecords[numRecords++] = newRecord;	  
    }
    else if(option == 'p') {
      for(int i = 0; i < numRecords; i++) {
        printf("Record %d\n", i+1);
        printRecord(bankRecords[i]);
        printf("\n");
      }
    }
    else if(option == 'q') {
      break;
    }
    else {
      printf("Error: Invalid option\n");
    }
  } 

  return 0;
}