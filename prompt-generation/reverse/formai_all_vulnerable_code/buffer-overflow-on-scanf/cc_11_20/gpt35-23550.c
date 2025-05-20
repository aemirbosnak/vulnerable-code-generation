//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

struct Expense{
    int day;
    int month;
    int year;
    char category[20];
    float amount;
};

int main(){
    int num_expenses = 0;
    struct Expense expenses[MAX_EXPENSES];

    int option = 0;

    do{
        printf("\n\nEnter Option:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Search Expenses\n");
        printf("4. Exit\n\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nAdd Expense\n");
                printf("------------\n");

                if(num_expenses == MAX_EXPENSES){
                    printf("Cannot add more expenses. Maximum reached.\n");
                    break;
                }

                printf("Enter Date(dd/mm/yyyy): ");
                scanf("%d/%d/%d", &expenses[num_expenses].day,
                    &expenses[num_expenses].month,
                    &expenses[num_expenses].year);

                printf("Enter Category: ");
                scanf("%s", expenses[num_expenses].category);

                printf("Enter Amount: ");
                scanf("%f", &expenses[num_expenses].amount);

                num_expenses++;

                break;

            case 2:
                printf("\nView Expenses\n");
                printf("--------------\n");

                if(num_expenses == 0){
                    printf("No Expenses to display.\n");
                    break;
                }

                for(int i = 0; i < num_expenses; i++){
                    printf("%02d/%02d/%4d %-20s %8.2f\n", 
                        expenses[i].day,
                        expenses[i].month,
                        expenses[i].year,
                        expenses[i].category,
                        expenses[i].amount);
                }

                break;

            case 3:
                printf("\nSearch Expenses\n");
                printf("----------------\n");

                if(num_expenses == 0){
                    printf("No Expenses to search.\n");
                    break;
                }

                printf("Enter Search Category: ");
                char search_category[20];
                scanf("%s", search_category);

                float total_amount = 0.0;

                for(int i = 0; i < num_expenses; i++){
                    if(strcmp(expenses[i].category, search_category) == 0){
                        printf("%02d/%02d/%4d %-20s %8.2f\n", 
                            expenses[i].day,
                            expenses[i].month,
                            expenses[i].year,
                            expenses[i].category,
                            expenses[i].amount);

                        total_amount += expenses[i].amount;
                    }
                }

                printf("Total Amount: %8.2f\n", total_amount);

                break;

            case 4:
                printf("\nExiting Program.\n");
                break;

            default:
                printf("\nInvalid Option.\n");
        }

    }while(option != 4);

    return 0;
}