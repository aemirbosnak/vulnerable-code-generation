//FormAI DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
struct expense{
    char date[20];
    char item[50];
    int price;
}e[100];
int total_expense=0;
void add_expense(){
    int i,n;
    printf("Enter the number of expenses to be added: ");
    scanf("%d",&n);
    for(i=total_expense;i<total_expense+n;i++){
        printf("Enter the %d expense date in yyyy-mm-dd: ",i+1);
        scanf("%s",e[i].date);
        printf("Enter the %d expense item: ",i+1);
        scanf(" %[^\n]s",e[i].item);
        printf("Enter the %d expense price: ",i+1);
        scanf("%d",&e[i].price);
    }
    total_expense+=n;
    printf("%d expenses added successfully!\n",n);
    printf("Total expenses added: %d\n",total_expense);
}
void view_expense(){
    int i;
    if(total_expense==0){
        printf("No expenses added yet!\n");
        return;
    }
    printf("-------------------------------\n");
    printf("  DATE       |    ITEM   | PRICE \n");
    printf("-------------------------------\n");
    for(i=0;i<total_expense;i++){
        printf("%s  | %s  |  %d\n",e[i].date,e[i].item,e[i].price);
    }
    printf("-------------------------------\n");
    printf("Total Expenses: %d\n",total_expense);
}
void search_expense(){
    int flag=0,i;
    char key[20];
    if(total_expense==0){
        printf("No expenses added yet!\n");
        return;
    }
    printf("Enter the date (yyyy-mm-dd) to search: ");
    scanf("%s",key);
    printf("-------------------------------\n");
    printf("  DATE       |    ITEM   | PRICE \n");
    printf("-------------------------------\n");
    for(i=0;i<total_expense;i++){
        if(strcmp(e[i].date,key)==0){
            printf("%s  | %s  |  %d\n",e[i].date,e[i].item,e[i].price);
            flag=1;
        }
    }
    if(flag==0){
        printf("No expenses found for this date!\n");
    }
}
void delete_expense(){
    int flag=0,i,j;
    char key[20];
    if(total_expense==0){
        printf("No expenses added yet!\n");
        return;
    }
    printf("Enter the date (yyyy-mm-dd) to delete: ");
    scanf("%s",key);
    for(i=0,j=0;i<total_expense;i++){
        if(strcmp(e[i].date,key)==0){
            flag=1;
            continue;
        }
        e[j]=e[i];
        j++;
    }
    if(flag==0){
        printf("No expenses found for this date!\n");
    }
    else{
        total_expense--;
        printf("Expense deleted successfully!\n");
        printf("Total expenses: %d\n",total_expense);
    }
}
int main(){
    int choice;
    while(1){
        printf("\nEXPENSE TRACKER MENU\n");
        printf("--------------------\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Search Expense\n");
        printf("4. Delete Expense\n");
        printf("5. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_expense();
                    break;
            case 2: view_expense();
                    break;
            case 3: search_expense();
                    break;
            case 4: delete_expense();
                    break;
            case 5: printf("Goodbye!");
                    exit(0);
            default:printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}