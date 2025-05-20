//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    int account_no;
    char name[50];
    float balance;
};

void print_account(struct account ac){
    printf("----------------------------------------\n");
    printf("|     Account Number : %-15d|\n", ac.account_no);
    printf("|     Name           : %-15s|\n", ac.name);
    printf("|     Balance        : %-15.2f|\n", ac.balance);
    printf("----------------------------------------\n");
}

void create_account(){
    FILE* fp = fopen("accounts.dat", "ab"); // Open file in append mode if exists
    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }
    struct account ac;

    // Read Account Details
    printf("Enter Account Number : ");
    scanf("%d", &ac.account_no);

    // Check if Account Number already exists
    FILE* fp2 = fopen("accounts.dat", "rb"); // Open file in read mode
    if(fp2 != NULL){
        struct account ac2;
        while(fread(&ac2, sizeof(struct account), 1, fp2)){
            if(ac2.account_no == ac.account_no){
                printf("Account Number already exists.\n");
                return;
            }
        }
    }
    fclose(fp2);

    printf("Enter Customer Name  : ");
    scanf(" %[^\n]", ac.name); // Reading string with spaces

    printf("Enter Opening Balance: ");
    scanf("%f", &ac.balance);

    // Write Account Details to file
    fwrite(&ac, sizeof(struct account), 1, fp);
    fclose(fp);
    printf("\nAccount Created Successfully.\n\n");
}

void view_account(){
    FILE* fp = fopen("accounts.dat", "rb"); // Open file in read mode
    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }
    int acc_no;
    printf("Enter Account Number : ");
    scanf("%d", &acc_no);

    struct account ac;
    int found = 0;

    // Search Account Details from file
    while(fread(&ac, sizeof(struct account), 1, fp)){
        if(ac.account_no == acc_no){
            print_account(ac);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Account not found.\n");
    }

    fclose(fp);
}

void deposit_money(){
    int acc_no, found = 0;
    float amt;

    printf("Enter Account Number : ");
    scanf("%d", &acc_no);

    FILE* fp = fopen("accounts.dat", "rb+"); // Open file in read/write mode
    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }

    struct account ac;

    // Search Account Details from file and Update Balance
    while(fread(&ac, sizeof(struct account), 1, fp)){
        if(ac.account_no == acc_no){
            found = 1;
            printf("Current Balance      : %.2f\n", ac.balance);
            printf("Enter Amount to deposit: ");
            scanf("%f", &amt);
            ac.balance += amt;
            fseek(fp, -sizeof(struct account), SEEK_CUR); // Move file pointer back to the current record to update
            fwrite(&ac, sizeof(struct account), 1, fp);
            printf("Updated Balance      : %.2f\n\n", ac.balance);
            break;
        }
    }

    if(!found){
        printf("Account not found.\n");
    }

    fclose(fp);
}

void withdraw_money(){
    int acc_no, found = 0;
    float amt;

    printf("Enter Account Number : ");
    scanf("%d", &acc_no);

    FILE* fp = fopen("accounts.dat", "rb+"); // Open file in read/write mode
    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }

    struct account ac;

    // Search Account Details from file and Update Balance
    while(fread(&ac, sizeof(struct account), 1, fp)){
        if(ac.account_no == acc_no){
            found = 1;
            printf("Current Balance      : %.2f\n", ac.balance);
            printf("Enter Amount to withdraw: ");
            scanf("%f", &amt);
            if(ac.balance >= amt){
                ac.balance -= amt;
                fseek(fp, -sizeof(struct account), SEEK_CUR); // Move file pointer back to the current record to update
                fwrite(&ac, sizeof(struct account), 1, fp);
                printf("Updated Balance      : %.2f\n\n", ac.balance);
            }
            else{
                printf("Insufficient Balance.\n\n");
            }
            break;
        }
    }

    if(!found){
        printf("Account not found.\n");
    }

    fclose(fp);
}

void transfer_money(){
    int acc_no, found = 0;
    float amt;

    printf("Enter Sender Account Number : ");
    scanf("%d", &acc_no);

    FILE* fp = fopen("accounts.dat", "rb+"); // Open file in read/write mode
    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }

    struct account ac;
    struct account ac2;

    // Search Sender Account Details from file and Update Balance
    while(fread(&ac, sizeof(struct account), 1, fp)){
        if(ac.account_no == acc_no){
            found = 1;
            printf("Current Balance             : %.2f\n", ac.balance);
            printf("Enter Amount to transfer    : ");
            scanf("%f", &amt);
            if(ac.balance >= amt){
                printf("Enter Recipient Account Number: ");
                scanf("%d", &ac2.account_no);
                FILE* fp2 = fopen("accounts.dat", "rb"); // Open file in read mode to search recipient account
                if(fp2 == NULL){
                    printf("Error opening file.\n");
                    return;
                }
                int found2 = 0;
                while(fread(&ac2, sizeof(struct account), 1, fp2)){
                    if(ac2.account_no == ac2.account_no){
                        found2 = 1;
                        ac2.balance += amt;
                        fclose(fp2);
                        break;
                    }
                }
                if(found2){ // If recipient account found in file
                    ac.balance -= amt;
                    fseek(fp, -sizeof(struct account), SEEK_CUR); // Move file pointer back to the current record to update sender account
                    fwrite(&ac, sizeof(struct account), 1, fp);
                    fseek(fp2, -sizeof(struct account), SEEK_CUR); // Move file pointer back to the current record to update recipient account
                    fwrite(&ac2, sizeof(struct account), 1, fp2);
                    printf("Updated Sender Balance       : %.2f\n\n", ac.balance);
                }
                else{
                    printf("Recipient Account not found.\n\n");
                }
                fclose(fp2);
            }
            else{
                printf("Insufficient Balance.\n\n");
            }
            break;
        }
    }

    if(!found){
        printf("Sender Account not found.\n");
    }

    fclose(fp);
}

void delete_account(){
    int acc_no, found = 0;

    printf("Enter Account Number : ");
    scanf("%d", &acc_no);

    FILE* fp = fopen("accounts.dat", "rb"); // Open file in read mode to backup data
    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }

    FILE* fp2 = fopen("accounts_backup.dat", "wb"); // Open another file in write mode to backup data
    if(fp2 == NULL){
        printf("Error opening file.\n");
        return;
    }

    int choice;
    char ch;

    struct account ac;
    while(fread(&ac, sizeof(struct account), 1, fp)){
        if(ac.account_no == acc_no){
            printf("Are you sure you want to delete following account? (1 for Yes, 0 for No)\n");
            print_account(ac);
            printf("Choice : ");
            scanf("%d", &choice);
            if(choice == 1){
                found = 1;
            }
            else{
                fwrite(&ac, sizeof(struct account), 1, fp2); // Copy non-deleted records to backup file
            }
        }
        else{
            fwrite(&ac, sizeof(struct account), 1, fp2); // Copy non-deleted records to backup file
        }
    }

    fclose(fp);
    fclose(fp2);

    if(found){
        remove("accounts.dat"); // Delete original file
        rename("accounts_backup.dat", "accounts.dat"); // Rename backup file
        printf("\nAccount Deleted Successfully.\n\n");
    }
    else{
        remove("accounts_backup.dat"); // Delete backup file
        printf("\nAccount not found.\n\n");
    }
}

void list_accounts(){
    FILE* fp = fopen("accounts.dat", "rb"); // Open file in read mode
    if(fp == NULL){
        printf("Error opening file.\n");
        return;
    }
    struct account ac;
    while(fread(&ac, sizeof(struct account), 1, fp)){
        print_account(ac);
    }
    fclose(fp);
}

int main(){
    int choice;

    while(1){
        printf("---- Bank Record System ----\n");
        printf("1. Create a New Account\n");
        printf("2. View an Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Transfer Money\n");
        printf("6. Delete an Account\n");
        printf("7. List All Accounts\n");
        printf("0. Exit the System\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create_account();
                break;
            case 2:
                view_account();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                transfer_money();
                break;
            case 6:
                delete_account();
                break;
            case 7:
                list_accounts();
                break;
            case 0:
                printf("Thank you for using the System.\n");
                exit(0);
            default:
                printf("Invalid Choice. Try again.\n");
                break;
        }
    }

    return 0;
}