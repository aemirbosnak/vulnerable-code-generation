//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine{
    int med_id;
    char med_name[50];
    int med_qty;
    float med_price;
}Medicine;

void display(Medicine *med, int size);
void addMedicine(Medicine *med, int *size);
void editMedicine(Medicine *med, int size);
void delMedicine(Medicine *med, int *size);
void searchMedicine(Medicine *med, int size);

int main()
{
    int size = 0, choice;

    printf("Welcome to the Medical Store Management System\n");

    Medicine *med = NULL;

    do{
        
        printf("\nChoose an option:\n");
        printf("1. View Medicine List\n");
        printf("2. Add Medicine\n");
        printf("3. Edit Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Search Medicine\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                display(med, size);
                break;
            case 2:
                addMedicine(med, &size);
                break;
            case 3:
                editMedicine(med, size);
                break;
            case 4:
                delMedicine(med, &size);
                break;
            case 5:
                searchMedicine(med, size);
                break;
            case 6:
                printf("Thank you for using our system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    }while(1);

    return 0;
}

void display(Medicine *med, int size)
{
    if(size == 0){
        printf("No data to display");
        return;
    }

    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");

    for(int i = 0; i < size; i++){
        printf("%-10d %-30s %-10d %-10.2f\n", med[i].med_id, med[i].med_name, med[i].med_qty, med[i].med_price);
    }
}

void addMedicine(Medicine *med, int *size)
{    
    if(*size == 0){
        med = malloc(sizeof(Medicine));
    }
    else{
        med = realloc(med, (*size + 1) * sizeof(Medicine));
    }

    int id, qty;
    float price;
    char name[50];

    printf("\nEnter details of the medicine to be added:\n");

    printf("ID: ");
    scanf("%d", &id);
    printf("Name: ");
    scanf("%s", name);
    printf("Quantity: ");
    scanf("%d", &qty);
    printf("Price: ");
    scanf("%f", &price);

    med[*size].med_id = id;
    strcpy(med[*size].med_name, name);
    med[*size].med_qty = qty;
    med[*size].med_price = price;

    (*size)++;

    printf("\nMedicine added successfully.\n");
}

void editMedicine(Medicine *med, int size)
{
    int id;

    printf("\nEnter ID of the medicine to be edited: ");
    scanf("%d", &id);

    for(int i = 0; i < size; i++){
        if(med[i].med_id == id){
            int choice;
            printf("Choose an option:\n");
            printf("1. Edit Name\n");
            printf("2. Edit Quantity\n");
            printf("3. Edit Price\n");

            scanf("%d", &choice);

            switch(choice){
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", med[i].med_name);
                    printf("Name updated successfully.\n");
                    return;
                case 2:
                    printf("Enter new quantity: ");
                    scanf("%d", &med[i].med_qty);
                    printf("Quantity updated successfully.\n");
                    return;
                case 3:
                    printf("Enter new price: ");
                    scanf("%f", &med[i].med_price);
                    printf("Price updated successfully.\n");
                    return;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void delMedicine(Medicine *med, int *size)
{
    int id;

    printf("\nEnter ID of the medicine to be deleted: ");
    scanf("%d", &id);

    for(int i = 0; i < *size; i++){
        if(med[i].med_id == id){
            for(int j = i; j < *size - 1; j++){
                med[j] = med[j + 1];
            }
            (*size)--;
            printf("Medicine with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void searchMedicine(Medicine *med, int size)
{
    char name[50];

    printf("\nEnter keyword to search: ");
    scanf("%s", name);

    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");

    for(int i = 0; i < size; i++){
        if(strstr(med[i].med_name, name) != NULL){
            printf("%-10d %-30s %-10d %-10.2f\n", med[i].med_id, med[i].med_name, med[i].med_qty, med[i].med_price);
        }
    }
}