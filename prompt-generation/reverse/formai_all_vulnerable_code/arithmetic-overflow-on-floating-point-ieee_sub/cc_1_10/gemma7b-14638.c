//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Person {
  char name[MAX_NAME_LENGTH];
  int age;
  double income;
  double expenses;
  double net_worth;
} Person;

int main() {
  // Create an array of persons
  Person persons[10];

  // Initialize the persons
  for (int i = 0; i < 10; i++) {
    persons[i].name[0] = '\0';
    persons[i].age = 0;
    persons[i].income = 0.0;
    persons[i].expenses = 0.0;
    persons[i].net_worth = 0.0;
  }

  // Get the persons' names, ages, incomes, and expenses
  for (int i = 0; i < 10; i++) {
    printf("Enter the name of person %d: ", i + 1);
    scanf("%s", persons[i].name);

    printf("Enter the age of person %d: ", i + 1);
    scanf("%d", &persons[i].age);

    printf("Enter the income of person %d: ", i + 1);
    scanf("%lf", &persons[i].income);

    printf("Enter the expenses of person %d: ", i + 1);
    scanf("%lf", &persons[i].expenses);
  }

  // Calculate the net worth for each person
  for (int i = 0; i < 10; i++) {
    persons[i].net_worth = persons[i].income - persons[i].expenses;
  }

  // Print the persons' net worth
  for (int i = 0; i < 10; i++) {
    printf("The net worth of person %d is $%.2lf\n", i + 1, persons[i].net_worth);
  }

  return 0;
}