//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

void addMedicine();
void searchMedicine();
void updateMedicine();
void displayMedicine();
void deleteMedicine();

int main() {
    int choice;

    while (1) {
        printf("\n===== MEDICAL STORE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Display Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                searchMedicine();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                displayMedicine();
                break;
            case 5:
                deleteMedicine();
                break;
            case 6:
                printf("Exiting the program...");
                exit(0);
            default:
                printf("Invalid choice. Please try again.");
        }
    }

    return 0;
}

void addMedicine() {
    struct Medicine med;
    FILE *fp;

    fp = fopen("medicines.dat", "ab+");
    fflush(stdin);

    printf("\nEnter medicine name: ");
    scanf("%[^\n]%*c", med.name);

    printf("\nEnter manufacturer name: ");
    scanf("%[^\n]%*c", med.manufacturer);

    printf("\nEnter medicine quantity: ");
    scanf("%d", &med.quantity);

    printf("\nEnter medicine price: ");
    scanf("%f", &med.price);

    fwrite(&med, sizeof(struct Medicine), 1, fp);
    fclose(fp);

    printf("\nMedicine added successfully.");
}

void searchMedicine() {
    struct Medicine med;
    int flag = 0, id = 1;
    char name[50];
    FILE *fp;

    fp = fopen("medicines.dat", "rb");

    printf("\nEnter medicine name to search: ");
    scanf("%[^\n]%*c", name);

    while (fread(&med, sizeof(struct Medicine), 1, fp) == 1) {
        if (strcmp(med.name, name) == 0) {
            printf("\nMedicine ID: %d", id);
            printf("\nMedicine Name: %s", med.name);
            printf("\nManufacturer Name: %s", med.manufacturer);
            printf("\nQuantity: %d", med.quantity);
            printf("\nPrice: %.2f", med.price);
            flag = 1;
        }
        id++;
    }

    fclose(fp);

    if (flag == 0)
        printf("\nMedicine not found.");
}

void updateMedicine() {
    struct Medicine med;
    int flag = 0, id = 1, choice;
    char name[50];
    FILE *fp, *tmpfp;

    fp = fopen("medicines.dat", "rb");
    tmpfp = fopen("tmp.dat", "wb");

    printf("\nEnter medicine name to update: ");
    scanf("%[^\n]%*c", name);

    while (fread(&med, sizeof(struct Medicine), 1, fp) == 1) {
        if (strcmp(med.name, name) == 0) {
            printf("\nMedicine ID: %d", id);
            printf("\nMedicine Name: %s", med.name);
            printf("\nManufacturer Name: %s", med.manufacturer);
            printf("\nQuantity: %d", med.quantity);
            printf("\nPrice: %.2f", med.price);
            flag = 1;

            printf("\n\nWhich information do you want to update?");
            printf("\n1. Medicine Name");
            printf("\n2. Manufacturer Name");
            printf("\n3. Quantity");
            printf("\n4. Price");

            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("\nEnter new medicine name: ");
                    scanf("%s", med.name);
                    break;
                case 2:
                    printf("\nEnter new manufacturer name: ");
                    scanf("%s", med.manufacturer);
                    break;
                case 3:
                    printf("\nEnter new quantity: ");
                    scanf("%d", &med.quantity);
                    break;
                case 4:
                    printf("\nEnter new price: ");
                    scanf("%f", &med.price);
                    break;
                default:
                    printf("\nInvalid choice.");
            }
        }
        fwrite(&med, sizeof(struct Medicine), 1, tmpfp);
        id++;
    }

    fclose(fp);
    fclose(tmpfp);

    if (flag == 0) {
        printf("\nMedicine not found.");
        remove("tmp.dat");
    } else {
        remove("medicines.dat");
        rename("tmp.dat", "medicines.dat");
        printf("\nMedicine updated successfully.");
    }
}

void displayMedicine() {
    struct Medicine med;
    int id = 1;
    FILE *fp;

    fp = fopen("medicines.dat", "rb");

    while (fread(&med, sizeof(struct Medicine), 1, fp) == 1) {
        printf("\nMedicine ID: %d", id);
        printf("\nMedicine Name: %s", med.name);
        printf("\nManufacturer Name: %s", med.manufacturer);
        printf("\nQuantity: %d", med.quantity);
        printf("\nPrice: %.2f\n", med.price);
        id++;
    }

    fclose(fp);
}

void deleteMedicine() {
    struct Medicine med;
    int flag = 0, id = 1;
    char name[50];
    FILE *fp, *tmpfp;

    fp = fopen("medicines.dat", "rb");
    tmpfp = fopen("tmp.dat", "wb");

    printf("\nEnter medicine name to delete: ");
    scanf("%[^\n]%*c", name);

    while (fread(&med, sizeof(struct Medicine), 1, fp) == 1) {
        if (strcmp(med.name, name) == 0) {
            printf("\nMedicine ID: %d", id);
            printf("\nMedicine Name: %s", med.name);
            printf("\nManufacturer Name: %s", med.manufacturer);
            printf("\nQuantity: %d", med.quantity);
            printf("\nPrice: %.2f", med.price);
            flag = 1;
        } else {
            fwrite(&med, sizeof(struct Medicine), 1, tmpfp);
        }
        id++;
    }

    fclose(fp);
    fclose(tmpfp);

    if (flag == 0) {
        printf("\nMedicine not found.");
        remove("tmp.dat");
    } else {
        remove("medicines.dat");
        rename("tmp.dat", "medicines.dat");
        printf("\nMedicine deleted successfully.");
    }
}