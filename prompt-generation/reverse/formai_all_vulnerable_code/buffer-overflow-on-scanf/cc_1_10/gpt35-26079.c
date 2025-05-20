//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

struct expenditure {
    float amount;
    char category[20];
};

struct income {
    float amount;
    char source[20];
};

typedef struct expenditure Expenditure;
typedef struct income Income;

void addExpenditure(Expenditure *e) {
    printf("Enter amount: ");
    scanf("%f", &(e->amount));
    printf("Enter category: ");
    scanf("%s", &(e->category));
}

void addIncome(Income *i) {
    printf("Enter amount: ");
    scanf("%f", &(i->amount));
    printf("Enter source: ");
    scanf("%s", &(i->source));
}

void printExpenditures(Expenditure *e, int count) {
    printf("\nExpenditures:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f\n", e[i].category, e[i].amount);
    }
}

void printIncomes(Income *i, int count) {
    printf("\nIncomes:\n");
    for (int j = 0; j < count; j++) {
        printf("%s: $%.2f\n", i[j].source, i[j].amount);
    }
}

float totalExpenditure(Expenditure *e, int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += e[i].amount;
    }
    return total;
}

float totalIncome(Income *i, int count) {
    float total = 0;
    for (int j = 0; j < count; j++) {
        total += i[j].amount;
    }
    return total;
}

void showSummary(Expenditure *e, Income *i, int e_count, int i_count) {
    printf("\nSummary:\n");
    printf("Total Income: $%.2f\n", totalIncome(i, i_count));
    printf("Total Expenditure: $%.2f\n", totalExpenditure(e, e_count));
    printf("Net Savings: $%.2f\n", totalIncome(i, i_count) - totalExpenditure(e, e_count));
}

int main(void) {
    Expenditure expenditures[20];
    Income incomes[20];
    int e_count = 0, i_count = 0;
    char option;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("Choose an option:\n");
        printf("1. Add Expenditure\n");
        printf("2. Add Income\n");
        printf("3. View Expenditures\n");
        printf("4. View Incomes\n");
        printf("5. View Summary\n");
        printf("6. Exit\n");

        scanf("%s", &option);

        switch (option) {
            case '1':
                addExpenditure(&(expenditures[e_count]));
                e_count++;
                break;
            case '2':
                addIncome(&(incomes[i_count]));
                i_count++;
                break;
            case '3':
                printExpenditures(expenditures, e_count);
                break;
            case '4':
                printIncomes(incomes, i_count);
                break;
            case '5':
                showSummary(expenditures, incomes, e_count, i_count);
                break;
            case '6':
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    } while (option != '6');

    return 0;
}