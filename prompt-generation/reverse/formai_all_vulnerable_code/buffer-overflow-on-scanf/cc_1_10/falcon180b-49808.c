//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be added.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    time_t start_time;
    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].start_time);

    time_t end_time;
    printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].end_time);

    num_appointments++;
}

void list_appointments() {
    if (num_appointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Add appointment\n");
        printf("2. List appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_appointment();
            break;
        case 2:
            list_appointments();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}