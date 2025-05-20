//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

struct Menu {
    char item[50];
    int price;
    int quantity;
};

struct Menu menu[3];

int main() {
    printf("Cafe Billing System\n");
    int choice, i;
    for (i = 0; i < 3; i++) {
        printf("Enter menu item %d: ", i+1);
        fgets(menu[i].item, sizeof(menu[i].item), stdin);
        menu[i].price = 0;
        menu[i].quantity = 0;
        printf("Enter price: ");
        scanf("%d", &menu[i].price);
        printf("Enter quantity: ");
        scanf("%d", &menu[i].quantity);
    }
    printf("\n");
    printf("Menu: \n");
    for (i = 0; i < 3; i++) {
        printf("%s @ $%.2f (x%d)\n", menu[i].item, menu[i].price, menu[i].quantity);
    }
    printf("\n");
    printf("Enter choice: \n1. View Menu\n2. Add item\n3. Remove item\n4. Modify price\n5. Modify quantity\n6. Exit\n");
    scanf("%d", &choice);
    while (choice!= 6) {
        switch (choice) {
            case 1:
                printf("Menu:\n");
                for (i = 0; i < 3; i++) {
                    printf("%s @ $%.2f (x%d)\n", menu[i].item, menu[i].price, menu[i].quantity);
                }
                break;
            case 2:
                printf("Enter item: ");
                fgets(menu[i].item, sizeof(menu[i].item), stdin);
                menu[i].price = 0;
                menu[i].quantity = 0;
                printf("Enter price: ");
                scanf("%d", &menu[i].price);
                printf("Enter quantity: ");
                scanf("%d", &menu[i].quantity);
                break;
            case 3:
                printf("Enter item: ");
                fgets(menu[i].item, sizeof(menu[i].item), stdin);
                menu[i].price = 0;
                menu[i].quantity = 0;
                printf("Remove item %s from menu? (y/n): ", menu[i].item);
                char ch;
                scanf("%c", &ch);
                if (ch == 'y') {
                    printf("Item removed.\n");
                    i--;
                }
                break;
            case 4:
                printf("Enter item: ");
                fgets(menu[i].item, sizeof(menu[i].item), stdin);
                menu[i].price = 0;
                menu[i].quantity = 0;
                printf("Enter new price: ");
                scanf("%d", &menu[i].price);
                printf("Enter new quantity: ");
                scanf("%d", &menu[i].quantity);
                break;
            case 5:
                printf("Enter item: ");
                fgets(menu[i].item, sizeof(menu[i].item), stdin);
                menu[i].price = 0;
                menu[i].quantity = 0;
                printf("Enter new quantity: ");
                scanf("%d", &menu[i].quantity);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");
        printf("Enter choice: \n1. View Menu\n2. Add item\n3. Remove item\n4. Modify price\n5. Modify quantity\n6. Exit\n");
        scanf("%d", &choice);
    }
    return 0;
}