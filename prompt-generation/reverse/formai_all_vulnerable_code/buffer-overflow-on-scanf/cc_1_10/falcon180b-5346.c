//Falcon-180B DATASET v1.0 Category: Password management ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000

typedef struct {
    char username[50];
    char password[50];
    int pin;
} account;

void addAccount(account arr[], int size) {
    char choice;
    int i;
    do {
        printf("\nEnter 1 to add an account.\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("\nEnter the username: ");
            scanf("%s", arr[size].username);
            printf("\nEnter the password: ");
            scanf("%s", arr[size].password);
            printf("\nEnter the pin: ");
            scanf("%d", &arr[size].pin);
            size++;
        }
    } while(choice == 1);
}

void displayAccounts(account arr[], int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("\nUsername: %s\nPassword: %s\nPin: %d", arr[i].username, arr[i].password, arr[i].pin);
    }
}

void searchAccount(account arr[], int size) {
    char username[50];
    int i, flag=0;
    printf("\nEnter the username to search: ");
    scanf("%s", username);
    for(i=0;i<size;i++) {
        if(strcmp(arr[i].username, username) == 0) {
            printf("\nUsername found!\n");
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("\nUsername not found!");
    }
}

int main() {
    account arr[MAX];
    int size=0;
    char choice;
    do {
        printf("\n\n********* WELCOME TO PASSWORD MANAGER *********\n");
        printf("\n1. Add account\n2. Display accounts\n3. Search account\n4. Exit");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addAccount(arr, size);
                break;
            case 2:
                if(size == 0) {
                    printf("\nNo accounts added yet!");
                }
                else {
                    displayAccounts(arr, size);
                }
                break;
            case 3:
                if(size == 0) {
                    printf("\nNo accounts added yet!");
                }
                else {
                    searchAccount(arr, size);
                }
                break;
            case 4:
                printf("\nThank you for using Password Manager!");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while(choice!= 4);
    return 0;
}