//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>  // Include standard input/output library

int main() {
    // Define variables
    int menu[5] = {50, 30, 40, 20, 60};  // Prices of menu items
    int quantity[5] = {0, 0, 0, 0, 0};   // Quantity of items ordered
    float sub_total = 0;  // Net amount
    float tax = 0.05;     // Tax rate
    float total = 0;      // Total bill
    int choice = 0;
    
    // Print the menu
    printf("Menu:\n");
    printf("1. Coffee - $50\n");
    printf("2. Tea - $30\n");
    printf("3. Sandwich - $40\n");
    printf("4. French Fries - $20\n");
    printf("5. Burger - $60\n");
    
    // Take orders
    do {
        printf("\nEnter choice (0 to stop): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity[0]);
                break;
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity[1]);
                break;
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity[2]);
                break;
            case 4:
                printf("Enter quantity: ");
                scanf("%d", &quantity[3]);
                break;
            case 5:
                printf("Enter quantity: ");
                scanf("%d", &quantity[4]);
                break;
            default:
                break;
        }
    } while (choice != 0);
    
    // Calculate the bill
    for (int i = 0; i < 5; i++) {
        sub_total += menu[i] * quantity[i];
    }
    total = sub_total + sub_total * tax;
    
    // Print receipt
    printf("\n\n\n");
    printf("                            Cafe Bill                       \n");
    printf("================================================================\n");
    printf("Item                     Quantity               Price\n");
    printf("================================================================\n");
    if (quantity[0] != 0) printf("Coffee                %3d                      $%5d\n", quantity[0], quantity[0] * menu[0]);
    if (quantity[1] != 0) printf("Tea                   %3d                      $%5d\n", quantity[1], quantity[1] * menu[1]);
    if (quantity[2] != 0) printf("Sandwich              %3d                      $%5d\n", quantity[2], quantity[2] * menu[2]);
    if (quantity[3] != 0) printf("French Fries          %3d                      $%5d\n", quantity[3], quantity[3] * menu[3]);
    if (quantity[4] != 0) printf("Burger                %3d                      $%5d\n", quantity[4], quantity[4] * menu[4]);
    printf("================================================================\n");
    printf("Sub Total                                            $%8.2f\n", sub_total);
    printf("Tax (5%%)                                            $%8.2f\n", sub_total * tax);
    printf("Total                                                $%8.2f\n", total);
    printf("================================================================\n");
    
    return 0;  // End of program
}