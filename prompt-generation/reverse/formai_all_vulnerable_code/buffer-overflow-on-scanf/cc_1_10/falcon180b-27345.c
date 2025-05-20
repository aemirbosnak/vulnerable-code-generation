//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

//Structure for each item in the expense list
typedef struct{
    char name[30];
    float price;
    int quantity;
}item;

//Function to add an item to the expense list
void addItem(item *expenseList, int *numItems){
    printf("Enter the name of the item: ");
    scanf("%s", &expenseList[*numItems].name);
    printf("Enter the price of the item: ");
    scanf("%f", &expenseList[*numItems].price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &expenseList[*numItems].quantity);
    (*numItems)++;
}

//Function to display the expense list
void displayExpenseList(item expenseList[], int numItems){
    printf("Expense List:\n");
    printf("--------------------\n");
    for(int i=0; i<numItems; i++){
        printf("%s - $%.2f - %d\n", expenseList[i].name, expenseList[i].price, expenseList[i].quantity);
    }
}

//Function to calculate the total cost of the expense list
float calculateTotalCost(item expenseList[], int numItems){
    float totalCost = 0.0;
    for(int i=0; i<numItems; i++){
        totalCost += expenseList[i].price * expenseList[i].quantity;
    }
    return totalCost;
}

int main(){
    item expenseList[MAX_ITEMS];
    int numItems = 0;

    //Add items to the expense list
    addItem(expenseList, &numItems);
    addItem(expenseList, &numItems);
    addItem(expenseList, &numItems);

    //Display the expense list
    displayExpenseList(expenseList, numItems);

    //Calculate the total cost of the expense list
    float totalCost = calculateTotalCost(expenseList, numItems);

    //Display the total cost
    printf("\nTotal Cost: $%.2f\n", totalCost);

    return 0;
}