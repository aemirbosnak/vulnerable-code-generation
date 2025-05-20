//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for customer record */
struct customer_record {
    int account_number;
    char name[30];
    float balance;
};

/* Function to save customer record to file */
void save_record(struct customer_record c) {
    FILE *fp;

    fp = fopen("customer_records.txt", "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "%d %s %.2f\n", c.account_number, c.name, c.balance);

    fclose(fp);
}

/* Function to search for a customer record */
void search_record(int account_number) {
    FILE *fp;
    struct customer_record c;
    int found = 0;

    fp = fopen("customer_records.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fscanf(fp, "%d %s %f", &c.account_number, c.name, &c.balance) == 3) {
        if (c.account_number == account_number) {
            printf("Customer Record Found!\n");
            printf("Account Number: %d\n", c.account_number);
            printf("Name: %s\n", c.name);
            printf("Balance: %.2f\n", c.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Customer Record Not Found!\n");
    }

    fclose(fp);
}

/* Function to update a customer record */
void update_record(int account_number, float new_balance) {
    FILE *fp, *temp_fp;
    struct customer_record c;
    int found = 0;

    fp = fopen("customer_records.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    temp_fp = fopen("temp_customer_records.txt", "w");

    if (temp_fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fscanf(fp, "%d %s %f", &c.account_number, c.name, &c.balance) == 3) {
        if (c.account_number == account_number) {
            c.balance = new_balance;
            found = 1;
        }
        fprintf(temp_fp, "%d %s %.2f\n", c.account_number, c.name, c.balance);
    }

    if (!found) {
        printf("Customer Record Not Found!\n");
        exit(1);
    }

    fclose(fp);
    fclose(temp_fp);

    remove("customer_records.txt");
    rename("temp_customer_records.txt", "customer_records.txt");
}

/* Main function */
int main() {
    int choice, account_number;
    float new_balance;
    struct customer_record c;

    printf("Welcome to the Banking Record System!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Customer Record\n");
        printf("2. Search Customer Record\n");
        printf("3. Update Customer Record\n");
        printf("4. Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Account Number: ");
                scanf("%d", &c.account_number);
                printf("Enter Name: ");
                scanf("%s", c.name);
                printf("Enter Balance: ");
                scanf("%f", &c.balance);
                save_record(c);
                printf("\nCustomer Record Added!\n");
                break;

            case 2:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                search_record(account_number);
                break;

            case 3:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_number);
                printf("Enter New Balance: ");
                scanf("%f", &new_balance);
                update_record(account_number, new_balance);
                printf("\nCustomer Record Updated!\n");
                break;

            case 4:
                printf("\nExiting Banking Record System...\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }

    return 0;
}