//FormAI DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXACCOUNTS 100
#define MAXPASSWORDS 50
#define MAXLENGTH 20

char accounts[MAXACCOUNTS][MAXLENGTH];
char passwords[MAXACCOUNTS][MAXPASSWORDS][MAXLENGTH];
int accountCount = 0;
int passwordCount[MAXACCOUNTS] = {0};

void addAccount() {
    if(accountCount == MAXACCOUNTS) {
        printf("Error - Account limit has been reached\n");
        return;
    }

    printf("Enter account name: ");
    scanf("%s",accounts[accountCount]);
    printf("Enter password: ");
    scanf("%s",passwords[accountCount][passwordCount[accountCount]]);
    passwordCount[accountCount]++;
    accountCount++;
}

void viewAccount() {
    char account[MAXLENGTH];
    printf("Enter the account name: ");
    scanf("%s",account);

    int i;
    for(i=0;i<accountCount;i++) {
        if(strcmp(accounts[i],account) == 0) {
            int j;
            for(j=0;j<passwordCount[i];j++) {
                printf("Password %d: %s\n",j+1,passwords[i][j]);
            }
            return;
        }
    }

    printf("Error - Account not found\n");
}

int main() {
    int option;
    do {
        printf("Password Manager:\n");
        printf("1 - Add an account\n");
        printf("2 - View an account\n");
        printf("3 - Exit\n");
        printf("Enter an option: ");
        scanf("%d",&option);

        switch(option) {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while(option != 3);
    return 0;
}