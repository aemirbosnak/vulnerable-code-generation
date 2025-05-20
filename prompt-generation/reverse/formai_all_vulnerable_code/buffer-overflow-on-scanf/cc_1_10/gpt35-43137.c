//FormAI DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    long int account_no;
    char name[50];
    float balance;
    int status;
};

void display_main_menu();
void create_account();
void display_account_details();
void deposit_money();
void withdraw_money();
void close_account();
void display_all_accounts();

int main() {
    int choice;

    do {
        display_main_menu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                display_account_details();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                close_account();
                break;
            case 6:
                display_all_accounts();
                break;
            case 0:
                printf("\nThank you for using our services. Have a nice day!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void display_main_menu() {
    printf("\n");
    printf("*******************************************\n");
    printf("*           BANKING RECORD SYSTEM          *\n");
    printf("*-----------------------------------------*\n");
    printf("* 1. Create new account                    *\n");
    printf("* 2. Display account details               *\n");
    printf("* 3. Deposit money into account            *\n");
    printf("* 4. Withdraw money from account           *\n");
    printf("* 5. Close account                         *\n");
    printf("* 6. Display all accounts                  *\n");
    printf("* 0. Exit                                  *\n");
    printf("*******************************************\n");
}

void create_account() {
    struct customer c;

    printf("\nEnter account number: ");
    scanf("%ld", &c.account_no);

    printf("Enter name: ");
    scanf("%s", c.name);

    printf("Enter balance: ");
    scanf("%f", &c.balance);

    c.status = 1;

    FILE *fptr;
    fptr = fopen("accounts.txt", "ab");

    if (fptr == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    fwrite(&c, sizeof(struct customer), 1, fptr);

    printf("\nAccount created successfully.\n");

    fclose(fptr);
}

void display_account_details() {
    long int account_no;
    printf("\nEnter account number: ");
    scanf("%ld", &account_no);

    struct customer c;
    int found = 0;

    FILE *fptr;
    fptr = fopen("accounts.txt", "rb");

    if (fptr == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    while (fread(&c, sizeof(struct customer), 1, fptr) == 1) {
        if (c.account_no == account_no && c.status == 1) {
            printf("\nName: %s\n", c.name);
            printf("Balance: %f\n", c.balance);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nAccount not found or closed.\n");
    }

    fclose(fptr);
}

void deposit_money() {
    long int account_no;
    float amount;
    printf("\nEnter account number: ");
    scanf("%ld", &account_no);

    struct customer c;
    int found = 0;

    FILE *fptr;
    fptr = fopen("accounts.txt", "rb+");

    if (fptr == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    while (fread(&c, sizeof(struct customer), 1, fptr) == 1) {
        if (c.account_no == account_no && c.status == 1) {
            printf("\nEnter amount to deposit: ");
            scanf("%f", &amount);

            c.balance += amount;

            fseek(fptr, -sizeof(struct customer), SEEK_CUR);
            fwrite(&c, sizeof(struct customer), 1, fptr);

            printf("\nAmount deposited successfully.\n");
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nAccount not found or closed.\n");
    }

    fclose(fptr);
}

void withdraw_money() {
    long int account_no;
    float amount;
    printf("\nEnter account number: ");
    scanf("%ld", &account_no);

    struct customer c;
    int found = 0;

    FILE *fptr;
    fptr = fopen("accounts.txt", "rb+");

    if (fptr == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    while (fread(&c, sizeof(struct customer), 1, fptr) == 1) {
        if (c.account_no == account_no && c.status == 1) {
            printf("\nEnter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > c.balance) {
                printf("\nInsufficient balance.\n");
                break;
            }

            c.balance -= amount;

            fseek(fptr, -sizeof(struct customer), SEEK_CUR);
            fwrite(&c, sizeof(struct customer), 1, fptr);

            printf("\nAmount withdrawn successfully.\n");
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nAccount not found or closed.\n");
    }

    fclose(fptr);
}

void close_account() {
    long int account_no;
    printf("\nEnter account number: ");
    scanf("%ld", &account_no);

    struct customer c;
    int found = 0;

    FILE *fptr;
    fptr = fopen("accounts.txt", "rb+");

    if (fptr == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    while (fread(&c, sizeof(struct customer), 1, fptr) == 1) {
        if (c.account_no == account_no && c.status == 1) {
            c.status = 0;

            fseek(fptr, -sizeof(struct customer), SEEK_CUR);
            fwrite(&c, sizeof(struct customer), 1, fptr);

            printf("\nAccount closed successfully.\n");
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nAccount not found or closed.\n");
    }

    fclose(fptr);
}

void display_all_accounts() {
    struct customer c;

    FILE *fptr;
    fptr = fopen("accounts.txt", "rb");

    if (fptr == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    printf("\n%-15s %-30s %-15s\n", "Account No.", "Name", "Balance");
    printf("--------------------------------------------------------\n");
    while (fread(&c, sizeof(struct customer), 1, fptr) == 1) {
        if (c.status == 1) {
            printf("%-15ld %-30s %-15.2f\n", c.account_no, c.name, c.balance);
        }
    }

    fclose(fptr);
}