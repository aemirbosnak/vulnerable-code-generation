//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[50];
    float amount;
};

void display_menu() {
    system("clear");
    printf("===========================\n");
    printf(" C Expense Tracker Program\n");
    printf("===========================\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
}

int main() {
    int choice, count = 0;
    struct expense expenses[100];

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("clear");
                printf("Enter expense name: ");
                scanf("%s", expenses[count].name);
                printf("Enter expense amount: ");
                scanf("%f", &expenses[count].amount);
                printf("\nExpense added!\n\n");
                count++;
                break;

            case 2:
                system("clear");
                if (count == 0) {
                    printf("No expenses found.\n\n");
                } else {
                    printf("Expenses:\n\n");
                    printf("| %-50s | %-10s |\n", "Name", "Amount");
                    printf("-------------------------------------------------------\n");
                    for (int i = 0; i < count; i++) {
                        printf("| %-50s | $%-9.2f |\n", expenses[i].name, expenses[i].amount);
                        printf("-------------------------------------------------------\n");
                    }
                }
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("Press any key to continue...\n");
        getchar();
        getchar();

    } while (choice != 3);

    return 0;
}