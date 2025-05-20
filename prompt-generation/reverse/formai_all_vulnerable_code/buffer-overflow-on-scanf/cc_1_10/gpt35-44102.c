//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine{
    char name[50];
    int quantity;
    float price;
};

void addMedicine();
void viewMedicine();
void searchMedicine();
void updateMedicine();
void deleteMedicine();

int main(){
    printf("\t\tWelcome to Medicine Store Management System\n\n");
    printf("Select an option:\n");
    printf("1. Add medicine\n");
    printf("2. View medicine\n");
    printf("3. Search medicine\n");
    printf("4. Update medicine\n");
    printf("5. Delete medicine\n");
    printf("6. Exit\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: addMedicine(); break;
        case 2: viewMedicine(); break;
        case 3: searchMedicine(); break;
        case 4: updateMedicine(); break;
        case 5: deleteMedicine(); break;
        case 6: printf("Thank you for using Medicine Store Management System!\n"); break;
        default: printf("Invalid choice, please try again!\n"); break;
    }
    return 0;
}

void addMedicine(){
    FILE *fp;
    struct Medicine m;
    fp = fopen("medicine.dat", "ab");
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter price: ");
    scanf("%f", &m.price);
    fwrite(&m, sizeof(m), 1, fp);
    fclose(fp);
    printf("Medicine added successfully!\n");
}

void viewMedicine(){
    FILE *fp;
    struct Medicine m;
    fp = fopen("medicine.dat", "rb");
    printf("Name\t\tQuantity\tPrice\n");
    while(fread(&m, sizeof(m), 1, fp) == 1){
        printf("%s\t\t%d\t\t%f\n", m.name, m.quantity, m.price);
    }
    fclose(fp);
}

void searchMedicine(){
    FILE *fp;
    struct Medicine m;
    char search[50];
    fp = fopen("medicine.dat", "rb");
    printf("Enter medicine name to search: ");
    scanf("%s", search);
    int found = 0;
    while(fread(&m, sizeof(m), 1, fp) == 1){
        if(strcmp(m.name, search) == 0){
            printf("Name\t\tQuantity\tPrice\n");
            printf("%s\t\t%d\t\t%f\n", m.name, m.quantity, m.price);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if(found == 0){
        printf("Medicine not found!\n");
    }
}

void updateMedicine(){
    FILE *fp, *fp_temp;
    struct Medicine m, new_m;
    char search[50];
    fp = fopen("medicine.dat", "rb");
    fp_temp = fopen("temp.dat", "wb");
    printf("Enter medicine name to update: ");
    scanf("%s", search);
    int found = 0;
    while(fread(&m, sizeof(m), 1, fp) == 1){
        if(strcmp(m.name, search) == 0){
            printf("Enter new medicine name: ");
            scanf("%s", new_m.name);
            printf("Enter new quantity: ");
            scanf("%d", &new_m.quantity);
            printf("Enter new price: ");
            scanf("%f", &new_m.price);
            fwrite(&new_m, sizeof(new_m), 1, fp_temp);
            printf("Medicine updated successfully!\n");
            found = 1;
        }
        else{
            fwrite(&m, sizeof(m), 1, fp_temp);
        }
    }
    fclose(fp);
    fclose(fp_temp);
    if(found == 0){
        printf("Medicine not found!\n");
    }
    remove("medicine.dat");
    rename("temp.dat", "medicine.dat");
}

void deleteMedicine(){
    FILE *fp, *fp_temp;
    struct Medicine m;
    char search[50];
    fp = fopen("medicine.dat", "rb");
    fp_temp = fopen("temp.dat", "wb");
    printf("Enter medicine name to delete: ");
    scanf("%s", search);
    int found = 0;
    while(fread(&m, sizeof(m), 1, fp) == 1){
        if(strcmp(m.name, search) == 0){
            printf("Medicine deleted successfully!\n");
            found = 1;
        }
        else{
            fwrite(&m, sizeof(m), 1, fp_temp);
        }
    }
    fclose(fp);
    fclose(fp_temp);
    if(found == 0){
        printf("Medicine not found!\n");
    }
    remove("medicine.dat");
    rename("temp.dat", "medicine.dat");
}