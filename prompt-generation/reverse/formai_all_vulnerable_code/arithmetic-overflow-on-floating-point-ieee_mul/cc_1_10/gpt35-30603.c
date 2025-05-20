//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <string.h>

//Structure to store Cafe Bill Details
typedef struct CafeBill {
    char itemName[50];
    float itemPrice;
    int quantity;
    float total;
} CafeBill;

//Function to get bill details from user
void getBillDetails(CafeBill *bill) {
    printf("Enter Item Name: ");
    fgets(bill->itemName, 50, stdin);
    strtok(bill->itemName, "\n"); //Remove new line character from item name
    
    printf("Enter Item Price: ");
    scanf("%f", &bill->itemPrice);
    
    printf("Enter Quantity: ");
    scanf("%d", &bill->quantity);
}

//Function to calculate total cost of the bill
void calculateTotal(CafeBill *bill) {
    bill->total = bill->itemPrice * bill->quantity;
}

int main() {
    int numberOfItems;
    float grandTotal = 0;
    
    printf("Enter Number of Items: ");
    scanf("%d", &numberOfItems);
    
    CafeBill itemBills[numberOfItems]; //Array of structures to store item bills
    
    //Get bill details for all items
    for(int i = 0; i < numberOfItems; i++) {
        printf("\nEnter Details for Item %d:\n", i+1);
        getBillDetails(&itemBills[i]);
        calculateTotal(&itemBills[i]);
        grandTotal += itemBills[i].total;
    }
    
    //Print Bill Details
    printf("\n\nCafe Bill\n");
    printf("-------------------------------------------------\n");
    printf("Item Name\t\tPrice\t\tQuantity\tTotal\n");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < numberOfItems; i++) {
        printf("%-30s%.2f\t\t%d\t\t%.2f\n", itemBills[i].itemName, itemBills[i].itemPrice, itemBills[i].quantity, itemBills[i].total);
    }
    
    printf("-------------------------------------------------\n");
    printf("Grand Total\t\t\t\t\t%.2f", grandTotal);
    
    return 0;
}