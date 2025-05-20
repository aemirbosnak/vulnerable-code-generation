//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine
{
    char name[50];
    char manufacturer[50];
    int quantity;
    float price; 
};

void addMedicine()
{
    FILE *fptr;
    struct medicine m;

    printf("\nEnter medicine name: ");
    scanf("%s", m.name);
    printf("Enter medicine manufacturer: ");
    scanf("%s", m.manufacturer);
    printf("Enter medicine quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &m.price);

    fptr = fopen("medicine.dat", "ab");
    fwrite(&m, sizeof(struct medicine), 1, fptr);
    fclose(fptr);

    printf("\nMedicine has been added successfully!\n");
}

void displayMedicines()
{
    FILE *fptr;
    struct medicine m;

    fptr = fopen("medicine.dat", "rb");
    if (fptr == NULL)
    {
        printf("No medicines available!\n");
    }
    else
    {
        printf("Name\tManufacturer\tQuantity\tPrice\n");
        while (fread(&m, sizeof(struct medicine), 1, fptr))
        {
            printf("%s\t%s\t\t%d\t\t%.2f\n", m.name, m.manufacturer, m.quantity, m.price);
        }
        fclose(fptr);
    }
}

void searchMedicine(char name[])
{
    FILE *fptr;
    struct medicine m;

    fptr = fopen("medicine.dat", "rb");
    if (fptr == NULL)
    {
        printf("No medicines available!\n");
    }
    else
    {
        int found = 0;
        while (fread(&m, sizeof(struct medicine), 1, fptr))
        {
            if (strcmp(name, m.name) == 0)
            {
                found = 1;
                printf("Name\tManufacturer\tQuantity\tPrice\n");
                printf("%s\t%s\t\t%d\t\t%.2f\n", m.name, m.manufacturer, m.quantity, m.price);
                break;
            }
        }
        if (!found)
        {
            printf("Medicine not found!\n");
        }
        fclose(fptr);
    }
}

int main()
{
    int choice;
    char name[50];

    do 
    {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n2. Display Medicines\n3. Search Medicine\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                printf("Enter medicine name to search: ");
                scanf("%s", name);
                searchMedicine(name);
                break;
            case 4:
                printf("Thank you for using the program!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}