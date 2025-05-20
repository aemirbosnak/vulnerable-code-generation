//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include<stdio.h>
#include<stdlib.h>

//Structure to hold the details of a finance entity
struct financeEntity{
    char name[20];
    float income, expense, totalIncome, totalExpense;
};

//Function to display the menu
int displayMenu(){
    int choice;
    printf("\n---- Personal Finance Planner ----\n\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Income\n");
    printf("4. View Expense\n");
    printf("5. View Balance\n");
    printf("6. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    return choice;
}

int main(){
    int choice, numEntities = 0, i;
    float totalIncome = 0, totalExpense = 0;

    struct financeEntity *entities = (struct financeEntity*) malloc(sizeof(struct financeEntity)*10);

    if(entities == NULL){
        printf("Memory allocation error\n");
        return 0;
    }

    //Main loop to get the user's input
    while(1){
        choice = displayMenu();

        switch(choice){
            case 1:
                printf("\nEnter the name of the income source: ");
                scanf("%s",entities[numEntities].name);
                printf("Enter the income amount: ");
                scanf("%f",&entities[numEntities].income);
                entities[numEntities].totalIncome = totalIncome + entities[numEntities].income;
                totalIncome = entities[numEntities].totalIncome;
                printf("<%s> income added successfully.\n",entities[numEntities].name);
                numEntities++;
                break;

            case 2:
                printf("\nEnter the name of the expense: ");
                scanf("%s",entities[numEntities].name);
                printf("Enter the expense amount: ");
                scanf("%f",&entities[numEntities].expense);
                entities[numEntities].totalExpense = totalExpense + entities[numEntities].expense;
                totalExpense = entities[numEntities].totalExpense;
                numEntities++;
                printf("<%s> expense added successfully.\n",entities[numEntities].name);
                break;

            case 3:
                printf("\nIncome:\n");
                printf("Name\t\tAmount\n");
                for(i=0;i<numEntities;i++){
                    if(entities[i].income != 0){
                        printf("%-20s\t%.2f\n",entities[i].name, entities[i].income);
                    }
                }
                printf("\nTotal Income: %.2f\n",totalIncome);
                break;

            case 4:
                printf("\nExpense:\n");
                printf("Name\t\tAmount\n");
                for(i=0;i<numEntities;i++){
                    if(entities[i].expense != 0){
                        printf("%-20s\t%.2f\n",entities[i].name, entities[i].expense);
                    }
                }
                printf("\nTotal Expense: %.2f\n",totalExpense);
                break;

            case 5:
                printf("\nBalance:\n");
                printf("Total Income: %.2f\n",totalIncome);
                printf("Total Expense: %.2f\n",totalExpense);
                printf("Balance: %.2f\n",totalIncome - totalExpense);
                break;

            case 6:
                printf("\nExiting the program...\n");
                free(entities);
                return 0;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}