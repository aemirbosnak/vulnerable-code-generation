//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MED_NAME_SIZE 50

typedef struct medicine {
    int id;
    char name[MED_NAME_SIZE];
    float price;
    int stock;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int numMedicines = 0;

void addMedicine() {
    int id;
    char name[MED_NAME_SIZE];
    float price;
    int stock;
    
    printf("Enter ID of medicine: ");
    scanf("%d", &id);
    getchar(); // Remove newline character from buffer
    
    printf("Enter name of medicine: ");
    fgets(name, MED_NAME_SIZE, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character from string
    
    printf("Enter price of medicine: ");
    scanf("%f", &price);
    getchar(); // Remove newline character from buffer
    
    printf("Enter stock of medicine: ");
    scanf("%d", &stock);
    getchar(); // Remove newline character from buffer
    
    Medicine med = {id, "", price, stock};
    strncpy(med.name, name, MED_NAME_SIZE);
    medicines[numMedicines++] = med;
    
    printf("Medicine added successfully!\n");
}

void printMedicines() {
    printf("ID\tName\t\tPrice\tStock\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%d\t%-15s%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].stock);
    }
}

void main() {
    int choice;
    
    while (1) {
        printf("\n1. Add medicine\n");
        printf("2. Print all medicines\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                printMedicines();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option selected\n");
        }
    }
}