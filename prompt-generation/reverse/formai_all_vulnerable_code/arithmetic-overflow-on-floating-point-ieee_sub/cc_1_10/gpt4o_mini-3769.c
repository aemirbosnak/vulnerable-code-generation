//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
    float investments;
} PersonalFinance;

void displayMenu() {
    printf("\n🚀 Welcome to Your Personal Finance Planner! 🚀\n");
    printf("1. Add New Financial Record\n");
    printf("2. View Financial Overview\n");
    printf("3. Update Financial Record\n");
    printf("4. Remove Financial Record\n");
    printf("5. Calculate Savings Rate\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

void addRecord(PersonalFinance *finance) {
    printf("\nEnter your name: ");
    scanf("%s", finance->name);
    printf("Enter your total monthly income: ");
    scanf("%f", &finance->income);
    printf("Enter your total monthly expenses: ");
    scanf("%f", &finance->expenses);
    finance->savings = finance->income - finance->expenses;
    finance->investments = 0;  // Assuming new record starts with no investments
    printf("🎉 Financial Record for %s added successfully! 🎉\n", finance->name);
}

void viewRecord(PersonalFinance *finance) {
    printf("\n📊 Financial Overview for %s 📊\n", finance->name);
    printf("Total Monthly Income: $%.2f\n", finance->income);
    printf("Total Monthly Expenses: $%.2f\n", finance->expenses);
    printf("Total Monthly Savings: $%.2f\n", finance->savings);
    printf("Total Monthly Investments: $%.2f\n", finance->investments);
}

void updateRecord(PersonalFinance *finance) {
    printf("\nEnter new monthly income: ");
    scanf("%f", &finance->income);
    printf("Enter new monthly expenses: ");
    scanf("%f", &finance->expenses);
    finance->savings = finance->income - finance->expenses;
    printf("✅ Financial Record Updated for %s! ✅\n", finance->name);
}

void removeRecord(PersonalFinance *finance) {
    finance->income = 0;
    finance->expenses = 0;
    finance->savings = 0;
    finance->investments = 0;
    finance->name[0] = '\0'; // Clear the name field
    printf("🗑️ Financial Record Removed! 🗑️\n");
}

void calculateSavingsRate(PersonalFinance *finance) {
    if (finance->income == 0) {
        printf("😟 Cannot calculate savings rate with zero income! 😟\n");
    } else {
        float savingsRate = (finance->savings / finance->income) * 100;
        printf("💰 Your Savings Rate is %.2f%% 💰\n", savingsRate);
    }
}

int main() {
    PersonalFinance finance = { .name = "", .income = 0, .expenses = 0, .savings = 0, .investments = 0 };
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(&finance);
                break;
            case 2:
                if (finance.name[0] != '\0') {
                    viewRecord(&finance);
                } else {
                    printf("😔 No records found! Please add a record first. 😔\n");
                }
                break;
            case 3:
                if (finance.name[0] != '\0') {
                    updateRecord(&finance);
                } else {
                    printf("😔 No records found! Please add a record first. 😔\n");
                }
                break;
            case 4:
                if (finance.name[0] != '\0') {
                    removeRecord(&finance);
                } else {
                    printf("😔 No records found! Please add a record first. 😔\n");
                }
                break;
            case 5:
                if (finance.name[0] != '\0') {
                    calculateSavingsRate(&finance);
                } else {
                    printf("😔 No records found! Please add a record first. 😔\n");
                }
                break;
            case 6:
                printf("🚀 Thank you for using the Personal Finance Planner! See you next time! 🚀\n");
                break;
            default:
                printf("❌ Invalid option! Please select between 1 and 6. ❌\n");
        }
    } while (choice != 6);

    return 0;
}