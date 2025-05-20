//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

struct Item{
    char name[MAX_NAME_LENGTH]; //name of item
    double price; //price of item
    int quantity; //quantity of item
};

struct Order{
    struct Item items[MAX_ITEMS]; //list of items
    int itemCount; //number of items in list
    double total; //total cost of order
};

void printMenu(){
    printf("Welcome to the Cafe Billing System!\n");
    printf("Menu:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Order\n");
    printf("4. Pay Bill\n");
    printf("5. Exit\n");
}

void addItem(struct Order* order, char name[], double price, int quantity){
    if(order->itemCount < MAX_ITEMS){
        struct Item newItem;
        strcpy(newItem.name, name);
        newItem.price = price;
        newItem.quantity = quantity;
        order->items[order->itemCount] = newItem;
        order->itemCount++;
        order->total += price*quantity;
        printf("%d %s added to order.\n", quantity, name);
    }else{
        printf("Sorry, order is full. Cannot add more items.\n");
    }
}

void removeItem(struct Order* order, char name[], int quantity){
    int index = -1;
    for(int i = 0; i < order->itemCount; i++){
        if(strcmp(order->items[i].name, name) == 0){
            index = i;
            break;
        }
    }

    if(index != -1){
        if(order->items[index].quantity > quantity){
            order->items[index].quantity -= quantity;
            order->total -= order->items[index].price * quantity;
            printf("%d %s removed from order.\n", quantity, name);
        }else{
            order->total -= order->items[index].price * order->items[index].quantity;
            printf("%d %s removed from order.\n", order->items[index].quantity, name);
            for(int i = index; i < order->itemCount - 1; i++){
                order->items[i] = order->items[i+1];
            }
            order->itemCount--;
        }
    }else{
        printf("Sorry, %s is not in the order.\n", name);
    }
}

void viewOrder(struct Order* order){
    printf("Current Order:\n");
    for(int i = 0; i < order->itemCount; i++){
        printf("%s (%d) - $%.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
    }
    printf("Total: $%.2f\n", order->total);
}

int main(){
    printf("Welcome to the Cafe Billing System!\n");
    struct Order currentOrder;
    currentOrder.itemCount = 0;
    currentOrder.total = 0.0;

    int choice = 0;
    while(1){
        printMenu();
        scanf("%d", &choice);

        if(choice == 1){
            char name[MAX_NAME_LENGTH];
            double price;
            int quantity;

            printf("Enter name of item: ");
            scanf("%s", name);

            printf("Enter price of item: ");
            scanf("%lf", &price);

            printf("Enter quantity of item: ");
            scanf("%d", &quantity);

            addItem(&currentOrder, name, price, quantity);
        }else if(choice == 2){
            char name[MAX_NAME_LENGTH];
            int quantity;

            printf("Enter name of item: ");
            scanf("%s", name);

            printf("Enter quantity of item: ");
            scanf("%d", &quantity);

            removeItem(&currentOrder, name, quantity);
        }else if(choice == 3){
            viewOrder(&currentOrder);
        }else if(choice == 4){
            printf("Amount Due: $%.2f\n", currentOrder.total);
            printf("Thank you. Payment Received!\n");
            break;
        }else if(choice == 5){
            printf("Goodbye!\n");
            break;
        }else{
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}