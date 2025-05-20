//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MINUTES_IN_HOUR 60

struct appointment {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
};

void print_menu() {
    printf("Appointment Scheduler Menu:\n");
    printf("1. Add appointment\n");
    printf("2. Delete appointment\n");
    printf("3. View appointments\n");
    printf("4. Exit\n");
}

void add_appointment() {
    struct appointment new_appointment;
    printf("Enter name: ");
    scanf("%s", new_appointment.name);
    printf("Enter start time (YYYY-MM-DD HH:MM): ");
    scanf("%s", new_appointment.start_time);
    printf("Enter end time (YYYY-MM-DD HH:MM): ");
    scanf("%s", new_appointment.end_time);
}

void delete_appointment() {
    printf("Enter name of appointment to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
}

void view_appointments() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    FILE *fp = fopen("appointments.txt", "r");
    if (fp == NULL) {
        printf("No appointments found.\n");
        return;
    }
    while (fscanf(fp, "%s %s %s\n", appointments[num_appointments].name, appointments[num_appointments].start_time, appointments[num_appointments].end_time)!= EOF) {
        num_appointments++;
    }
    fclose(fp);
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s %s - %s\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time);
    }
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                delete_appointment();
                break;
            case 3:
                view_appointments();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}