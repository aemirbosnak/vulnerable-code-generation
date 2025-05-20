//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>

struct Account {
    char name[50];
    int balance;
};

struct Menu {
    char name[50];
    int (*function)(void);
};

void menu_option_1(void) {
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Add expense:\n");
            char expense[50];
            scanf("%s", expense);
            struct Account account;
            account.name[0] = '\0';
            account.balance = 0;
            account.name[0] = '\0';
            strcpy(account.name, expense);
            printf("Expense added: %s\n", expense);
            break;
        case 2:
            printf("View expenses:\n");
            for(int i = 0; i < 5; i++) {
                printf("%d. %s - %d\n", i + 1, account.name, account.balance);
            }
            break;
        case 3:
            exit(0);
            break;
    }
}

void menu_option_2(void) {
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Add expense:\n");
            char expense[50];
            scanf("%s", expense);
            struct Account account;
            account.name[0] = '\0';
            account.balance = 0;
            account.name[0] = '\0';
            strcpy(account.name, expense);
            printf("Expense added: %s\n", expense);
            break;
        case 2:
            printf("View expenses:\n");
            for(int i = 0; i < 5; i++) {
                printf("%d. %s - %d\n", i + 1, account.name, account.balance);
            }
            break;
        case 3:
            exit(0);
            break;
    }
}

int main(void) {
    struct Menu menu[] = {
        {"Add expense", menu_option_1},
        {"View expenses", menu_option_2},
        {NULL, NULL}
    };

    int choice;
    while(1) {
        printf("Select an option:\n");
        for(int i = 0; menu[i].name[0]!= '\0'; i++) {
            printf("%d. %s\n", i + 1, menu[i].name);
        }

        scanf("%d", &choice);

        if(menu[choice - 1].function == NULL) {
            printf("Invalid option. Please try again.\n");
        } else {
            menu[choice - 1].function();
        }
    }
    return 0;
}