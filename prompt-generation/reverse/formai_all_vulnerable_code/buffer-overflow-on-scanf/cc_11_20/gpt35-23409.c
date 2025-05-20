//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Expense {
    int id;
    char name[50];
    float amount;
    char date[20];
} Expense;

int main() {
    FILE *fp;
    Expense ex;
    int choice, id, count = 0;
    float total_amount = 0;
    bool found = false;

    fp = fopen("expenses.txt", "a+");

    if (fp == NULL) {
        printf("File does not exist!\n");
        exit(1);
    }

    while (true) {
        printf("\n1) Add Expense\n2) View Expenses\n3) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter expense name: ");
                scanf("%s", ex.name);
                printf("Enter expense amount: ");
                scanf("%f", &ex.amount);
                printf("Enter expense date (dd/mm/yyyy): ");
                scanf("%s", ex.date);

                fseek(fp, 0, SEEK_END);
                ex.id = count + 1;
                fprintf(fp, "%d %s %.2f %s\n", ex.id, ex.name, ex.amount, ex.date);
                count++;
                total_amount += ex.amount;
                printf("\nExpense added successfully!\n");
                break;

            case 2:
                fseek(fp, 0, SEEK_SET);
                if (fgetc(fp) == EOF) {
                    printf("\nNo expenses found!\n");
                    break;
                }

                printf("\nEnter expense id (0 to view all expenses): ");
                scanf("%d", &id);

                if (id == 0) {
                    printf("\nAll expenses:\n");
                    printf("ID   Name                       Amount     Date\n");
                    printf("--   ----                       ------     ----\n");

                    while (!feof(fp)) {
                        fscanf(fp, "%d %s %f %s", &ex.id, ex.name, &ex.amount, ex.date);
                        if (found) {
                            printf("%-4d %-25s %-10.2f %s\n", ex.id, ex.name, ex.amount, ex.date);
                        }
                        found = true;
                    }

                    if (!found) {
                        printf("\nNo expenses found!\n");
                    } else {
                        printf("\nTotal expense amount: %.2f\n", total_amount);
                    }
                    found = false;
                } else {
                    found = false;
                    while (!feof(fp)) {
                        fscanf(fp, "%d %s %f %s", &ex.id, ex.name, &ex.amount, ex.date);
                        if (ex.id == id) {
                            printf("\nExpense details:\n");
                            printf("ID   Name                       Amount     Date\n");
                            printf("--   ----                       ------     ----\n");
                            printf("%-4d %-25s %-10.2f %s\n", ex.id, ex.name, ex.amount, ex.date);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nExpense not found!\n");
                    }
                }
                break;

            case 3:
                fclose(fp);
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}