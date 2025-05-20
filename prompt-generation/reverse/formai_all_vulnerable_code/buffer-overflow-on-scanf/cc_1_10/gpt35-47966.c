//FormAI DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct expense {
    char category[50];
    float amount;
    char date[30];
    char note[100];
};

int main() {
    int choice;
    FILE *fp;
    time_t curr_time;
    struct tm *local_time;
    char date[30];

    curr_time = time(NULL);
    local_time = localtime(&curr_time);
    strftime(date, 30, "%x %I:%M %p", local_time);

    printf("\t\t\t\tFuturistic Expense Tracker\n");
    printf("\t\t\t\t--------------------------\n\n");

    while (1) {
        printf("Enter 1 to add an expense\nEnter 2 to display expenses\nEnter 3 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fp = fopen("expense.txt", "a+");
                if (fp == NULL) {
                    printf("Error: Could not open file\n");
                    exit(1);
                }

                printf("\nEnter category (max 50 characters): ");
                char category[50];
                scanf(" %[^\n]s", category);

                printf("Enter amount: ");
                float amount;
                scanf("%f", &amount);

                printf("Enter note (max 100 characters): ");
                char note[100];
                scanf(" %[^\n]s", note);

                struct expense ex;
                strcpy(ex.category, category);
                ex.amount = amount;
                strcpy(ex.note, note);
                strcpy(ex.date, date);

                fwrite(&ex, sizeof(ex), 1, fp);
                fclose(fp);

                printf("\nExpense added successfully!\n\n");
                break;

            case 2:
                fp = fopen("expense.txt", "r");
                if (fp == NULL) {
                    printf("Error: Could not open file\n");
                    exit(1);
                }

                struct expense expenses[100];
                int count = 0;

                while (fread(&expenses[count], sizeof(struct expense), 1, fp) == 1) {
                    count++;
                }

                printf("\n");
                if (count == 0) {
                    printf("No expenses found!\n\n");
                } else {
                    printf("Category\tAmount\t\tDate\t\tNote\n");
                    for (int i = 0; i < count; i++) {
                        printf("%s\t\t%.2f\t\t%s\t%s\n", expenses[i].category, expenses[i].amount, expenses[i].date, expenses[i].note);
                    }
                    printf("\n");
                }

                fclose(fp);
                break;

            case 3:
                printf("\nThank you for using Futuristic Expense Tracker!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n\n");
                break;
        }
    }
    return 0;
}