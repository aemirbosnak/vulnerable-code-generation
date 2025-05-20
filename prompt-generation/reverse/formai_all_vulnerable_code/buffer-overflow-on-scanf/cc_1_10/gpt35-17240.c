//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30 // Maximum length of username, password, and website name

struct account {
    char website[MAX];
    char username[MAX];
    char password[MAX];
};

void print_account(struct account acc) {
    printf("Website: %s\n", acc.website);
    printf("Username: %s\n", acc.username);
    printf("Password: %s\n", acc.password);
}

void encrypt(char *str) {
    int key = 3; // Encryption key
    while (*str) {
        *str += key;
        str++;
    }
}

void add_account(struct account database[], int *num) {
    printf("Website: ");
    scanf("%s", database[*num].website);
    printf("Username: ");
    scanf("%s", database[*num].username);
    printf("Password: ");
    scanf("%s", database[*num].password);
    encrypt(database[*num].password); // Encrypt the password before storing
    (*num)++;
}

void view_accounts(struct account database[], int num) {
    for (int i = 0; i < num; i++) {
        printf("\nAccount %d:\n", i+1);
        print_account(database[i]);
    }
}

void search_accounts(struct account database[], int num, char *query) {
    int flag = 0;
    for (int i = 0; i < num; i++) {
        if (strstr(database[i].website, query) != NULL) {
            printf("\nSearch result:\n");
            print_account(database[i]);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("\nNo results found.\n");
    }
}

void decrypt(char *str) {
    int key = 3; // Decryption key (same as encryption key)
    while (*str) {
        *str -= key;
        str++;
    }
}

void edit_account(struct account database[], int num, char *website) {
    int index = -1;
    for (int i = 0; i < num; i++) {
        if (strcmp(database[i].website, website) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nWebsite not found.\n");
        return;
    }
    printf("\nCurrent account details:");
    print_account(database[index]);
    printf("\nEnter new details:\n");
    printf("Username: ");
    scanf("%s", database[index].username);
    printf("Password: ");
    scanf("%s", database[index].password);
    encrypt(database[index].password); // Encrypt the new password
    printf("\nAccount details updated successfully.\n");
}

int main() {
    struct account database[MAX];
    int num = 0;
    int choice;
    char query[MAX];
    char website[MAX];
    
    while (1) {
        printf("\n==============================\n");
        printf("Password Manager\n");
        printf("==============================\n");
        printf("1. Add account\n");
        printf("2. View accounts\n");
        printf("3. Search accounts\n");
        printf("4. Edit account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_account(database, &num);
                break;
            case 2:
                view_accounts(database, num);
                break;
            case 3:
                printf("\nEnter a query to search: ");
                scanf("%s", query);
                search_accounts(database, num, query);
                break;
            case 4:
                printf("\nEnter the website name to edit: ");
                scanf("%s", website);
                edit_account(database, num, website);
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}