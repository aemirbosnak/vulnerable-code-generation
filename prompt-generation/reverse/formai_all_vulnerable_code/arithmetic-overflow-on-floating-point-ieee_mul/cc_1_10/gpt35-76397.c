//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>

// Function to calculate net worth
float calculateNetWorth(float assets[], float liabilities[], int num) {
    float netWorth = 0;
    for(int i=0; i<num; i++) {
        netWorth += assets[i];
        netWorth -= liabilities[i];
    }
    return netWorth;
}

// Function to calculate debt-to-income ratio
float calculateDebtToIncomeRatio(float monthlyDebtPayments, float monthlyIncome) {
    float debtToIncomeRatio = monthlyDebtPayments / monthlyIncome;
    return debtToIncomeRatio;
}

// Function to calculate retirement savings
float calculateRetirementSavings(float currentSavings, float monthlySavings, float years) {
    float retirementSavings = currentSavings;
    for(int i=0; i<years; i++) {
        retirementSavings += monthlySavings * 12;
        retirementSavings += retirementSavings * 0.05; // assuming 5% annual return on investment
    }
    return retirementSavings;
}

int main() {
    // User inputs
    int numAssets;
    printf("Enter the number of assets: ");
    scanf("%d", &numAssets);
    float assets[numAssets];
    printf("Enter the value of each asset: \n");
    for(int i=0; i<numAssets; i++) {
        printf("Asset %d: ", i+1);
        scanf("%f", &assets[i]);
    }

    int numLiabilities;
    printf("Enter the number of liabilities: ");
    scanf("%d", &numLiabilities);
    float liabilities[numLiabilities];
    printf("Enter the value of each liability: \n");
    for(int i=0; i<numLiabilities; i++) {
        printf("Liability %d: ", i+1);
        scanf("%f", &liabilities[i]);
    }

    float monthlyDebtPayments;
    printf("Enter your monthly debt payments: ");
    scanf("%f", &monthlyDebtPayments);

    float monthlyIncome;
    printf("Enter your monthly income: ");
    scanf("%f", &monthlyIncome);

    float currentSavings;
    printf("Enter your current retirement savings: ");
    scanf("%f", &currentSavings);

    float monthlySavings;
    printf("Enter your monthly retirement savings: ");
    scanf("%f", &monthlySavings);

    float years;
    printf("Enter the number of years you plan to save for retirement: ");
    scanf("%f", &years);

    // Calculations
    float netWorth = calculateNetWorth(assets, liabilities, numAssets);
    float debtToIncomeRatio = calculateDebtToIncomeRatio(monthlyDebtPayments, monthlyIncome);
    float retirementSavings = calculateRetirementSavings(currentSavings, monthlySavings, years);

    // Output
    printf("\n");
    printf("Net worth: $%.2f\n", netWorth);
    printf("Debt-to-income ratio: %.2f%%\n", debtToIncomeRatio * 100);
    printf("Projected retirement savings after %0.0f years: $%.2f\n", years, retirementSavings);

    return 0;
}