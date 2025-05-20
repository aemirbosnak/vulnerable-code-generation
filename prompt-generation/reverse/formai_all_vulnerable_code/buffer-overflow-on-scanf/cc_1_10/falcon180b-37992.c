//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

#define MAX_EXPENSES 100

typedef struct expense{
    char category[50];
    char description[100];
    double amount;
    time_t date;
}Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(){
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);
    time_t now = time(NULL);
    expenses[num_expenses].date = now;
    num_expenses++;
}

void view_expenses(){
    printf("Expense ID\tCategory\tDescription\tAmount\tDate\n");
    for(int i=0; i<num_expenses; i++){
        printf("%d\t%s\t%s\t%.2lf\t%s\n", i+1, expenses[i].category, expenses[i].description, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void search_expense(){
    char search_category[50];
    printf("Enter expense category to search: ");
    scanf("%s", search_category);
    for(int i=0; i<num_expenses; i++){
        if(strcmp(expenses[i].category, search_category) == 0){
            printf("Expense found:\n");
            printf("ID: %d\n", i+1);
            printf("Category: %s\n", expenses[i].category);
            printf("Description: %s\n", expenses[i].description);
            printf("Amount: $%.2lf\n", expenses[i].amount);
            printf("Date: %s\n", ctime(&expenses[i].date));
        }
    }
}

int main(){
    srand(time(NULL));
    int choice;
    do{
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(choice!= 4);
    return 0;
}