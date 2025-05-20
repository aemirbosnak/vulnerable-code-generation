//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Record {
  char name[50];
  int age;
  double income;
  double expense;
  double net_worth;
};

void calculate_net_worth(struct Record *record) {
  record->net_worth = record->income - record->expense;
}

int main() {
  struct Record records[MAX];

  // Create and initialize records
  for (int i = 0; i < MAX; i++) {
    records[i].name[0] = '\0';
    records[i].age = 0;
    records[i].income = 0.0;
    records[i].expense = 0.0;
    records[i].net_worth = 0.0;
  }

  // Get user input
  printf("Enter the number of records you want to create: ");
  int num_records;
  scanf("%d", &num_records);

  // Loop to get data for each record
  for (int i = 0; i < num_records; i++) {
    printf("Enter the name of the record: ");
    scanf("%s", records[i].name);

    printf("Enter the age of the record: ");
    scanf("%d", &records[i].age);

    printf("Enter the income of the record: ");
    scanf("%lf", &records[i].income);

    printf("Enter the expense of the record: ");
    scanf("%lf", &records[i].expense);
  }

  // Calculate the net worth for each record
  for (int i = 0; i < num_records; i++) {
    calculate_net_worth(&records[i]);
  }

  // Print the records
  printf("Here is a list of records:\n");
  for (int i = 0; i < num_records; i++) {
    printf("Name: %s\n", records[i].name);
    printf("Age: %d\n", records[i].age);
    printf("Income: %.2lf\n", records[i].income);
    printf("Expense: %.2lf\n", records[i].expense);
    printf("Net Worth: %.2lf\n", records[i].net_worth);
    printf("\n");
  }

  return 0;
}