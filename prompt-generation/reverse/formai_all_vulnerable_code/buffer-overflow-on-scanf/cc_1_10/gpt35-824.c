//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int total_items = 0;

// Structure definition
struct medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Function prototypes
void add_medicine();
void print_medicine();
void search_medicine();
void update_medicine();
void delete_medicine();

int main() {
    int choice;
    
    do {
        printf("\n-- Medical Store Management System --\n\n");
        printf("1. Add Medicine\n");
        printf("2. Print Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                print_medicine();
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
                printf("\n-- Exiting the program --\n");
                break;
            default:
                printf("\nInvalid choice, try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}

void add_medicine() {
    struct medicine temp;
    
    printf("\nEnter the details for the new medicine:\n");
    printf("ID: ");
    scanf("%d", &temp.id);
    printf("Name: ");
    scanf("%s", temp.name);
    printf("Quantity: ");
    scanf("%d", &temp.quantity);
    printf("Price: ");
    scanf("%f", &temp.price);
    
    // Save the medicine to a file
    FILE *fp = fopen("medicines.dat", "ab");
    fwrite(&temp, sizeof(temp), 1, fp);
    fclose(fp);
    
    total_items++;
    
    printf("\nMedicine added successfully.\n");
}

void print_medicine() {
    struct medicine temp;
    
    // Open the file for reading
    FILE *fp = fopen("medicines.dat", "rb");
    
    // Print the table header
    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------\n");
    
    // Loop through all the medicines and print their details
    while(fread(&temp, sizeof(temp), 1, fp)) {
        printf("%-5d %-20s %-10d %-10.2f\n", temp.id, temp.name, temp.quantity, temp.price);
    }
    
    fclose(fp);
}

void search_medicine() {
    int id;
    struct medicine temp;
    
    printf("\nEnter the ID of the medicine to search for: ");
    scanf("%d", &id);
    
    // Open the file for reading
    FILE *fp = fopen("medicines.dat", "rb");
    
    // Loop through all the medicines and find the one with the specified ID
    while(fread(&temp, sizeof(temp), 1, fp)) {
        if(temp.id == id) {
            printf("\nMedicine found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", temp.id, temp.name, temp.quantity, temp.price);
            fclose(fp);
            return;
        }
    }
    
    fclose(fp);
    printf("\nMedicine not found.\n");
}

void update_medicine() {
    int id, choice;
    struct medicine temp;
    
    printf("\nEnter the ID of the medicine to update: ");
    scanf("%d", &id);
    
    // Open the file for reading and writing
    FILE *fp = fopen("medicines.dat", "rb+");
    
    // Loop through all the medicines and find the one with the specified ID
    while(fread(&temp, sizeof(temp), 1, fp)) {
        if(temp.id == id) {
            printf("\nMedicine found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", temp.id, temp.name, temp.quantity, temp.price);
            
            do {
                printf("\n-- Update Menu --\n\n");
                printf("1. Update name\n");
                printf("2. Update quantity\n");
                printf("3. Update price\n");
                printf("4. Back to main menu\n\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                
                switch(choice) {
                    case 1:
                        printf("Enter the new name: ");
                        scanf("%s", temp.name);
                        break;
                    case 2:
                        printf("Enter the new quantity: ");
                        scanf("%d", &temp.quantity);
                        break;
                    case 3:
                        printf("Enter the new price: ");
                        scanf("%f", &temp.price);
                        break;
                    case 4:
                        printf("\n-- Returning to main menu --\n");
                        break;
                    default:
                        printf("\nInvalid choice, try again.\n");
                }
            } while(choice != 4);
            
            // Write the updated medicine back to the file
            fseek(fp, -sizeof(temp), SEEK_CUR);
            fwrite(&temp, sizeof(temp), 1, fp);
            fclose(fp);
            return;
        }
    }
    
    fclose(fp);
    printf("\nMedicine not found.\n");
}

void delete_medicine() {
    int id;
    struct medicine temp;
    
    printf("\nEnter the ID of the medicine to delete: ");
    scanf("%d", &id);
    
    // Open the file for reading and writing
    FILE *fp = fopen("medicines.dat", "rb+");
    
    // Loop through all the medicines and find the one with the specified ID
    while(fread(&temp, sizeof(temp), 1, fp)) {
        if(temp.id == id) {
            printf("\nMedicine found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", temp.id, temp.name, temp.quantity, temp.price);
            
            // Delete the medicine by moving all the other medicines up one position
            for(int i=0; i<total_items-1; i++) {
                fseek(fp, sizeof(struct medicine), SEEK_CUR);
                fread(&temp, sizeof(temp), 1, fp);
                fseek(fp, -2*sizeof(struct medicine), SEEK_CUR);
                fwrite(&temp, sizeof(temp), 1, fp);
                fseek(fp, sizeof(temp), SEEK_CUR);
            }
            
            // Decrease the total items count and truncate the file
            total_items--;
            ftruncate(fileno(fp), total_items*sizeof(struct medicine));
            
            fclose(fp);
            printf("\nMedicine deleted successfully.\n");
            return;
        }
    }
    
    fclose(fp);
    printf("\nMedicine not found.\n");
}