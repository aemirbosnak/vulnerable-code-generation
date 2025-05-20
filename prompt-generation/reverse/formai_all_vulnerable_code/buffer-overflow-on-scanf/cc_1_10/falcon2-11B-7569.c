//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
    char name[50];
    char address[100];
    int age;
    float blood_pressure;
    float pulse_rate;
    int appointments[10];
};

struct doctor {
    char name[50];
    char speciality[50];
    char phone[20];
};

struct clinic {
    char name[50];
    char address[100];
    int capacity;
    int beds[10];
    struct doctor doctors[10];
};

void create_patient(struct patient *patient) {
    printf("Enter patient name: ");
    scanf("%s", patient->name);
    printf("Enter patient address: ");
    scanf("%s", patient->address);
    printf("Enter patient age: ");
    scanf("%d", &patient->age);
    printf("Enter patient blood pressure: ");
    scanf("%f", &patient->blood_pressure);
    printf("Enter patient pulse rate: ");
    scanf("%f", &patient->pulse_rate);
}

void create_doctor(struct doctor *doctor) {
    printf("Enter doctor name: ");
    scanf("%s", doctor->name);
    printf("Enter doctor speciality: ");
    scanf("%s", doctor->speciality);
    printf("Enter doctor phone number: ");
    scanf("%s", doctor->phone);
}

void create_clinic(struct clinic *clinic) {
    printf("Enter clinic name: ");
    scanf("%s", clinic->name);
    printf("Enter clinic address: ");
    scanf("%s", clinic->address);
    printf("Enter clinic capacity: ");
    scanf("%d", &clinic->capacity);
}

void display_patient(struct patient *patient) {
    printf("Patient Details:\n");
    printf("Name: %s\n", patient->name);
    printf("Address: %s\n", patient->address);
    printf("Age: %d\n", patient->age);
    printf("Blood Pressure: %f\n", patient->blood_pressure);
    printf("Pulse Rate: %f\n", patient->pulse_rate);
}

void display_doctor(struct doctor *doctor) {
    printf("Doctor Details:\n");
    printf("Name: %s\n", doctor->name);
    printf("Speciality: %s\n", doctor->speciality);
    printf("Phone: %s\n", doctor->phone);
}

void display_clinic(struct clinic *clinic) {
    printf("Clinic Details:\n");
    printf("Name: %s\n", clinic->name);
    printf("Address: %s\n", clinic->address);
    printf("Capacity: %d\n", clinic->capacity);
}

int main() {
    struct patient patient1;
    create_patient(&patient1);
    display_patient(&patient1);

    struct doctor doctor1;
    create_doctor(&doctor1);
    display_doctor(&doctor1);

    struct clinic clinic1;
    create_clinic(&clinic1);
    display_clinic(&clinic1);

    return 0;
}