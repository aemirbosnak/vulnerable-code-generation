//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: introspective
#include <stdio.h>

struct warehouse {
    int id;
    char name[20];
    int quantity;
    float price;
};

int main() {
    int n;
    printf("Enter the number of items in the warehouse: ");
    scanf("%d", &n);

    struct warehouse w[n];

    // Getting input from user
    for(int i=0; i<n; i++) {
        printf("Enter details for item %d\n", i+1);
        printf("Enter ID: ");
        scanf("%d", &w[i].id);
        printf("Enter Name: ");
        scanf("%s", w[i].name);
        printf("Enter Quantity: ");
        scanf("%d", &w[i].quantity);
        printf("Enter Price: ");
        scanf("%f", &w[i].price);
    }

    // Printing warehouse details
    printf("\n\nWarehouse Details:\n");
    printf("%-10s%-20s%-10s%-10s\n", "ID", "Name", "Quantity", "Price");
    for(int i=0; i<n; i++) {
        printf("%-10d%-20s%-10d%-10.2f\n", w[i].id, w[i].name, w[i].quantity, w[i].price);
    }

    // Searching for an item
    int search = 0;
    printf("\nEnter the ID of the item to search: ");
    scanf("%d", &search);

    for(int i=0; i<n; i++) {
        if(w[i].id == search) {
            printf("%-10s%-20s%-10s%-10s\n", "ID", "Name", "Quantity", "Price");
            printf("%-10d%-20s%-10d%-10.2f\n", w[i].id, w[i].name, w[i].quantity, w[i].price);
            break;
        }
    }

    return 0;
}