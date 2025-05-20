//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100 //Maximum number of expenses to be stored

//Structure to store the expense details
struct Expense {
    char category[20];
    float amount;
    char date[15];
} Exp[MAX]; 

//Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Function to show the menu
void showMenu() {
    printf("---------------------------------------\n");
    printf("------------Expense Tracker------------\n");
    printf("---------------------------------------\n\n");
    printf("---Please select an option:---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Search Expenses\n");
    printf("4. Delete All Expenses\n");
    printf("0. Exit\n\n");
    printf("Option: ");
}

//Function to add new expense
void addExpense() {
    printf("---------------------------------------\n");
    printf("------------Expense Tracker------------\n");
    printf("---------------------------------------\n\n");
    
    char category[20], date[15];
    float amount;
    int i = 0, j;
    
    printf("---Add Expense Details---\n\n");
    
    //Get category of expense
    printf("Expense category (up to 20 characters): ");
    fgets(category, 20, stdin);
    strcpy(Exp[i].category, category);
    
    //Get amount of expense
    while (1) {
        char amountStr[15];
        printf("Expense amount: ");
        fgets(amountStr, 15, stdin);
        if (sscanf(amountStr, "%f", &amount) == 1 && amount > 0) {
            Exp[i].amount = amount;
            break;
        } else {
            printf("Invalid input. Enter amount again.\n");
        }
        clearInputBuffer();
    }
    
    //Get date of expense
    printf("Date (dd-mm-yyyy): ");
    fgets(date, 15, stdin);
    strcpy(Exp[i].date, date);
    
    printf("\n---Expense Added Successfully---\n\n");
    
    //Clear input buffer
    clearInputBuffer();
}

//Function to view all expenses
void viewExpenses() {
    printf("---------------------------------------\n");
    printf("------------Expense Tracker------------\n");
    printf("---------------------------------------\n\n");
    
    int i;
    
    printf("---All Expenses---\n\n");
    
    if (Exp[0].amount == 0) {
        printf("No expenses found.\n");
        return;
    }
    
    //Print table header
    printf("#  Category              Amount        Date\n");
    printf("--------------------------------------------------\n");
    
    for (i = 0; i < MAX; i++) {
        if (Exp[i].amount != 0) {
            printf("%d. %-20s %.2f        %s\n", i+1, Exp[i].category, Exp[i].amount, Exp[i].date);
        }
    }
}

//Function to search expenses
void searchExpenses() {
    printf("---------------------------------------\n");
    printf("------------Expense Tracker------------\n");
    printf("---------------------------------------\n\n");
    
    char category[20];
    int i;
    float amount;
    char date[15];
    int found = 0;
    
    printf("---Search Expenses---\n\n");
    
    //Get search criteria
    printf("Enter search criteria:\n");
    printf("Category (enter 'n/a' for any): ");
    fgets(category, 20, stdin);
    
    char amountStr[15];
    printf("Amount (enter 0 for any): ");
    fgets(amountStr, 15, stdin);
    sscanf(amountStr, "%f", &amount);
    
    printf("Date (enter 'n/a' for any): ");
    fgets(date, 15, stdin);
    
    printf("\n---Search Results---\n\n");
    
    //Print table header
    printf("#  Category              Amount        Date\n");
    printf("--------------------------------------------------\n");
    
    //Search for expenses
    for (i = 0; i < MAX; i++) {
        if (Exp[i].amount != 0) {
            if ((strcmp(category, "n/a\n") == 0 || strcmp(Exp[i].category, category) == 0) &&
                (amount == 0 || Exp[i].amount == amount) &&
                (strcmp(date, "n/a\n") == 0 || strcmp(Exp[i].date, date) == 0)) {
                printf("%d. %-20s %.2f        %s\n", i+1, Exp[i].category, Exp[i].amount, Exp[i].date);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("No expenses found.\n");
    }
}

//Function to delete all expenses
void deleteAllExpenses() {
    printf("---------------------------------------\n");
    printf("------------Expense Tracker------------\n");
    printf("---------------------------------------\n\n");
    
    char confirm;
    
    printf("---Delete All Expenses---\n\n");
    printf("Are you sure you want to delete all expenses? (y/n): ");
    scanf("%c", &confirm);
    
    if (confirm == 'y' || confirm == 'Y') {
        memset(Exp, 0, sizeof(Exp)); //Reset all expenses to 0
        printf("All expenses deleted.\n");
    } else {
        printf("Delete all expenses canceled.\n");
    }
    
    //Clear input buffer
    clearInputBuffer();
}

int main() {
    int option;
    
    while (1) {
        showMenu();
        scanf("%d", &option);
        clearInputBuffer();
        
        switch (option) {
            case 0:
                printf("\nThank you for using Expense Tracker.\n");
                return 0;
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                searchExpenses();
                break;
            case 4:
                deleteAllExpenses();
                break;
            default:
                printf("Invalid option. Please select a valid option.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}