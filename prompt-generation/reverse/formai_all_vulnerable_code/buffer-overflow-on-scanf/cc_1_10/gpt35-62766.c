//FormAI DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//Struct to store the expense records
struct ExpenseRecord {
    int id;
    double amount;
    char category[20];
    char description[100];
};

//Function to create a new expense record
struct ExpenseRecord createExpenseRecord(int id, double amount, char category[], char description[]){
    struct ExpenseRecord expense;
    expense.id = id;
    expense.amount = amount;
    strcpy(expense.category, category);
    strcpy(expense.description, description);
    return expense;
}

int main(){
    int numRecords = 0; //Variable to store the number of expense records
    struct ExpenseRecord* records = NULL; //Pointer to struct array of expense records

    //Welcome user to the Expense Tracker
    printf("Welcome to the Expense Tracker!\n");

    int option;
    do{
        //Present menu to user
        printf("\nMain Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Enter option: ");

        scanf("%d", &option);
        //Consume newline character from input stream
        while(getchar() != '\n');

        switch(option){
            case 1:{
                //Prompt user for details of new expense record
                printf("\nAdd Expense:\n");
                printf("Enter amount: ");
                double amount;
                scanf("%lf", &amount);
                while(getchar() != '\n');

                char category[20];
                printf("Enter category: ");
                scanf("%s", category);
                while(getchar() != '\n');

                char description[100];
                printf("Enter description: ");
                fgets(description, 100, stdin);
                //Remove newline character at end of description
                description[strcspn(description, "\n")] = 0;

                //Create new expense record and add to struct array
                records = (struct ExpenseRecord*) realloc(records, (++numRecords) * sizeof(struct ExpenseRecord));
                records[numRecords-1] = createExpenseRecord(numRecords, amount, category, description);

                printf("Expense added succesfully.\n");
                break;
            }
            case 2:{
                if(numRecords > 0){
                    //Present all expense records to user
                    printf("\nExpense Records:\n");
                    printf("%-5s%-15s%-20s%s\n", "ID", "Amount", "Category", "Description");
                    for(int i = 0; i < numRecords; i++){
                        printf("%-5d%-15.2lf%-20s%s\n", records[i].id, records[i].amount, records[i].category, records[i].description);
                    }
                }
                else{
                    printf("\nNo expense records found.\n");
                }
                break;
            }
            case 3:{
                //Prompt user for expense record ID to delete
                printf("\nDelete Expense:\n");
                printf("Enter ID of expense to delete: ");
                int id;
                scanf("%d", &id);

                int found = 0; //Flag to indicate if expense record with given ID was found
                for(int i = 0; i < numRecords; i++){
                    if(records[i].id == id){
                        found = 1;
                        //Shift all subsequent expense records one position to the left
                        for(int j = i; j < numRecords-1; j++){
                            records[j] = records[j+1];
                            records[j].id -= 1;
                        }
                        numRecords--;
                        printf("Expense record with ID %d deleted successfully.\n", id);
                        break;
                    }
                }
                if(!found){
                    printf("Expense record with ID %d not found.\n", id);
                }
                break;
            }
            case 4:{
                printf("\nThank you for using the Expense Tracker!\n");
                break;
            }
            default:{
                printf("\nInvalid option entered.\n");
            }
        }
    }while(option != 4);

    free(records); //Free dynamically allocated memory

    return 0;
}