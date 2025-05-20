//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <string.h>

struct Item {
    char name[20];
    int price;
    int quantity;
};

int total = 0;

void addItem(struct Item items[], int index) {
    printf("Enter item name: ");
    scanf("%s", items[index].name);
    printf("Enter item price (in dollars): ");
    scanf("%d", &items[index].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[index].quantity);
    total += items[index].price * items[index].quantity;
}

void printBill(struct Item items[], int count) {
    printf("\n\n");
    printf("**************************\n");
    printf("    Welcome to Retro Cafe  \n");
    printf("**************************\n\n");
    printf("Items purchased: \n\n");
    for(int i = 0; i < count; i++) {
        printf("%s - $%d x %d = $%d \n", items[i].name, items[i].price, items[i].quantity, items[i].price * items[i].quantity);
    }
    printf("\nTotal bill amount (including taxes): $%d\n", total*107/100);
    printf("\nThank you for visiting Retro Cafe. Have a nice day!\n\n");
}

int main() {
    int menuChoice, itemCount = 0;
    struct Item items[10];
    
    do {
        printf("\t RETRO CAFE BILLING SYSTEM\n");
        printf("\t_________________________\n\n");
        printf("1. Add an item to the bill\n");
        printf("2. Print the bill and exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);
        
        switch(menuChoice) {
            
            case 1:
                addItem(items, itemCount);
                itemCount++;
                break;
            
            case 2:
                printBill(items, itemCount);
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while(menuChoice != 2);
    
    return 0;
}