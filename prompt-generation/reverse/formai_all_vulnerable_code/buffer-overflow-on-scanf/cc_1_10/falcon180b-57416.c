//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[50];
    int priority;
    int appointment_time;
    int duration;
} appointment;

appointment appointments[MAX_SIZE];
int num_appointments = 0;

void add_appointment(appointment *app) {
    appointments[num_appointments] = *app;
    num_appointments++;
}

void remove_appointment(int id) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].id == id) {
            for (int j = i; j < num_appointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            num_appointments--;
            break;
        }
    }
}

void sort_appointments() {
    for (int i = 0; i < num_appointments - 1; i++) {
        for (int j = i + 1; j < num_appointments; j++) {
            if (appointments[i].priority < appointments[j].priority) {
                appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }
}

int main() {
    appointment new_appointment;
    int choice;

    do {
        printf("1. Add appointment\n2. Remove appointment\n3. Sort appointments\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter appointment ID: ");
            scanf("%d", &new_appointment.id);
            printf("Enter appointment name: ");
            scanf("%s", new_appointment.name);
            printf("Enter appointment priority: ");
            scanf("%d", &new_appointment.priority);
            printf("Enter appointment time: ");
            scanf("%d", &new_appointment.appointment_time);
            printf("Enter appointment duration: ");
            scanf("%d", &new_appointment.duration);
            add_appointment(&new_appointment);
            break;
        case 2:
            printf("Enter appointment ID to remove: ");
            int id;
            scanf("%d", &id);
            remove_appointment(id);
            break;
        case 3:
            sort_appointments();
            printf("Appointments sorted by priority.\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}