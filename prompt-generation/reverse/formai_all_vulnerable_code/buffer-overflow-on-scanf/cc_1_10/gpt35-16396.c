//FormAI DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void surrealExpenses(){
    printf("Welcome to the Surreal Expense Tracker!\n");
    printf("Where the impossible becomes possible!\n");

    while(1){
        printf("\nAvailable options:\n");
        printf("1. Record expense\n");
        printf("2. View expenses\n");
        printf("3. Get random expense\n");
        printf("4. Exit\n");
        printf("Please choose an option: ");

        int option;
        scanf("%d", &option);

        if(option == 1){
            printf("\nEnter the amount: ");
            float amount;
            scanf("%f", &amount);
            printf("Enter the description: ");
            char description[50];
            scanf("%s", description);
            printf("\nExpense recorded successfully!\n");
        }
        else if(option == 2){
            printf("\nExpense list:\n");
            printf("Amount \t Description\n");
            int counter = 1;
            for(int i = 0; i < 10; i++){
                float amount = rand() % 1000;
                char description[50];
                for(int j = 0; j < 5; j++){
                    description[j] = rand() % 26 + 97;
                }
                printf("%.2f \t %s\n", amount, description);
            }
        }
        else if(option == 3){
            printf("\nRandom expense:\n");
            float amount = rand() % 1000;
            char description[50];
            for(int j = 0; j < 5; j++){
                description[j] = rand() % 26 + 97;
            }
            printf("%.2f \t %s\n", amount, description);
        }
        else if(option == 4){
            printf("\nGoodbye!\n");
            exit(0);
        }
        else{
            printf("\nInvalid option. Please try again.\n");
        }
    }
}

int main(){
    srand(time(NULL)); //initialize random seed

    surrealExpenses(); //start expense tracker
    return 0;
}