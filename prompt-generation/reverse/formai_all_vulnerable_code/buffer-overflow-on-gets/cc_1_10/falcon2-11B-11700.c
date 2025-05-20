//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));
    char* name[3] = {"John", "Jane", "Jack"};
    int num;
    char* financial_category;
    char* investment_type;
    int investment_amount;
    char* expense_type;
    int expense_amount;
    int income_amount;
    char* deposit_type;
    int deposit_amount;
    int balance;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Enter your name: ");
    gets(name);

    printf("Please choose a financial category:\n");
    for(int i = 0; i < 3; i++) {
        printf("%s\n", name[i]);
    }

    printf("Enter your choice: ");
    scanf("%d", &num);
    printf("Your chosen name is %s\n", name[num]);

    printf("Enter your investment type: ");
    scanf("%s", &investment_type);

    printf("Enter the amount you wish to invest: ");
    scanf("%d", &investment_amount);

    printf("Enter your expense type: ");
    scanf("%s", &expense_type);

    printf("Enter the amount of your expense: ");
    scanf("%d", &expense_amount);

    printf("Enter your income amount: ");
    scanf("%d", &income_amount);

    printf("Enter your deposit type: ");
    scanf("%s", &deposit_type);

    printf("Enter the amount of your deposit: ");
    scanf("%d", &deposit_amount);

    printf("Your total balance is %d\n", income_amount - expense_amount + investment_amount + deposit_amount);
    return 0;
}