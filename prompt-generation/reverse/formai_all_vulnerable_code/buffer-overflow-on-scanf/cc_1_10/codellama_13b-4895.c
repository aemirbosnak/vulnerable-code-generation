//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
// Medical Store Management System
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a patient
struct Patient {
    char name[50];
    char address[100];
    char phone[15];
    char disease[100];
    int age;
    float weight;
    float height;
};

// Structure to represent a medication
struct Medication {
    char name[50];
    char type[50];
    int price;
};

// Structure to represent a prescription
struct Prescription {
    char patient_name[50];
    char medication[50];
    int quantity;
};

// Function to create a new patient
void createPatient(struct Patient *patient) {
    printf("Enter patient name: ");
    scanf("%s", patient->name);
    printf("Enter patient address: ");
    scanf("%s", patient->address);
    printf("Enter patient phone: ");
    scanf("%s", patient->phone);
    printf("Enter patient disease: ");
    scanf("%s", patient->disease);
    printf("Enter patient age: ");
    scanf("%d", &patient->age);
    printf("Enter patient weight: ");
    scanf("%f", &patient->weight);
    printf("Enter patient height: ");
    scanf("%f", &patient->height);
}

// Function to create a new medication
void createMedication(struct Medication *medication) {
    printf("Enter medication name: ");
    scanf("%s", medication->name);
    printf("Enter medication type: ");
    scanf("%s", medication->type);
    printf("Enter medication price: ");
    scanf("%d", &medication->price);
}

// Function to create a new prescription
void createPrescription(struct Prescription *prescription) {
    printf("Enter patient name: ");
    scanf("%s", prescription->patient_name);
    printf("Enter medication name: ");
    scanf("%s", prescription->medication);
    printf("Enter quantity: ");
    scanf("%d", &prescription->quantity);
}

// Function to print a patient's information
void printPatient(struct Patient *patient) {
    printf("Patient Name: %s\n", patient->name);
    printf("Patient Address: %s\n", patient->address);
    printf("Patient Phone: %s\n", patient->phone);
    printf("Patient Disease: %s\n", patient->disease);
    printf("Patient Age: %d\n", patient->age);
    printf("Patient Weight: %f\n", patient->weight);
    printf("Patient Height: %f\n", patient->height);
}

// Function to print a medication's information
void printMedication(struct Medication *medication) {
    printf("Medication Name: %s\n", medication->name);
    printf("Medication Type: %s\n", medication->type);
    printf("Medication Price: %d\n", medication->price);
}

// Function to print a prescription's information
void printPrescription(struct Prescription *prescription) {
    printf("Patient Name: %s\n", prescription->patient_name);
    printf("Medication Name: %s\n", prescription->medication);
    printf("Quantity: %d\n", prescription->quantity);
}

int main() {
    struct Patient patient;
    struct Medication medication;
    struct Prescription prescription;

    // Create a new patient
    createPatient(&patient);

    // Create a new medication
    createMedication(&medication);

    // Create a new prescription
    createPrescription(&prescription);

    // Print patient's information
    printPatient(&patient);

    // Print medication's information
    printMedication(&medication);

    // Print prescription's information
    printPrescription(&prescription);

    return 0;
}