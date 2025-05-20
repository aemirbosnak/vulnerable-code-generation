//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Struct which holds financial information
typedef struct {
    double salary; //Annual salary
    double expenses; //Monthly expenses
    double savings; //Total savings
    double investments; //Total investments
} finance;

//Function to get input from user
void getUserInput(finance *f) {
    printf("Enter your annual salary: $");
    scanf("%lf", &f->salary);
    printf("Enter your monthly expenses: $");
    scanf("%lf", &f->expenses);
    printf("Enter your total savings: $");
    scanf("%lf", &f->savings);
    printf("Enter your total investments: $");
    scanf("%lf", &f->investments);
}

//Function to calculate net worth
double calculateNetWorth(finance *f) {
    double netWorth = f->savings + f->investments;
    return netWorth;
}

//Function to calculate monthly savings rate
double calculateMonthlySavings(finance *f) {
    double monthlySavings = (f->salary / 12) - f->expenses;
    return monthlySavings;
}

//Function to check if user can afford a purchase
bool canAffordPurchase(finance *f, double purchasePrice) {
    double monthlySavings = calculateMonthlySavings(f);
    double totalSavings = f->savings + monthlySavings;
    if (totalSavings >= purchasePrice) {
        return true;
    } else {
        return false;
    }
}

//Main function
int main() {
    finance userFinances;
    getUserInput(&userFinances);
    double netWorth = calculateNetWorth(&userFinances);
    printf("Your net worth is: $%.2lf\n", netWorth);
    double monthlySavings = calculateMonthlySavings(&userFinances);
    printf("Your monthly savings rate is: $%.2lf\n", monthlySavings);
    printf("\n");
    bool canAfford = canAffordPurchase(&userFinances, 500.00);
    if (canAfford) {
        printf("You can afford a $500.00 purchase!\n");
    } else {
        printf("You cannot afford a $500.00 purchase.\n");
    }
    printf("\n");
    canAfford = canAffordPurchase(&userFinances, 1000.00);
    if (canAfford) {
        printf("You can afford a $1000.00 purchase!\n");
    } else {
        printf("You cannot afford a $1000.00 purchase.\n");
    }
    return 0;
}