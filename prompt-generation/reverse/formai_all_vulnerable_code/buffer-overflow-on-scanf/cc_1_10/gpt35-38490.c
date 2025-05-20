//FormAI DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

//create a structure to hold expense data
struct expenses{
    char expense_name[50];
    int expense_amount;
};

int main(){

    int total_expenses = 0;
    int choice = 0;
    int i;

    printf("================== WELCOME TO EXPENSE TRACKER ==================\n\n");

    printf("SELECT YOUR CHOICE\n");
    printf("1. ADD EXPENSE\n");
    printf("2. DISPLAY EXPENSES\n");
    printf("3. EXIT\n");

    //create an array of 100 expenses
    struct expenses expense_list[100];

    //while loop for user interaction
    while(choice != 3){

        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("\nENTER EXPENSE NAME: ");
                scanf("%s", &expense_list[total_expenses].expense_name);

                printf("\nENTER EXPENSE AMOUNT: ");
                scanf("%d", &expense_list[total_expenses].expense_amount);

                total_expenses++;

                break;

            case 2:
                printf("\n================== EXPENSE LIST ==================\n\n");

                for(i = 0; i < total_expenses; i++){
                    printf("%s\t%d\n", expense_list[i].expense_name, expense_list[i].expense_amount);
                }

                break;

            case 3:
                printf("\n================== GOODBYE ==================\n\n");

                break;

            default:
                printf("\nINVALID CHOICE, PLEASE ENTER A VALID CHOICE\n");

                break;
        }

    }

    return 0;
}