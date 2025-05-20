//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int age;
    char email[50];
    char phone[20];
} Patient;

typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
} AppointmentDate;

typedef struct {
    Patient patient;
    AppointmentDate date;
} Appointment;

int main() {
    int choice;
    bool isRunning = true;
    Appointment appointments[100];
    int appointmentCount = 0;

    while (isRunning) {
        printf("Select an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View all appointments\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter patient name: ");
                char patientName[50];
                scanf("%s", patientName);

                printf("Enter patient age: ");
                int patientAge;
                scanf("%d", &patientAge);

                printf("Enter patient email: ");
                char patientEmail[50];
                scanf("%s", patientEmail);

                printf("Enter patient phone: ");
                char patientPhone[20];
                scanf("%s", patientPhone);

                printf("Enter appointment date (dd/mm/yyyy hh:mm): ");
                int day, month, year, hour, minute;
                scanf("%d/%d/%d %d:%d", &day, &month, &year, &hour, &minute);

                Appointment appointment;
                strcpy(appointment.patient.name, patientName);
                appointment.patient.age = patientAge;
                strcpy(appointment.patient.email, patientEmail);
                strcpy(appointment.patient.phone, patientPhone);
                appointment.date.day = day;
                appointment.date.month = month;
                appointment.date.year = year;
                appointment.date.hour = hour;
                appointment.date.minute = minute;

                appointments[appointmentCount] = appointment;
                appointmentCount++;

                printf("Appointment scheduled successfully!\n\n");
                break;
            }
            case 2: {
                if (appointmentCount == 0) {
                    printf("No appointments scheduled yet.\n\n");
                } else {
                    printf("All appointments:\n");
                    for (int i = 0; i < appointmentCount; i++) {
                        printf("Patient name: %s\n", appointments[i].patient.name);
                        printf("Patient age: %d\n", appointments[i].patient.age);
                        printf("Patient email: %s\n", appointments[i].patient.email);
                        printf("Patient phone: %s\n", appointments[i].patient.phone);
                        printf("Appointment date (dd/mm/yyyy hh:mm): %d/%d/%d %d:%d\n\n", 
                            appointments[i].date.day, appointments[i].date.month, 
                            appointments[i].date.year, appointments[i].date.hour, 
                            appointments[i].date.minute);
                    }
                }
                break;
            }
            case 3: {
                printf("Exiting program...\n");
                isRunning = false;
                break;
            }
            default: {
                printf("Invalid option.\n\n");
                break;
            }
        }
    }

    return 0;
}