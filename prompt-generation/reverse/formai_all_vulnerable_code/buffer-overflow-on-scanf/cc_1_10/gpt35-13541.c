//FormAI DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to add new expense to the record
void addExpense(int *count, float *expenses, char (*category)[20], char (*description)[100]) {
    printf("Enter Category: ");
    scanf("%s", category[*count]);
    printf("Enter Description: ");
    scanf("%s", description[*count]);
    printf("Enter Expense Amount: ");
    scanf("%f", &expenses[*count]);
    *count += 1;
    printf("Expense added successfully.\n");
}

// function to display all recorded expenses
void displayExpenses(int count, float *expenses, char (*category)[20], char (*description)[100]){
    printf("No.\tCategory\tDescription\tAmount\n");
    for(int i=0; i<count; i++){
        printf("%d\t%s\t\t%s\t\t%.2f\n", i+1, category[i], description[i], expenses[i]);
    }
}

// function to calculate total expense
float calculateTotal(int count, float *expenses){
    float total = 0;
    for(int i=0; i<count; i++){
        total += expenses[i];
    }
    return total;
}

// function to display expense summary by category
void displayByCategory(int count, float *expenses, char (*category)[20]){
    float totalFood = 0, totalTravel = 0, totalEntertainment = 0, totalOther = 0;
    for(int i=0; i<count; i++){
        if(strcmp(category[i], "Food") == 0){
            totalFood += expenses[i];
        }
        else if(strcmp(category[i], "Travel") == 0){
            totalTravel += expenses[i];
        }
        else if(strcmp(category[i], "Entertainment") == 0){
            totalEntertainment += expenses[i];
        }
        else{
            totalOther += expenses[i];
        }
    }
    printf("Expense Summary by Category\n");
    printf("Category\tAmount\n");
    printf("Food\t\t%.2f\n", totalFood);
    printf("Travel\t\t%.2f\n", totalTravel);
    printf("Entertainment\t%.2f\n", totalEntertainment);
    printf("Other\t\t%.2f\n", totalOther);
}

int main(){
    int option, count=0;
    float expenses[50];
    char category[50][20], description[50][100];

    while(1){
        printf("Expense Tracker\n");
        printf("----------------\n");
        printf("1. Add New Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Calculate Total Expense\n");
        printf("4. Display Expense Summary by Category\n");
        printf("5. Exit\n");
        printf("Enter Option: ");
        
        scanf("%d", &option);

        switch (option){
            case 1:
                addExpense(&count, expenses, category, description);
                break;
            
            case 2:
                displayExpenses(count, expenses, category, description);
                break;
            
            case 3:
                printf("Total Expense: %.2f\n", calculateTotal(count, expenses));
                break;
            
            case 4:
                displayByCategory(count, expenses, category);
                break;
            
            case 5:
                exit(0);
                break;
            
            default:
                printf("Invalid Option selected. Please try again.\n");
                break;
        }
    }

    return 0;
}