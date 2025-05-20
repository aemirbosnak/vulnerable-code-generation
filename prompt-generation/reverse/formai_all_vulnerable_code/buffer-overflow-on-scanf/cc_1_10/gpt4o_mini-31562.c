//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int id;
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void add_medicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Medicine storage is full!\n");
        return;
    }
    
    Medicine new_medicine;
    
    printf("Enter Medicine ID: ");
    scanf("%d", &new_medicine.id);
    
    getchar(); // to consume the newline character
    
    printf("Enter Medicine Name: ");
    fgets(new_medicine.name, NAME_LENGTH, stdin);
    new_medicine.name[strcspn(new_medicine.name, "\n")] = 0; // remove newline
    
    printf("Enter Medicine Price: ");
    scanf("%f", &new_medicine.price);
    
    printf("Enter Medicine Quantity: ");
    scanf("%d", &new_medicine.quantity);
    
    medicines[medicine_count] = new_medicine;
    medicine_count++;
    
    printf("Medicine added successfully!\n");
}

void delete_medicine() {
    if (medicine_count == 0) {
        printf("No medicines to delete!\n");
        return;
    }
    
    int id;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < medicine_count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicine_count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    
    printf("Medicine with ID %d not found!\n", id);
}

void view_medicines() {
    if (medicine_count == 0) {
        printf("No medicines available!\n");
        return;
    }
    
    printf("\nMedicines in store:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
    printf("\n");
}

void menu() {
    while (1) {
        printf("------------- Medical Store Management System -------------\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. View Medicines\n");
        printf("4. Exit\n");
        printf("------------------------------------------------------------\n");
        printf("Select an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                delete_medicine();
                break;
            case 3:
                view_medicines();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}