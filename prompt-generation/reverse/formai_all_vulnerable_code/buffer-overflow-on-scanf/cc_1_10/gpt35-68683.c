//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about medicines
typedef struct Medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

// Function declarations
void display_menu();
void add_medicine();
void display_medicines();
void search_medicine();
void update_medicine();
void delete_medicine();

// Global variables
Medicine medicines[100];
int medicine_count = 0;

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                printf("Exiting program...");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

// Function to display the menu options
void display_menu() {
    printf("\n===== Medical Store Management System =====\n\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n\n");
}

// Function to add medicine to the system
void add_medicine() {
    Medicine m;
    printf("\nEnter details of medicine:\n");
    printf("Name: ");
    getchar();
    fgets(m.name, 50, stdin);
    printf("Manufacturer: ");
    fgets(m.manufacturer, 50, stdin);
    printf("Price: ");
    scanf("%f", &m.price);
    printf("Quantity: ");
    scanf("%d", &m.quantity);

    medicines[medicine_count] = m;
    medicine_count++;

    printf("\nMedicine added successfully.\n");
}

// Function to display all medicines in the system
void display_medicines() {
    if (medicine_count == 0) {
        printf("No medicines found.\n");
    } else {
        printf("\nMedicines in the system:\n\n");
        printf("No.  Name                     Manufacturer            Price     Quantity\n");
        printf("======================================================================\n");

        for (int i = 0; i < medicine_count; i++) {
            printf("%-4d %-24s %-24s %-9.2f %d\n",
                   i+1,
                   medicines[i].name,
                   medicines[i].manufacturer,
                   medicines[i].price,
                   medicines[i].quantity);
        }
    }
}

// Function to search for a medicine by name
void search_medicine() {
    char search_name[50];
    int found = 0;

    printf("\nEnter name of medicine to search for: ");
    getchar();
    fgets(search_name, 50, stdin);

    for (int i = 0; i < medicine_count; i++) {
        if (strstr(medicines[i].name, search_name) != NULL) {
            found = 1;
            printf("\nMedicine found:\n\n");
            printf("Name: %s", medicines[i].name);
            printf("Manufacturer: %s", medicines[i].manufacturer);
            printf("Price: %.2f\n", medicines[i].price);
            printf("Quantity: %d\n", medicines[i].quantity);
            break;
        }
    }

    if (found == 0) {
        printf("\nMedicine not found.\n");
    }
}

// Function to update medicine information
void update_medicine() {
    char search_name[50];
    int found = 0;

    printf("\nEnter name of medicine to update: ");
    getchar();
    fgets(search_name, 50, stdin);

    for (int i = 0; i < medicine_count; i++) {
        if (strstr(medicines[i].name, search_name) != NULL) {
            found = 1;
            printf("\nEnter new details for medicine:\n");
            printf("Name: ");
            fgets(medicines[i].name, 50, stdin);
            printf("Manufacturer: ");
            fgets(medicines[i].manufacturer, 50, stdin);
            printf("Price: ");
            scanf("%f", &medicines[i].price);
            printf("Quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("\nMedicine updated successfully.\n");
            break;
        }
    }

    if (found == 0) {
        printf("\nMedicine not found.\n");
    }
}

// Function to delete medicine from the system
void delete_medicine() {
    char search_name[50];
    int found = 0;

    printf("\nEnter name of medicine to delete: ");
    getchar();
    fgets(search_name, 50, stdin);

    for (int i = 0; i < medicine_count; i++) {
        if (strstr(medicines[i].name, search_name) != NULL) {
            found = 1;
            for (int j = i; j < medicine_count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicine_count--;
            printf("\nMedicine deleted successfully.\n");
            break;
        }
    }

    if (found == 0) {
        printf("\nMedicine not found.\n");
    }
}