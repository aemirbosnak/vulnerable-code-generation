//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense {
    int id;
    char type[20];
    float amount;
};

int main() {
    FILE *fp;
    fp = fopen("expenses.txt", "a+"); //append mode

    int option, num_expenses = 0, i;
    float total_expense = 0;

    struct expense arr[1000]; // maximum 1000 expenses

    while (1) {
        printf("Enter an option:\n1. Add an expense\n2. Show all expenses\n3. Show total expenses\n4. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the expense type: ");
                scanf("%s", arr[num_expenses].type);

                printf("Enter the expense amount: ");
                scanf("%f", &arr[num_expenses].amount);

                arr[num_expenses].id = num_expenses + 1; // assign id
                num_expenses++;

                // write expense to file
                fprintf(fp, "%d %s %.2f\n", arr[num_expenses-1].id, arr[num_expenses-1].type, arr[num_expenses-1].amount);
                break;

            case 2:
                rewind(fp); // move file pointer to start
                printf("Expenses:\n");
                for (i=0; i<num_expenses; i++) {
                    printf("%d. Type: %s Amount: %.2f\n", arr[i].id, arr[i].type, arr[i].amount);
                }

                // read expenses from file
                char line[50];
                while (fgets(line, 50, fp) != NULL) {
                    int id;
                    char type[20];
                    float amount;

                    sscanf(line, "%d %s %f\n", &id, type, &amount);
                    printf("%d. Type: %s Amount: %.2f\n", id, type, amount);
                }

                break;

            case 3:
                for (i=0; i<num_expenses; i++) {
                    total_expense += arr[i].amount;
                }
                printf("Total expenses: %.2f\n", total_expense);
                break;

            case 4:
                fclose(fp);
                exit(0);

            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}