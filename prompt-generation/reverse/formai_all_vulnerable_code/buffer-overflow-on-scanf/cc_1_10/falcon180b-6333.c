//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_AMOUNT_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} Expense;

int main() {
    FILE *fp;
    char filename[MAX_NAME_LENGTH];
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    int choice = 0;

    do {
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter the filename to save expenses: ");
                scanf("%s", filename);

                fp = fopen(filename, "a");
                if(fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }

                printf("Enter the name of the expense: ");
                scanf("%s", expenses[num_expenses].name);

                printf("Enter the category of the expense: ");
                scanf("%s", expenses[num_expenses].category);

                printf("Enter the amount of the expense: ");
                scanf("%s", expenses[num_expenses].amount);

                fwrite(&expenses[num_expenses], sizeof(Expense), 1, fp);
                fclose(fp);
                num_expenses++;
                break;
            }
            case 2: {
                printf("Enter the filename to view expenses: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");
                if(fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }

                while(fread(&expenses[num_expenses], sizeof(Expense), 1, fp) == 1) {
                    printf("Name: %s\n", expenses[num_expenses].name);
                    printf("Category: %s\n", expenses[num_expenses].category);
                    printf("Amount: %s\n", expenses[num_expenses].amount);
                    num_expenses++;
                }

                fclose(fp);
                break;
            }
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}