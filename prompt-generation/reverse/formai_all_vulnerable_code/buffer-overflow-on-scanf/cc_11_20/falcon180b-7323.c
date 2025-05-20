//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50
#define MAX_SALES 100

struct item {
    char name[50];
    int price;
    int quantity;
};

struct customer {
    char name[50];
    int customer_id;
};

struct sale {
    int sale_id;
    struct item item;
    struct customer customer;
    int quantity;
    int amount;
};

int main() {
    FILE *fp;
    char filename[100];
    int choice;
    int customer_count = 0;
    int item_count = 0;
    int sale_count = 0;

    // Initialize file names
    strcpy(filename, "customer.txt");
    strcpy(filename, "item.txt");
    strcpy(filename, "sale.txt");

    // Open files for reading and writing
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    // Read customer data
    while (fread(&customer_count, sizeof(int), 1, fp) == 1) {
        printf("Number of customers: %d\n", customer_count);
    }

    // Read item data
    while (fread(&item_count, sizeof(int), 1, fp) == 1) {
        printf("Number of items: %d\n", item_count);
    }

    // Read sale data
    while (fread(&sale_count, sizeof(int), 1, fp) == 1) {
        printf("Number of sales: %d\n", sale_count);
    }

    // Display menu
    printf("1. Add customer\n");
    printf("2. Add item\n");
    printf("3. Add sale\n");
    printf("4. View customer list\n");
    printf("5. View item list\n");
    printf("6. View sales list\n");
    printf("7. Exit\n");

    // Get user choice
    scanf("%d", &choice);

    // Perform selected function
    switch (choice) {
        case 1:
            // Add customer
            break;
        case 2:
            // Add item
            break;
        case 3:
            // Add sale
            break;
        case 4:
            // View customer list
            break;
        case 5:
            // View item list
            break;
        case 6:
            // View sales list
            break;
        case 7:
            // Exit
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    // Close file
    fclose(fp);
    return 0;
}