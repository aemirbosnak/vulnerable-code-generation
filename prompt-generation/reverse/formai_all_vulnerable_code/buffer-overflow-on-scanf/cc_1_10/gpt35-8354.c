//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining Constants
#define MAX 10
#define MAX_MEDICINE_NAME 30
#define MAX_SUPPLIER_NAME 25
#define MAX_EXD_DATE 10
#define MAX_MFG_DATE 10
#define MAX_MEDICINE_AMOUNT 200
#define MAX_MEDICINE_PRICE 3

//Structure for Medicine
struct medicine {
    char medicine_name[MAX_MEDICINE_NAME];
    int medicine_id;
    char supplier_name[MAX_SUPPLIER_NAME];
    float medicine_price;
    int medicine_amount;
    char mfg_date[MAX_MFG_DATE];
    char exd_date[MAX_EXD_DATE];
};

//Header for functions
int menu();
void addNewMedicine(struct medicine *md, int);
void displayMedicine(struct medicine *md, int);
void removeMedicine(struct medicine *md, int);

void main() {
    int choice;
    int medicine_count = 0;
    struct medicine md[MAX];

    while(1) {
        choice = menu();
        switch(choice) {
            case 1:
                addNewMedicine(md, medicine_count);
                medicine_count++;
                break;
            case 2:
                displayMedicine(md, medicine_count);
                break;
            case 3:
                removeMedicine(md, medicine_count);
                medicine_count--;
                break;
            case 4:
                printf("\nExiting the program.\n");
                exit(0);
            default:
                printf("\nInvalid Input!\n");
                break;
        }
    }
}

//Function to display menu options
int menu() {
    int choice;

    printf("\n** MEDICAL STORE MANAGEMENT SYSTEM **\n");
    printf("\n1] Add New Medicine.");
    printf("\n2] Display Medicine.");
    printf("\n3] Remove Medicine.");
    printf("\n4] Exit.");
    printf("\nEnter Your Choice: ");
    scanf("%d", &choice);

    return choice;
}

//Function to add new medicine
void addNewMedicine(struct medicine *md, int index) {

    printf("\n** ADD MEDICINE **\n");

    printf("\nMedicine Name: ");
    scanf("%s", md[index].medicine_name);

    printf("Medicine ID: ");
    scanf("%d", &md[index].medicine_id);

    printf("Supplier Name: ");
    scanf("%s", md[index].supplier_name);

    printf("Medicine Price: ");
    scanf("%f", &md[index].medicine_price);

    printf("Medicine Amount: ");
    scanf("%d", &md[index].medicine_amount);

    printf("Mfg Date [DD/MM/YYYY]: ");
    scanf("%s", md[index].mfg_date);

    printf("Exd Date [DD/MM/YYYY]: ");
    scanf("%s", md[index].exd_date);

    printf("\nMedicine has been added successfully!\n");
    return;
}

//Function to display medicine details
void displayMedicine(struct medicine *md, int medicine_count) {

    if(medicine_count == 0) {
        printf("\nNo Medicines in the Inventory!\n");
        return;
    }

    printf("\n** MEDICINE DETAILS **\n");

    int i;
    for(i = 0; i < medicine_count; i++) {
        printf("\nMedicine %d:", i+1);
        printf("\nMedicine Name: %s", md[i].medicine_name);
        printf("\nMedicine ID: %d", md[i].medicine_id);
        printf("\nSupplier Name: %s", md[i].supplier_name);
        printf("\nMedicine Price: %.2f", md[i].medicine_price);
        printf("\nMedicine Amount: %d", md[i].medicine_amount);
        printf("\nMfg Date: %s", md[i].mfg_date);
        printf("\nExd Date: %s\n", md[i].exd_date);
    }

    return;
}

//Function to remove medicine from inventory
void removeMedicine(struct medicine *md, int medicine_count) {

    if(medicine_count == 0) {
        printf("\nNo Medicines in the Inventory!\n");
        return;
    }

    int med_id;
    int i, j;

    printf("\n** REMOVE MEDICINE **\n");

    printf("\nEnter the Medicine ID: ");
    scanf("%d", &med_id);

    for(i = 0; i < medicine_count; i++) {
        if(md[i].medicine_id == med_id) {
            for(j = i; j < medicine_count - 1; j++) {
                md[j] = md[j+1];
            }
            printf("\nMedicine has been removed successfully!\n");
            return;
        }
    }

    printf("\nMedicine ID not found!\n");
    return;
}