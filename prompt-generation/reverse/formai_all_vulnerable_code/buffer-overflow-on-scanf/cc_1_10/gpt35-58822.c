//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000

struct Appointment {
    char name[50];
    char date[11];
    char time[6];
};

int num_appointments = 0;

struct Appointment appointments[MAX_APPOINTMENTS];

void menu() {
    printf("\nAppointment Scheduler\n");
    printf("----------------------\n");
    printf("1. Create Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
}

void create_appointment() {
    if(num_appointments == MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    struct Appointment appt;
    printf("\nEnter client name: ");
    scanf("%s", appt.name);
    printf("Enter date(yyyy-mm-dd): ");
    scanf("%s", appt.date);
    printf("Enter time(HH:MM): ");
    scanf("%s", appt.time);

    appointments[num_appointments++] = appt;

    printf("\nAppointment created successfully.\n");
}

void view_appointments() {
    if(num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nUpcoming Appointments\n");
    printf("----------------------\n");
    printf("Client Name\tDate\t\tTime\n");

    for(int i = 0; i < num_appointments; i++) {
        printf("%s\t\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    int option;

    do {
        menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: create_appointment(); break;
            case 2: view_appointments(); break;
            case 3: break;
            default: printf("Invalid option. Please try again.\n");
        }
    } while(option != 3);

    printf("Exiting application...\n");

    return 0;
}