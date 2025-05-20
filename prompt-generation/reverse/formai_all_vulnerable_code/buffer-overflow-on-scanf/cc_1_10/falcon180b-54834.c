//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000 // maximum number of items in the warehouse
#define MAX_WAREHOUSE_NAME 50 // maximum length of warehouse name
#define MAX_WAREHOUSE_ADDRESS 100 // maximum length of warehouse address

typedef struct {
    int id;
    char name[MAX_WAREHOUSE_NAME];
    char address[MAX_WAREHOUSE_ADDRESS];
    float latitude;
    float longitude;
} Warehouse;

Warehouse warehouses[MAX_WAREHOUSE_SIZE]; // array of warehouses
int num_warehouses = 0; // number of warehouses currently in the system

void add_warehouse() {
    printf("Enter warehouse name: ");
    scanf("%s", warehouses[num_warehouses].name);
    printf("Enter warehouse address: ");
    scanf("%s", warehouses[num_warehouses].address);
    printf("Enter warehouse latitude: ");
    scanf("%f", &warehouses[num_warehouses].latitude);
    printf("Enter warehouse longitude: ");
    scanf("%f", &warehouses[num_warehouses].longitude);
    num_warehouses++;
}

void view_warehouses() {
    printf("ID\tName\tAddress\tLatitude\tLongitude\n");
    for (int i = 0; i < num_warehouses; i++) {
        printf("%d\t%s\t%s\t%.2f\t%.2f\n", warehouses[i].id, warehouses[i].name, warehouses[i].address, warehouses[i].latitude, warehouses[i].longitude);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add warehouse\n2. View warehouses\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_warehouse();
                break;
            case 2:
                view_warehouses();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}