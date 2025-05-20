//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    float price;
    int quantity;
} Product;

int main() {
    Product products[5] = {{"Aspirin", 2.50, 100},
                       {"Paracetamol", 1.20, 50},
                       {"Ibuprofen", 3.00, 30},
                       {"Pain Killer", 5.00, 10},
                       {"Antibiotic", 10.00, 5}};

    int index;

    printf("Welcome to the Medical Store Management System!\n");

    printf("1. Add a new product\n");
    printf("2. View all products\n");
    printf("3. Update a product's price or quantity\n");
    printf("4. Delete a product\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &index);

    switch(index) {
        case 1:
            printf("Enter the product's name: ");
            scanf("%s", products[index].name);
            printf("Enter the product's price: ");
            scanf("%f", &products[index].price);
            printf("Enter the product's quantity: ");
            scanf("%d", &products[index].quantity);
            break;
        case 2:
            printf("All products:\n");
            for(int i = 0; i < 5; i++) {
                printf("%d. %s - Price: %.2f, Quantity: %d\n", i+1, products[i].name, products[i].price, products[i].quantity);
            }
            break;
        case 3:
            printf("Enter the product's index: ");
            scanf("%d", &index);

            printf("Enter the new price: ");
            scanf("%f", &products[index].price);
            printf("Enter the new quantity: ");
            scanf("%d", &products[index].quantity);
            break;
        case 4:
            printf("Enter the product's index: ");
            scanf("%d", &index);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}