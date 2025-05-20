//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct {
    char name[50];
    int age;
    float weight;
} Patient;

typedef struct {
    char name[50];
    float price;
} Medicine;

typedef struct {
    char name[50];
    int qty;
} Prescription;

typedef struct {
    char name[50];
    float quantity;
} Stock;

int main() {
    // Create some patients
    Patient patient1 = {"John Doe", 35, 75.5};
    Patient patient2 = {"Jane Doe", 28, 60.3};
    Patient patient3 = {"Bob Smith", 42, 82.1};

    // Create some medicines
    Medicine medicine1 = {"Aspirin", 5.99};
    Medicine medicine2 = {"Ibuprofen", 9.99};
    Medicine medicine3 = {"Paracetamol", 3.99};

    // Create some prescriptions
    Prescription prescription1 = {"Medicine1", 2};
    Prescription prescription2 = {"Medicine2", 1};
    Prescription prescription3 = {"Medicine3", 3};

    // Create some stocks
    Stock stock1 = {"Aspirin", 10};
    Stock stock2 = {"Ibuprofen", 8};
    Stock stock3 = {"Paracetamol", 12};

    // Now we have a medical store with patients, medicines, prescriptions, and stocks!

    // Let's do some funny stuff with them!

    // Let's start with some jokes
    printf("Why did the aspirin go to the doctor?\n");
    printf("Because it had a headache!\n");

    printf("Why did the ibuprofen go to the doctor?\n");
    printf("Because it had a pain in the neck!\n");

    printf("Why did the paracetamol go to the doctor?\n");
    printf("Because it had a fever!\n");

    // Now let's see how many prescriptions each patient has
    printf("Patient 1 has %d prescriptions.\n", patient1.age);
    printf("Patient 2 has %d prescriptions.\n", patient2.age);
    printf("Patient 3 has %d prescriptions.\n", patient3.age);

    // And how much stock of each medicine
    printf("Aspirin stock: %d\n", stock1.quantity);
    printf("Ibuprofen stock: %d\n", stock2.quantity);
    printf("Paracetamol stock: %d\n", stock3.quantity);

    // Let's calculate the total price of all medicines in stock
    float totalPrice = 0.0;
    totalPrice += medicine1.price * stock1.quantity;
    totalPrice += medicine2.price * stock2.quantity;
    totalPrice += medicine3.price * stock3.quantity;
    printf("Total price of medicines in stock: $%.2f\n", totalPrice);

    // Let's see how much each patient owes
    float patientOwings[3] = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        int prescriptions[3] = {0, 0, 0};
        for (int j = 0; j < 3; j++) {
            prescriptions[j] += prescription1.qty * patient1.name[j] + prescription2.qty * patient2.name[j] + prescription3.qty * patient3.name[j];
        }
        patientOwings[i] = prescriptions[i] * medicine1.price + prescriptions[i + 1] * medicine2.price + prescriptions[i + 2] * medicine3.price;
    }
    printf("Patient 1 owes: $%.2f\n", patientOwings[0]);
    printf("Patient 2 owes: $%.2f\n", patientOwings[1]);
    printf("Patient 3 owes: $%.2f\n", patientOwings[2]);

    // Let's see if the stock is sufficient for the prescriptions
    if (stock1.quantity >= prescription1.qty) {
        printf("Stock is sufficient for Medicine1 prescription.\n");
    } else {
        printf("Stock is not sufficient for Medicine1 prescription.\n");
    }

    if (stock2.quantity >= prescription2.qty) {
        printf("Stock is sufficient for Medicine2 prescription.\n");
    } else {
        printf("Stock is not sufficient for Medicine2 prescription.\n");
    }

    if (stock3.quantity >= prescription3.qty) {
        printf("Stock is sufficient for Medicine3 prescription.\n");
    } else {
        printf("Stock is not sufficient for Medicine3 prescription.\n");
    }

    // Let's see if the prescriptions are sufficient for the patients
    if (prescription1.qty >= patient1.age) {
        printf("Prescription is sufficient for patient 1.\n");
    } else {
        printf("Prescription is not sufficient for patient 1.\n");
    }

    if (prescription2.qty >= patient2.age) {
        printf("Prescription is sufficient for patient 2.\n");
    } else {
        printf("Prescription is not sufficient for patient 2.\n");
    }

    if (prescription3.qty >= patient3.age) {
        printf("Prescription is sufficient for patient 3.\n");
    } else {
        printf("Prescription is not sufficient for patient 3.\n");
    }

    return 0;
}