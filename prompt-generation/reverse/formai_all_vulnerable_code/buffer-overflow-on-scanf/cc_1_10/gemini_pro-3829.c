//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char company[50];
    int quantity;
    float price;
    float discount;
} medicine;

medicine medicines[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if (num_medicines >= MAX_MEDICINES) {
        printf("Medicine list is full!\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", medicines[num_medicines].name);

    printf("Enter medicine company: ");
    scanf("%s", medicines[num_medicines].company);

    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[num_medicines].quantity);

    printf("Enter medicine price: ");
    scanf("%f", &medicines[num_medicines].price);

    printf("Enter medicine discount: ");
    scanf("%f", &medicines[num_medicines].discount);

    num_medicines++;
}

void delete_medicine() {
    char name[50];

    printf("Enter medicine name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < num_medicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            num_medicines--;
            break;
        }
    }
}

void search_medicine() {
    char name[50];

    printf("Enter medicine name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Company: %s\n", medicines[i].company);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %f\n", medicines[i].price);
            printf("Discount: %f\n", medicines[i].discount);
            return;
        }
    }

    printf("Medicine not found!\n");
}

void list_medicines() {
    printf("Medicine List:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d. %s (%s)\n", i + 1, medicines[i].name, medicines[i].company);
    }
}

void main_menu() {
    int choice;

    while (1) {
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. List Medicines\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                delete_medicine();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                list_medicines();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    main_menu();
    return 0;
}