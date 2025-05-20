//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int acc_num;
    char name[30];
    float balance;
} account;

typedef struct {
    int acc_num;
    float amount;
    char type[10];
    char date[20];
} transaction;

void deposit(account *acc, float amount);
void withdraw(account *acc, float amount);
void view_balance(account acc);
void view_transactions();

int main() {
    int choice, acc_num;
    float amount;
    account acc;
    transaction tr;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Welcome to the banking record system!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Open account\n");
        printf("2. Deposit funds\n");
        printf("3. Withdraw funds\n");
        printf("4. View balance\n");
        printf("5. View transaction history\n");
        printf("6. Exit\n");
        printf("Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Open account
                printf("\nEnter account number: ");
                scanf("%d", &acc.acc_num);
                printf("Enter name: ");
                scanf("%s", acc.name);
                printf("Enter initial balance: ");
                scanf("%f", &acc.balance);

                // Save account info to file
                FILE *f = fopen("accounts.txt", "a");
                fprintf(f, "%d,%s,%.2f\n", acc.acc_num, acc.name, acc.balance);
                fclose(f);

                printf("\nAccount created successfully.\n");
                break;

            case 2:
                // Deposit funds
                printf("\nEnter account number: ");
                scanf("%d", &acc_num);
                f = fopen("accounts.txt", "r");
                while (fscanf(f, "%d,%[^,],%f\n", &acc.acc_num, acc.name, &acc.balance) != EOF) {
                    if (acc.acc_num == acc_num) {
                        fclose(f);
                        printf("Enter amount to deposit: ");
                        scanf("%f", &amount);
                        deposit(&acc, amount);
                        // Save transaction info to file
                        f = fopen("transactions.txt", "a");
                        sprintf(tr.date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
                        tr.acc_num = acc.acc_num;
                        tr.amount = amount;
                        strcpy(tr.type, "Deposit");
                        fprintf(f, "%d,%.2f,%s,%s\n", tr.acc_num, tr.amount, tr.type, tr.date);
                        fclose(f);
                        break;
                    }
                }
                if (acc_num != acc.acc_num) {
                    printf("\nAccount not found.\n");
                    fclose(f);
                }
                break;

            case 3:
                // Withdraw funds
                printf("\nEnter account number: ");
                scanf("%d", &acc_num);
                f = fopen("accounts.txt", "r");
                while (fscanf(f, "%d,%[^,],%f\n", &acc.acc_num, acc.name, &acc.balance) != EOF) {
                    if (acc.acc_num == acc_num) {
                        fclose(f);
                        printf("Enter amount to withdraw: ");
                        scanf("%f", &amount);
                        withdraw(&acc, amount);
                        if (acc.balance < 0) {
                            printf("\nInsufficient balance.\n");
                            acc.balance += amount;
                        }
                        else {
                            // Save transaction info to file
                            f = fopen("transactions.txt", "a");
                            sprintf(tr.date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
                            tr.acc_num = acc.acc_num;
                            tr.amount = amount;
                            strcpy(tr.type, "Withdraw");
                            fprintf(f, "%d,%.2f,%s,%s\n", tr.acc_num, tr.amount, tr.type, tr.date);
                            fclose(f);
                        }
                        break;
                    }
                }
                if (acc_num != acc.acc_num) {
                    printf("\nAccount not found.\n");
                    fclose(f);
                }
                break;

            case 4:
                // View balance
                printf("\nEnter account number: ");
                scanf("%d", &acc_num);
                f = fopen("accounts.txt", "r");
                while (fscanf(f, "%d,%[^,],%f\n", &acc.acc_num, acc.name, &acc.balance) != EOF) {
                    if (acc.acc_num == acc_num) {
                        fclose(f);
                        view_balance(acc);
                        break;
                     }
                }
                if (acc_num != acc.acc_num) {
                    printf("\nAccount not found.\n");
                    fclose(f);
                }
                break;

            case 5:
                // View transaction history
                printf("\nEnter account number: ");
                scanf("%d", &acc_num);
                f = fopen("transactions.txt", "r");
                printf("\nAccount Number\tAmount\tType\tDate\n");
                while (fscanf(f, "%d,%f,%[^,],%s\n", &tr.acc_num, &tr.amount, tr.type, tr.date) != EOF) {
                    if (tr.acc_num == acc_num) {
                        printf("%d\t\t%.2f\t%s\t%s\n", tr.acc_num, tr.amount, tr.type, tr.date);
                    }
                }
                fclose(f);
                break;

            case 6:
                // Exit
                printf("\nThank you for using the banking record system!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void deposit(account *acc, float amount) {
    acc->balance += amount;
    printf("\n$%.2f deposited successfully.\n", amount);
    view_balance(*acc);
}

void withdraw(account *acc, float amount) {
    acc->balance -= amount;
    printf("\n$%.2f withdrawn successfully.\n", amount);
    view_balance(*acc);
}

void view_balance(account acc) {
    printf("\nAccount Number: %d\n", acc.acc_num);
    printf("Name: %s\n", acc.name);
    printf("Current Balance: $%.2f\n", acc.balance);
}

void view_transactions() {
    // TODO: Implement function to view transaction history
}