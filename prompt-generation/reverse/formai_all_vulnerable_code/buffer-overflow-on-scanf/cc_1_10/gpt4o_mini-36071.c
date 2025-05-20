//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MEDICINE_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MEDICINE_NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void load_medicines() {
    FILE *file = fopen("medicines.dat", "rb");
    if (file != NULL) {
        fread(&medicine_count, sizeof(int), 1, file);
        fread(medicines, sizeof(Medicine), medicine_count, file);
        fclose(file);
    }
}

void save_medicines() {
    FILE *file = fopen("medicines.dat", "wb");
    fwrite(&medicine_count, sizeof(int), 1, file);
    fwrite(medicines, sizeof(Medicine), medicine_count, file);
    fclose(file);
}

void add_medicine() {
    if (medicine_count < MAX_MEDICINES) {
        Medicine new_med;
        printf("Enter Medicine ID: ");
        scanf("%d", &new_med.id);
        printf("Enter Medicine Name: ");
        getchar(); // To consume the newline character
        fgets(new_med.name, MEDICINE_NAME_LENGTH, stdin);
        new_med.name[strcspn(new_med.name, "\n")] = 0; // Remove trailing newline
        printf("Enter Medicine Price: ");
        scanf("%f", &new_med.price);
        printf("Enter Medicine Quantity: ");
        scanf("%d", &new_med.quantity);

        medicines[medicine_count++] = new_med;
        save_medicines();
        printf("Medicine added successfully!\n");
    } else {
        printf("Cannot add more medicines, storage full.\n");
    }
}

void view_medicines() {
    printf("\nAvailable Medicines:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void delete_medicine() {
    int id;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < medicine_count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicine_count--;
            save_medicines();
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    
    printf("Medicine ID not found!\n");
}

void display_menu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Delete Medicine\n");
    printf("4. Exit\n");
    printf("----------------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    load_medicines();
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                view_medicines();
                break;
            case 3:
                delete_medicine();
                break;
            case 4:
                printf("Exiting the system!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}