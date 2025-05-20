//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void display_menu();
void add_transaction(double amount, char* category);
void display_transactions();
void calculate_total_spent(char* category);

struct transaction {
    char* category;
    double amount;
};

// Global variables
int num_transactions = 0;
struct transaction transactions[100];

int main() {
    char choice;
    do {
        display_menu();
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                add_transaction(0, "");
                break;
            case '2':
                display_transactions();
                break;
            case '3':
                printf("Enter category: ");
                char category[50];
                scanf("%s", category);
                calculate_total_spent(category);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= '4');
    return 0;
}

void display_menu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add transaction\n");
    printf("2. Display transactions\n");
    printf("3. Calculate total spent in a category\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void add_transaction(double amount, char* category) {
    if(num_transactions >= 100) {
        printf("Maximum number of transactions reached\n");
        return;
    }
    transactions[num_transactions].category = (char*)malloc(strlen(category)+1);
    strcpy(transactions[num_transactions].category, category);
    transactions[num_transactions].amount = amount;
    num_transactions++;
}

void display_transactions() {
    if(num_transactions == 0) {
        printf("No transactions yet\n");
        return;
    }
    printf("\nTransactions:\n");
    for(int i=0; i<num_transactions; i++) {
        printf("%s: %.2f\n", transactions[i].category, transactions[i].amount);
    }
}

void calculate_total_spent(char* category) {
    double total = 0;
    int count = 0;
    for(int i=0; i<num_transactions; i++) {
        if(strcmp(transactions[i].category, category) == 0) {
            total += transactions[i].amount;
            count++;
        }
    }
    if(count == 0) {
        printf("No transactions in this category\n");
    } else {
        printf("Total spent in %s: %.2f\n", category, total);
    }
}