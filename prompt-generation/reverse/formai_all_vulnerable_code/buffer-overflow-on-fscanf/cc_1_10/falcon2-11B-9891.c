//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

void my_sigint_handler(int signum) {
    printf("Exiting...\n");
    exit(0);
}

int main() {
    // Initializing variables
    char user_name[50];
    char budget_file[50];
    int budget_amount;
    int current_month;
    int current_year;
    int current_day;
    int current_balance;
    int total_income;
    int total_expenses;
    int total_savings;
    int total_investments;
    int total_debt;
    int total_assets;
    int total_liabilities;
    int total_net_worth;
    int current_net_worth;
    char budget_data[1000];
    char current_budget_data[1000];
    int budget_data_length;
    int current_budget_data_length;

    // Reading user name
    printf("Please enter your name: ");
    fgets(user_name, sizeof(user_name), stdin);

    // Reading budget file name
    printf("Please enter the budget file name: ");
    fgets(budget_file, sizeof(budget_file), stdin);

    // Opening budget file
    FILE *fp = fopen(budget_file, "r");
    if (fp == NULL) {
        printf("Error opening budget file.\n");
        return 1;
    }

    // Reading budget amount
    fscanf(fp, "%d\n", &budget_amount);

    // Reading current month and year
    fscanf(fp, "%d %d\n", &current_month, &current_year);

    // Reading current day
    fscanf(fp, "%d\n", &current_day);

    // Reading current balance
    fscanf(fp, "%d\n", &current_balance);

    // Reading total income
    fscanf(fp, "%d\n", &total_income);

    // Reading total expenses
    fscanf(fp, "%d\n", &total_expenses);

    // Reading total savings
    fscanf(fp, "%d\n", &total_savings);

    // Reading total investments
    fscanf(fp, "%d\n", &total_investments);

    // Reading total debt
    fscanf(fp, "%d\n", &total_debt);

    // Reading total assets
    fscanf(fp, "%d\n", &total_assets);

    // Reading total liabilities
    fscanf(fp, "%d\n", &total_liabilities);

    // Reading total net worth
    fscanf(fp, "%d\n", &total_net_worth);

    // Reading current net worth
    fscanf(fp, "%d\n", &current_net_worth);

    // Closing budget file
    fclose(fp);

    // Reading budget data
    fp = fopen(budget_file, "r");
    if (fp == NULL) {
        printf("Error opening budget file.\n");
        return 1;
    }
    fscanf(fp, "%s", budget_data);
    fclose(fp);

    // Reading current budget data
    fp = fopen(budget_file, "r");
    if (fp == NULL) {
        printf("Error opening budget file.\n");
        return 1;
    }
    fscanf(fp, "%s", current_budget_data);
    fclose(fp);

    // Converting budget data to integer
    budget_data_length = strlen(budget_data);
    for (int i = 0; i < budget_data_length; i++) {
        budget_data[i] = tolower(budget_data[i]);
    }
    for (int i = 0; i < budget_data_length; i++) {
        if (isdigit(budget_data[i])) {
            budget_data[i] = budget_data[i] - '0';
        }
    }

    // Converting current budget data to integer
    current_budget_data_length = strlen(current_budget_data);
    for (int i = 0; i < current_budget_data_length; i++) {
        current_budget_data[i] = tolower(current_budget_data[i]);
    }
    for (int i = 0; i < current_budget_data_length; i++) {
        if (isdigit(current_budget_data[i])) {
            current_budget_data[i] = current_budget_data[i] - '0';
        }
    }

    // Calculating total income
    total_income = (budget_data[0] + budget_data[1] * 10 + budget_data[2] * 100 + budget_data[3] * 1000) + (current_budget_data[0] + current_budget_data[1] * 10 + current_budget_data[2] * 100 + current_budget_data[3] * 1000);

    // Calculating total expenses
    total_expenses = (budget_data[4] + budget_data[5] * 10 + budget_data[6] * 100 + budget_data[7] * 1000) + (current_budget_data[4] + current_budget_data[5] * 10 + current_budget_data[6] * 100 + current_budget_data[7] * 1000);

    // Calculating total savings
    total_savings = (budget_data[8] + budget_data[9] * 10 + budget_data[10] * 100 + budget_data[11] * 1000) + (current_budget_data[8] + current_budget_data[9] * 10 + current_budget_data[10] * 100 + current_budget_data[11] * 1000);

    // Calculating total investments
    total_investments = (budget_data[12] + budget_data[13] * 10 + budget_data[14] * 100 + budget_data[15] * 1000) + (current_budget_data[12] + current_budget_data[13] * 10 + current_budget_data[14] * 100 + current_budget_data[15] * 1000);

    // Calculating total debt
    total_debt = (budget_data[16] + budget_data[17] * 10 + budget_data[18] * 100 + budget_data[19] * 1000) + (current_budget_data[16] + current_budget_data[17] * 10 + current_budget_data[18] * 100 + current_budget_data[19] * 1000);

    // Calculating total assets
    total_assets = (budget_data[20] + budget_data[21] * 10 + budget_data[22] * 100 + budget_data[23] * 1000) + (current_budget_data[20] + current_budget_data[21] * 10 + current_budget_data[22] * 100 + current_budget_data[23] * 1000);

    // Calculating total liabilities
    total_liabilities = (budget_data[24] + budget_data[25] * 10 + budget_data[26] * 100 + budget_data[27] * 1000) + (current_budget_data[24] + current_budget_data[25] * 10 + current_budget_data[26] * 100 + current_budget_data[27] * 1000);

    // Calculating total net worth
    total_net_worth = total_assets - total_liabilities;

    // Calculating current net worth
    current_net_worth = total_assets - total_liabilities;

    // Printing results
    printf("Total income: %d\n", total_income);
    printf("Total expenses: %d\n", total_expenses);
    printf("Total savings: %d\n", total_savings);
    printf("Total investments: %d\n", total_investments);
    printf("Total debt: %d\n", total_debt);
    printf("Total assets: %d\n", total_assets);
    printf("Total liabilities: %d\n", total_liabilities);
    printf("Total net worth: %d\n", total_net_worth);
    printf("Current net worth: %d\n", current_net_worth);

    // Exit program
    return 0;
}