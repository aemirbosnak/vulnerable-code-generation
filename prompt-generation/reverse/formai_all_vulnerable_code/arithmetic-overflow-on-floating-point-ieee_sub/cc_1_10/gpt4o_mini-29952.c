//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold romantic financial information
typedef struct {
    char name[50];
    float monthly_income;
    float monthly_expenses;
    float savings;
} FinancialLover;

// Function declarations
void createProfile(FinancialLover *lover);
void displayProfile(FinancialLover lover);
float calculateSavings(FinancialLover lover);
void romanticAdvice(FinancialLover lover);

int main() {
    FinancialLover myLove;

    // Create a romantic financial profile
    createProfile(&myLove);
    // Display the profile
    displayProfile(myLove);
    // Calculate and display savings
    float savings = calculateSavings(myLove);
    printf("Oh my love, your total savings this month is: $%.2f\n\n", savings);

    // Offer some romantic financial advice
    romanticAdvice(myLove);

    return 0;
}

void createProfile(FinancialLover *lover) {
    printf("Welcome to the LoveNest Personal Finance Planner!\n\n");
    printf("Let's know each other better. What's your name, my sweet?\n");
    fgets(lover->name, sizeof(lover->name), stdin);
    lover->name[strcspn(lover->name, "\n")] = 0;  // Remove newline character

    printf("Darling %s, please tell me your monthly income ($):\n", lover->name);
    scanf("%f", &lover->monthly_income);
    printf("And how much do you indulge in expenses each month ($):\n");
    scanf("%f", &lover->monthly_expenses);
    lover->savings = 0;  // Initialize savings
}

void displayProfile(FinancialLover lover) {
    printf("\nOh, my beloved %s, here is your financial profile:\n", lover.name);
    printf("Monthly Income: $%.2f\n", lover.monthly_income);
    printf("Monthly Expenses: $%.2f\n", lover.monthly_expenses);
}

float calculateSavings(FinancialLover lover) {
    lover.savings = lover.monthly_income - lover.monthly_expenses;
    return lover.savings;
}

void romanticAdvice(FinancialLover lover) {
    printf("Here's a little love note for your financial heart:\n");
    if (lover.monthly_income > lover.monthly_expenses) {
        printf("My dearest, your financial future is as bright as our love! Save a portion of your savings and invest it wisely.\n");
    } else {
        printf("Oh sweetheart, worry not, for every cloud has a silver lining. Adjust your expenses and remember, love is priceless! \n");
    }
    printf("Consider creating a budget for your romance; it helps to know where our love dollars flow!\n");
    printf("Remember, true wealth lies in sharing dreams with your beloved.\n");
    printf("May your financial journey be filled with love and prosperity!\n");
}