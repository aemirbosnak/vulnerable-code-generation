//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for medicine
struct Medicine {
    int id; //unique id for medicine
    char name[50]; //name of the medicine
    int quantity; //number of stock available
    float price; //price of one unit
};

//function to add new medicine to the store
void addMedicine(struct Medicine *m, int *n) {
    printf("Enter details of medicine:\n");
    printf("Name: ");
    scanf("%s", m[*n].name);
    printf("Quantity: ");
    scanf("%d", &m[*n].quantity);
    printf("Price: ");
    scanf("%f", &m[*n].price);
    m[*n].id = *n; //assigning id to the medicine
    printf("Medicine added successfully!\n");
    *n = *n + 1; //incrementing total no. of medicines in the store
}

//function to display details of all medicines in the store
void displayAllMedicines(struct Medicine *m, int n) {
    if(n == 0) {
        printf("No medicines available in the store.\n");
        return;
    }
    printf("Details of all medicines in the store:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%s\t%d\t\t%f\n", m[i].id, m[i].name, m[i].quantity, m[i].price);
    }
}

//function to search for a medicine by id
void searchMedicineById(struct Medicine *m, int n) {
    if(n == 0) {
        printf("No medicines available in the store.\n");
        return;
    }
    int id;
    printf("Enter id of the medicine to search: ");
    scanf("%d", &id);
    for(int i=0; i<n; i++) {
        if(m[i].id == id) {
            printf("Details of medicine with id %d:\n", id);
            printf("Name: %s\n", m[i].name);
            printf("Quantity: %d\n", m[i].quantity);
            printf("Price: %f\n", m[i].price);
            return;
        }
    }
    printf("Medicine with id %d not found in the store.\n", id);
}

int main() {
    struct Medicine *medicines = (struct Medicine*) malloc(sizeof(struct Medicine) * 10); //allocating space for 10 medicines initially
    int n = 0; //initially no medicines in the store
    int choice;
    do {
        printf("\nMedical Store Management System:\n");
        printf("1. Add Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search Medicine By ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(medicines, &n);
                break;
            case 2:
                displayAllMedicines(medicines, n);
                break;
            case 3:
                searchMedicineById(medicines, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    free(medicines); //freeing the allocated memory
    return 0;
}