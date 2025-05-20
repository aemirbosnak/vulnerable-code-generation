//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 20
#define MAX_MANUFACTURER_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char manufacturer[MAX_MANUFACTURER_LENGTH];
    float price;
    int quantity;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int num_medicines;
} MedicineStore;

int find_medicine_by_name(MedicineStore* store, char name[]) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_medicine(MedicineStore* store, Medicine medicine) {
    if (store->num_medicines < MAX_MEDICINES) {
        store->medicines[store->num_medicines] = medicine;
        store->num_medicines++;
        printf("Medicine added successfully!\n");
    } else {
        printf("Store is full, cannot add more medicines!\n");
    }
}

void remove_medicine(MedicineStore* store, char name[]) {
    int index = find_medicine_by_name(store, name);
    if (index != -1) {
        for (int i = index; i < store->num_medicines - 1; i++) {
            store->medicines[i] = store->medicines[i+1];
        }
        store->num_medicines--;
        printf("Medicine removed successfully!\n");
    } else {
        printf("Medicine not found!\n");
    }
}

void update_medicine_quantity(MedicineStore* store, char name[], int quantity) {
    int index = find_medicine_by_name(store, name);
    if (index != -1) {
        store->medicines[index].quantity += quantity;
        printf("Medicine quantity updated successfully!\n");
    } else {
        printf("Medicine not found!\n");
    }
}

void print_store(MedicineStore* store) {
    printf("Medicine Store:\n");
    printf("ID\tName\tManufacturer\tPrice\tQuantity\n");
    for (int i = 0; i < store->num_medicines; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", store->medicines[i].id, store->medicines[i].name,
            store->medicines[i].manufacturer, store->medicines[i].price, store->medicines[i].quantity);
    }
}

int main() {
    MedicineStore store = { .num_medicines = 0 };
    int choice = 0;
    do {
        printf("\nMenu:\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Update Medicine Quantity\n");
        printf("4. Print Store\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            Medicine medicine;
            printf("Enter Name: ");
            scanf("%s", medicine.name);
            printf("Enter Manufacturer: ");
            scanf("%s", medicine.manufacturer);
            printf("Enter Price: ");
            scanf("%f", &medicine.price);
            printf("Enter Quantity: ");
            scanf("%d", &medicine.quantity);
            medicine.id = store.num_medicines + 1;
            add_medicine(&store, medicine);
            break;
        }
        case 2: {
            char name[MAX_NAME_LENGTH];
            printf("Enter Name: ");
            scanf("%s", name);
            remove_medicine(&store, name);
            break;
        }
        case 3: {
            char name[MAX_NAME_LENGTH];
            int quantity;
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Quantity: ");
            scanf("%d", &quantity);
            update_medicine_quantity(&store, name, quantity);
            break;
        }
        case 4: {
            print_store(&store);
            break;
        }
        case 5: {
            printf("Exiting program...\n");
            break;
        }
        default: {
            printf("Invalid choice, please enter a valid choice!\n");
            break;
        }
        }
    } while (choice != 5);
    return 0;
}