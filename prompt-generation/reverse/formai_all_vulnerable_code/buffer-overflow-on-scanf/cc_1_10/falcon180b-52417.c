//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments;

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);
    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);
    num_appointments++;
}

void remove_appointment() {
    int index;
    printf("Enter index of appointment to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_appointments) {
        num_appointments--;
        for (int i = index; i < num_appointments; i++) {
            appointments[i] = appointments[i+1];
        }
    } else {
        printf("Invalid index.\n");
    }
}

void view_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Enter 1 to add an appointment, 2 to remove an appointment, or 3 to view appointments.\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add_appointment();
            break;
        case 2:
            remove_appointment();
            break;
        case 3:
            view_appointments();
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}