//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine {
    char name[50];
    int id;
    float rate;
};

void addMedicine(struct Medicine *med, int size) {
    printf("Enter medicine name: ");
    scanf("%s", med[size].name);
    printf("Enter medicine id: ");
    scanf("%d", &med[size].id);
    printf("Enter medicine rate: ");
    scanf("%f", &med[size].rate);
}

void displayMedicines(struct Medicine *med, int size) {
    printf("Medicine Details\n");
    printf("Name\tID\tRate\n");
    for(int i=0; i<size; i++) {
        printf("%s\t%d\t%f\n", med[i].name, med[i].id, med[i].rate);
    }
}

void searchMedicine(struct Medicine *med, int size, int id) {
    for(int i=0; i<size; i++) {
        if(med[i].id == id) {
            printf("Medicine Details\n");
            printf("Name\tID\tRate\n");
            printf("%s\t%d\t%f\n", med[i].name, med[i].id, med[i].rate);
            return;
        }
    }
    printf("Medicine with ID %d not found\n", id);
}

int main() {
    int size, choice, id;
    printf("Enter number of medicines: ");
    scanf("%d", &size);
    struct Medicine *med = (struct Medicine *) malloc(size * sizeof(struct Medicine));
    do {
        printf("Menu\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(med, size);
                size++; // Increase the size since we added a new medicine
                break;
            case 2:
                displayMedicines(med, size);
                break;
            case 3:
                printf("Enter medicine ID: ");
                scanf("%d", &id);
                searchMedicine(med, size, id);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please select again\n");
        }
    } while(choice != 4);
    free(med);
    return 0;
}