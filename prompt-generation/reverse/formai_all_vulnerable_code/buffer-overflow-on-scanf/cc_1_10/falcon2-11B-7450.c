//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Struct for storing appointments
struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    char details[100];
};

// Struct for storing appointments in an array
struct AppointmentArray {
    struct Appointment appointments[10];
    int numAppointments;
};

// Function to print all appointments in the array
void printAppointments(struct AppointmentArray *apArray) {
    printf("Appointments:\n");
    for (int i = 0; i < apArray->numAppointments; i++) {
        printf("Name: %s\n", apArray->appointments[i].name);
        printf("Date: %s\n", apArray->appointments[i].date);
        printf("Time: %s\n", apArray->appointments[i].time);
        printf("Details: %s\n", apArray->appointments[i].details);
        printf("\n");
    }
}

// Function to add an appointment to the array
void addAppointment(struct AppointmentArray *apArray, char *name, char *date, char *time, char *details) {
    apArray->numAppointments++;
    strcpy(apArray->appointments[apArray->numAppointments - 1].name, name);
    strcpy(apArray->appointments[apArray->numAppointments - 1].date, date);
    strcpy(apArray->appointments[apArray->numAppointments - 1].time, time);
    strcpy(apArray->appointments[apArray->numAppointments - 1].details, details);
}

// Function to remove an appointment from the array
void removeAppointment(struct AppointmentArray *apArray, char *name) {
    for (int i = 0; i < apArray->numAppointments; i++) {
        if (strcmp(apArray->appointments[i].name, name) == 0) {
            for (int j = i; j < apArray->numAppointments - 1; j++) {
                strcpy(apArray->appointments[j].name, apArray->appointments[j + 1].name);
                strcpy(apArray->appointments[j].date, apArray->appointments[j + 1].date);
                strcpy(apArray->appointments[j].time, apArray->appointments[j + 1].time);
                strcpy(apArray->appointments[j].details, apArray->appointments[j + 1].details);
            }
            apArray->numAppointments--;
            return;
        }
    }
}

// Function to search for an appointment by name
struct Appointment *searchAppointment(struct AppointmentArray *apArray, char *name) {
    for (int i = 0; i < apArray->numAppointments; i++) {
        if (strcmp(apArray->appointments[i].name, name) == 0) {
            return &(apArray->appointments[i]);
        }
    }
    return NULL;
}

// Function to modify an appointment by name
void modifyAppointment(struct AppointmentArray *apArray, char *name, char *date, char *time, char *details) {
    struct Appointment *appointment = searchAppointment(apArray, name);
    if (appointment!= NULL) {
        strcpy(appointment->name, date);
        strcpy(appointment->time, time);
        strcpy(appointment->details, details);
    }
}

int main() {
    struct AppointmentArray apArray;
    apArray.numAppointments = 0;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("1. Add appointment\n");
    printf("2. Remove appointment\n");
    printf("3. Search appointment\n");
    printf("4. Modify appointment\n");
    printf("5. Print appointments\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    while (choice!= 6) {
        switch (choice) {
            case 1: {
                printf("Enter appointment details:\n");
                printf("Name: ");
                char name[50];
                scanf("%s", name);
                printf("Date: ");
                char date[50];
                scanf("%s", date);
                printf("Time: ");
                char time[50];
                scanf("%s", time);
                printf("Details: ");
                char details[100];
                scanf("%s", details);
                addAppointment(&apArray, name, date, time, details);
                break;
            }
            case 2: {
                printf("Enter appointment name to remove: ");
                char name[50];
                scanf("%s", name);
                removeAppointment(&apArray, name);
                break;
            }
            case 3: {
                printf("Enter appointment name to search: ");
                char name[50];
                scanf("%s", name);
                struct Appointment *appointment = searchAppointment(&apArray, name);
                if (appointment!= NULL) {
                    printf("Name: %s\n", appointment->name);
                    printf("Date: %s\n", appointment->date);
                    printf("Time: %s\n", appointment->time);
                    printf("Details: %s\n", appointment->details);
                } else {
                    printf("Appointment not found\n");
                }
                break;
            }
            case 4: {
                printf("Enter appointment name to modify: ");
                char name[50];
                scanf("%s", name);
                printf("Enter new appointment details:\n");
                printf("Name: ");
                char date[50];
                scanf("%s", date);
                printf("Time: ");
                char time[50];
                scanf("%s", time);
                printf("Details: ");
                char details[100];
                scanf("%s", details);
                modifyAppointment(&apArray, name, date, time, details);
                break;
            }
            case 5: {
                printAppointments(&apArray);
                break;
            }
            default:
                printf("Invalid choice\n");
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    return 0;
}