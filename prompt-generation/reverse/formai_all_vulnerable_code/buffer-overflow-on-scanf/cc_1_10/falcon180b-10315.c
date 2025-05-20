//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char category[50];
    float amount;
    char date[15];
} Expense;

int main() {
    int choice, i;
    FILE *fp;
    Expense expenses[100];

    printf("Welcome to the Expense Tracker!\n");
    printf("Please choose an option:\n");
    printf("1. Add an expense\n2. View expenses\n3. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the category of the expense: ");
            scanf("%s", expenses[0].category);
            printf("Enter the amount of the expense: $");
            scanf("%f", &expenses[0].amount);
            printf("Enter the date of the expense (mm/dd/yyyy): ");
            scanf("%s", expenses[0].date);

            printf("Expense added successfully!\n");

            printf("Do you want to add another expense? (y/n) ");
            scanf(" %c", &choice);

            if(choice == 'y' || choice == 'Y') {
                for(i=1; i<100; i++) {
                    printf("Enter the category of the expense: ");
                    scanf("%s", expenses[i].category);
                    printf("Enter the amount of the expense: $");
                    scanf("%f", &expenses[i].amount);
                    printf("Enter the date of the expense (mm/dd/yyyy): ");
                    scanf("%s", expenses[i].date);

                    printf("Expense added successfully!\n");

                    printf("Do you want to add another expense? (y/n) ");
                    scanf(" %c", &choice);
                }
            }

            break;

        case 2:
            printf("Viewing expenses...\n");

            for(i=0; i<100; i++) {
                printf("Category: %s\nAmount: $%.2f\nDate: %s\n\n", expenses[i].category, expenses[i].amount, expenses[i].date);
            }

            break;

        case 3:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}