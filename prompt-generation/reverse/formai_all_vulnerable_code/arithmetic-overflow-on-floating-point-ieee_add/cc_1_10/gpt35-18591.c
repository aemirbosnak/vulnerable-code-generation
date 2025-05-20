//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define struct to hold financial information
typedef struct {
    float income;
    float housing;
    float transport;
    float food;
    float entertainment;
    float other;
} finance;

// Define function to calculate and print total expenses
void totalExpenses(finance f) {
    float total = f.housing + f.transport + f.food + f.entertainment + f.other;
    printf("\nTotal expenses: $%.2f", total);
}

int main() {
    finance f;
    printf("Enter monthly income: $");
    scanf("%f", &f.income);
    printf("Enter monthly housing expenses: $");
    scanf("%f", &f.housing);
    printf("Enter monthly transportation expenses: $");
    scanf("%f", &f.transport);
    printf("Enter monthly food expenses: $");
    scanf("%f", &f.food);
    printf("Enter monthly entertainment expenses: $");
    scanf("%f", &f.entertainment);
    printf("Enter other monthly expenses: $");
    scanf("%f", &f.other);
    
    // Print and calculate total expenses
    printf("\n--- Monthly Expenses ---");
    printf("\nHousing: $%.2f", f.housing);
    printf("\nTransportation: $%.2f", f.transport);
    printf("\nFood: $%.2f", f.food);
    printf("\nEntertainment: $%.2f", f.entertainment);
    printf("\nOther: $%.2f", f.other);
    
    totalExpenses(f);
    
    // Calculate and print remaining income
    float remaining = f.income - (f.housing + f.transport + f.food + f.entertainment + f.other);
    printf("\n\nRemaining income: $%.2f", remaining);
    
    return 0;
}