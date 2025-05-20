//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_CATEGORIES 50
#define MAX_ITEMS 100
#define MAX_EXPENSES 1000

struct category{
    char name[50];
    int expenses_count;
};

struct expense{
    char name[50];
    char category[50];
    int amount;
    time_t date;
};

int main(){
    struct category categories[MAX_CATEGORIES];
    int categories_count=0;
    struct expense expenses[MAX_EXPENSES];
    int expenses_count=0;
    int quit=0;

    while(!quit){
        printf("\nExpense Tracker\n");
        printf("1. Add Category\n2. Add Expense\n3. View Expenses\n4. Quit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter Category Name: ");
                char category_name[50];
                scanf("%s",category_name);
                for(int i=0;i<categories_count;i++){
                    if(strcmp(category_name,categories[i].name)==0){
                        printf("Category already exists\n");
                        break;
                    }
                }
                strcpy(categories[categories_count].name,category_name);
                categories[categories_count].expenses_count=0;
                categories_count++;
                printf("Category added successfully\n");
                break;
            }
            case 2:{
                printf("Enter Expense Name: ");
                char expense_name[50];
                scanf("%s",expense_name);
                printf("Enter Category: ");
                char expense_category[50];
                scanf("%s",expense_category);
                for(int i=0;i<categories_count;i++){
                    if(strcmp(expense_category,categories[i].name)==0){
                        strcpy(expenses[expenses_count].category,categories[i].name);
                        expenses_count++;
                        printf("Expense added successfully\n");
                        break;
                    }
                }
                if(expenses_count==MAX_EXPENSES){
                    printf("Maximum number of expenses reached\n");
                }
                break;
            }
            case 3:{
                printf("\nExpenses\n");
                for(int i=0;i<expenses_count;i++){
                    printf("%s - %s - %d - %s\n",expenses[i].name,expenses[i].category,expenses[i].amount,ctime(&expenses[i].date));
                }
                break;
            }
            case 4:{
                printf("Thank you for using Expense Tracker\n");
                quit=1;
                break;
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}