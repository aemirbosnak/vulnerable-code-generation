//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare function prototypes
void addMedicine();
void viewMedicineList();
void searchMedicine();
void updateMedicine();
void deleteMedicine();

int main()
{
    int choice;

    while(1) {
        printf("\n\n-----------------------");
        printf("\n Medical Store Management System");
        printf("\n-----------------------");
        printf("\n1. Add Medicine");
        printf("\n2. View Medicine List");
        printf("\n3. Search Medicine");
        printf("\n4. Update Medicine Quantity");
        printf("\n5. Delete Medicine");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addMedicine();
                break;

            case 2:
                viewMedicineList();
                break;

            case 3:
                searchMedicine();
                break;

            case 4:
                updateMedicine();
                break;

            case 5:
                deleteMedicine();
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("\nInvalid choice, please try again\n");
                break;
        }
    }

    return 0;
}

void addMedicine()
{
    FILE *fp;
    char name[20];
    int qty;
    float price;

    printf("\nEnter medicine name: ");
    scanf("%s", name);

    printf("Enter medicine quantity: ");
    scanf("%d", &qty);

    printf("Enter medicine price: ");
    scanf("%f", &price);

    fp = fopen("medicine.dat", "ab");
    if(fp == NULL) // check if file exists or not
    {
        printf("\nError opening file\n");
        return;
    }

    // write data to file
    fwrite(&name, sizeof(name), 1, fp);
    fwrite(&qty, sizeof(qty), 1, fp);
    fwrite(&price, sizeof(price), 1, fp);

    fclose(fp); // close file
    printf("\nMedicine added successfully!\n");
}

void viewMedicineList()
{
    FILE *fp;
    int i = 1, qty;
    float price;
    char name[20];

    fp = fopen("medicine.dat", "rb");
    if(fp == NULL) // check if file exists or not
    {
        printf("\nError opening file\n");
        return;
    }

    printf("\nMedicine List\n");
    printf("-----------------------------------------------------\n");
    printf("ID. Name\t\tQuantity\tPrice\n");
    printf("-----------------------------------------------------\n");

    // read data from file
    while(fread(&name, sizeof(name), 1, fp) == 1)
    {
        fread(&qty, sizeof(qty), 1, fp);
        fread(&price, sizeof(price), 1, fp);

        printf("%d. %-20s %7d \t %.2f\n", i++, name, qty, price);
    }

    fclose(fp); // close file
}

void searchMedicine()
{
    FILE *fp;
    char name[20];
    int qty;
    float price;
    int found = 0;

    printf("\nEnter name of the medicine to search: ");
    scanf("%s", name);

    fp = fopen("medicine.dat", "rb");
    if(fp == NULL) // check if file exists or not
    {
        printf("\nError opening file\n");
        return;
    }

    // read data from file
    while(fread(&name, sizeof(name), 1, fp) == 1)
    {
        fread(&qty, sizeof(qty), 1, fp);
        fread(&price, sizeof(price), 1, fp);

        if(strcmp(name, name) == 0)
        {
            printf("\nMedicine details\n");
            printf("-------------------------\n");
            printf("Name: %s", name);
            printf("\nQuantity: %d", qty);
            printf("\nPrice: %.2f", price);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nMedicine not found\n");
    }

    fclose(fp); // close file
}

void updateMedicine()
{
    FILE *fp;
    char name[20];
    int qty, newQty = 0;
    float price;

    printf("\nEnter name of the medicine to update: ");
    scanf("%s", name);

    fp = fopen("medicine.dat", "rb+");
    if(fp == NULL) // check if file exists or not
    {
        printf("\nError opening file\n");
        return;
    }

    // read and update data in file
    while(fread(&name, sizeof(name), 1, fp) == 1)
    {
        fread(&qty, sizeof(qty), 1, fp);
        fread(&price, sizeof(price), 1, fp);

        if(strcmp(name, name) == 0)
        {
            printf("\nEnter new quantity: ");
            scanf("%d", &newQty);

            fseek(fp, -sizeof(qty), SEEK_CUR); // move file pointer back by one record
            fwrite(&newQty, sizeof(newQty), 1, fp); // write new data to file

            printf("\nMedicine quantity updated successfully!\n");
            break;
        }
    }

    fclose(fp); // close file
}

void deleteMedicine()
{
    FILE *fp, *tempFile;
    char name[20];
    int qty;
    float price;

    printf("\nEnter name of the medicine to delete: ");
    scanf("%s", name);

    fp = fopen("medicine.dat", "rb");
    if(fp == NULL) // check if file exists or not
    {
        printf("\nError opening file\n");
        return;
    }

    tempFile = fopen("temporary.dat", "wb");
    if(tempFile == NULL)
    {
        printf("\nError creating temporary file\n");
        return;
    }

    // copy data to temporary file, except the record to be deleted
    while(fread(&name, sizeof(name), 1, fp) == 1)
    {
        fread(&qty, sizeof(qty), 1, fp);
        fread(&price, sizeof(price), 1, fp);

        if(strcmp(name, name) != 0)
        {
            fwrite(&name, sizeof(name), 1, tempFile);
            fwrite(&qty, sizeof(qty), 1, tempFile);
            fwrite(&price, sizeof(price), 1, tempFile);
        }
    }

    fclose(fp); // close file
    fclose(tempFile); // close temporary file

    remove("medicine.dat"); // remove original file
    rename("temporary.dat", "medicine.dat"); // rename temporary file as original file

    printf("\nMedicine deleted successfully!\n");
}