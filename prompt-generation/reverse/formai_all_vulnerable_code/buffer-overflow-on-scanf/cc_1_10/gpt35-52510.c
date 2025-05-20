//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for storing medicine details
struct Medicine {
    char name[50];
    char brand[50];
    int quantity;
    float price;
};

//function declarations
void addMedicine();
void removeMedicine();
void searchMedicine();
void viewAllMedicines();

//global variables
struct Medicine med[100];
int num_meds = 0;

int main() {

    int choice;

    while(1) {
        printf("\n\n======= Medical Store Management System =======\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. View All Medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addMedicine();
                    break;

            case 2: removeMedicine();
                    break;

            case 3: searchMedicine();
                    break;

            case 4: viewAllMedicines();
                    break;

            case 5: exit(0);

            default: printf("Invalid choice! Please try again.\n");
                     break;
        }
    }

    return 0;
}

void addMedicine() {
    printf("\n\n======= Add New Medicine =======\n");

    printf("Enter Medicine Name: ");
    scanf("%s", med[num_meds].name);

    printf("Enter Medicine Brand: ");
    scanf("%s", med[num_meds].brand);

    printf("Enter Medicine Quantity: ");
    scanf("%d", &med[num_meds].quantity);

    printf("Enter Medicine Price: ");
    scanf("%f", &med[num_meds].price);

    printf("\nMedicine Added Successfully!\n");

    num_meds++;
}

void removeMedicine() {
    char name[50];
    printf("\n\n======= Remove Medicine =======\n");

    printf("Enter Name of Medicine to be Removed: ");
    scanf("%s", name);

    int found = 0;
    for(int i=0;i<num_meds;i++) {
        if(strcmp(med[i].name, name) == 0) {
            found = 1;
            for(int j=i;j<num_meds-1;j++) {
                med[j] = med[j+1];
            }
            num_meds--;
            printf("Medicine Removed Successfully!\n");
            break;
        }
    }

    if(found == 0) {
        printf("Medicine not found in stock.\n");
    }
}

void searchMedicine() {
    char name[50];
    printf("\n\n======= Search Medicine =======\n");

    printf("Enter Name of Medicine to Search: ");
    scanf("%s", name);

    int found = 0;
    for(int i=0;i<num_meds;i++) {
        if(strcmp(med[i].name, name) == 0) {
            found = 1;
            printf("Details of Medicine:\n");
            printf("Name: %s\n", med[i].name);
            printf("Brand: %s\n", med[i].brand);
            printf("Quantity: %d\n", med[i].quantity);
            printf("Price: %.2f\n", med[i].price);
            break;
        }
    }

    if(found == 0) {
        printf("Medicine not found in stock.\n");
    }
}

void viewAllMedicines() {
    printf("\n\n======= All Medicines in Stock =======\n");

    for(int i=0;i<num_meds;i++) {
        printf("Details of Medicine %d:\n", i+1);
        printf("Name: %s\n", med[i].name);
        printf("Brand: %s\n", med[i].brand);
        printf("Quantity: %d\n", med[i].quantity);
        printf("Price: %.2f\n", med[i].price);
    }

    if(num_meds == 0) {
        printf("No Medicines in Stock!\n");
    }
}