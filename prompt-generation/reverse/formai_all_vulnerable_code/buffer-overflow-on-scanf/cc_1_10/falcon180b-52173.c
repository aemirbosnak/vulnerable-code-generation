//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the personal finance planner
typedef struct financePlanner {
    char name[50];
    int age;
    float income;
    float expenses;
    float savings;
    char partnerName[50];
} FinancePlanner;

// Function to initialize the personal finance planner
void initFinancePlanner(FinancePlanner *fp) {
    strcpy(fp->name, "Romeo");
    fp->age = 25;
    fp->income = 5000;
    fp->expenses = 3000;
    fp->savings = fp->income - fp->expenses;
    strcpy(fp->partnerName, "Juliet");
}

// Function to display the personal finance planner
void displayFinancePlanner(FinancePlanner fp) {
    printf("Name: %s\n", fp.name);
    printf("Age: %d\n", fp.age);
    printf("Income: $%.2f\n", fp.income);
    printf("Expenses: $%.2f\n", fp.expenses);
    printf("Savings: $%.2f\n", fp.savings);
    printf("Partner's Name: %s\n", fp.partnerName);
}

// Function to calculate the savings for the personal finance planner
void calculateSavings(FinancePlanner *fp) {
    fp->savings = fp->income - fp->expenses;
}

// Function to update the personal finance planner
void updateFinancePlanner(FinancePlanner *fp) {
    printf("Enter your name: ");
    scanf("%s", fp->name);
    printf("Enter your age: ");
    scanf("%d", &fp->age);
    printf("Enter your income: ");
    scanf("%f", &fp->income);
    printf("Enter your expenses: ");
    scanf("%f", &fp->expenses);
    calculateSavings(fp);
}

int main() {
    FinancePlanner fp;
    initFinancePlanner(&fp);
    displayFinancePlanner(fp);

    updateFinancePlanner(&fp);
    displayFinancePlanner(fp);

    return 0;
}