//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure to hold data about income and expenses
struct finances {
    float income;
    float expenses;
};

int main() {
    // initialize variables
    struct finances current_finances = {0};
    char choice;

    // loop to continuously prompt user for input and display menu
    while(1) {
        printf("\n\nPERSONAL FINANCE PLANNER\n");
        printf("----------------------------\n");
        printf("1. Enter Income for the Month.\n");
        printf("2. Enter Expenses for the Month.\n");
        printf("3. View Current Finances.\n");
        printf("4. Exit.\n\n");
        printf("Enter your choice:\n");
        scanf("%c", &choice); // get user input
        
        switch(choice) {
            case '1': // update income
                printf("\nEnter Income: ");
                scanf("%f", &current_finances.income);
                getchar(); // clear buffer
                break;
            case '2': // update expenses
                printf("\nEnter Expenses: ");
                scanf("%f", &current_finances.expenses);
                getchar(); // clear buffer
                break;
            case '3': // display current finances
                printf("\nCurrent Finances:\n\n");
                printf("Income: %.2f\n", current_finances.income);
                printf("Expenses: %.2f\n", current_finances.expenses);
                printf("Net Income: %.2f\n", current_finances.income - current_finances.expenses);
                getchar(); // clear buffer
                break;
            case '4': // exit program
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default: // invalid input
                printf("\nInvalid Choice. Please try again.\n");
                getchar(); // clear buffer
                break;
        }
    }

    return 0;
}