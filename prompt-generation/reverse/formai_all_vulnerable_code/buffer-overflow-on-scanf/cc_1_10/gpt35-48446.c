//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    int id;
    char name[50];
    float price;
};

void addMedicine() {
    FILE *fp;
    struct Medicine m;
    fp = fopen("medicines.dat", "ab");
    printf("Enter Medicine ID: ");
    scanf("%d", &m.id);
    printf("Enter Medicine Name: ");
    scanf("%s", m.name);
    printf("Enter Medicine Price: ");
    scanf("%f", &m.price);
    fwrite(&m, sizeof(struct Medicine), 1, fp);
    printf("Medicine Added Successfully!\n");
    fclose(fp);
}

void displayMedicines() {
    FILE *fp;
    struct Medicine m;
    fp = fopen("medicines.dat", "rb");
    printf("%-10s%-20s%s\n", "ID", "Name", "Price");
    while(fread(&m, sizeof(struct Medicine), 1, fp)) {
        printf("%-10d%-20s%.2f\n", m.id, m.name, m.price);
    }
    fclose(fp);
}

void searchMedicine() {
    FILE *fp;
    struct Medicine m;
    int id, found = 0;
    fp = fopen("medicines.dat", "rb");
    printf("Enter Medicine ID to Search: ");
    scanf("%d", &id);
    while(fread(&m, sizeof(struct Medicine), 1, fp)) {
        if(m.id == id) {
            printf("%-10s%-20s%s\n", "ID", "Name", "Price");
            printf("%-10d%-20s%.2f\n", m.id, m.name, m.price);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Medicine Not Found!\n");
    }
    fclose(fp);
}

void updateMedicine() {
    FILE *fp;
    struct Medicine m;
    int id, found = 0;
    fp = fopen("medicines.dat", "r+b");
    printf("Enter Medicine ID to Update: ");
    scanf("%d", &id);
    while(fread(&m, sizeof(struct Medicine), 1, fp)) {
        if(m.id == id) {
            printf("Enter New Medicine Name: ");
            scanf("%s", m.name);
            printf("Enter New Medicine Price: ");
            scanf("%f", &m.price);
            fseek(fp, -sizeof(struct Medicine), SEEK_CUR);
            fwrite(&m, sizeof(struct Medicine), 1, fp);
            found = 1;
            printf("Medicine Updated Successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("Medicine Not Found!\n");
    }
    fclose(fp);
}

void deleteMedicine() {
    FILE *fp, *fpTemp;
    struct Medicine m;
    int id, found = 0;
    fp = fopen("medicines.dat", "rb");
    fpTemp = fopen("temp.dat", "wb");
    printf("Enter Medicine ID to Delete: ");
    scanf("%d", &id);
    while(fread(&m, sizeof(struct Medicine), 1, fp)) {
        if(m.id == id) {
            found = 1;
        } else {
            fwrite(&m, sizeof(struct Medicine), 1, fpTemp);
        }
    }
    if(found) {
        printf("Medicine Deleted Successfully!\n");
    } else {
        printf("Medicine Not Found!\n");
    }
    fclose(fp);
    fclose(fpTemp);
    remove("medicines.dat");
    rename("temp.dat", "medicines.dat");
}

int main() {
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("0. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            addMedicine();
            break;
        case 2:
            displayMedicines();
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
        case 0:
            printf("Exiting Medical Store Management System...\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    } while(choice!=0);

    return 0;
}