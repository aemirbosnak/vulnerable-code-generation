//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct medicine {
    char name[50];
    int qty;
    float price;
};

void addMedicine(struct medicine list[], int *size) {
    printf("Enter name of medicine: ");
    scanf("%s", list[*size].name);
    printf("Enter quantity of medicine: ");
    scanf("%d", &list[*size].qty);
    printf("Enter price of medicine: ");
    scanf("%f", &list[*size].price);
    
    (*size)++;
    printf("Medicine successfully added!\n\n");
}

void removeMedicine(struct medicine list[], int *size) {
    char name[50];
    printf("Enter name of medicine you want to remove: ");
    scanf("%s", name);
    
    int i, index = -1;
    for (i = 0; i < *size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Medicine not found!\n\n");
    } else {
        for (i = index; i < *size - 1; i++) {
            list[i] = list[i+1];
        }
        (*size)--;
        printf("Medicine successfully removed!\n\n");
    }
}

void displayMedicines(struct medicine list[], int size) {
    int i;
    printf("|%-20s|%-10s|%-10s|\n", "Medicine", "Quantity", "Price");
    for (i = 0; i < size; i++) {
        printf("|%-20s|%-10d|%-10.2f|\n", list[i].name, list[i].qty, list[i].price);
    }
    printf("\n");
}

int main() {
    struct medicine list[100];
    int size = 0, choice;
    
    printf("===== C MEDICAL STORE MANAGEMENT SYSTEM =====\n");
    
    while (1) {
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Display medicines\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMedicine(list, &size);
                break;
            case 2:
                removeMedicine(list, &size);
                break;
            case 3:
                displayMedicines(list, size);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n\n");
        }
    }
    
    return 0;
}