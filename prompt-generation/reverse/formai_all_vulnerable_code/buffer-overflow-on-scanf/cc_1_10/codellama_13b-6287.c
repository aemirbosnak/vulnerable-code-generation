//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: funny
/*
 * Medical Store Management System
 * By Anonymous
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a patient
typedef struct {
    char name[100];
    int age;
    char gender;
    char disease[100];
} Patient;

// Structure to represent a medication
typedef struct {
    char name[100];
    int quantity;
    float price;
} Medication;

// Structure to represent a transaction
typedef struct {
    int id;
    Patient patient;
    Medication medication;
    int quantity;
    float price;
    char date[10];
} Transaction;

// Function to print the welcome message
void welcome() {
    printf("Welcome to the Medical Store Management System\n");
    printf("What would you like to do?\n");
    printf("1. Add a new patient\n");
    printf("2. Add a new medication\n");
    printf("3. Add a new transaction\n");
    printf("4. Print the patient list\n");
    printf("5. Print the medication list\n");
    printf("6. Print the transaction list\n");
    printf("7. Exit\n");
}

// Function to add a new patient
void addPatient(Patient *patient) {
    printf("Enter the patient's name: ");
    scanf("%s", patient->name);
    printf("Enter the patient's age: ");
    scanf("%d", &patient->age);
    printf("Enter the patient's gender: ");
    scanf(" %c", &patient->gender);
    printf("Enter the patient's disease: ");
    scanf("%s", patient->disease);
}

// Function to add a new medication
void addMedication(Medication *medication) {
    printf("Enter the medication's name: ");
    scanf("%s", medication->name);
    printf("Enter the medication's quantity: ");
    scanf("%d", &medication->quantity);
    printf("Enter the medication's price: ");
    scanf("%f", &medication->price);
}

// Function to add a new transaction
void addTransaction(Transaction *transaction) {
    printf("Enter the transaction's id: ");
    scanf("%d", &transaction->id);
    printf("Enter the patient's name: ");
    scanf("%s", transaction->patient.name);
    printf("Enter the medication's name: ");
    scanf("%s", transaction->medication.name);
    printf("Enter the quantity: ");
    scanf("%d", &transaction->quantity);
    printf("Enter the price: ");
    scanf("%f", &transaction->price);
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", transaction->date);
}

// Function to print the patient list
void printPatientList(Patient *patients, int numPatients) {
    printf("Patient List:\n");
    for (int i = 0; i < numPatients; i++) {
        printf("%d. %s (%d years old, %c)\n", i + 1, patients[i].name, patients[i].age, patients[i].gender);
    }
}

// Function to print the medication list
void printMedicationList(Medication *medications, int numMedications) {
    printf("Medication List:\n");
    for (int i = 0; i < numMedications; i++) {
        printf("%d. %s (%d units, %.2f)\n", i + 1, medications[i].name, medications[i].quantity, medications[i].price);
    }
}

// Function to print the transaction list
void printTransactionList(Transaction *transactions, int numTransactions) {
    printf("Transaction List:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("%d. %d %s (%d units, %.2f, %s)\n", i + 1, transactions[i].id, transactions[i].patient.name, transactions[i].quantity, transactions[i].price, transactions[i].date);
    }
}

// Main function
int main() {
    // Declare variables
    int option;
    Patient patients[100];
    Medication medications[100];
    Transaction transactions[100];
    int numPatients = 0, numMedications = 0, numTransactions = 0;

    // Welcome message
    welcome();

    // Loop until the user chooses to exit
    do {
        // Get the user's option
        printf("Enter your option: ");
        scanf("%d", &option);

        // Add a new patient
        if (option == 1) {
            addPatient(&patients[numPatients++]);
        }
        // Add a new medication
        else if (option == 2) {
            addMedication(&medications[numMedications++]);
        }
        // Add a new transaction
        else if (option == 3) {
            addTransaction(&transactions[numTransactions++]);
        }
        // Print the patient list
        else if (option == 4) {
            printPatientList(patients, numPatients);
        }
        // Print the medication list
        else if (option == 5) {
            printMedicationList(medications, numMedications);
        }
        // Print the transaction list
        else if (option == 6) {
            printTransactionList(transactions, numTransactions);
        }
        // Exit the program
        else if (option == 7) {
            break;
        }
        // Invalid option
        else {
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 7);

    return 0;
}