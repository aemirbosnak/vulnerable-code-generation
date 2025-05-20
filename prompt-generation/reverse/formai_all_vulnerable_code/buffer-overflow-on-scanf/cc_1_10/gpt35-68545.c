//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char type[20];
    int quantity;
    float price;
} medicine;

void add_medicine(medicine[], int*);
int search_by_name(medicine[], int, char[]);
void update_medicine(medicine[], int);
void delete_medicine(medicine[], int*);
void display_medicines(medicine[], int);

int main()
{
    int choice, size = 0, index;
    medicine inventory[100];
    char search_name[50];

    do {
        printf("-----------------------\n");
        printf("  MEDICAL STORE SYSTEM  \n");
        printf("-----------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Display Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_medicine(inventory, &size);
                break;
            case 2:
                printf("Enter the name of the medicine to search: ");
                scanf("%s", search_name);
                index = search_by_name(inventory, size, search_name);
                if(index == -1) {
                    printf("Medicine not found in inventory!\n");
                } else {
                    printf("Medicine found at index %d:\n", index);
                    printf("Name: %s\n", inventory[index].name);
                    printf("Type: %s\n", inventory[index].type);
                    printf("Quantity: %d\n", inventory[index].quantity);
                    printf("Price: Rs %.2f\n", inventory[index].price);
                }
                break;
            case 3:
                update_medicine(inventory, size);
                break;
            case 4:
                delete_medicine(inventory, &size);
                break;
            case 5:
                display_medicines(inventory, size);
                break;
            case 6:
                printf("Exiting Medical Store System...\n");
                break;
            default:
                printf("Invalid choice, please enter a valid choice (1-6)!\n");
                break;
        }

        printf("\n");

    } while(choice != 6);

    return 0;
}

void add_medicine(medicine inventory[], int *size)
{
    if(*size == 100) {
        printf("Inventory is full, cannot add more medicines!\n");
    } else {
        printf("Enter details of the medicine to add:\n");
        printf("Name: ");
        scanf("%s", inventory[*size].name);
        printf("Type: ");
        scanf("%s", inventory[*size].type);
        printf("Quantity: ");
        scanf("%d", &inventory[*size].quantity);
        printf("Price: ");
        scanf("%f", &inventory[*size].price);
        (*size)++;
        printf("Medicine added to inventory successfully!\n");
    }
}

int search_by_name(medicine inventory[], int size, char search_name[])
{
    int i, index = -1;
    for(i = 0; i < size; i++) {
        if(strcmp(inventory[i].name, search_name) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

void update_medicine(medicine inventory[], int size)
{
    char update_name[50];
    int choice, index;

    printf("Enter the name of the medicine to update: ");
    scanf("%s", update_name);
    index = search_by_name(inventory, size, update_name);
    if(index == -1) {
        printf("Medicine not found in inventory!\n");
    } else {
        printf("Medicine found at index %d:\n", index);
        printf("Name: %s\n", inventory[index].name);
        printf("Type: %s\n", inventory[index].type);
        printf("Quantity: %d\n", inventory[index].quantity);
        printf("Price: Rs %.2f\n", inventory[index].price);
        do {
            printf("Select the field to update:\n");
            printf("1. Name\n");
            printf("2. Type\n");
            printf("3. Quantity\n");
            printf("4. Price\n");
            printf("5. Exit\n");
            printf("Enter your choice (1-5): ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", inventory[index].name);
                    printf("Name updated successfully!\n");
                    break;
                case 2:
                    printf("Enter new type: ");
                    scanf("%s", inventory[index].type);
                    printf("Type updated successfully!\n");
                    break;
                case 3:
                    printf("Enter new quantity: ");
                    scanf("%d", &inventory[index].quantity);
                    printf("Quantity updated successfully!\n");
                    break;
                case 4:
                    printf("Enter new price: ");
                    scanf("%f", &inventory[index].price);
                    printf("Price updated successfully!\n");
                    break;
                case 5:
                    printf("Exiting update mode...\n");
                    break;
                default:
                    printf("Invalid choice, please enter a valid choice (1-5)!\n");
                    break;
            }
        } while(choice != 5);
    }
}

void delete_medicine(medicine inventory[], int *size)
{
    char delete_name[50];
    int i, index;

    printf("Enter the name of the medicine to delete: ");
    scanf("%s", delete_name);
    index = search_by_name(inventory, *size, delete_name);
    if(index == -1) {
        printf("Medicine not found in inventory!\n");
    } else {
        printf("Medicine found at index %d:\n", index);
        printf("Name: %s\n", inventory[index].name);
        printf("Type: %s\n", inventory[index].type);
        printf("Quantity: %d\n", inventory[index].quantity);
        printf("Price: Rs %.2f\n", inventory[index].price);
        for(i = index; i < (*size)-1; i++) {
            inventory[i] = inventory[i+1];
        }
        (*size)--;
        printf("Medicine deleted from inventory successfully!\n");
    }
}

void display_medicines(medicine inventory[], int size)
{
    int i;
    if(size == 0) {
        printf("Inventory is empty!\n");
    } else {
        printf("Inventory:\n");
        printf("%-20s %-20s %-20s %-20s\n", "Name", "Type", "Quantity", "Price");
        for(i = 0; i < size; i++) {
            printf("%-20s %-20s %-20d Rs %-20.2f\n", inventory[i].name, inventory[i].type, inventory[i].quantity, inventory[i].price);
        }
    }
}