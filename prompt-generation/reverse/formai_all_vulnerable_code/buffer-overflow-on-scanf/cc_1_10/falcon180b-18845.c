//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
} appointment;

void schedule_appointment(appointment* appointments, int num_appointments, char* name, char* date) {
    for(int i = 0; i < num_appointments; i++) {
        if(strcmp(appointments[i].name, name) == 0) {
            printf("Error: Appointment already scheduled for %s on %s.\n", name, date);
            return;
        }
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].date, date);
    num_appointments++;
}

void display_schedule(appointment* appointments, int num_appointments) {
    printf("Schedule:\n");
    for(int i = 0; i < num_appointments; i++) {
        printf("%s - %s\n", appointments[i].name, appointments[i].date);
    }
}

void main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    system("clear");

    while(1) {
        system("clear");
        printf("Appointment Scheduler\n");
        printf("1. Schedule appointment\n");
        printf("2. Display schedule\n");
        printf("3. Quit\n");

        int choice = 0;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", appointments[num_appointments].name);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", appointments[num_appointments].date);
                num_appointments++;
                break;
            case 2:
                display_schedule(appointments, num_appointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}