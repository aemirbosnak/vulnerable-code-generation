//FormAI DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>

//Structure to store the expense details
struct Expense {
    int day;
    int month;
    int year;
    char item[50];
    float cost;
};

//Function to add expense details to the storage
void addExpense(struct Expense expenseArr[], int *size) {
    printf("Enter the details of the expense (dd mm yyyy item cost):\n");
    scanf("%d %d %d %[^\n]s", &expenseArr[*size].day, &expenseArr[*size].month, &expenseArr[*size].year, expenseArr[*size].item, &expenseArr[*size].cost);
    (*size)++;
    printf("Expense added successfully!\n\n");
}

//Function to view all the expense details
void viewExpenses(struct Expense expenseArr[], int size) {
    if(size == 0) {
        printf("No expenses found.\n");
        return;
    }
    printf("|%10s |%12s |%5s |%20s |%10s |\n", "Date", "Item", "Cost", " ");
    printf("|%10s |%12s |%5s |%20s |%10s |\n", "----------", "----------", "----------", "--------------------", "----------");
    for(int i=0; i<size; i++) {
        printf("|%02d-%02d-%04d |%12s |%5.2f |%20s |%10s |\n", expenseArr[i].day, expenseArr[i].month, expenseArr[i].year, expenseArr[i].item, expenseArr[i].cost, " ");
        printf("|%10s |%12s |%5s |%20s |%10s |\n", " ", " ", " ", " ", " ");
    }
}

//Function to compute the total expense amount
float computeTotalExpense(struct Expense expenseArr[], int size) {
    float total = 0.0;
    for(int i=0; i<size; i++) {
        total += expenseArr[i].cost;
    }
    return total;
}

int main() {
    //Declare an array of expense structures with a capacity of 100
    struct Expense expenseArr[100];
    int size = 0;
    int choice;
    do {
        printf("****Expense Tracker****\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Compute Total Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExpense(expenseArr, &size);
                break;
            case 2:
                viewExpenses(expenseArr, size);
                break;
            case 3:
                printf("Total expense amount: %5.2f\n\n", computeTotalExpense(expenseArr, size));
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    } while(choice != 4);
    return 0;
}