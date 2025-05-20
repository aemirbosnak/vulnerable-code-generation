//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_SIZE 50

typedef struct {
    char name[MAX_NAME_SIZE];
    int appointment_id;
    int appointment_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int next_appointment_id = 1;

void add_appointment(char* name, int appointment_time) {
    int i;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].appointment_id == 0) {
            strcpy(appointments[i].name, name);
            appointments[i].appointment_id = next_appointment_id;
            appointments[i].appointment_time = appointment_time;
            next_appointment_id++;
            return;
        }
    }
    printf("Sorry, no more appointments available.\n");
}

void view_appointments() {
    int i;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].appointment_id!= 0) {
            printf("Appointment %d: %s at %d\n", appointments[i].appointment_id, appointments[i].name, appointments[i].appointment_time);
        }
    }
}

int main() {
    int choice;
    char name[MAX_NAME_SIZE];

    while (1) {
        printf("1. Add appointment\n2. View appointments\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            add_appointment(name, 0);
            break;

        case 2:
            view_appointments();
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}