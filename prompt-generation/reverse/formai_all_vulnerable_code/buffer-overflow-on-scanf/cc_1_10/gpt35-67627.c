//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    int tableNum;
    float total;
};

struct Item {
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct Customer customer;
    struct Item item[10];
    int numItems, i;
    float subtotal, tax, total;

    printf("Welcome to C Cafe!\n");
    
    printf("What is the customer name? ");
    fgets(customer.name, 50, stdin);
    
    printf("What is the table number? ");
    scanf("%d", &customer.tableNum);
    
    printf("How many items did the customer order? ");
    scanf("%d", &numItems);
    
    for (i = 0; i < numItems; i++) {
        getchar(); // Clear buffer
        printf("Item #%d name: ", i + 1);
        fgets(item[i].name, 50, stdin);
        
        printf("Item #%d price: ", i + 1);
        scanf("%f", &item[i].price);
        
        printf("Item #%d quantity: ", i + 1);
        scanf("%d", &item[i].quantity);
    }
    
    // Calculate subtotal
    subtotal = 0.0;
    for (i = 0; i < numItems; i++) {
        subtotal += item[i].price * item[i].quantity;
    }
    
    // Calculate tax
    tax = subtotal * 0.05;
    
    // Calculate total
    total = subtotal + tax;

    // Display receipt
    printf("\nTable: %d\n", customer.tableNum);
    printf("Name: %s", customer.name);
    printf("----------------------------\n");
    for (i = 0; i < numItems; i++) {
        printf("%s x%d \t $%.2f\n", item[i].name, item[i].quantity, item[i].price);
    }
    printf("----------------------------\n");
    printf("Subtotal \t\t $%.2f\n", subtotal);
    printf("Tax (5%%) \t\t $%.2f\n", tax);
    printf("Total \t\t\t $%.2f\n", total);

    return 0;
}