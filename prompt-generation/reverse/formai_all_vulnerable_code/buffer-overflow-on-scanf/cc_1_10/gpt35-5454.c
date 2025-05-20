//FormAI DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include<stdio.h>

// Structure to store expense details
struct expense{
    char type[20];
    float amount;
    int day;
    int month;
    int year;
};

// Function to add a new expense
void addExpense(struct expense arr[], int *n){
    printf("\nEnter Expense Type (eg: Food, Entertainment, Rent) : ");
    scanf("%s", arr[*n].type);
    printf("Enter Expense Amount : ");
    scanf("%f", &(arr[*n].amount));
    printf("Enter Expense Date (dd mm yyyy) : ");
    scanf("%d %d %d", &(arr[*n].day), &(arr[*n].month), &(arr[*n].year));
    (*n)++;
}

// Function to remove an expense by index
void removeExpense(struct expense arr[], int *n){
    int index;
    printf("\nEnter Index of Expense to be removed : ");
    scanf("%d", &index);
    if(index<0 || index>=*n){
        printf("Invalid Index!\n\n");
        return;
    }
    for(int i=index; i<*n-1; i++){
        arr[i] = arr[i+1];
    }
    (*n)--;
    printf("Expense Removed Successfully\n\n");
}

// Function to calculate total expense
float calculateTotal(struct expense arr[], int n){
    float sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i].amount;
    }
    return sum;
}

// Function to calculate average expense per month
float calculateAverage(struct expense arr[], int n){
    int month, year, count = 0;
    float sum = 0;
    printf("\nEnter Month and Year to calculate Average Expense : ");
    scanf("%d %d", &month, &year);
    for(int i=0; i<n; i++){
        if(arr[i].month == month && arr[i].year == year){
            sum += arr[i].amount;
            count++;
        }
    }
    if(count == 0){
        printf("\nNo Expense Entries Found for this Month and Year\n\n");
        return 0;
    }
    return sum/(float)count;
}

// Function to display all expenses
void displayExpenses(struct expense arr[], int n){
    if(n==0){
        printf("\nNo Expense Entries Found!\n\n");
        return;
    }
    printf("\n%-5s %-15s %-10s %-10s %-10s\n", "Index", "Expense Type", "Amount", "Date", "Month");
    for(int i=0; i<n; i++){
        printf("%-5d %-15s %-10.2f %02d/%02d/%-6d %02d\n", i, arr[i].type, arr[i].amount, arr[i].day, arr[i].month, arr[i].year);
    }
}

int main(){
    struct expense arr[100];
    int n = 0, choice;
    while(1){
        printf("Enter Choice : \n1. Add Expense\n2. Remove Expense\n3. Calculate Total Expense\n4. Calculate Average Expense per Month\n5. Display Expenses\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: addExpense(arr, &n);
                    break;
            case 2: removeExpense(arr, &n);
                    break;
            case 3: printf("\nTotal Expense : %.2f\n\n", calculateTotal(arr, n));
                    break;
            case 4: printf("\nAverage Expense per Month : %.2f\n\n", calculateAverage(arr, n));
                    break;
            case 5: displayExpenses(arr, n);
                    break;
            case 6: return 0;
        }
    }
    return 0;
}