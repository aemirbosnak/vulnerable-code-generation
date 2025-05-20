//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: excited
// Personal Finance Planner
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction {
    char type;
    double amount;
};

struct Budget {
    double income;
    double expenses[5];
    double savings[5];
};

struct Person {
    char name[50];
    struct Budget budget;
    struct Transaction transactions[100];
    int num_transactions;
};

void print_menu() {
    printf("Welcome to the personal finance planner!\n");
    printf("Please choose an option:\n");
    printf("1. Add transaction\n");
    printf("2. View transactions\n");
    printf("3. Update budget\n");
    printf("4. Calculate savings\n");
    printf("5. Exit\n");
}

void add_transaction(struct Person *person) {
    struct Transaction transaction;
    printf("Enter transaction type (I/E): ");
    scanf("%c", &transaction.type);
    printf("Enter transaction amount: ");
    scanf("%lf", &transaction.amount);
    person->transactions[person->num_transactions] = transaction;
    person->num_transactions++;
}

void view_transactions(struct Person *person) {
    int i;
    for (i = 0; i < person->num_transactions; i++) {
        printf("Transaction %d: %c %f\n", i, person->transactions[i].type, person->transactions[i].amount);
    }
}

void update_budget(struct Person *person) {
    printf("Enter new income: ");
    scanf("%lf", &person->budget.income);
    printf("Enter new expenses: ");
    for (int i = 0; i < 5; i++) {
        scanf("%lf", &person->budget.expenses[i]);
    }
    printf("Enter new savings: ");
    for (int i = 0; i < 5; i++) {
        scanf("%lf", &person->budget.savings[i]);
    }
}

void calculate_savings(struct Person *person) {
    double savings = 0;
    for (int i = 0; i < 5; i++) {
        savings += person->budget.savings[i];
    }
    printf("Savings: %f\n", savings);
}

int main() {
    struct Person person;
    int choice;
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    strcpy(person.name, name);
    print_menu();
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_transaction(&person);
                break;
            case 2:
                view_transactions(&person);
                break;
            case 3:
                update_budget(&person);
                break;
            case 4:
                calculate_savings(&person);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
        print_menu();
    }
    return 0;
}