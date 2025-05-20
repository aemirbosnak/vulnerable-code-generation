//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DOCTORS 10
#define MAX_APPOINTMENTS 100

// Appointment structure
typedef struct {
    char doctor[50];
    char patient[50];
    char date[20];
    char time[10];
} Appointment;

// Doctor structure
typedef struct {
    char name[50];
    char specialty[50];
    int appointments_count;
    Appointment appointments[MAX_APPOINTMENTS];
} Doctor;

// Array of doctors
Doctor doctors[MAX_DOCTORS];
int doctor_count = 0;

// Function prototypes
void menu();
void add_doctor();
void view_doctors();
void schedule_appointment();
void view_appointments();

int main() {
    menu();
    return 0;
}

// Prints the main menu
void menu() {
    int choice;
    do {
        printf("\n------ Appointment Scheduler Menu ------\n");
        printf("1. Add Doctor\n2. View Doctors\n3. Schedule Appointment\n4. View Appointments\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_doctor();
                break;
            case 2:
                view_doctors();
                break;
            case 3:
                schedule_appointment();
                break;
            case 4:
                view_appointments();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

// Adds a doctor to the array of doctors
void add_doctor() {
    Doctor doc;
    printf("\nEnter doctor name: ");
    scanf("%s", doc.name);
    printf("Enter doctor specialty: ");
    scanf("%s", doc.specialty);
    doc.appointments_count = 0;
    doctors[doctor_count] = doc;
    doctor_count++;
    printf("%s added successfully.\n", doc.name);
}

// Views the list of doctors
void view_doctors() {
    if (doctor_count == 0) {
        printf("\nNo doctors added yet.\n");
    } else {
        printf("\n------ List of Doctors ------\n");
        for (int i = 0; i < doctor_count; i++) {
            printf("%d. Name: %s, Specialty: %s\n", i+1, doctors[i].name, doctors[i].specialty);
            printf("   Appointments: %d\n", doctors[i].appointments_count);
            printf("\n");
        }
    }
}

// Schedules an appointment
void schedule_appointment() {
    char doc_name[50];
    int doc_index = -1;
    bool valid_time = true;

    printf("\nEnter doctor name: ");
    scanf("%s", doc_name);

    // Search for doctor by name
    for (int i = 0; i < doctor_count; i++) {
        if (strcmp(doctors[i].name, doc_name) == 0) {
            doc_index = i;
            break;
        }
    }

    if (doc_index == -1) {
        printf("\nDoctor not found. Please try again.\n");
        return;
    }

    // Check if doctor has any available slots
    if (doctors[doc_index].appointments_count >= MAX_APPOINTMENTS) {
        printf("\nThis doctor has no available slots for today. Try another day.\n");
        return;
    }

    // Check if doctor has any appointments yet
    if (doctors[doc_index].appointments_count == 0) {
        printf("\nDoctor has no appointments scheduled yet. First appointment is 9:00 AM.\n");
        strcpy(doctors[doc_index].appointments[0].time, "9:00 AM");
    }

    // Get appointment details from user
    Appointment apt;
    printf("Enter patient name: ");
    scanf("%s", apt.patient);
    printf("Enter appointment date (MM/DD/YYYY): ");
    scanf("%s", apt.date);

    // Validate time
    do {
        valid_time = true;
        printf("Enter appointment time (HH:MM AM/PM): ");
        scanf("%s", apt.time);

        // Check if time is in correct format
        if (strlen(apt.time) != 8) {
            printf("Invalid time format. Please try again.\n");
            valid_time = false;
            continue;
        }

        int hh = atoi(strtok(apt.time, ":"));
        int mm = atoi(strtok(NULL, " "));
        char period[3];
        strcpy(period, strtok(NULL, " "));

        // Check if hour is valid
        if (hh < 1 || hh > 12) {
            printf("Invalid hour. Please try again.\n");
            valid_time = false;
            continue;
        }

        // Check if minute is valid
        if (mm < 0 || mm > 59) {
            printf("Invalid minute. Please try again.\n");
            valid_time = false;
            continue;
        }

        // Check if period is valid
        if (strcmp(period, "AM") != 0 && strcmp(period, "PM") != 0) {
            printf("Invalid period. Please try again.\n");
            valid_time = false;
            continue;
        }

        // Check for overlapping appointments
        for (int i = 0; i < doctors[doc_index].appointments_count; i++) {
            if (strcmp(doctors[doc_index].appointments[i].date, apt.date) == 0 &&
                strcmp(doctors[doc_index].appointments[i].time, apt.time) == 0) {
                printf("This time slot is already taken. Please choose another time.\n");
                valid_time = false;
                break;
            }
        }

    } while (!valid_time);

    // Add appointment to doctor's list
    doctors[doc_index].appointments[doctors[doc_index].appointments_count] = apt;
    doctors[doc_index].appointments_count++;

    printf("\nAppointment scheduled successfully for %s with Dr. %s on %s at %s.\n", apt.patient, doctors[doc_index].name, apt.date, apt.time);
}

// Displays the list of appointments for a particular doctor
void view_appointments() {
    char doc_name[50];
    int doc_index = -1;

    printf("\nEnter doctor name: ");
    scanf("%s", doc_name);

    // Search for doctor by name
    for (int i = 0; i < doctor_count; i++) {
        if (strcmp(doctors[i].name, doc_name) == 0) {
            doc_index = i;
            break;
        }
    }

    if (doc_index == -1) {
        printf("\nDoctor not found. Please try again.\n");
        return;
    }

    if (doctors[doc_index].appointments_count == 0) {
        printf("\nNo appointments scheduled for this doctor yet.\n");
    } else {
        printf("\n------ Appointments for Dr. %s ------\n", doctors[doc_index].name);
        for (int i = 0; i < doctors[doc_index].appointments_count; i++) {
            printf("Patient: %s, Date: %s, Time: %s\n", doctors[doc_index].appointments[i].patient, doctors[doc_index].appointments[i].date, doctors[doc_index].appointments[i].time);
        }
    }
}