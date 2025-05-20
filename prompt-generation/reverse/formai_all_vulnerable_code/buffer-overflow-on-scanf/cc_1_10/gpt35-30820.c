//FormAI DATASET v1.0 Category: Banking Record System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BankRecord {
    char name[50];
    int accountNumber;
    int balance;
};

struct BankRecord bank;

int main(){
    printf("Welcome to our banking system!\n");

    printf("Please enter your name: ");
    fgets(bank.name, 50, stdin);
    printf("Enter your account number: ");
    scanf("%d",&bank.accountNumber);
    printf("Enter your opening balance: ");
    scanf("%d",&bank.balance);

    FILE *filePointer;

    // create a file named bank_record.txt and append data
    filePointer = fopen("bank_record.txt", "a");
    fprintf(filePointer, "%s %d %d\n", bank.name, bank.accountNumber, bank.balance);

    fclose(filePointer);

    printf("\nDear %s, your bank record has been added successfully!\n", bank.name);
    printf("\nWould you like to view your record? (y/n)\n");

    char choice;
    scanf(" %c",&choice);

    if(choice=='y'){
        printf("Your bank record is: \n");

        filePointer = fopen("bank_record.txt", "r");

        if (filePointer == NULL) {
            printf("Sorry, unable to open the bank record file.\n");
            return 0;
        }

        char ch;
        printf("name account_number balance\n");
        while((ch = fgetc(filePointer)) != EOF){
            printf("%c",ch);
        }

        fclose(filePointer);
        printf("\nThank you for using our system!\n");
    } else {
        printf("\nThank you for using our system!\n");
    }

    return 0;
}