//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int num_of_medicines = 0;

void add_medicine() {
    Medicine medicine;
    printf("Enter medicine name: ");
    scanf("%s", medicine.name);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicine.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);
    medicine.id = num_of_medicines;
    medicines[num_of_medicines++] = medicine;
}

void remove_medicine() {
    int id;
    printf("Enter ID of medicine to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < num_of_medicines; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < num_of_medicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            num_of_medicines--;
            printf("Medicine removed successfully!\n");
            return;
        }
    }
    printf("Medicine with ID %d not found!\n", id);
}

void list_medicines() {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < num_of_medicines; i++) {
        Medicine medicine = medicines[i];
        printf("%d\t%s\t%d\t\t%.2f\n", medicine.id, medicine.name, medicine.quantity, medicine.price);
    }
}

void search_medicine() {
    char name[50];
    printf("Enter medicine name to search for: ");
    scanf("%s", name);
    for (int i = 0; i < num_of_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            Medicine medicine = medicines[i];    
            printf("ID: %d\n", medicine.id);
            printf("Quantity: %d\n", medicine.quantity);
            printf("Price: %.2f\n", medicine.price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void update_medicine() {
    int id;
    printf("Enter ID of medicine to update: ");
    scanf("%d", &id);
    for (int i = 0; i < num_of_medicines; i++) {
        if (medicines[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine with ID %d not found!\n", id);
}

int main() {
    int choice = 0;
    while (1) {
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. List medicines\n");
        printf("4. Search medicine\n");
        printf("5. Update medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                list_medicines();
                break;
            case 4:
                search_medicine();
                break;
            case 5:
                update_medicine();
                break;
            case 6:
                printf("Thank you for using our system!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}