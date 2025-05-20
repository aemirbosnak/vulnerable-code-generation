//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_ERROR 1
#define INPUT_SUCCESS 0
#define INPUT_LIMIT 100

typedef struct {
    char name[50];
    double income;
    double expense;
    double savings;
    double debt;
    double credit_score;
} PersonalFinance;

int input_validation(char input[], int limit) {
    int length = strlen(input);
    if (length > limit) {
        printf("Input too long. Please enter a name with %d or fewer characters.\n", limit);
        return INPUT_ERROR;
    }
    return INPUT_SUCCESS;
}

int get_int_input(char prompt[]) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

double get_double_input(char prompt[]) {
    double input;
    printf("%s", prompt);
    scanf("%lf", &input);
    return input;
}

PersonalFinance* create_personal_finance() {
    PersonalFinance* pf = (PersonalFinance*)malloc(sizeof(PersonalFinance));
    pf->income = 0;
    pf->expense = 0;
    pf->savings = 0;
    pf->debt = 0;
    pf->credit_score = 0;
    return pf;
}

void print_personal_finance(PersonalFinance pf) {
    printf("Name: %s\n", pf.name);
    printf("Income: $%.2lf\n", pf.income);
    printf("Expense: $%.2lf\n", pf.expense);
    printf("Savings: $%.2lf\n", pf.savings);
    printf("Debt: $%.2lf\n", pf.debt);
    printf("Credit Score: %d\n", pf.credit_score);
}

int main() {
    char name[50];
    int choice;
    PersonalFinance pf = *create_personal_finance();

    do {
        printf("Personal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Add Savings\n");
        printf("4. Add Debt\n");
        printf("5. View Personal Finance Summary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income amount: ");
                pf.income += get_double_input("");
                break;
            case 2:
                printf("Enter expense amount: ");
                pf.expense += get_double_input("");
                break;
            case 3:
                printf("Enter savings amount: ");
                pf.savings += get_double_input("");
                break;
            case 4:
                printf("Enter debt amount: ");
                pf.debt += get_double_input("");
                break;
            case 5:
                print_personal_finance(pf);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 6);

    return 0;
}