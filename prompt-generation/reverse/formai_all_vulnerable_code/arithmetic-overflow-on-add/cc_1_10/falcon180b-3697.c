//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DURATION 120
#define MIN_DURATION 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration;
    time_t start_time;
} appointment;

int num_appointments = 0;
appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be added.\n");
        return;
    }
    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[num_appointments].name);
    appointments[num_appointments].duration = rand() % (MAX_DURATION - MIN_DURATION) + MIN_DURATION;
    appointments[num_appointments].start_time = time(NULL) + (appointments[num_appointments].duration * 60);
    num_appointments++;
    printf("Appointment added successfully.\n");
}

void delete_appointment() {
    if (num_appointments == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    int index;
    printf("Enter the index of the appointment to delete: ");
    scanf("%d", &index);
    if (index < 0 || index >= num_appointments) {
        printf("Invalid index.\n");
        return;
    }
    num_appointments--;
    for (int i = index; i < num_appointments; i++) {
        appointments[i] = appointments[i + 1];
    }
    printf("Appointment deleted successfully.\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments to view.\n");
        return;
    }
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%d minutes) at %s\n", appointments[i].name, appointments[i].duration, ctime(&appointments[i].start_time));
    }
}

void main() {
    srand(time(NULL));
    int choice, index;
    while (1) {
        printf("1. Add appointment\n2. Delete appointment\n3. View appointments\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_appointment();
            break;
        case 2:
            printf("Enter the index of the appointment to delete: ");
            scanf("%d", &index);
            delete_appointment();
            break;
        case 3:
            view_appointments();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}