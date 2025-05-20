//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

struct expenselog {
    int id;
    char name[50];
    int amount;
    int date;
};

int main() {
    struct expenselog expenselog[10];
    int num_expenselogs = 0;
    int choice;

    printf("Welcome to the Cyberpunk Expense Tracker!\n");

    while (1) {
        printf("1. Add a new expense log\n");
        printf("2. List all expense logs\n");
        printf("3. Edit an expense log\n");
        printf("4. Delete an expense log\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the ID of the expense log: ");
                scanf("%d", &expenselog[num_expenselogs].id);
                printf("Enter the name of the expense log: ");
                scanf("%s", expenselog[num_expenselogs].name);
                printf("Enter the amount of the expense log: ");
                scanf("%d", &expenselog[num_expenselogs].amount);
                printf("Enter the date of the expense log (YYYY-MM-DD): ");
                scanf("%d", &expenselog[num_expenselogs].date);
                num_expenselogs++;
                printf("Expense log added successfully!\n");
                break;

            case 2:
                if (num_expenselogs == 0) {
                    printf("No expense logs found.\n");
                } else {
                    for (int i = 0; i < num_expenselogs; i++) {
                        printf("ID: %d\n", expenselog[i].id);
                        printf("Name: %s\n", expenselog[i].name);
                        printf("Amount: %d\n", expenselog[i].amount);
                        printf("Date: %d\n", expenselog[i].date);
                        printf("\n");
                    }
                }
                break;

            case 3:
                if (num_expenselogs == 0) {
                    printf("No expense logs found.\n");
                } else {
                    printf("Enter the ID of the expense log you want to edit: ");
                    scanf("%d", &choice);

                    for (int i = 0; i < num_expenselogs; i++) {
                        if (expenselog[i].id == choice) {
                            printf("Enter the new name of the expense log: ");
                            scanf("%s", expenselog[i].name);
                            printf("Enter the new amount of the expense log: ");
                            scanf("%d", &expenselog[i].amount);
                            printf("Enter the new date of the expense log (YYYY-MM-DD): ");
                            scanf("%d", &expenselog[i].date);
                            printf("Expense log edited successfully!\n");
                            break;
                        }
                    }
                }
                break;

            case 4:
                if (num_expenselogs == 0) {
                    printf("No expense logs found.\n");
                } else {
                    printf("Enter the ID of the expense log you want to delete: ");
                    scanf("%d", &choice);

                    for (int i = 0; i < num_expenselogs; i++) {
                        if (expenselog[i].id == choice) {
                            printf("Expense log deleted successfully!\n");
                            for (int j = i; j < num_expenselogs - 1; j++) {
                                expenselog[j] = expenselog[j + 1];
                            }
                            num_expenselogs--;
                            break;
                        }
                    }
                }
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}