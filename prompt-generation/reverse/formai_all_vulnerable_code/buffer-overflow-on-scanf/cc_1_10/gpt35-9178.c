//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define a structure to store expense details
struct Expense{
    char type[20];
    float amount;
    char date[15];
};

int main(){
    FILE *fptr; //file pointer variable
    struct Expense expense; //create an instance of the structure
    char choice; //variable to store user input
    float total = 0; //variable to track total expenses

    //open expense file in append mode
    fptr = fopen("expenses.dat", "ab");
    if(fptr == NULL){
        printf("Error: Unable to open file.");
        exit(1);
    }

    //print the title and header for the expense tracker
    printf("------Expense Tracker------\n\n");
    printf("| %-20s| %-10s| %-15s|\n", "Type", "Amount", "Date");
    printf("-----------------------------------------\n");

    //loop to add expense details
    do{
        printf("\nEnter expense type: ");
        scanf("%s", expense.type);
        printf("Enter expense amount: ");
        scanf("%f", &expense.amount);
        printf("Enter expense date (dd/mm/yyyy): ");
        scanf("%s", expense.date);

        //write the expense details to the file
        fwrite(&expense, sizeof(expense), 1, fptr);

        //add expense amount to total
        total += expense.amount;

        printf("\nDo you want to add another expense? (Y/N): ");
        scanf(" %c", &choice);
    }while(choice == 'Y' || choice == 'y');

    //close the file
    fclose(fptr);

    //open expense file in read mode
    fptr = fopen("expenses.dat", "rb");
    if(fptr == NULL){
        printf("Error: Unable to open file.");
        exit(1);
    }

    //print the expenses read from the file
    while(fread(&expense, sizeof(expense), 1, fptr) == 1){
        printf("| %-20s| %-10.2f| %-15s|\n", expense.type, expense.amount, expense.date);
        printf("-----------------------------------------\n");
    }

    //close the file
    fclose(fptr);

    //print the total expenses
    printf("\nTotal expenses: %.2f", total);

    return 0;
}