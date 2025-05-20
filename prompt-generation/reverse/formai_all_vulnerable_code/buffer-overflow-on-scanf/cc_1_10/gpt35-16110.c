//FormAI DATASET v1.0 Category: Banking Record System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for Bank Account related information
typedef struct{
    char accnum[10];
    char name[50];
    char add[100];
    char acc_type[10];
    float balance;
}acc_info;

// Function to create new account
void new_acc(){

    acc_info acc;

    // Accepting user input for account details
    printf("Enter new account number: ");
    scanf("%s", acc.accnum);
    printf("Enter holder name: ");
    getchar();
    fgets(acc.name, 50, stdin);
    printf("Enter holder address: ");
    fgets(acc.add, 100, stdin);
    printf("Enter account type (savings/current): ");
    scanf("%s", acc.acc_type);

    // Setting default balance to zero
    acc.balance = 0.0;

    // Writing account details to file
    FILE *fp;
    fp = fopen("acc_details.txt", "a+");
    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("\nNew account created successfully!\n");
}

// Function to display account details
void show_acc_details(){

    // Accepting user input for account number to display
    char accnum[10];
    printf("\nEnter account number: ");
    scanf("%s", accnum);

    acc_info acc;
    FILE *fp;
    fp = fopen("acc_details.txt", "r");

    // Searching for the account number in the file
    while(fread(&acc, sizeof(acc_info), 1, fp) == 1){
        if(strcmp(acc.accnum, accnum) == 0){
            printf("\nAccount details:\n");
            printf("Account number: %s\n", acc.accnum);
            printf("Holder name: %s", acc.name);
            printf("Holder address: %s", acc.add);
            printf("Account type: %s\n", acc.acc_type);
            printf("Balance: Rs. %.2f\n", acc.balance);
            fclose(fp);
            return;
        }
    }

    // Displaying error message if account number is not found in the file
    printf("\nAccount not found!\n");
    fclose(fp);
}

// Function to deposit amount in account
void deposit(){

    // Accepting user input for account number and amount to be deposited
    char accnum[10];
    printf("\nEnter account number: ");
    scanf("%s", accnum);

    float deposit_amt;
    printf("Enter amount to deposit: ");
    scanf("%f", &deposit_amt);

    acc_info acc;
    FILE *fp;
    fp = fopen("acc_details.txt", "r+");

    // Searching for the account number in the file
    while(fread(&acc, sizeof(acc_info), 1, fp) == 1){
        if(strcmp(acc.accnum, accnum) == 0){
            acc.balance += deposit_amt;

            // Updating account details in the file
            fseek(fp, -1*sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            fclose(fp);
            printf("\nAmount deposited successfully!\n");
            return;
        }
    }

    // Displaying error message if account number is not found in the file
    printf("\nAccount not found!\n");
    fclose(fp);
}

// Function to withdraw amount from account
void withdraw(){

    // Accepting user input for account number and amount to be withdrawn
    char accnum[10];
    printf("\nEnter account number: ");
    scanf("%s", accnum);

    float withdraw_amt;
    printf("Enter amount to withdraw: ");
    scanf("%f", &withdraw_amt);

    acc_info acc;
    FILE *fp;
    fp = fopen("acc_details.txt", "r+");

    // Searching for the account number in the file
    while(fread(&acc, sizeof(acc_info), 1, fp) == 1){
        if(strcmp(acc.accnum, accnum) == 0){
            if(acc.balance < withdraw_amt){
                // Displaying error message if insufficient balance in account
                printf("\nInsufficient balance!\n");
                fclose(fp);
                return;
            }
            else{
                acc.balance -= withdraw_amt;

                // Updating account details in the file
                fseek(fp, -1*sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                fclose(fp);
                printf("\nAmount withdrawn successfully!\n");
                return;
            }
        }
    }

    // Displaying error message if account number is not found in the file
    printf("\nAccount not found!\n");
    fclose(fp);
}

int main(){

    int choice;

    // Displaying menu to the user
    printf("\n*****Banking Record System*****\n\n");
    printf("1. Create new account\n");
    printf("2. Show account details\n");
    printf("3. Deposit amount\n");
    printf("4. Withdraw amount\n");
    printf("5. Exit\n\n");

    // Accepting user input for choice
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    // Performing corresponding operation based on user choice
    switch(choice){
        case 1: new_acc();
                break;
        case 2: show_acc_details();
                break;
        case 3: deposit();
                break;
        case 4: withdraw();
                break;
        case 5: printf("\nThank you for using the program!\n");
                exit(0);
                break;
        default: printf("\nInvalid choice! Please try again.\n");
                 main();
                 break;
    }

    return 0;
}