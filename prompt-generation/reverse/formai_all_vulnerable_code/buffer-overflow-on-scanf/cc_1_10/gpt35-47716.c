//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    char name[50];
    Time startTime;
    int duration; // in minutes
} Appointment;

int numAppointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void addAppointment(char* name, Time startTime, int duration) {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached\n");
        return;
    }

    Appointment newAppointment;
    strcpy(newAppointment.name, name);
    newAppointment.startTime = startTime;
    newAppointment.duration = duration;

    appointments[numAppointments++] = newAppointment;
}

void printAppointment(Appointment appointment) {
    printf("%02d:%02d - %02d:%02d %s\n", 
            appointment.startTime.hour, appointment.startTime.minute, 
            appointment.startTime.hour + appointment.duration/60, appointment.startTime.minute + appointment.duration%60,
            appointment.name
    );
}

void printAppointments() {
    for (int i=0; i<numAppointments; i++) {
        printf("%d. ", i+1);
        printAppointment(appointments[i]);
    }
}

bool isTimeValid(Time time) {
    if (time.hour < 0 || time.hour > 23)
        return false;
    
    if (time.minute < 0 || time.minute > 59)
        return false;

    return true;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    printf("Welcome to Appointment Scheduler\n");

    while(true) {
        printf("\nMenu:\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        int choice;
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: {
                char name[50];
                printf("\nEnter name: ");
                fgets(name, sizeof(name), stdin);

                Time startTime;
                printf("\nEnter start time (hh:mm): ");
                scanf("%d:%d", &startTime.hour, &startTime.minute);
                clearInputBuffer();

                if (!isTimeValid(startTime)) {
                    printf("\nError: Invalid time\n");
                    break;
                }

                int duration;
                printf("\nEnter duration (in minutes): ");
                scanf("%d", &duration);
                clearInputBuffer();

                addAppointment(name, startTime, duration);
                printf("\nAppointment added successfully\n");
                break;
            }
            case 2:
                printf("\nAppointments:\n");
                printAppointments();
                break;
            case 3:
                printf("\nGoodbye\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }

    return 0;
}