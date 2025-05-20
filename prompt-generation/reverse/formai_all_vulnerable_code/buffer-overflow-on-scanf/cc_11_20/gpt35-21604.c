//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[50];
    int account_no;
    float balance;
};

int main() {
    struct account account_list[100];
    int count = 0;
    char name[50];
    int account_no;
    float balance;
    int option;
    int i;

    while (1) {
        printf("Welcome to the banking record system\n");
        printf("1. Add account\n2. Search account\n3. Update account\n4. Delete account\n5. List all accounts\n6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter account no.: ");
                scanf("%d", &account_no);
                printf("Enter balance: ");
                scanf("%f", &balance);
                strcpy(account_list[count].name, name);
                account_list[count].account_no = account_no;
                account_list[count].balance = balance;
                count++;
                printf("Account added successfully!\n");
                break;
            case 2:
                printf("Enter account no.: ");
                scanf("%d", &account_no);
                for (i = 0; i < count; i++) {
                    if (account_list[i].account_no == account_no) {
                        printf("Name: %s\nAccount no.: %d\nBalance: %.2f\n", account_list[i].name, account_list[i].account_no, account_list[i].balance);
                        break;
                    }
                }
                if (i == count) {
                    printf("Account not found!\n");
                }
                break;
            case 3:
                printf("Enter account no.: ");
                scanf("%d", &account_no);
                for (i = 0; i < count; i++) {
                    if (account_list[i].account_no == account_no) {
                        printf("Enter new balance: ");
                        scanf("%f", &balance);
                        account_list[i].balance = balance;
                        printf("Account updated successfully!\n");
                        break;
                    }
                }
                if (i == count) {
                    printf("Account not found!\n");
                }
                break;
            case 4:
                printf("Enter account no.: ");
                scanf("%d", &account_no);
                for (i = 0; i < count; i++) {
                    if (account_list[i].account_no == account_no) {
                        strcpy(account_list[i].name, account_list[count-1].name);
                        account_list[i].account_no = account_list[count-1].account_no;
                        account_list[i].balance = account_list[count-1].balance;
                        count--;
                        printf("Account deleted successfully!\n");
                        break;
                    }
                }
                if (i == count) {
                    printf("Account not found!\n");
                }
                break;
            case 5:
                for (i = 0; i < count; i++) {
                    printf("Name: %s\nAccount no.: %d\nBalance: %.2f\n", account_list[i].name, account_list[i].account_no, account_list[i].balance);
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}