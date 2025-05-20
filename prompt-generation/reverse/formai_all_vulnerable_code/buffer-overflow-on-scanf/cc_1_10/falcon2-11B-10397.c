//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENT_LENGTH 50
#define MAX_PATIENT_LENGTH 50
#define MAX_TIME_LENGTH 50

typedef struct {
    char appointment_name[MAX_APPOINTMENT_LENGTH];
    char patient_name[MAX_PATIENT_LENGTH];
    char appointment_date[MAX_TIME_LENGTH];
} Appointment;

int main() {
    Appointment appointments[100]; // maximum 100 appointments
    int num_appointments = 0;
    int index = 0;

    // Prompt user to enter appointment details
    printf("Enter appointment name (up to %d characters): ", MAX_APPOINTMENT_LENGTH);
    scanf("%s", appointments[index].appointment_name);

    printf("Enter patient name (up to %d characters): ", MAX_PATIENT_LENGTH);
    scanf("%s", appointments[index].patient_name);

    printf("Enter appointment date (in format MM/DD/YYYY): ");
    scanf("%s", appointments[index].appointment_date);

    index++;
    num_appointments++;

    // Repeat for multiple appointments

    while (num_appointments < 100) {
        printf("Enter appointment name (up to %d characters): ", MAX_APPOINTMENT_LENGTH);
        scanf("%s", appointments[index].appointment_name);

        printf("Enter patient name (up to %d characters): ", MAX_PATIENT_LENGTH);
        scanf("%s", appointments[index].patient_name);

        printf("Enter appointment date (in format MM/DD/YYYY): ");
        scanf("%s", appointments[index].appointment_date);

        index++;
        num_appointments++;
    }

    // Display appointments
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Appointment Name: %s\n", appointments[i].appointment_name);
        printf("Patient Name: %s\n", appointments[i].patient_name);
        printf("Appointment Date: %s\n", appointments[i].appointment_date);
        printf("\n");
    }

    return 0;
}