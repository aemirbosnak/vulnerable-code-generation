//FormAI DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Let's create a surreal banking system that records dreams instead of transactions

struct DreamRecord {
  int customerID;
  char dream[100];
  float accountBalance;
  int lucidityLevel;
};

void enterDreamRecord(struct DreamRecord *record) {
  printf("Enter customer ID: ");
  scanf("%d", &record->customerID);

  printf("Enter dream: ");
  scanf(" %[^\n]", record->dream);
   
  printf("Enter account balance: $");
  scanf("%f", &record->accountBalance);

  printf("Enter lucidity level (1-10): ");
  scanf("%d", &record->lucidityLevel);
}

void showDreamRecord(struct DreamRecord record) {
  printf("Dream ID: %d\n", record.customerID);
  printf("Dream: %s\n", record.dream);
  printf("Account Balance: $%.2f\n", record.accountBalance);
  printf("Lucidity Level: %d\n", record.lucidityLevel);
}

int main() {
  srand(time(NULL));

  int numRecords;
  printf("How many dreams would you like to record? ");
  scanf("%d", &numRecords);

  struct DreamRecord *records = malloc(numRecords * sizeof(struct DreamRecord));

  for (int i = 0; i < numRecords; i++) {
    enterDreamRecord(&records[i]);
  }

  printf("\n***** DREAM RECORDS *****\n");

  for (int i = 0; i < numRecords; i++) {
    printf("\nRecord #%d:\n", i + 1);
    showDreamRecord(records[i]);
  }

  free(records);
  return 0;
}