//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50
#define MAX_TIME_LENGTH 10

struct Appointment {
    char name[MAX_NAME_LENGTH];
    char start_time[MAX_TIME_LENGTH];
    char end_time[MAX_TIME_LENGTH];
};

struct Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *name, char *start_time, char *end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Max number of appointments reached.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].start_time, start_time);
    strcpy(appointments[num_appointments].end_time, end_time);
    num_appointments++;
}

int main() {
    char name[MAX_NAME_LENGTH];
    char start_time[MAX_TIME_LENGTH];
    char end_time[MAX_TIME_LENGTH];

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. List appointments\n");
        printf("3. Remove appointment\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter start time (HH:MM): ");
                scanf("%s", start_time);
                printf("Enter end time (HH:MM): ");
                scanf("%s", end_time);

                add_appointment(name, start_time, end_time);
                printf("Appointment added successfully.\n");
                break;
            case 2:
                if (num_appointments == 0) {
                    printf("No appointments found.\n");
                } else {
                    printf("\nAppointment List:\n");
                    for (int i = 0; i < num_appointments; i++) {
                        printf("%s (%s - %s)\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time);
                    }
                }
                break;
            case 3:
                if (num_appointments == 0) {
                    printf("No appointments found.\n");
                } else {
                    int index;
                    printf("Enter appointment index to remove: ");
                    scanf("%d", &index);

                    if (index >= 0 && index < num_appointments) {
                        for (int i = index; i < num_appointments - 1; i++) {
                            strcpy(appointments[i].name, appointments[i + 1].name);
                            strcpy(appointments[i].start_time, appointments[i + 1].start_time);
                            strcpy(appointments[i].end_time, appointments[i + 1].end_time);
                        }
                        num_appointments--;
                        printf("Appointment removed successfully.\n");
                    } else {
                        printf("Error: Invalid appointment index.\n");
                    }
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}