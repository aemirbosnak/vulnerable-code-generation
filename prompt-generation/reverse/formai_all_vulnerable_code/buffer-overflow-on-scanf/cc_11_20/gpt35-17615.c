//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct product list[100];
    int count = 0;
    int choice;

    while(1) {
        printf("1. Add Product\n");
        printf("2. View Product Inventory\n");
        printf("3. Update Product Quantity\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter product name: ");
                scanf("%s", list[count].name);
                printf("Enter quantity: ");
                scanf("%d", &list[count].quantity);
                printf("Enter price: ");
                scanf("%f", &list[count].price);
                list[count].id = count + 1;
                count++;
                printf("Product added!\n");
                break;
            }
            case 2: {
                printf("ID\tNAME\t\tQUANTITY\tPRICE\n");
                for(int i=0; i<count; i++) {
                    printf("%d\t", list[i].id);
                    printf("%s\t\t", list[i].name);
                    printf("%d\t\t", list[i].quantity);
                    printf("$%.2f\n", list[i].price);
                }
                break;
            }
            case 3: {
                int id, qty;
                printf("Enter product ID: ");
                scanf("%d", &id);
                for(int i=0; i<count; i++) {
                    if(list[i].id == id) {
                        printf("Enter new quantity: ");
                        scanf("%d", &qty);
                        list[i].quantity = qty;
                        printf("Quantity updated!\n");
                        break;
                    }
                }
                break;
            }
            case 4: {
                int id;
                printf("Enter product ID: ");
                scanf("%d", &id);
                for(int i=0; i<count; i++) {
                    if(list[i].id == id) {
                        for(int j=i; j<count-1; j++) {
                            list[j] = list[j+1];
                            list[j].id--;
                        }
                        count--;
                        printf("Product deleted!\n");
                        break;
                    }
                }
                break;
            }
            case 5: {
                printf("Exiting program...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}