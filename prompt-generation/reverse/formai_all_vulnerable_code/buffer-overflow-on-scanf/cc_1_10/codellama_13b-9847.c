//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: surprised
/*
 * Medical Store Management System
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a patient
typedef struct {
    char name[50];
    char address[50];
    char phone_number[15];
    char disease[50];
    char medication[50];
    char doctor[50];
    float bill;
} Patient;

// Function to add a patient to the system
void addPatient(Patient* patient) {
    printf("Enter patient name: ");
    scanf("%s", patient->name);
    printf("Enter patient address: ");
    scanf("%s", patient->address);
    printf("Enter patient phone number: ");
    scanf("%s", patient->phone_number);
    printf("Enter patient disease: ");
    scanf("%s", patient->disease);
    printf("Enter patient medication: ");
    scanf("%s", patient->medication);
    printf("Enter patient doctor: ");
    scanf("%s", patient->doctor);
    printf("Enter patient bill: ");
    scanf("%f", &patient->bill);
}

// Function to print patient details
void printPatient(Patient patient) {
    printf("Patient Name: %s\n", patient.name);
    printf("Patient Address: %s\n", patient.address);
    printf("Patient Phone Number: %s\n", patient.phone_number);
    printf("Patient Disease: %s\n", patient.disease);
    printf("Patient Medication: %s\n", patient.medication);
    printf("Patient Doctor: %s\n", patient.doctor);
    printf("Patient Bill: %f\n", patient.bill);
}

// Function to search patient by name
void searchPatientByName(Patient* patient, char* name) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(patient[i].name, name) == 0) {
            printPatient(patient[i]);
            return;
        }
    }
    printf("Patient not found\n");
}

// Function to search patient by disease
void searchPatientByDisease(Patient* patient, char* disease) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(patient[i].disease, disease) == 0) {
            printPatient(patient[i]);
            return;
        }
    }
    printf("Patient not found\n");
}

// Function to update patient details
void updatePatient(Patient* patient) {
    printf("Enter patient name: ");
    scanf("%s", patient->name);
    printf("Enter patient address: ");
    scanf("%s", patient->address);
    printf("Enter patient phone number: ");
    scanf("%s", patient->phone_number);
    printf("Enter patient disease: ");
    scanf("%s", patient->disease);
    printf("Enter patient medication: ");
    scanf("%s", patient->medication);
    printf("Enter patient doctor: ");
    scanf("%s", patient->doctor);
    printf("Enter patient bill: ");
    scanf("%f", &patient->bill);
}

// Function to delete patient
void deletePatient(Patient* patient) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(patient[i].name, patient->name) == 0) {
            patient[i].name[0] = '\0';
            patient[i].address[0] = '\0';
            patient[i].phone_number[0] = '\0';
            patient[i].disease[0] = '\0';
            patient[i].medication[0] = '\0';
            patient[i].doctor[0] = '\0';
            patient[i].bill = 0;
            return;
        }
    }
    printf("Patient not found\n");
}

int main() {
    Patient patient[5];
    int choice;

    // Add patient details
    for (int i = 0; i < 5; i++) {
        addPatient(&patient[i]);
    }

    // Search patient by name
    char name[50];
    printf("Enter patient name to search: ");
    scanf("%s", name);
    searchPatientByName(patient, name);

    // Search patient by disease
    char disease[50];
    printf("Enter patient disease to search: ");
    scanf("%s", disease);
    searchPatientByDisease(patient, disease);

    // Update patient details
    char name_update[50];
    printf("Enter patient name to update: ");
    scanf("%s", name_update);
    updatePatient(patient);

    // Delete patient
    char name_delete[50];
    printf("Enter patient name to delete: ");
    scanf("%s", name_delete);
    deletePatient(patient);

    return 0;
}