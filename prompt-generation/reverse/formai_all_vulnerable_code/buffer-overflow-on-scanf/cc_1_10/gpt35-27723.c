//FormAI DATASET v1.0 Category: Expense Tracker ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct expense{
    char name[20];
    float cost;
    int day;
    char category[10];
}EXPENSE;

void display_menu(){
    printf("WELCOME TO EXPENSE TRACKER\n");
    printf("1. Add expense\n");
    printf("2. Display expenses\n");
    printf("3. Search expense\n");
    printf("4. Delete expense\n");
    printf("5. Quit\n");
}

void add_expense(EXPENSE *e){
    printf("Enter name of expense: ");
    scanf("%s",e->name);
    printf("Enter cost of expense: ");
    scanf("%f",&e->cost);
    printf("Enter day of expense: ");
    scanf("%d",&e->day);
    printf("Enter category of expense: ");
    scanf("%s",e->category);
    printf("Expense added!\n");
}

void display_expenses(EXPENSE *e,int count){
    if(count==0){
        printf("No expenses added yet!\n");
        return;
    }
    printf("Name | Cost | Day | Category\n");
    for(int i=0;i<count;i++){
        printf("%s | %.2f | %d | %s\n",e[i].name,e[i].cost,e[i].day,e[i].category);
    }
}

void search_expense(EXPENSE *e,int count){
    char query[20];
    printf("Enter name of expense to search: ");
    scanf("%s",query);
    for(int i=0;i<count;i++){
        if(strcmp(e[i].name,query)==0){
            printf("Name | Cost | Day | Category\n");
            printf("%s | %.2f | %d | %s\n",e[i].name,e[i].cost,e[i].day,e[i].category);
            return;
        }
    }
    printf("Expense not found!\n");
}

void delete_expense(EXPENSE *e,int *count){
    char query[20];
    printf("Enter name of expense to delete: ");
    scanf("%s",query);
    for(int i=0;i<*count;i++){
        if(strcmp(e[i].name,query)==0){
            *count=*count-1;
            for(int j=i;j<*count;j++){
                strcpy(e[j].name,e[j+1].name);
                e[j].cost=e[j+1].cost;
                e[j].day=e[j+1].day;
                strcpy(e[j].category,e[j+1].category);
            }
            printf("Expense deleted!\n");
            return;
        }
    }
    printf("Expense not found!\n");
}

int main(){
    printf("**Initializing Expense Tracker**\n");
    EXPENSE *e=(EXPENSE*)malloc(100*sizeof(EXPENSE));
    int choice=0,count=0;
    while(choice!=5){
        display_menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_expense(&e[count++]); break;
            case 2: display_expenses(e,count); break;
            case 3: search_expense(e,count); break;
            case 4: delete_expense(e,&count); break;
            case 5: printf("Thank you for using Expense Tracker!\n"); break;
            default: printf("Invalid choice!\n");
        }
    }
    free(e);
    return 0;
}