//FormAI DATASET v1.0 Category: Banking Record System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record {
    int account_number;
    char name[50];
    int balance;
};

void create_account() {
    struct record r;
    printf("\nEnter Account Number: ");
    scanf("%d", &r.account_number);
    printf("\nEnter Name: ");
    scanf("%s", r.name);
    printf("\nEnter Balance: ");
    scanf("%d", &r.balance);
    FILE *fp = fopen("records.bin", "ab");
    fwrite(&r, sizeof(r), 1, fp);
    fclose(fp);
    printf("\nAccount Created Successfully!\n");
    printf("-------------------------\n");
}

void view_accounts() {
    struct record r;
    FILE *fp = fopen("records.bin", "rb");
    if(fp == NULL) {
        printf("\nNo Accounts Found!\n");
        printf("-------------------------\n");
        return;
    }
    printf("\nAccounts:\n");
    while(fread(&r, sizeof(r), 1, fp)) {
        printf("\nAccount Number: %d\n", r.account_number);
        printf("Name: %s\n", r.name);
        printf("Balance: %d\n", r.balance);
        printf("-------------------------\n");
    }
    fclose(fp);
}

void search_account() {
    struct record r;
    int account_number;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    FILE *fp = fopen("records.bin", "rb");
    if(fp == NULL) {
        printf("\nNo Accounts Found!\n");
        printf("-------------------------\n");
        return;
    }
    while(fread(&r, sizeof(r), 1, fp)) {
        if(r.account_number == account_number) {
            printf("\nAccount Number: %d\n", r.account_number);
            printf("Name: %s\n", r.name);
            printf("Balance: %d\n", r.balance);
            printf("-------------------------\n");
            fclose(fp);
            return;
        }
    }
    printf("\nAccount not found!\n");
    printf("-------------------------\n");
    fclose(fp);
}

void delete_account() {
    struct record r;
    int account_number;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    FILE *fp = fopen("records.bin", "rb");
    FILE *fp2 = fopen("temp.bin", "wb");
    if(fp == NULL) {
        printf("\nNo Accounts Found!\n");
        printf("-------------------------\n");
        return;
    }
    while(fread(&r, sizeof(r), 1, fp)) {
        if(r.account_number != account_number) {
            fwrite(&r, sizeof(r), 1, fp2);
        }
    }
    fclose(fp);
    fclose(fp2);
    remove("records.bin");
    rename("temp.bin", "records.bin");
    printf("\nAccount deleted Successfully!\n");
    printf("-------------------------\n");
}

void modify_account() {
    struct record r;
    int account_number;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    FILE *fp = fopen("records.bin", "rb+");
    if(fp == NULL) {
        printf("\nNo Accounts Found!\n");
        printf("-------------------------\n");
        return;
    }
    while(fread(&r, sizeof(r), 1, fp)) {
        if(r.account_number == account_number) {
            printf("\nAccount Number: %d\n", r.account_number);
            printf("Name: %s\n", r.name);
            printf("Balance: %d\n", r.balance);
            printf("-------------------------\n");
            printf("\nEnter New Balance: ");
            scanf("%d", &r.balance);
            fseek(fp, -sizeof(r), SEEK_CUR);
            fwrite(&r, sizeof(r), 1, fp);
            printf("\nAccount modified Successfully!\n");
            printf("-------------------------\n");
            fclose(fp);
            return;
        }
    }
    printf("\nAccount not found!\n");
    printf("-------------------------\n");
    fclose(fp);
}

int main() {
    while(1) {
        int option;
        printf("\nWelcome to the Bank Record System!\n");
        printf("1. Create Account\n");
        printf("2. View All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Delete Account\n");
        printf("5. Modify Account\n");
        printf("6. Exit\n");
        printf("\nEnter Option Number: ");
        scanf("%d", &option);
        printf("-------------------------\n");
        switch(option) {
            case 1:
                create_account();
                break;
            case 2:
                view_accounts();
                break;
            case 3:
                search_account();
                break;
            case 4:
                delete_account();
                break;
            case 5:
                modify_account();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Option! Try Again.\n");
                printf("-------------------------\n");
                break;
        }
    }
    return 0;
}