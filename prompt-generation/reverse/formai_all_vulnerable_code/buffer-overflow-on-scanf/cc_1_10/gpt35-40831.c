//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
// Function to calculate total bill
float calcBill(int quantity, float price) {
    float total = quantity * price;
    if(total <= 2000) {
        total = total + (total * 0.05); // 5% tax for bills under or equal to 2000
    }
    else if(total > 2000 && total <= 5000) {
        total = total + (total * 0.1); // 10% tax for bills between 2000 and 5000
    }
    else {
        total = total + (total * 0.15); // 15% tax for bills above 5000
    }
    return total;
}
// Function to display menu
void displayMenu() {
    printf("\n\tMenu\n");
    printf("1. Coffee              Rs.50\n");
    printf("2. Tea                 Rs.30\n");
    printf("3. Sandwich            Rs.80\n");
    printf("4. Burger              Rs.100\n");
    printf("5. Pasta               Rs.150\n");
}
int main() {
    char name[50], contact[15];
    int choice, quantity;
    float price, total;
    // Get customer details
    printf("Enter customer name: ");
    scanf("%[^\n]%*c", name);
    printf("Enter contact number: ");
    scanf("%s", contact);
    // Display menu
    displayMenu();
    // Get order details
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    switch(choice) {
        case 1:
            price = 50;
            break;
        case 2:
            price = 30;
            break;
        case 3:
            price = 80;
            break;
        case 4:
            price = 100;
            break;
        case 5:
            price = 150;
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }
    // Calculate total bill
    total = calcBill(quantity, price);
    // Print invoice
    printf("\n\tInvoice\n");
    printf("Customer name: %s\n", name);
    printf("Contact number: %s\n", contact);
    printf("Item: ");
    switch(choice) {
        case 1:
            printf("Coffee\n");
            break;
        case 2:
            printf("Tea\n");
            break;
        case 3:
            printf("Sandwich\n");
            break;
        case 4:
            printf("Burger\n");
            break;
        case 5:
            printf("Pasta\n");
            break;
    }
    printf("Price per unit: Rs.%0.2f\n", price);
    printf("Quantity: %d\n", quantity);
    printf("Total bill: Rs.%0.2f\n", total);
    return 0;
}