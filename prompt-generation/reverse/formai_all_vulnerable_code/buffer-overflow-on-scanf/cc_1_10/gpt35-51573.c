//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/* Structures for storing medicine information */

struct Medicine {
    int id;
    char name[MAX_SIZE];
    char category[MAX_SIZE];
    float price;
    int stock;
};

struct MedicineStore {
    int size;
    struct Medicine medicines[MAX_SIZE];
};

/* Function for adding medicine to store */

void add_medicine(struct MedicineStore *store, struct Medicine medicine) {
    if (store->size == MAX_SIZE) {
        printf("ERROR: Store is full\n");
        return;
    }
    store->medicines[store->size] = medicine;
    store->size++;
    printf("Medicine added successfully\n");
}

/* Function for searching medicine by name */

void search_medicine(struct MedicineStore *store, char name[MAX_SIZE]) {
    for (int i = 0; i < store->size; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("ID: %d\n", store->medicines[i].id);
            printf("Name: %s\n", store->medicines[i].name);
            printf("Category: %s\n", store->medicines[i].category);
            printf("Price: %.2f\n", store->medicines[i].price);
            printf("Stock: %d\n", store->medicines[i].stock);
            return;
        }
    }
    printf("Medicine not found\n");
}

/* Function for deleting medicine by ID */

void delete_medicine(struct MedicineStore *store, int id) {
    for (int i = 0; i < store->size; i++) {
        if (store->medicines[i].id == id) {
            for (int j = i; j < store->size - 1; j++) {
                store->medicines[j] = store->medicines[j + 1];
            }
            store->size--;
            printf("Medicine deleted successfully\n");
            return;
        }
    }
    printf("ERROR: Medicine ID not found\n");
}

int main() {
    struct MedicineStore store;
    store.size = 0;

    /* Menu loop */
    while (1) {
        printf("\n");
        printf("====== Medical Store Management System ======\n");
        printf("1. Add new medicine\n");
        printf("2. Search medicine by name\n");
        printf("3. Delete medicine by ID\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /* Add new medicine */
                printf("\nEnter medicine details:\n");
                printf("ID: ");
                int id;
                scanf("%d", &id);
                printf("Name: ");
                char name[MAX_SIZE];
                scanf("%s", name);
                printf("Category: ");
                char category[MAX_SIZE];
                scanf("%s", category);
                printf("Price: ");
                float price;
                scanf("%f", &price);
                printf("Stock: ");
                int stock;
                scanf("%d", &stock);
                struct Medicine medicine = {id, name, category, price, stock};
                add_medicine(&store, medicine);
                break;

            case 2:
                /* Search medicine by name */
                printf("\nEnter medicine name: ");
                char search_name[MAX_SIZE];
                scanf("%s", search_name);
                search_medicine(&store, search_name);
                break;

            case 3:
                /* Delete medicine by ID */
                printf("\nEnter medicine ID to delete: ");
                int delete_id;
                scanf("%d", &delete_id);
                delete_medicine(&store, delete_id);
                break;

            case 4:
                /* Quit */
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nERROR: Invalid choice, please enter a number between 1 and 4\n");
                break;
        }
    }

    return 0;
}