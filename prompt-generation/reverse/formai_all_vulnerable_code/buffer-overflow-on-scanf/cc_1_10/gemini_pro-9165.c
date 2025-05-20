//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine_t;

void add_medicine(medicine_t *medicines, int *num_medicines) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[*num_medicines].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[*num_medicines].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[*num_medicines].price);
    (*num_medicines)++;
}

void display_medicines(medicine_t *medicines, int num_medicines) {
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s\t%d\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void search_medicine(medicine_t *medicines, int num_medicines) {
    char name[50];
    printf("Enter medicine name to search for: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found!\nName: %s\nQuantity: %d\nPrice: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void update_medicine(medicine_t *medicines, int num_medicines) {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found!\nEnter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void delete_medicine(medicine_t *medicines, int *num_medicines) {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < *num_medicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*num_medicines)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

int main() {
    medicine_t medicines[100];
    int num_medicines = 0;
    int choice;
    do {
        printf("1. Add medicine\n2. Display medicines\n3. Search medicine\n4. Update medicine\n5. Delete medicine\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine(medicines, &num_medicines);
                break;
            case 2:
                display_medicines(medicines, num_medicines);
                break;
            case 3:
                search_medicine(medicines, num_medicines);
                break;
            case 4:
                update_medicine(medicines, num_medicines);
                break;
            case 5:
                delete_medicine(medicines, &num_medicines);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}