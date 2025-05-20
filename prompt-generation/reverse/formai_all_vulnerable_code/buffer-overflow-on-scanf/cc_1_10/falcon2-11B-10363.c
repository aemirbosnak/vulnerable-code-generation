//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medical_store {
    char name[100];
    int id;
    float price;
};

int main() {
    struct medical_store store1, store2, store3;
    int choice;

    printf("Welcome to Medical Store Management System!\n");
    printf("Please select an option:\n");
    printf("1. Add new store\n");
    printf("2. List all stores\n");
    printf("3. Update store details\n");
    printf("4. Delete store\n");
    printf("5. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter store name: ");
                scanf("%s", store1.name);
                printf("Enter store id: ");
                scanf("%d", &store1.id);
                printf("Enter store price: ");
                scanf("%f", &store1.price);
                break;
            case 2:
                printf("All stores:\n");
                printf("Store Name | Store ID | Store Price\n");
                printf("-------------------------------\n");
                printf("%s | %d | %.2f\n", store1.name, store1.id, store1.price);
                printf("%s | %d | %.2f\n", store2.name, store2.id, store2.price);
                printf("%s | %d | %.2f\n", store3.name, store3.id, store3.price);
                break;
            case 3:
                printf("Enter store id: ");
                scanf("%d", &store1.id);
                printf("Enter new store name: ");
                scanf("%s", store1.name);
                printf("Enter new store price: ");
                scanf("%f", &store1.price);
                break;
            case 4:
                printf("Enter store id: ");
                scanf("%d", &store1.id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}