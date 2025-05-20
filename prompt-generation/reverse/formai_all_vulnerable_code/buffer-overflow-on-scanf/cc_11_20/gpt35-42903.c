//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

struct password {
    char website[MAX_SIZE];
    char username[MAX_SIZE];
    char password[MAX_SIZE];
};

int main() {
    struct password accounts[MAX_SIZE];
    int num_accounts = 0;
    int option;

    do {
        printf("\nWelcome to Password Manager\n");
        printf("1. Add an account\n");
        printf("2. View all accounts\n");
        printf("3. Search an account\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                if (num_accounts == MAX_SIZE) {
                    printf("\nCannot add more accounts. Limit reached!\n");
                } else {
                    struct password new_account;
                    printf("\nEnter website name: ");
                    scanf("%s", new_account.website);
                    printf("Enter username: ");
                    scanf("%s", new_account.username);
                    printf("Enter password: ");
                    scanf("%s", new_account.password);

                    accounts[num_accounts] = new_account;
                    num_accounts++;

                    printf("\nAccount added!\n");
                }
                break;
            case 2:
                if (num_accounts == 0) {
                    printf("\nNo accounts found!\n");
                } else {
                    printf("\nWebsite\t\tUsername\t\tPassword\n");
                    for (int i = 0; i < num_accounts; i++) {
                        printf("%s\t\t%s\t\t%s\n", accounts[i].website, accounts[i].username, accounts[i].password);
                    }
                }
                break;
            case 3:
                if (num_accounts == 0) {
                    printf("\nNo accounts found!\n");
                } else {
                    char search_website[MAX_SIZE];
                    printf("\nEnter website name to search: ");
                    scanf("%s", search_website);

                    int found = 0;
                    for (int i = 0; i < num_accounts; i++) {
                        if (strcmp(accounts[i].website, search_website) == 0) {
                            printf("\nWebsite\t\tUsername\t\tPassword\n");
                            printf("%s\t\t%s\t\t%s\n", accounts[i].website, accounts[i].username, accounts[i].password);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nAccount not found!\n");
                    }
                }
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again!\n");
        }

    } while (option != 4);

    return 0;
}