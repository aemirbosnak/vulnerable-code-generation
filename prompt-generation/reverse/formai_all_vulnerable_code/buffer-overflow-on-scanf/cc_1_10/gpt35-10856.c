//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[20];
    int order_id;
    int table_num;
    float amount;
};

void print_menu() {
    printf("\n\n============ CYBERCAFE MENU ============\n\n");
    printf("[1] Caffeine Blast             $3.00\n");
    printf("[2] Neon Espresso             $4.00\n");
    printf("[3] Binary Brew               $5.00\n");
    printf("[4] Digital Delight           $6.00\n");
    printf("[5] Quantum Quencher          $7.00\n");
}

int main() {
    int choice, quantity, table_num, exit = 0;
    float amount = 0;
    struct customer customer[10];
    int i = 0;
    
    while (exit != 1) {
        printf("Welcome to the CYBERCAFE\n");
        printf("=========================\n\n");
        
        printf("Enter table number: ");
        scanf("%d", &table_num);
        
        print_menu();
        
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        switch (choice) {
            case 1:
                amount = 3.0 * quantity;
                break;
            case 2:
                amount = 4.0 * quantity;
                break;
            case 3:
                amount = 5.0 * quantity;
                break;
            case 4:
                amount = 6.0 * quantity;
                break;
            case 5:
                amount = 7.0 * quantity;
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }
        
        printf("\nTotal amount: $%.2f\n\n", amount);
        
        strcpy(customer[i].name, "UNKNOWN");
        customer[i].order_id = i + 1;
        customer[i].table_num = table_num;
        customer[i].amount = amount;
        
        printf("Your order ID is %d\n\n", customer[i].order_id);
        
        i++;
        
        printf("Do you want to exit? [1 for YES, 0 for NO]:");
        scanf("%d", &exit);
    }
    
    printf("\n\n============= BILL =============\n\n");
    for (int j = 0; j < i; j++) {
        printf("Order ID: %d\n", customer[j].order_id);
        printf("Table Number: %d\n", customer[j].table_num);
        printf("Customer Name: %s\n", customer[j].name);
        printf("Amount: $%.2f\n\n", customer[j].amount);
    }
    printf("===============================\n");
    
    return 0;
}