//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menu {
    char name[20];
    int price;
};

struct order {
    char name[20];
    int quantity;
    int total_price;
};

void display_menu(struct menu *m, int n) {
    printf("------------------------------\n");
    printf("| %-20s | %-5s |\n", "Menu Item", "Price");
    printf("------------------------------\n");
    for(int i=0;i<n;i++) {
        printf("| %-20s | %-5d |\n", m[i].name, m[i].price);
    }
    printf("------------------------------\n");
}

void place_order(struct menu *m, int n, struct order *o, int *count) {
    char item[20];
    int quantity, total_price;
    printf("Enter the item you want to order: ");
    scanf("%s", item);
    for(int i=0;i<n;i++) {
        if(strcmp(m[i].name, item) == 0) {
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            total_price = m[i].price * quantity;
            strcpy(o[*count].name, item);
            o[*count].quantity = quantity;
            o[*count].total_price = total_price;
            *count += 1;
            printf("Item added to order.\n");
            return;
        }
    }
    printf("Item not found in menu.\n");
}

void display_order(struct order *o, int n) {
    if(n == 0) {
        printf("No items in order.\n");
        return;
    }
    int total = 0;
    printf("-----------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Item", "Quantity", "Total Price");
    printf("-----------------------------------------------\n");
    for(int i=0;i<n;i++) {
        printf("| %-20s | %-10d | %-10d |\n", o[i].name, o[i].quantity, o[i].total_price);
        total += o[i].total_price;
    }
    printf("-----------------------------------------------\n");
    printf("| %-20s | %-10s | %-10d |\n", "Total", "", total);
    printf("-----------------------------------------------\n");
}

void generate_bill(struct order *o, int n) {
    if(n == 0) {
        printf("No items in order.\n");
        return;
    }
    int total = 0;
    printf("-----------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Item", "Quantity", "Total Price");
    printf("-----------------------------------------------\n");
    for(int i=0;i<n;i++) {
        printf("| %-20s | %-10d | %-10d |\n", o[i].name, o[i].quantity, o[i].total_price);
        total += o[i].total_price;
    }
    printf("-----------------------------------------------\n");
    printf("| %-20s | %-10s | %-10d |\n", "Total", "", total);
    printf("-----------------------------------------------\n");
    printf("Thank you for visiting us.\n");
}

int main() {
    struct menu m[5] = {{"Coffee", 50}, {"Tea", 20}, {"Sandwich", 80}, {"Burger", 100}, {"Pizza", 150}};
    struct order o[10];
    int choice, count=0;
    while(1) {
        printf("1. Display menu\n2. Place order\n3. Display order\n4. Generate bill and exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_menu(m, 5);
                break;
            case 2:
                place_order(m, 5, o, &count);
                break;
            case 3:
                display_order(o, count);
                break;
            case 4:
                generate_bill(o, count);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}