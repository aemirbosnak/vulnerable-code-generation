//FormAI DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char description[100];
    double amount;
} Expense;

void print_header();
int get_menu_option();
void wait_for_user_input();
void clear_screen();

int main() {
    int max_expenses = 100;
    Expense* expenses = calloc(max_expenses, sizeof(Expense));
    int num_expenses = 0;

    clear_screen();
    print_header();

    while (1) {
        int option = get_menu_option();

        if (option == 1) {
            // Add expense
            if (num_expenses >= max_expenses) {
                printf("\nSorry, you cannot add more expenses as the limit has been reached (max: %d).\n\n", max_expenses);
                wait_for_user_input();
            } else {
                clear_screen();
                printf("ADD EXPENSE\n\n");
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%10s", expenses[num_expenses].date);
                printf("Enter description: ");
                scanf(" %[^\n]s", expenses[num_expenses].description);
                printf("Enter amount: ");
                scanf("%lf", &expenses[num_expenses].amount);
                printf("\nNew expense has been added.\n\n");
                num_expenses++;
                wait_for_user_input();
            }
        } else if (option == 2) {
            // View expenses
            clear_screen();
            printf("EXPENSES\n\n");
            if (num_expenses == 0) {
                printf("No expenses added yet.\n");
            } else {
                printf("Date          Description                                   Amount\n");
                printf("----------------------------------------------------------------------------\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%s   %-45s $%.2lf\n", expenses[i].date, expenses[i].description, expenses[i].amount);
                }
            }
            printf("\n");
            wait_for_user_input();
        } else if (option == 3) {
            // Exit program
            clear_screen();
            printf("Thank you for using the Expense Tracker. Bye!\n\n");
            wait_for_user_input();
            break;
        }
        else {
          printf("\nInvalid option. Please choose a valid option.\n\n");
          wait_for_user_input();
        }

        clear_screen();
        print_header();
    }

    free(expenses);

    return 0;
}

void print_header() {
    printf("******** EXPENSE TRACKER ********\n\n");
    printf("MENU\n\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n\n");
}

int get_menu_option() {
    int option;
    printf("Enter option (1-3): ");

    while (scanf("%d", &option) != 1) {
        printf("Invalid input. Please enter a number between 1 and 3.\n");
        printf("Enter option (1-3): ");
        while (getchar() != '\n');
    }

    while (getchar() != '\n');

    return option;
}

void wait_for_user_input() {
    printf("Press Enter to continue.\n");
    while (getchar() != '\n');
}

void clear_screen() {
    system("clear || cls");
}