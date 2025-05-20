//FormAI DATASET v1.0 Category: Password management ; Style: active
#include<stdio.h>
#include<string.h>

struct Password{
    char domain[50];
    char username[50];
    char password[50];
} p[100];

int num_of_accounts = 0;

void displayAccounts(){
    if(num_of_accounts == 0){
        printf("No accounts found\n");
        return;
    }
    printf("List of Accounts:\n");
    for(int i=0;i<num_of_accounts;i++){
        printf("%d) Domain: %s\nUsername: %s\nPassword: %s\n\n", i+1, p[i].domain, p[i].username, p[i].password);
    }
}

void addAccount(){
    printf("Enter domain: ");
    scanf("%s", p[num_of_accounts].domain);
    printf("Enter username: ");
    scanf("%s", p[num_of_accounts].username);
    printf("Enter password: ");
    scanf("%s", p[num_of_accounts].password);
    num_of_accounts++;
    printf("Account added successfully!\n");
}

void deleteAccount(){
    if(num_of_accounts == 0){
        printf("No accounts found\n");
        return;
    }
    int choice;
    displayAccounts();
    printf("Enter account number to delete: ");
    scanf("%d", &choice);
    choice--;
    for(int i=choice;i<num_of_accounts-1;i++){
        strcpy(p[i].domain, p[i+1].domain);
        strcpy(p[i].username, p[i+1].username);
        strcpy(p[i].password, p[i+1].password);
    }
    num_of_accounts--;
    printf("Account deleted successfully!\n");
}

void updatePassword(){
    if(num_of_accounts == 0){
        printf("No accounts found\n");
        return;
    }
    int choice;
    char new_password[50];
    displayAccounts();
    printf("Enter account number to update password: ");
    scanf("%d", &choice);
    choice--;
    printf("Enter new password: ");
    scanf("%s", new_password);
    strcpy(p[choice].password, new_password);
    printf("Password updated successfully!\n");
}

int main(){
    int option;
    do{
        printf("\n-------------------------------------------------\n");
        printf("Password Management System - Options\n");
        printf("-------------------------------------------------\n");
        printf("1) Display accounts\n");
        printf("2) Add new account\n");
        printf("3) Delete an account\n");
        printf("4) Update a password\n");
        printf("5) Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                displayAccounts();
                break;
            case 2:
                addAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                updatePassword();
                break;
            case 5:
                printf("Exiting..");
                break;
            default:
                printf("Invalid option\n");
        }
    }while(option!=5);
    return 0;
}