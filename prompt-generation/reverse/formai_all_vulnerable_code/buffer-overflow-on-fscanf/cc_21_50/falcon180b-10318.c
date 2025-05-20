//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct transaction {
    char date[11];
    char description[51];
    float amount;
};

int main() {
    FILE *fp;
    char filename[51];
    int choice, i, j;
    struct transaction transactions[MAX_SIZE];
    int num_transactions = 0;

    printf("Welcome to the Personal Finance Planner!\n");

    // Load previous data
    printf("Loading previous data...\n");
    sprintf(filename, "transactions.txt");
    fp = fopen(filename, "r");
    if (fp!= NULL) {
        while (fscanf(fp, "%s %s %f\n", transactions[num_transactions].date, transactions[num_transactions].description, &(transactions[num_transactions].amount))!= EOF) {
            num_transactions++;
        }
        fclose(fp);
    }

    // Main menu
    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Add new transaction\n");
        printf("2. View transactions\n");
        printf("3. Edit transaction\n");
        printf("4. Delete transaction\n");
        printf("5. Save data\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter transaction date (YYYY-MM-DD): ");
            scanf("%s", transactions[num_transactions].date);
            printf("Enter transaction description: ");
            scanf("%s", transactions[num_transactions].description);
            printf("Enter transaction amount: ");
            scanf("%f", &(transactions[num_transactions].amount));
            num_transactions++;
            break;

        case 2:
            printf("\nTransactions:\n");
            for (i = 0; i < num_transactions; i++) {
                printf("%s %s $%.2f\n", transactions[i].date, transactions[i].description, transactions[i].amount);
            }
            break;

        case 3:
            printf("Enter transaction index to edit: ");
            scanf("%d", &i);
            if (i >= 0 && i < num_transactions) {
                printf("\nEdit transaction:\n");
                printf("1. Date\n");
                printf("2. Description\n");
                printf("3. Amount\n");
                printf("Enter your choice: ");
                scanf("%d", &j);

                switch (j) {
                case 1:
                    printf("Enter new transaction date (YYYY-MM-DD): ");
                    scanf("%s", transactions[i].date);
                    break;

                case 2:
                    printf("Enter new transaction description: ");
                    scanf("%s", transactions[i].description);
                    break;

                case 3:
                    printf("Enter new transaction amount: ");
                    scanf("%f", &(transactions[i].amount));
                    break;
                }
            } else {
                printf("Invalid transaction index.\n");
            }
            break;

        case 4:
            printf("Enter transaction index to delete: ");
            scanf("%d", &i);
            if (i >= 0 && i < num_transactions) {
                for (j = i; j < num_transactions - 1; j++) {
                    transactions[j] = transactions[j + 1];
                }
                num_transactions--;
            } else {
                printf("Invalid transaction index.\n");
            }
            break;

        case 5:
            printf("\nSaving data...\n");
            sprintf(filename, "transactions.txt");
            fp = fopen(filename, "w");
            if (fp!= NULL) {
                for (i = 0; i < num_transactions; i++) {
                    fprintf(fp, "%s %s %f\n", transactions[i].date, transactions[i].description, transactions[i].amount);
                }
                fclose(fp);
            }
            break;

        case 6:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}