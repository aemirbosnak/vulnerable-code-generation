//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LEN 50
#define MAX_COMPANY_LEN 50

// Structure to represent a medicine
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char company[MAX_COMPANY_LEN];
    int quantity;
    float price;
} Medicine;

// Global array to store medicines
Medicine inventory[MAX_MEDICINES];

// Number of medicines currently in the inventory
int medicine_count = 0;

// Function prototypes
void addMedicine();
void listMedicines();
void updateMedicine();
void deleteMedicine();
void searchMedicine();
void paranoidMenu();

int main() {
    printf("Welcome to the Paranoid Medical Store Management System!\n");
    printf("You can never be too careful with your medicines...\n");
    
    paranoidMenu();
    return 0;
}

void paranoidMenu() {
    char choice;

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Add Medicine\n");
        printf("2. List Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Search Medicine\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        choice = getchar();
        getchar();  // to consume the newline

        switch (choice) {
            case '1':
                addMedicine();
                break;
            case '2':
                listMedicines();
                break;
            case '3':
                updateMedicine();
                break;
            case '4':
                deleteMedicine();
                break;
            case '5':
                searchMedicine();
                break;
            case '6':
                printf("Exiting the system... But you should always keep an eye out!\n");
                exit(0);
            default:
                printf("That's not a valid option! Are you trying to deceive me?\n");
        }
    }
}

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("I can't let you add more medicines, the inventory is full! Stay vigilant!\n");
        return;
    }
    
    Medicine med;
    med.id = medicine_count + 1;  // Incremental ID for new medicines

    printf("Enter the name of the medicine: ");
    scanf("%s", med.name);
    printf("Enter the company manufacturing the medicine: ");
    scanf("%s", med.company);
    printf("Enter the quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter the price: ");
    scanf("%f", &med.price);

    inventory[medicine_count] = med;
    medicine_count++;
    printf("Medicine added successfully! But remember, trust no one!\n");
}

void listMedicines() {
    if (medicine_count == 0) {
        printf("The inventory is empty! Someone must be hiding the medicines...\n");
        return;
    }

    printf("\nListing all medicines:\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("ID: %d, Name: %s, Company: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].company,
               inventory[i].quantity, inventory[i].price);
    }
}

void updateMedicine() {
    int id;
    printf("Enter the ID of the medicine to update: ");
    scanf("%d", &id);

    if (id < 1 || id > medicine_count) {
        printf("Are you trying to fool me? There's no medicine with that ID!\n");
        return;
    }

    Medicine *med = &inventory[id - 1];
    
    printf("Updating medicine (current: %s). Enter new name (or press enter to keep current): ", med->name);
    char input[MAX_NAME_LEN];
    fgets(input, sizeof(input), stdin);
    
    if (strlen(input) > 1) {
        strcpy(med->name, strtok(input, "\n"));
    }

    printf("Current company: %s. Enter new company (or press enter to keep current): ", med->company);
    fgets(input, sizeof(input), stdin);
    
    if (strlen(input) > 1) {
        strcpy(med->company, strtok(input, "\n"));
    }
    
    printf("Current quantity: %d. Enter new quantity (or -1 to keep current): ", med->quantity);
    int new_quantity;
    scanf("%d", &new_quantity);
    if (new_quantity != -1) {
        med->quantity = new_quantity;
    }
    
    printf("Current price: %.2f. Enter new price (or -1 to keep current): ", med->price);
    float new_price;
    scanf("%f", &new_price);
    if (new_price != -1) {
        med->price = new_price;
    }

    printf("Medicine updated successfully! Always check for imposters!\n");
}

void deleteMedicine() {
    int id;
    printf("Enter the ID of the medicine to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > medicine_count) {
        printf("There's no medicine with that ID to delete! Someone's tricking you...\n");
        return;
    }

    for (int i = id - 1; i < medicine_count - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift left
    }
    medicine_count--;
    printf("Medicine deleted successfully! Are you sure it was the right one?\n");
}

void searchMedicine() {
    char name[MAX_NAME_LEN];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);
    
    int found = 0;
    printf("\nSearching for %s...\n", name);
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Found: ID: %d, Name: %s, Company: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].company,
                   inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No medicine found with the name '%s'! Someone must be hiding it...\n", name);
    }
}