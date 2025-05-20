//FormAI DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[20];
    float amount;
    char date[10];
};

int main() {
    int choice, count = 0;
    float total = 0;
    struct expense expenses[50];

    while (1) {
        printf("\n******* Expense Tracker *******\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("\nEnter expense category: ");
                scanf("%s", &expenses[count].category);
                printf("Enter expense amount: ");
                scanf("%f", &expenses[count].amount);
                printf("Enter expense date (dd/mm/yyyy): ");
                scanf("%s", &expenses[count].date);
                total += expenses[count].amount;
                count++;
                break;
            }
            case 2: {
                if (count == 0) {
                    printf("\nNo expenses found.\n");
                } else {
                    printf("\nList of expenses:\n");
                    printf("| %-20s | %-10s | %s |\n", "Category", "Amount", "Date");
                    for (int i = 0; i < count; i++) {
                        printf("| %-20s | %-10.2f | %s |\n", expenses[i].category, expenses[i].amount, expenses[i].date);
                    }
                    printf("| %-20s | %-10.2f |        |\n", "TOTAL", total);
                }
                break;
            }
            case 3: {
                printf("\nThank you for using Expense Tracker.\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice, please try again.\n");
            }
        }
    }
    return 0;
}