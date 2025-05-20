//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    double balance;
} account;

void add_account(account *list, int size, char *name, double balance) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            list[i].balance += balance;
            return;
        }
    }
    strcpy(list[size].name, name);
    list[size].balance = balance;
    size++;
}

void display_accounts(account *list, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s: $%.2f\n", list[i].name, list[i].balance);
    }
}

int main() {
    account list[100];
    int size = 0;
    char input[100];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            printf("Enter account name: ");
            scanf("%s", input);
            printf("Enter account balance: ");
            scanf("%lf", &list[size].balance);
            strcpy(list[size].name, input);
            size++;
        } else if (strcmp(input, "display") == 0) {
            display_accounts(list, size);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}