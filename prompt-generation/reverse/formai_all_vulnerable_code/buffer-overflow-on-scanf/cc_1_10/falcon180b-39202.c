//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char date[10];
    char time[10];
    char location[50];
    int duration;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone_number);

    printf("Enter email: ");
    scanf("%s", appointments[num_appointments].email);

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);

    printf("Enter location: ");
    scanf("%s", appointments[num_appointments].location);

    printf("Enter duration (in minutes): ");
    scanf("%d", &appointments[num_appointments].duration);

    printf("\nAppointment added.\n\n");
}

void view_appointments(Appointment* appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s - %s - %s - %d minutes\n", appointments[i].name, appointments[i].phone_number, appointments[i].email, appointments[i].date, appointments[i].time, appointments[i].duration);
    }
}

void search_appointment(Appointment* appointments, int num_appointments, char* search_term) {
    int found = 0;
    printf("\nSearching for '%s'...\n", search_term);
    for (int i = 0; i < num_appointments; i++) {
        if (strstr(appointments[i].name, search_term) || strstr(appointments[i].phone_number, search_term) || strstr(appointments[i].email, search_term) || strstr(appointments[i].location, search_term)) {
            printf("%s - %s - %s - %s - %s - %d minutes\n", appointments[i].name, appointments[i].phone_number, appointments[i].email, appointments[i].date, appointments[i].time, appointments[i].duration);
            found = 1;
        }
    }
    if (!found) {
        printf("No appointments found.\n");
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        printf("\n\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Search appointments\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_appointments == MAX_APPOINTMENTS) {
                    printf("Maximum number of appointments reached.\n");
                } else {
                    add_appointment(appointments, num_appointments);
                    num_appointments++;
                }
                break;
            case 2:
                if (num_appointments == 0) {
                    printf("No appointments.\n");
                } else {
                    view_appointments(appointments, num_appointments);
                }
                break;
            case 3:
                printf("Enter search term: ");
                char search_term[MAX_NAME_LENGTH];
                scanf("%s", search_term);
                search_appointment(appointments, num_appointments, search_term);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}