//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int amount;
    char category[50];
} transaction;

void add_transaction(transaction* t, int size, char* name, char* category, int amount) {
    strcpy(t[size].name, name);
    strcpy(t[size].category, category);
    t[size].amount = amount;
}

void display_transactions(transaction* t, int size) {
    printf("Transaction\tCategory\tAmount\n");
    for(int i=0; i<size; i++) {
        printf("%s\t%s\t%d\n", t[i].name, t[i].category, t[i].amount);
    }
}

int main() {
    transaction t[MAX_SIZE];
    int size=0;

    char ch;

    do {
        printf("\n1. Add Transaction\n2. Display Transactions\n3. Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: {
                char name[50];
                char category[50];
                int amount;

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter category: ");
                scanf("%s", category);

                printf("Enter amount: ");
                scanf("%d", &amount);

                add_transaction(t, size, name, category, amount);
                size++;

                break;
            }

            case 2: {
                display_transactions(t, size);

                break;
            }

            case 3: {
                exit(0);

                break;
            }

            default: {
                printf("Invalid choice\n");
            }
        }

    } while(1);

    return 0;
}