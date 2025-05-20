//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

int main() {
    int choice, totalMedicines = 0;
    Medicine *medicines = NULL;
    char filename[50];

    printf("Welcome to Happy Meds Medical Store Management System!\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Update medicine price\n");
        printf("4. Update medicine quantity\n");
        printf("5. List all medicines\n");
        printf("6. Save changes and exit\n");
        printf("Choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                totalMedicines++;
                medicines = (Medicine*) realloc(medicines, totalMedicines * sizeof(Medicine));
                printf("\nEnter medicine details:\n");
                printf("ID: ");
                scanf("%d", &medicines[totalMedicines-1].id);
                printf("Name: ");
                scanf(" %[^\n]", medicines[totalMedicines-1].name);
                printf("Price: ");
                scanf("%f", &medicines[totalMedicines-1].price);
                printf("Quantity: ");
                scanf("%d", &medicines[totalMedicines-1].quantity);
                printf("Medicine added successfully!\n");
                break;
            }
            case 2: {
                int id, index = -1;
                printf("\nEnter ID of medicine to remove: ");
                scanf("%d", &id);
                for (int i = 0; i < totalMedicines; i++) {
                    if (medicines[i].id == id) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    printf("Medicine with ID %d not found!\n", id);
                } else {
                    for (int i = index; i < totalMedicines - 1; i++) {
                        medicines[i] = medicines[i+1];
                    }
                    totalMedicines--;
                    medicines = (Medicine*) realloc(medicines, totalMedicines * sizeof(Medicine));
                    printf("Medicine with ID %d removed successfully!\n", id);
                }
                break;
            }
            case 3: {
                int id, index = -1;
                float price;
                printf("\nEnter ID of medicine to update price: ");
                scanf("%d", &id);
                for (int i = 0; i < totalMedicines; i++) {
                    if (medicines[i].id == id) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    printf("Medicine with ID %d not found!\n", id);
                } else {
                    printf("Enter new price for medicine: ");
                    scanf("%f", &price);
                    medicines[index].price = price;
                    printf("Price for medicine with ID %d updated successfully!\n", id);
                }
                break;
            }
            case 4: {
                int id, index = -1, quantity;
                printf("\nEnter ID of medicine to update quantity: ");
                scanf("%d", &id);
                for (int i = 0; i < totalMedicines; i++) {
                    if (medicines[i].id == id) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    printf("Medicine with ID %d not found!\n", id);
                } else {
                    printf("Enter new quantity for medicine: ");
                    scanf("%d", &quantity);
                    medicines[index].quantity = quantity;
                    printf("Quantity for medicine with ID %d updated successfully!\n", id);
                }
                break;
            }
            case 5: {
                printf("\nList of all medicines:\n");
                printf("ID\tName\t\t\tPrice\tQuantity\n");
                for (int i = 0; i < totalMedicines; i++) {
                    printf("%d\t%-20s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
                }
                break;
            }
            case 6: {
                FILE *file;
                printf("\nEnter filename to save changes: ");
                scanf(" %[^\n]", filename);
                file = fopen(filename, "w");
                if (file == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }
                fprintf(file, "ID,Name,Price,Quantity\n");
                for (int i = 0; i < totalMedicines; i++) {
                    fprintf(file, "%d,%s,%.2f,%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
                }
                printf("Changes saved successfully and program will exit now.\n");
                fclose(file);
                break;
            }
            default: {
                printf("\nInvalid choice!\n");
                break;
            }
        }
    } while(choice != 6);

    free(medicines);
    return 0;
}