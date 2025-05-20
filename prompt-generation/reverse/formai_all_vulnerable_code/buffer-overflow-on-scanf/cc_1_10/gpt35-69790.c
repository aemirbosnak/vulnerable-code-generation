//FormAI DATASET v1.0 Category: Expense Tracker ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct transaction {
    int id;
    char date[20];
    char description[50];
    float amount;
};

void create_transaction(struct transaction *trans, int id) {
    trans->id = id;
    printf("Enter date of transaction (DD/MM/YYYY): ");
    scanf("%s", trans->date);
    printf("Enter description of transaction: ");
    scanf(" %[^\n]s", trans->description);
    printf("Enter amount: ");
    scanf("%f", &trans->amount);
}

void display_transaction(struct transaction trans) {
    printf("%-4d%-15s%-30s%-10.2f\n", trans.id, trans.date, trans.description, trans.amount);
}

char* get_month(char* date) {
    char* token = strtok(date, "/");
    int count = 0;
    while(token != NULL && count < 2) {
        token = strtok(NULL, "/");
        count++;
    }
    return token;
}

int main() {
    int option, id, count=0;
    float total_amount=0;
    struct transaction transactions[1000];
    printf("Welcome to Expense Tracker\n");
    do {
        printf("\n1. Add Transaction\n2. Display Transactions\n3. Monthly Expenses\n4. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Enter ID for new transaction: ");
                scanf("%d", &id);
                create_transaction(&transactions[count], id);
                total_amount += transactions[count].amount;
                count++;
                break;
            case 2:
                printf("ID   Date          Description                   Amount\n");
                printf("------------------------------------------------------------\n");
                for(int i=0; i<count; i++) {
                    display_transaction(transactions[i]);
                }
                printf("\nTotal Expenses: %.2f\n", total_amount);
                break;
            case 3:
                printf("Enter month (MM): ");
                char month[3];
                scanf("%s", month);
                printf("\nID   Date          Description                   Amount\n");
                printf("------------------------------------------------------------\n");
                for(int i=0; i<count; i++) {
                    if(strcmp(get_month(transactions[i].date), month) == 0) {
                        display_transaction(transactions[i]);
                    }
                }
                break;
            case 4:
                printf("Thank you for using Expense Tracker\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while(option != 4);
    return 0;
}