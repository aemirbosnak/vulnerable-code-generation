//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>

struct item {
    char name[50];
    float price;
};

struct item items[100];

int main() {
    int i, j;
    float total, discount;
    char name[50];

    printf("Medical Store Management System\n");

    for (i = 0; i < 100; i++) {
        printf("\n------------------------------------\n");
        printf("| Medical Store Management System |\n");
        printf("------------------------------------\n");
        printf("Item No: %d\n", i + 1);
        printf("Item Name: ");
        scanf("%s", name);
        printf("Price: ");
        scanf("%f", &items[i].price);
        printf("\n");
    }

    printf("\n1. Display all items\n");
    printf("2. Add a new item\n");
    printf("3. Update an item's price\n");
    printf("4. Delete an item\n");
    printf("5. Calculate total price\n");
    printf("6. Apply discount\n");
    printf("7. Quit\n");

    printf("Enter your choice: ");
    scanf("%d", &j);

    switch (j) {
        case 1:
            printf("\nAll Items:\n");
            for (i = 0; i < 100; i++) {
                printf("| %s | %f\n", items[i].name, items[i].price);
            }
            break;
        case 2:
            printf("\nEnter new item name: ");
            scanf("%s", name);
            printf("Enter new item price: ");
            scanf("%f", &items[i].price);
            printf("\n");
            break;
        case 3:
            printf("\nEnter item name: ");
            scanf("%s", name);
            for (i = 0; i < 100; i++) {
                if (strcmp(items[i].name, name) == 0) {
                    printf("Old price: %.2f\n", items[i].price);
                    printf("New price: ");
                    scanf("%f", &items[i].price);
                    printf("\n");
                }
            }
            break;
        case 4:
            printf("\nEnter item name: ");
            scanf("%s", name);
            for (i = 0; i < 100; i++) {
                if (strcmp(items[i].name, name) == 0) {
                    printf("Item deleted\n");
                    items[i].name[0] = '\0';
                    items[i].price = 0.0;
                }
            }
            break;
        case 5:
            total = 0.0;
            for (i = 0; i < 100; i++) {
                total += items[i].price;
            }
            printf("Total price: %.2f\n", total);
            break;
        case 6:
            printf("\nEnter item name: ");
            scanf("%s", name);
            for (i = 0; i < 100; i++) {
                if (strcmp(items[i].name, name) == 0) {
                    discount = items[i].price * 0.10;
                    printf("Discount: %.2f\n", discount);
                    items[i].price -= discount;
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}