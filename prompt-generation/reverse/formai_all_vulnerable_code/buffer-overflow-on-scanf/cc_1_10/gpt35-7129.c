//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

void add_medicine(struct medicine *store, int *count) {
    printf("Enter medicine details:\n");
    printf("ID: ");
    scanf("%d", &store[*count].id);
    printf("Name: ");
    scanf("%s", store[*count].name);
    printf("Quantity: ");
    scanf("%d", &store[*count].quantity);
    printf("Price: ");
    scanf("%f", &store[*count].price);

    (*count)++;
}

void print_inventory(struct medicine *store, int count) {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", store[i].id, store[i].name, store[i].quantity, store[i].price);
    }
}

int main() {
    printf("Welcome to the Medical Store Management System!\n");

    const int MAX_MEDICINES = 100;
    struct medicine store[MAX_MEDICINES];
    int count = 0;

    while (1) {
        printf("Options:\n");
        printf("1. Add medicine\n");
        printf("2. Display inventory\n");
        printf("3. Quit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_medicine(store, &count);
                break;
            case 2:
                print_inventory(store, count);
                break;
            case 3:
                printf("Exiting... Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}