//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_SIZE 256

typedef struct {
    char name[ACCOUNT_SIZE];
    char number[17];
    float balance;
} Account;

void create_account(Account *accounts, int *count) {
    Account new_account;
    printf("Enter account holder's name: ");
    fgets(new_account.name, ACCOUNT_SIZE, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0;
    printf("Enter account number: ");
    fgets(new_account.number, sizeof(new_account.number), stdin);
    new_account.number[strcspn(new_account.number, "\n")] = 0;
    new_account.balance = 0;

    if (*count < MAX_ACCOUNTS) {
        accounts[*count] = new_account;
        (*count)++;
        printf("Account created successfully.\n");
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

void display_accounts(Account accounts[], int count) {
    int i;
    printf("\nAccounts:\n");
    for (i = 0; i < count; i++) {
        printf("%d. %s %s $%.2f\n", i+1, accounts[i].name, accounts[i].number, accounts[i].balance);
    }
}

void save_accounts(Account accounts[], int count, const char *filename) {
    int i;
    FILE *file;
    file = fopen(filename, "w");
    for (i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%.2f\n", accounts[i].name, accounts[i].number, accounts[i].balance);
    }
    fclose(file);
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int count = 0;
    const char *filename = "accounts.txt";

    if (access(filename, F_OK) == 0) {
        FILE *file;
        file = fopen(filename, "r");
        while (fscanf(file, "%s%*s%s%f", accounts[count].name, accounts[count].number, &accounts[count].balance) != EOF) {
            count++;
        }
        fclose(file);
    }

    while (1) {
        int choice;
        printf("\nC Banking System\n");
        printf("1. Create new account\n");
        printf("2. Display accounts\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(accounts, &count);
                break;
            case 2:
                display_accounts(accounts, count);
                break;
            case 3:
                save_accounts(accounts, count, filename);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}