//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int age;
    int appointment_time;
} Patient;

void generate_random_patients(Patient patients[], int num_patients) {
    srand(time(NULL));
    for (int i = 0; i < num_patients; i++) {
        patients[i].id = i;
        sprintf(patients[i].name, "Patient %d", i);
        patients[i].age = rand() % 100;
        patients[i].appointment_time = rand() % 24;
    }
}

void print_patient(Patient patient) {
    printf("ID: %d\n", patient.id);
    printf("Name: %s\n", patient.name);
    printf("Age: %d\n", patient.age);
    printf("Appointment Time: %d\n", patient.appointment_time);
}

void sort_patients_by_appointment_time(Patient patients[], int num_patients) {
    for (int i = 0; i < num_patients - 1; i++) {
        for (int j = 0; j < num_patients - i - 1; j++) {
            if (patients[j].appointment_time > patients[j + 1].appointment_time) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num_patients;
    printf("Enter the number of patients: ");
    scanf("%d", &num_patients);

    Patient patients[num_patients];
    generate_random_patients(patients, num_patients);

    printf("Unsorted Patients:\n");
    for (int i = 0; i < num_patients; i++) {
        print_patient(patients[i]);
    }

    sort_patients_by_appointment_time(patients, num_patients);

    printf("\nSorted Patients:\n");
    for (int i = 0; i < num_patients; i++) {
        print_patient(patients[i]);
    }

    return 0;
}