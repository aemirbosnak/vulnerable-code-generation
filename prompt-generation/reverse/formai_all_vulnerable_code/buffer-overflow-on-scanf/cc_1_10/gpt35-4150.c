//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FinancialEntry {
    char title[100];
    float amount;
    int type;
};

typedef struct FinancialEntry FinancialEntry;

void printOptions(){
    printf("Select an option below:\n");
    printf("1 - Add Income\n");
    printf("2 - Add Expense\n");
    printf("3 - View Financial Report\n");
    printf("4 - Exit\n");
}

int getOption(){
    int option = 0;
    printf("Enter your option: ");
    scanf("%d", &option);
    return option;
}

void addEntry(FinancialEntry* entries, int* counter, char* title, float amount, int type){
    FinancialEntry newEntry;
    strcpy(newEntry.title, title);
    newEntry.amount = amount;
    newEntry.type = type;
    
    entries[(*counter)] = newEntry;
    (*counter)++;
    printf("Entry added successfully!\n");
}

void viewReport(FinancialEntry* entries, int counter){
    float totalIncome = 0;
    float totalExpenses = 0;
    
    printf("\n");
    printf("-------------------------------------------------------\n");
    printf("                         REPORT                          \n");
    printf("-------------------------------------------------------\n");
    printf(" Title                         |   Type   |    Amount   \n");
    printf("-------------------------------------------------------\n");
    for(int i=0; i<counter; i++){
        printf(" %-30s |", entries[i].title);
        if(entries[i].type==1){
            printf(" Income  |");
            totalIncome += entries[i].amount;
        }else{
            printf(" Expense |");
            totalExpenses += entries[i].amount;
        }
        printf(" $ %.2f\n", entries[i].amount);
    }
    printf("-------------------------------------------------------\n");
    printf(" Total Income: $ %.2f\n", totalIncome);
    printf(" Total Expenses: $ %.2f\n", totalExpenses);
    printf(" Net Income: $ %.2f\n", totalIncome - totalExpenses);
    printf("-------------------------------------------------------\n");
    printf("\n");
}

int main(){
    int option = 0;
    FinancialEntry entries[100];
    int counter = 0;
    
    while(option != 4){
        printOptions();
        option = getOption();

        switch(option){
            case 1:{
                char title[100];
                float amount = 0;
                printf("Enter the title of the income: ");
                scanf(" %[^\n]s", title);
                printf("Enter the amount of the income: ");
                scanf("%f", &amount);
                addEntry(entries, &counter, title, amount, 1);
                break;
            }
            case 2:{
                char title[100];
                float amount = 0;
                printf("Enter the title of the expense: ");
                scanf(" %[^\n]s", title);
                printf("Enter the amount of the expense: ");
                scanf("%f", &amount);
                addEntry(entries, &counter, title, amount, 2);
                break;
            }
            case 3:{
                viewReport(entries, counter);
                break;
            }
            case 4:{
                printf("Exiting program...\n");
                break;
            }
            default:{
                printf("Invalid option, please select a valid one.\n");
                break;
            }
        }

    }
    return 0;
}