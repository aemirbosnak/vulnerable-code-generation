//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

typedef struct PersonalFinance {
    char name[MAX_NUM];
    int age;
    double income;
    double expenses;
    double savings;
} PersonalFinance;

int main() {
    PersonalFinance person[MAX_NUM];

    // Initialize the personal finance structure
    for (int i = 0; i < MAX_NUM; i++) {
        person[i].name[0] = '\0';
        person[i].age = 0;
        person[i].income = 0.0;
        person[i].expenses = 0.0;
        person[i].savings = 0.0;
    }

    // Get the number of persons
    int num_persons = 0;
    printf("Enter the number of persons: ");
    scanf("%d", &num_persons);

    // Populate the personal finance structure
    for (int i = 0; i < num_persons; i++) {
        printf("Enter the name of person %d: ", i + 1);
        scanf("%s", person[i].name);

        printf("Enter the age of person %d: ", i + 1);
        scanf("%d", &person[i].age);

        printf("Enter the income of person %d: ", i + 1);
        scanf("%lf", &person[i].income);

        printf("Enter the expenses of person %d: ", i + 1);
        scanf("%lf", &person[i].expenses);

        person[i].savings = person[i].income - person[i].expenses;
    }

    // Print the personal finance structure
    for (int i = 0; i < num_persons; i++) {
        printf("Name: %s\n", person[i].name);
        printf("Age: %d\n", person[i].age);
        printf("Income: %.2lf\n", person[i].income);
        printf("Expenses: %.2lf\n", person[i].expenses);
        printf("Savings: %.2lf\n", person[i].savings);
        printf("\n");
    }

    return 0;
}