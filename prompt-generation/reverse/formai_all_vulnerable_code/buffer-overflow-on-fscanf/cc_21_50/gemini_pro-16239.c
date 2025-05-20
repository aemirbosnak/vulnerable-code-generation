//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[50];
    char acc_num[20];
    double balance;
};

int main() {
    struct account accounts[100];
    int num_accounts = 0;

    // Read account data from file
    FILE *fp = fopen("accounts.txt", "r");
    if (!fp) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(fp, "%s %s %lf", accounts[num_accounts].name, accounts[num_accounts].acc_num, 
    &accounts[num_accounts].balance) != EOF) {
        num_accounts++;
    }

    fclose(fp);

    // Display account data
    printf("Account information:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s %s %.2f\n", accounts[i].name, accounts[i].acc_num, accounts[i].balance);
    }

    // Process user input
    while (1) {
        char input[50];
        printf("\nEnter a command (deposit, withdraw, balance, quit): ");
        scanf("%s", input);

        if (strcmp(input, "deposit") == 0) {
            char acc_num[20];
            double amount;

            printf("Enter account number: ");
            scanf("%s", acc_num);

            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);

            // Find account index
            int index = -1;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].acc_num, acc_num) == 0) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                printf("Account not found\n");
            } else {
                accounts[index].balance += amount;
                printf("Deposit successful\n");
            }
        } else if (strcmp(input, "withdraw") == 0) {
            char acc_num[20];
            double amount;

            printf("Enter account number: ");
            scanf("%s", acc_num);

            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);

            // Find account index
            int index = -1;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].acc_num, acc_num) == 0) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                printf("Account not found\n");
            } else if (accounts[index].balance < amount) {
                printf("Insufficient funds\n");
            } else {
                accounts[index].balance -= amount;
                printf("Withdrawal successful\n");
            }
        } else if (strcmp(input, "balance") == 0) {
            char acc_num[20];

            printf("Enter account number: ");
            scanf("%s", acc_num);

            // Find account index
            int index = -1;
            for (int i = 0; i < num_accounts; i++) {
                if (strcmp(accounts[i].acc_num, acc_num) == 0) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                printf("Account not found\n");
            } else {
                printf("Balance: %.2f\n", accounts[index].balance);
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    // Write account data to file
    fp = fopen("accounts.txt", "w");
    if (!fp) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_accounts; i++) {
        fprintf(fp, "%s %s %.2f\n", accounts[i].name, accounts[i].acc_num, accounts[i].balance);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}