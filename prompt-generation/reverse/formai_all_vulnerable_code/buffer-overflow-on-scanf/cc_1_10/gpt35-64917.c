//FormAI DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//This is an Expense Tracker program to keep track of your expenses.

struct expense{
    char item[100];
    float price;
    char date[20];
};

void addExpense(struct expense* expenses, int count){
    printf("Enter item name: ");
    scanf(" %[^\n]", expenses[count].item);
    printf("Enter item price: ");
    scanf("%f", &expenses[count].price);
    printf("Enter date of purchase: ");
    scanf(" %[^\n]", expenses[count].date);
    printf("Expense added successfully!\n");
}

void displayExpenses(struct expense* expenses, int count){
    if(count == 0){
        printf("No expenses added yet!\n");
    }
    else{
        printf("Item\t\tPrice\t\tDate\n");
        printf("----------------------------------------------\n");
        for(int i=0; i<count; i++){
            printf("%s\t\t%.2f\t\t%s\n", expenses[i].item, expenses[i].price, expenses[i].date);
        }
    }
}

void deleteExpense(struct expense* expenses, int count){
    if(count == 0){
        printf("No expenses added yet!\n");
    }
    else{
        char item[100];
        printf("Enter item name to be deleted: ");
        scanf(" %[^\n]", item);
        for(int i=0; i<count; i++){
            if(strcmp(item, expenses[i].item) == 0){
                for(int j=i; j<count-1; j++){
                    expenses[j] = expenses[j+1];
                }
                printf("Expense deleted successfully!\n");
                return;
            }
        }
        printf("Item not found!\n");
    }
}

void searchExpense(struct expense* expenses, int count){
    if(count == 0){
        printf("No expenses added yet!\n");
    }
    else{
        char item[100];
        printf("Enter item name to be searched: ");
        scanf(" %[^\n]", item);
        for(int i=0; i<count; i++){
            if(strcmp(item, expenses[i].item) == 0){
                printf("Item\t\tPrice\t\tDate\n");
                printf("----------------------------------------------\n");
                printf("%s\t\t%.2f\t\t%s\n", expenses[i].item, expenses[i].price, expenses[i].date);
                return;
            }
        }
        printf("Item not found!\n");
    }
}

int main() {
    int option;
    int count = 0;
    struct expense expenses[100];
    do {
        printf("Expense Tracker Menu\n");
        printf("1. Add Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Search Expense\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addExpense(expenses, count);
                count++;
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                deleteExpense(expenses, count);
                count--;
                break;
            case 4:
                searchExpense(expenses, count);
                break;
            case 5:
                printf("Thank you for using Expense Tracker!\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 5);
    return 0;
}