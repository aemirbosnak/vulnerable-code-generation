//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[50];
    char description[100];
    int quantity;
    int price;
} Item;

typedef struct {
    int id;
    char name[50];
    char address[100];
    int phone;
} Supplier;

typedef struct {
    int id;
    char name[50];
    char address[100];
    int phone;
} Customer;

typedef struct {
    int id;
    char name[50];
    int quantity;
} Order;

typedef struct {
    int id;
    char name[50];
    int quantity;
    int reorder_level;
    int order_quantity;
    int reorder_quantity;
    int price;
} Product;

int main() {
    int choice;
    char filename[50];
    FILE *fp;

    do {
        printf("1. Enter items\n");
        printf("2. Enter suppliers\n");
        printf("3. Enter customers\n");
        printf("4. Place an order\n");
        printf("5. Generate report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter filename for items: ");
            scanf("%s", filename);
            fp = fopen(filename, "wb");
            if (fp == NULL) {
                printf("Error opening file\n");
                exit(1);
            }
            break;
        case 2:
            printf("Enter filename for suppliers: ");
            scanf("%s", filename);
            fp = fopen(filename, "wb");
            if (fp == NULL) {
                printf("Error opening file\n");
                exit(1);
            }
            break;
        case 3:
            printf("Enter filename for customers: ");
            scanf("%s", filename);
            fp = fopen(filename, "wb");
            if (fp == NULL) {
                printf("Error opening file\n");
                exit(1);
            }
            break;
        case 4:
            printf("Enter filename for orders: ");
            scanf("%s", filename);
            fp = fopen(filename, "wb");
            if (fp == NULL) {
                printf("Error opening file\n");
                exit(1);
            }
            break;
        case 5:
            printf("Enter filename for report: ");
            scanf("%s", filename);
            fp = fopen(filename, "wb");
            if (fp == NULL) {
                printf("Error opening file\n");
                exit(1);
            }
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 6);

    return 0;
}