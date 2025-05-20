//FormAI DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
    int pid;
    char name[20];
    float price;
};

int main() {
    struct product inventory[50];
    int size = 0, choice = 0, pid, flag = 0, i;
    float price;
    char name[20];

    while(1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n2. Search product by ID\n3. Search product by name\n4. Display inventory\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter product ID: ");
                scanf("%d", &pid);
                for(i=0; i<size; i++) {
                    if(inventory[i].pid == pid) {
                        printf("Product ID already exists!\n");
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    inventory[size].pid = pid;
                    printf("Enter product name: ");
                    scanf("%s", inventory[size].name);
                    printf("Enter product price: ");
                    scanf("%f", &inventory[size].price);
                    size++;
                }
                break;

            case 2:
                printf("Enter product ID to search: ");
                scanf("%d", &pid);
                for(i=0; i<size; i++) {
                    if(inventory[i].pid == pid) {
                        printf("Product found!\n");
                        printf("ID: %d\nName: %s\nPrice: %.2f\n", inventory[i].pid, inventory[i].name, inventory[i].price);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("Product not found!\n");
                }
                break;

            case 3:
                printf("Enter product name to search: ");
                scanf("%s", name);
                for(i=0; i<size; i++) {
                    if(strcmp(inventory[i].name, name) == 0) {
                        printf("Product found!\n");
                        printf("ID: %d\nName: %s\nPrice: %.2f\n", inventory[i].pid, inventory[i].name, inventory[i].price);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("Product not found!\n");
                }
                break;

            case 4:
                printf("Product Inventory\n");
                for(i=0; i<size; i++) {
                    printf("ID: %d\nName: %s\nPrice: %.2f\n", inventory[i].pid, inventory[i].name, inventory[i].price);
                }
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}