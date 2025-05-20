//FormAI DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the account record
struct Account {
    int acc_id;
    char name[20];
    float balance;
};

// Function to create a new account record
void create_account() {
    printf("\n");
    printf("Enter Account ID: ");
    int id;
    scanf("%d", &id);

    printf("Enter Account Holder Name: ");
    char name[20];
    scanf("%s", name);

    printf("Enter Account Balance: ");
    float balance;
    scanf("%f", &balance);

    // Write new record to file
    FILE *fp = fopen("accounts.dat", "ab");
    struct Account account = { id, name, balance };
    fwrite(&account, sizeof(struct Account), 1, fp);
    fclose(fp);

    printf("\n");
    printf("Account Created Successfully\n");
}

// Function to display existing account records
void display_accounts() {
    int count = 0;

    // Read records from file and output to console
    FILE *fp = fopen("accounts.dat", "rb");
    printf("\n");
    printf("ID\t NAME\t BALANCE\n");
    printf("------------------------------------------------\n");
    while(!feof(fp)) {
        struct Account account;
        fread(&account, sizeof(struct Account), 1, fp);

        if(feof(fp))
            break;

        printf("%d\t %s\t %.2f\n", account.acc_id, account.name, account.balance);
        count++;
    }
    fclose(fp);

    if(count == 0) {
        printf("\n");
        printf("No Accounts Found\n");
    }
}

// Function to search for an account record
void search_account() {
    printf("\n");
    printf("Enter Account ID: ");
    int id;
    scanf("%d", &id);

    // Iterate through records until the matching record is found
    FILE *fp = fopen("accounts.dat", "rb");
    while(!feof(fp)) {
        struct Account account;
        fread(&account, sizeof(struct Account), 1, fp);

        if(feof(fp))
            break;

        if(account.acc_id == id) {
            printf("\n");
            printf("ID\t NAME\t BALANCE\n");
            printf("------------------------------------------------\n");
            printf("%d\t %s\t %.2f\n", account.acc_id, account.name, account.balance);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\n");
    printf("Account Not Found\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n");
        printf("========== Banking Record System ==========\n");
        printf("\n");
        printf("Choose an option:\n");
        printf("\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Search Account\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter Your Choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_account();
                break;
            case 2:
                display_accounts();
                break;
            case 3:
                search_account();
                break;
            case 4:
                exit(0);
            default:
                printf("\n");
                printf("Invalid Choice, Please Try Again\n");
        }
    } while(choice != 4);

    return 0;
}