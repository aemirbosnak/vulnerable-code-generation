//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

typedef struct{
    char name[50];
    char category[50];
    float amount;
    char date[20];
}Expense;

void addExpense(Expense *expenses, int *size){
    printf("Enter expense name: ");
    scanf("%s", expenses[*size].name);
    printf("Enter expense category: ");
    scanf("%s", expenses[*size].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*size].amount);
    strcpy(expenses[*size].date, "N/A");
    (*size)++;
}

void viewExpenses(Expense *expenses, int size){
    printf("\nExpense Details:\n");
    printf("--------------------\n");
    printf("Name\tCategory\tAmount\tDate\n");
    for(int i=0; i<size; i++){
        printf("%s\t%s\t%.2f\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void searchExpense(Expense *expenses, int size){
    char searchName[50];
    printf("\nEnter expense name to search: ");
    scanf("%s", searchName);
    for(int i=0; i<size; i++){
        if(strcmp(expenses[i].name, searchName) == 0){
            printf("\nExpense found:\n");
            printf("Name: %s\n", expenses[i].name);
            printf("Category: %s\n", expenses[i].category);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
        }
    }
}

void sortExpenses(Expense *expenses, int size, char sortType){
    if(sortType == 'n'){
        for(int i=0; i<size-1; i++){
            for(int j=i+1; j<size; j++){
                if(strcmp(expenses[i].name, expenses[j].name) > 0){
                    Expense temp = expenses[i];
                    expenses[i] = expenses[j];
                    expenses[j] = temp;
                }
            }
        }
    }
    else if(sortType == 'a'){
        for(int i=0; i<size-1; i++){
            for(int j=i+1; j<size; j++){
                if(expenses[i].amount > expenses[j].amount){
                    Expense temp = expenses[i];
                    expenses[i] = expenses[j];
                    expenses[j] = temp;
                }
            }
        }
    }
}

int main(){
    Expense expenses[MAX_SIZE];
    int size = 0;

    while(1){
        printf("\nEnter 1 to add expense\nEnter 2 to view expenses\nEnter 3 to search expense\nEnter 4 to sort expenses\nEnter 5 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addExpense(expenses, &size);
                break;
            case 2:
                viewExpenses(expenses, size);
                break;
            case 3:
                searchExpense(expenses, size);
                break;
            case 4:
                printf("\nEnter sort type (n for name, a for amount): ");
                char sortType;
                scanf("%c", &sortType);
                sortExpenses(expenses, size, sortType);
                printf("\nExpenses sorted successfully!\n");
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}