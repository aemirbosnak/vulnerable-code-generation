//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct patient {
    char name[50];
    int age;
};

void insert_patient(struct patient* patients, int patients_size, int new_patient_size) {
    int i = 0;
    struct patient new_patient;
    printf("Enter the patient's name: ");
    scanf("%s", new_patient.name);
    printf("Enter the patient's age: ");
    scanf("%d", &new_patient.age);
    for (i = 0; i < patients_size; i++) {
        if (strcmp(patients[i].name, new_patient.name) == 0) {
            printf("Patient already exists.\n");
            return;
        }
    }
    if (new_patient_size < patients_size) {
        for (i = patients_size; i < new_patient_size; i++) {
            patients[i] = new_patient;
        }
    }
    else {
        for (i = patients_size; i > 0; i--) {
            patients[i] = patients[i - 1];
        }
        patients[0] = new_patient;
    }
}

void display_patients(struct patient* patients, int patients_size) {
    int i = 0;
    for (i = 0; i < patients_size; i++) {
        printf("Patient %d: %s (%d)\n", i + 1, patients[i].name, patients[i].age);
    }
}

int main() {
    struct patient patients[5];
    int patients_size = sizeof(patients) / sizeof(patients[0]);
    int new_patient_size;

    while (1) {
        printf("1. Insert a new patient\n");
        printf("2. Display all patients\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the patient list: ");
                scanf("%d", &new_patient_size);
                insert_patient(patients, patients_size, new_patient_size);
                patients_size = new_patient_size;
                break;
            case 2:
                display_patients(patients, patients_size);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}