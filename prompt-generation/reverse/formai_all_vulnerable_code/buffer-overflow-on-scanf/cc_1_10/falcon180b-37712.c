//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Struct for Personal Finance Planner
typedef struct {
    char name[50];
    float income;
    float expenses[10];
    float savings;
} PersonalFinance;

// Function to Print Personal Finance Details
void printPersonalFinance(PersonalFinance pf) {
    printf("\nPersonal Finance Details:\n");
    printf("Name: %s\n", pf.name);
    printf("Income: $%.2f\n", pf.income);
    printf("Expenses:\n");
    for(int i=0; i<10; i++) {
        if(pf.expenses[i] > 0) {
            printf("  %d. %s: $%.2f\n", i+1, (char *)malloc(strlen("Category")), pf.expenses[i]);
        }
    }
    printf("Savings: $%.2f\n", pf.savings);
}

// Function to Get Personal Finance Input from User
PersonalFinance getPersonalFinance() {
    PersonalFinance pf;
    printf("Enter Your Name: ");
    scanf("%s", pf.name);
    printf("Enter Your Income: $");
    scanf("%f", &pf.income);
    printf("Enter Your Expenses:\n");
    for(int i=0; i<10; i++) {
        printf("  %d. Category: ", i+1);
        char category[50];
        scanf("%s", category);
        printf("  Amount: $");
        scanf("%f", &pf.expenses[i]);
    }
    printf("Enter Your Savings: $");
    scanf("%f", &pf.savings);
    return pf;
}

// Main Function
int main() {
    PersonalFinance pf = getPersonalFinance();
    printPersonalFinance(pf);
    return 0;
}