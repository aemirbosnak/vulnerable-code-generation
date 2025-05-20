//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char medicineName[50];
    int quantity;
    double price;
} Medicine;

typedef struct {
    int id;
    char patientName[50];
    char doctorName[50];
    char medicineName[50];
    int quantity;
    double totalPrice;
} Prescription;

int main() {
    int numMedicines;
    printf("Enter the number of medicines: ");
    scanf("%d", &numMedicines);

    Medicine *medicines = malloc(numMedicines * sizeof(Medicine));
    for (int i = 0; i < numMedicines; i++) {
        printf("\nEnter details for medicine %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", medicines[i].medicineName);
        printf("Quantity: ");
        scanf("%d", &medicines[i].quantity);
        printf("Price: ");
        scanf("%lf", &medicines[i].price);
    }

    int numPrescriptions;
    printf("\nEnter the number of prescriptions: ");
    scanf("%d", &numPrescriptions);

    Prescription *prescriptions = malloc(numPrescriptions * sizeof(Prescription));
    for (int i = 0; i < numPrescriptions; i++) {
        printf("\nEnter details for prescription %d:\n", i + 1);
        printf("Patient Name: ");
        scanf("%s", prescriptions[i].patientName);
        printf("Doctor Name: ");
        scanf("%s", prescriptions[i].doctorName);
        printf("Medicine Name: ");
        scanf("%s", prescriptions[i].medicineName);
        printf("Quantity: ");
        scanf("%d", &prescriptions[i].quantity);

        for (int j = 0; j < numMedicines; j++) {
            if (strcmp(medicines[j].medicineName, prescriptions[i].medicineName) == 0) {
                double totalPrice = prescriptions[i].quantity * medicines[j].price;
                prescriptions[i].totalPrice = totalPrice;
                medicines[j].quantity -= prescriptions[i].quantity;
            }
        }
    }

    printf("\nMEDICINES:\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%s - %d - %.2lf\n", medicines[i].medicineName, medicines[i].quantity, medicines[i].price);
    }

    printf("\nPRESCRIPTIONS:\n");
    for (int i = 0; i < numPrescriptions; i++) {
        printf("ID: %d - Patient: %s - Doctor: %s - Medicine: %s - Quantity: %d - Total Price: %.2lf\n", 
        i + 1, prescriptions[i].patientName, prescriptions[i].doctorName, prescriptions[i].medicineName, 
        prescriptions[i].quantity, prescriptions[i].totalPrice);
    }

    free(medicines);
    free(prescriptions);

    return 0;
}