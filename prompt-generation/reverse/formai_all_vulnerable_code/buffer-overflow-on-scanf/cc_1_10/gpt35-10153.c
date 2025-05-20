//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char name[100];
    int age;
    char gender[10];
    char phone_number[15];
    int doctor_id;
    char appointment_date[11];
};

struct Doctor {
    int id;
    char name[100];
    char speciality[50];
    char clinic_location[100];
    int appointments_available;
};

struct Appointment {
    int id;
    int patient_id;
    int doctor_id;
    char date[11];
};

// Variables to keep track of the number of patients, doctors, and appointments
int num_patients = 0;
int num_doctors = 0;
int num_appointments = 0;

// Arrays to store the patients, doctors, and appointments
struct Patient patients[100];
struct Doctor doctors[10];
struct Appointment appointments[100];

// Function to add a new patient to the system
void add_patient() {
    printf("Enter patient name: ");
    scanf("%s", patients[num_patients].name);
    printf("Enter patient age: ");
    scanf("%d", &patients[num_patients].age);
    printf("Enter patient gender: ");
    scanf("%s", patients[num_patients].gender);
    printf("Enter patient phone number: ");
    scanf("%s", patients[num_patients].phone_number);
    num_patients++;
    printf("Patient added successfully!\n");
}

// Function to add a new doctor to the system
void add_doctor() {
    printf("Enter doctor name: ");
    scanf("%s", doctors[num_doctors].name);
    printf("Enter doctor speciality: ");
    scanf("%s", doctors[num_doctors].speciality);
    printf("Enter clinic location: ");
    scanf("%s", doctors[num_doctors].clinic_location);
    printf("Enter number of available appointments: ");
    scanf("%d", &doctors[num_doctors].appointments_available);
    doctors[num_doctors].id = num_doctors + 1;
    num_doctors++;
    printf("Doctor added successfully!\n");
}

// Function to schedule an appointment
void schedule_appointment() {
    // First, ask the user to select a doctor
    printf("Select a doctor:\n");
    for (int i = 0; i < num_doctors; i++) {
        printf("%d. %s (%s) - %s\n", doctors[i].id, doctors[i].name, doctors[i].speciality, doctors[i].clinic_location);
    }
    int selected_doctor_id;
    scanf("%d", &selected_doctor_id);
    // Check to make sure the selected doctor ID is valid
    if (selected_doctor_id < 1 || selected_doctor_id > num_doctors) {
        printf("Invalid doctor ID!\n");
        return;
    }
    // Check to make sure the selected doctor has available appointments
    if (doctors[selected_doctor_id - 1].appointments_available == 0) {
        printf("Sorry, this doctor has no available appointments!\n");
        return;
    }
    // Next, ask the user to enter patient information
    printf("Enter patient name: ");
    char patient_name[100];
    scanf("%s", patient_name);
    printf("Enter patient age: ");
    int patient_age;
    scanf("%d", &patient_age);
    printf("Enter patient gender: ");
    char patient_gender[10];
    scanf("%s", patient_gender);
    printf("Enter patient phone number: ");
    char patient_phone_number[15];
    scanf("%s", patient_phone_number);
    // Find the next available appointment for the selected doctor
    char appointment_date[11];
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].doctor_id == selected_doctor_id) {
            strcpy(appointment_date, appointments[i].date);
            break;
        }
    }
    int appointment_id = num_appointments + 1;
    // Add the appointment to the system
    strcpy(patients[num_patients].name, patient_name);
    patients[num_patients].age = patient_age;
    strcpy(patients[num_patients].gender, patient_gender);
    strcpy(patients[num_patients].phone_number, patient_phone_number);
    patients[num_patients].doctor_id = selected_doctor_id;
    strcpy(patients[num_patients].appointment_date, appointment_date);
    num_patients++;
    appointments[num_appointments].id = appointment_id;
    appointments[num_appointments].patient_id = num_patients;
    appointments[num_appointments].doctor_id = selected_doctor_id;
    strcpy(appointments[num_appointments].date, appointment_date);
    num_appointments++;
    doctors[selected_doctor_id - 1].appointments_available--;
    printf("Appointment scheduled for %s with Dr. %s on %s\n", patient_name, doctors[selected_doctor_id - 1].name, appointment_date);
}

int main() {
    while (1) {
        printf("Welcome to the appointment scheduler!\n");
        printf("Please select an option:\n");
        printf("1. Add patient\n");
        printf("2. Add doctor\n");
        printf("3. Schedule appointment\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                add_doctor();
                break;
            case 3:
                schedule_appointment();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}