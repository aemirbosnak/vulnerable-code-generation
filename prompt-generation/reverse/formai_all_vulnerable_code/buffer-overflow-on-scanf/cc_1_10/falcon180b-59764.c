//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the maximum number of items
#define MAX_ITEMS 100

//Define the structure of an item
typedef struct {
    char name[50];
    float price;
} Item;

//Define the structure of an order
typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

//Function to add an item to the order
void addItem(Order* order) {
    int i;
    for(i=0;i<order->numItems;i++) {
        if(strcmp(order->items[i].name,"")==0) {
            printf("Enter the name of the item: ");
            scanf("%s",order->items[i].name);
            printf("Enter the price of the item: ");
            scanf("%f",&order->items[i].price);
            return;
        }
    }
    printf("The order is full. Cannot add more items.\n");
}

//Function to remove an item from the order
void removeItem(Order* order) {
    int i,j;
    char name[50];
    printf("Enter the name of the item to remove: ");
    scanf("%s",name);
    for(i=0;i<order->numItems;i++) {
        if(strcmp(order->items[i].name,name)==0) {
            for(j=i;j<order->numItems-1;j++) {
                strcpy(order->items[j].name,order->items[j+1].name);
                order->items[j].price = order->items[j+1].price;
            }
            order->numItems--;
            return;
        }
    }
    printf("The item does not exist in the order.\n");
}

//Function to display the order
void displayOrder(Order* order) {
    int i;
    printf("Order:\n");
    for(i=0;i<order->numItems;i++) {
        printf("%s - $%.2f\n",order->items[i].name,order->items[i].price);
    }
}

//Function to calculate the total price of the order
float calculateTotal(Order* order) {
    int i;
    float total = 0.0;
    for(i=0;i<order->numItems;i++) {
        total += order->items[i].price;
    }
    return total;
}

//Main function
int main() {
    Order order;
    order.numItems = 0;
    int choice,i;
    float total;
    
    do {
        printf("\nCafe Billing System\n");
        printf("1. Add item\n2. Remove item\n3. Display order\n4. Calculate total\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                removeItem(&order);
                break;
            case 3:
                displayOrder(&order);
                break;
            case 4:
                total = calculateTotal(&order);
                printf("Total price of the order: $%.2f\n",total);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!=5);
    
    return 0;
}