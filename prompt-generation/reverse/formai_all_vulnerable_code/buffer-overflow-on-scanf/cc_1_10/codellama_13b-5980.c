//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
/*
 * C Medical Store Management System
 * A simple program to manage medical stores
 *
 * Author: Your Name
 */

#include <stdio.h>
#include <stdlib.h>

// Structures for patients and drugs
typedef struct {
    int id;
    char name[50];
    char age;
    char gender;
    char address[100];
    char phone[20];
} patient;

typedef struct {
    int id;
    char name[50];
    char price;
    char quantity;
} drug;

// Functions for managing patients and drugs
void addPatient(patient* patients, int* numPatients) {
    printf("Enter patient details: ");
    scanf("%d %s %c %s %s %s", &patients[*numPatients].id, patients[*numPatients].name, &patients[*numPatients].age, patients[*numPatients].gender, patients[*numPatients].address, patients[*numPatients].phone);
    *numPatients += 1;
}

void addDrug(drug* drugs, int* numDrugs) {
    printf("Enter drug details: ");
    scanf("%d %s %c %d", &drugs[*numDrugs].id, drugs[*numDrugs].name, &drugs[*numDrugs].price, &drugs[*numDrugs].quantity);
    *numDrugs += 1;
}

void displayPatients(patient* patients, int numPatients) {
    printf("Patients: \n");
    for (int i = 0; i < numPatients; i++) {
        printf("%d: %s %c %s %s %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].address, patients[i].phone);
    }
}

void displayDrugs(drug* drugs, int numDrugs) {
    printf("Drugs: \n");
    for (int i = 0; i < numDrugs; i++) {
        printf("%d: %s %c %d\n", drugs[i].id, drugs[i].name, drugs[i].price, drugs[i].quantity);
    }
}

int main() {
    // Arrays for patients and drugs
    patient patients[100];
    drug drugs[100];

    // Variables for number of patients and drugs
    int numPatients = 0;
    int numDrugs = 0;

    // Main loop
    while (1) {
        printf("Menu: \n");
        printf("1. Add patient\n");
        printf("2. Add drug\n");
        printf("3. Display patients\n");
        printf("4. Display drugs\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(&patients, &numPatients);
                break;
            case 2:
                addDrug(&drugs, &numDrugs);
                break;
            case 3:
                displayPatients(patients, numPatients);
                break;
            case 4:
                displayDrugs(drugs, numDrugs);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}