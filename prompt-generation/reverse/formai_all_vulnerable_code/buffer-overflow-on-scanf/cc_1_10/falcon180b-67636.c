//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define maximum length of strings
#define MAX_LENGTH 100

// define structure for personal finance data
typedef struct {
    char name[MAX_LENGTH];
    double income;
    double expenses;
    double savings;
} finance_data;

// function to read input from user
void read_input(finance_data* data) {
    printf("Enter your name: ");
    scanf("%s", data->name);

    printf("Enter your income: ");
    scanf("%lf", &data->income);

    printf("Enter your expenses: ");
    scanf("%lf", &data->expenses);

    printf("Enter your savings: ");
    scanf("%lf", &data->savings);
}

// function to print personal finance data
void print_data(finance_data* data) {
    printf("\nName: %s\n", data->name);
    printf("Income: $%.2lf\n", data->income);
    printf("Expenses: $%.2lf\n", data->expenses);
    printf("Savings: $%.2lf\n", data->savings);
}

// main function
int main() {
    finance_data data;

    // loop until user decides to quit
    while (1) {
        // read input from user
        read_input(&data);

        // print personal finance data
        print_data(&data);

        // ask user if they want to continue or quit
        char choice;
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);

        // if user wants to quit, break out of loop
        if (tolower(choice) == 'n') {
            break;
        }
    }

    return 0;
}