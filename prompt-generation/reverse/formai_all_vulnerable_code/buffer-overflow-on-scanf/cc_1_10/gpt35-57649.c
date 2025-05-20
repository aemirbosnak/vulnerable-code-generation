//FormAI DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Expense {
    char category[20];
    float amount;
    char date[20];  
    struct Expense *next;
};

typedef struct Expense expense;

expense *head = NULL;

void addExpense(char category[20], float amount, char date[20]){
    expense *new_expense = (expense*)malloc(sizeof(expense));
    strcpy(new_expense->category, category);
    new_expense->amount = amount;
    strcpy(new_expense->date, date);
    new_expense->next = head;
    head = new_expense;
}

void viewExpense(){
    expense *ptr = head;
    printf("\n%-20s%-20s%-20s\n", "Category", "Amount", "Date");
    while(ptr != NULL){
        printf("%-20s%-20.2f%-20s\n", ptr->category, ptr->amount, ptr->date);
        ptr = ptr->next;
    }
}

void searchExpense(char date[20]){
    expense *ptr = head;
    int found = 0;
    printf("\n%-20s%-20s%-20s\n", "Category", "Amount", "Date");
    while(ptr != NULL){
        if(strcmp(ptr->date, date) == 0){
            printf("%-20s%-20.2f%-20s\n", ptr->category, ptr->amount, ptr->date);
            found = 1;
        }
        ptr = ptr->next;
    }
    if(found == 0){
        printf("\nNo expense on this date!\n");
    }
}

void deleteExpense(char date[20]){
    expense *ptr = head, *prev = NULL;
    int found = 0; 
    while(ptr != NULL){
        if(strcmp(ptr->date, date) == 0){
            if(prev == NULL){
                head = ptr->next;
                free(ptr);
            }else{
                prev->next = ptr->next;
                free(ptr);
            }
            found = 1;
            printf("\nExpense deleted successfully!\n");
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if(found == 0){
        printf("\nNo expense on this date to delete!\n");
    }
}

int main(){
    int choice;
    char category[20], date[20];
    float amount;
    while(1){
        printf("\n------Expense Tracker------\n");
        printf("\n1. Add Expense\n2. View Expenses\n3. Search Expense\n4. Delete Expense\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("\nEnter category: ");
                scanf("%s", category);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter date(dd/mm/yyyy): ");
                scanf("%s", date);
                addExpense(category, amount, date);
                printf("\nExpense added successfully!\n");
                break;
            }
            case 2:{
                viewExpense();
                break;
            }
            case 3:{
                printf("\nEnter date to search expense(dd/mm/yyyy): ");
                scanf("%s", date);
                searchExpense(date);
                break;
            }
            case 4:{
                printf("\nEnter date to delete expense(dd/mm/yyyy): ");
                scanf("%s", date);
                deleteExpense(date);
                break;
            }
            case 5:{
                exit(0);
            }
            default:{
                printf("\nInvalid choice!\n");
                break;
            }
        }
    }
    return 0;
}