//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transaction{
    int type; // 0 - expense, 1 - income
    char category[20];
    float amount;
    char note[50];
};

struct date{
    int day, month, year;
};

struct finance{
    char name[50];
    char email[50];
    struct date dob;
    float balance;
    int num_transactions;
    struct transaction transactions[100];
};

void display_menu(){
    printf("==== Personal Finance Planner ====\n");
    printf("1. Add transaction\n");
    printf("2. View transactions\n");
    printf("3. View balance\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void add_transaction(struct finance *f){
    printf("Enter transaction type (0 - expense, 1 - income): ");
    scanf("%d", &f->transactions[f->num_transactions].type);
    printf("Enter category: ");
    scanf("%s", f->transactions[f->num_transactions].category);
    printf("Enter amount: ");
    scanf("%f", &f->transactions[f->num_transactions].amount);
    printf("Enter note: ");
    scanf("%s", f->transactions[f->num_transactions].note);
    printf("Transaction added successfully!\n");
    f->num_transactions++;
    f->balance += f->transactions[f->num_transactions-1].amount;
}

void view_transactions(struct finance f){
    printf("==== Transactions ====\n");
    for(int i=0; i<f.num_transactions; i++){
        printf("%d. ", i+1);
        printf("Type: %s, ", f.transactions[i].type == 0 ? "expense" : "income");
        printf("Category: %s, ", f.transactions[i].category);
        printf("Amount: $%.2f, ", f.transactions[i].amount);
        printf("Note: %s\n", f.transactions[i].note);
    }
}

void view_balance(struct finance f){
    printf("==== Balance ====\n");
    printf("Name: %s\n", f.name);
    printf("Email: %s\n", f.email);
    printf("Date of birth: %d/%d/%d\n", f.dob.day, f.dob.month, f.dob.year);
    printf("Balance: $%.2f\n", f.balance);
}

int main(){
    struct finance f;
    printf("Welcome to Personal Finance Planner!\n");
    printf("Please enter your name: ");
    scanf("%s", f.name);
    printf("Please enter your email: ");
    scanf("%s", f.email);
    printf("Please enter your date of birth (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &f.dob.day, &f.dob.month, &f.dob.year);
    f.balance = 0;
    f.num_transactions = 0;
    int choice;
    do{
        display_menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_transaction(&f);
                break;
            case 2:
                view_transactions(f);
                break;
            case 3:
                view_balance(f);
                break;
            case 4:
                printf("Thank you for using Personal Finance Planner!");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }while(1);
    return 0;
}