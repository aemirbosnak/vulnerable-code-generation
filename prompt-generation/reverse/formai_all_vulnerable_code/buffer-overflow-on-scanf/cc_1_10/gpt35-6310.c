//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for record keeping
typedef struct{
    int accountNumber;
    char accountHolder[50];
    char accountType[10];
    float balance;
}Records;

// Function prototypes
void menu();
void createAccount();
void showAccountDetails();
void deposit();
void withdraw();
void saveToFile();
void help();

// Variables to hold records
Records *bankRecords;

// Main function
int main(){

    printf("*********************\n");
    printf("*** C BANK SYSTEM ***\n");
    printf("*********************\n\n");

    menu();

    return 0;
}

// Function to display the menu
void menu(){

    int choice;

    printf("Please choose an option:\n");
    printf("1. Create account\n");
    printf("2. Show account details\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Save to file\n");
    printf("6. Help\n");
    printf("7. Exit\n\n");

    printf("Choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            createAccount();
            break;
        case 2:
            showAccountDetails();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            saveToFile();
            break;
        case 6:
            help();
            break;
        case 7:
            printf("Exiting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            menu();
            break;
    }
}

// Function to create a new account
void createAccount(){

    int numAccounts, i;

    printf("Enter the number of accounts to create: ");
    scanf("%d", &numAccounts);

    // Allocate memory for accounts
    bankRecords = (Records*)malloc(numAccounts * sizeof(Records));

    for(i = 0; i < numAccounts; i++){

        printf("\n========== CREATING ACCOUNT %d ==========\n", i+1);

        // Get account number
        printf("Enter account number: ");
        scanf("%d", &bankRecords[i].accountNumber);

        // Get account holder name
        printf("Enter account holder name: ");
        getchar();
        fgets(bankRecords[i].accountHolder, 50, stdin);

        // Get account type
        printf("Enter account type: ");
        scanf("%s", bankRecords[i].accountType);

        // Get initial balance
        printf("Enter initial balance: ");
        scanf("%f", &bankRecords[i].balance);

    }

    printf("\nAccounts created successfully!\n");
    printf("Returning to menu...\n\n");

    menu();
}

// Function to display account details
void showAccountDetails(){

    int accountNum, i;

    printf("Enter account number: ");
    scanf("%d", &accountNum);

    for(i = 0; i < sizeof(bankRecords); i++){

        if(bankRecords[i].accountNumber == accountNum){

            printf("\n========== ACCOUNT DETAILS ==========\n");
            printf("Account number: %d\n", bankRecords[i].accountNumber);
            printf("Account holder: %s", bankRecords[i].accountHolder);
            printf("Account type: %s\n", bankRecords[i].accountType);
            printf("Balance: %0.2f\n", bankRecords[i].balance);
            printf("====================================\n\n");

            menu();
        }
    }

    printf("Account not found. Please try again.\n\n");
    menu();
}

// Function to deposit to an account
void deposit(){

    int accountNum, i;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNum);

    for(i = 0; i < sizeof(bankRecords); i++){

        if(bankRecords[i].accountNumber == accountNum){

            // Get deposit amount
            printf("Enter deposit amount: ");
            scanf("%f", &amount);

            // Update balance
            bankRecords[i].balance += amount;

            printf("\nDeposit successful!\n");
            printf("New balance: %0.2f\n\n", bankRecords[i].balance);

            menu();
        }
    }

    printf("Account not found. Please try again.\n\n");
    menu();
}

// Function to withdraw from an account
void withdraw(){

    int accountNum, i;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNum);

    for(i = 0; i < sizeof(bankRecords); i++){

        if(bankRecords[i].accountNumber == accountNum){

            // Get withdrawal amount
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);

            // Check if enough balance
            if(amount > bankRecords[i].balance){

                printf("\nInsufficient balance.\n\n");
                menu();

            }else{

                // Update balance
                bankRecords[i].balance -= amount;

                printf("\nWithdrawal successful!\n");
                printf("New balance: %0.2f\n\n", bankRecords[i].balance);

                menu();
            }
        }
    }

    printf("Account not found. Please try again.\n\n");
    menu();
}

// Function to save records to file
void saveToFile(){

    FILE *file;
    char fileName[20];
    int i;

    printf("Enter file name (without extension): ");
    scanf("%s", fileName);

    strcat(fileName, ".txt");

    // Open file for writing
    file = fopen(fileName, "w");

    // Write records to file
    for(i = 0; i < sizeof(bankRecords); i++){

        fprintf(file, "%d,%s,%s,%0.2f\n", bankRecords[i].accountNumber, bankRecords[i].accountHolder, bankRecords[i].accountType, bankRecords[i].balance);

    }

    fclose(file);

    printf("\nRecords saved successfully!\n");
    printf("Returning to menu...\n\n");

    menu();

}

// Function to display help
void help(){

    printf("\n========== HELP ==========\n");
    printf("1. To create a new account, select option 1 from the menu.\n");
    printf("2. To display account details, select option 2 from the menu.\n");
    printf("3. To deposit to an account, select option 3 from the menu.\n");
    printf("4. To withdraw from an account, select option 4 from the menu.\n");
    printf("5. To save records to file, select option 5 from the menu.\n");
    printf("6. To display help, select option 6 from the menu.\n");
    printf("7. To exit the program, select option 7 from the menu.\n");
    printf("==========================\n\n");

    menu();
}