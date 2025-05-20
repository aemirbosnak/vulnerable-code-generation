//Falcon-180B DATASET v1.0 Category: Password management ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_ACCOUNTS 100
#define MAX_USERNAME 20
#define MAX_PASSWORD 30
#define MAX_EMAIL 50

typedef struct{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char email[MAX_EMAIL];
    int is_admin;
}account;

int num_accounts = 0;
account accounts[MAX_ACCOUNTS];

int add_account(){
    if(num_accounts >= MAX_ACCOUNTS){
        printf("Error: Maximum number of accounts reached.\n");
        return 1;
    }
    account new_account;
    printf("Enter username: ");
    scanf("%s", new_account.username);
    printf("Enter password: ");
    scanf("%s", new_account.password);
    printf("Enter email: ");
    scanf("%s", new_account.email);
    printf("Is this account an administrator? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y'){
        new_account.is_admin = 1;
    }else{
        new_account.is_admin = 0;
    }
    accounts[num_accounts] = new_account;
    num_accounts++;
    printf("Account added successfully.\n");
    return 0;
}

int login(){
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    int i;
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for(i=0; i<num_accounts; i++){
        if(strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0){
            printf("Login successful.\n");
            return 0;
        }
    }
    printf("Invalid username or password.\n");
    return 1;
}

int view_accounts(){
    int i;
    for(i=0; i<num_accounts; i++){
        printf("Username: %s\n", accounts[i].username);
        printf("Password: %s\n", accounts[i].password);
        printf("Email: %s\n", accounts[i].email);
        printf("Is admin? %s\n\n", accounts[i].is_admin? "Yes" : "No");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n");
        printf("1. Add account\n");
        printf("2. Login\n");
        printf("3. View accounts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_account();
                break;
            case 2:
                login();
                break;
            case 3:
                view_accounts();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}