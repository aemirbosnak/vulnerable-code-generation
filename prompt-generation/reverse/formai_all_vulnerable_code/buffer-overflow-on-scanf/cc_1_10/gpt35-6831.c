//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10  // maximum number of appointments that can be scheduled
#define MAX_NAME_LENGTH 30  // maximum length of name of the person scheduling the appointment
#define MAX_DATE_LENGTH 11  // maximum length of the scheduled date in the format of DD/MM/YYYY
#define MAX_TIME_LENGTH 6  // maximum length of the scheduled time in 24-hour format

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

void printMenu() {
    printf("Appointment Scheduler\n");
    printf("----------------------\n");
    printf("1. Schedule an appointment\n");
    printf("2. Cancel an appointment\n");
    printf("3. View scheduled appointments\n");
    printf("4. Exit\n");
}

int getOption() {
    int option;
    printf("Enter your choice: ");
    scanf("%d", &option);
    return option;
}

void addAppointment(Appointment appointments[], int *numAppointments) {
    if (*numAppointments >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments have already been scheduled.\n");
        return;
    }

    char name[MAX_NAME_LENGTH], date[MAX_DATE_LENGTH], time[MAX_TIME_LENGTH];
    printf("Enter name: ");
    scanf(" %[^\n]", name);  // read name with spaces
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", date);
    printf("Enter time (24-hour format): ");
    scanf("%s", time);

    strcpy(appointments[*numAppointments].name, name);
    strcpy(appointments[*numAppointments].date, date);
    strcpy(appointments[*numAppointments].time, time);
    printf("Appointment scheduled successfully.\n");
    (*numAppointments)++;
}

void cancelAppointment(Appointment appointments[], int *numAppointments) {
    if (*numAppointments == 0) {
        printf("No appointments scheduled yet.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    int i, j;
    printf("Enter name: ");
    scanf(" %[^\n]", name);

    bool found = false;
    for (i = 0; i < *numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            found = true;
            printf("Appointment scheduled on %s at %s has been cancelled.\n", appointments[i].date, appointments[i].time);
            for (j = i+1; j < *numAppointments; j++) {
                strcpy(appointments[j-1].name, appointments[j].name);
                strcpy(appointments[j-1].date, appointments[j].date);
                strcpy(appointments[j-1].time, appointments[j].time);
            }
            (*numAppointments)--;
            break;
        }
    }
    if (!found) {
        printf("No appointment has been scheduled with the given name.\n");
    }
}

void viewAppointments(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments scheduled yet.\n");
        return;
    }

    printf("Scheduled Appointments\n");
    printf("----------------------\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s on %s at %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0, option;

    do {
        printMenu();
        option = getOption();

        switch(option) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                cancelAppointment(appointments, &numAppointments);
                break;
            case 3:
                viewAppointments(appointments, numAppointments);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }

        printf("\n");
    } while (option != 4);

    return 0;
}