//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>

void menu();
void add_expense(char* name, char* description, double amount);
void view_expenses();
void exit_program();

int main() {
    menu();
    return 0;
}

void menu() {
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit Program\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_expense("Name", "Description", 1.50);
            break;
        case 2:
            view_expenses();
            break;
        case 3:
            exit_program();
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void add_expense(char* name, char* description, double amount) {
    printf("Expense added: %s - %s - $%.2f\n", name, description, amount);
}

void view_expenses() {
    printf("Expenses:\n");
    printf("Name - Description - Amount\n");
    printf("-----------------------------\n");
    printf("Name - Description - Amount\n");
    printf("-----------------------------\n");
    printf("Name - Description - Amount\n");
    printf("-----------------------------\n");
    printf("Name - Description - Amount\n");
    printf("-----------------------------\n");
    printf("Name - Description - Amount\n");
    printf("-----------------------------\n");
    printf("Name - Description - Amount\n");
    printf("-----------------------------\n");
    printf("Name - Description - Amount\n");
    printf("-----------------------------\n");
    printf("Name - Description - Amount\n");
    printf("-----------------------------\n");
}

void exit_program() {
    printf("Program exited!\n");
}