//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_APPOINTMENTS 100  // Maximum number of appointments that can be scheduled

typedef struct appointment {
    char name[30];
    char date[20];
    char time[20];
}Appointment;

void display_menu() {
    printf("\n-----------MENU-----------\n");
    printf("1. Schedule new appointment\n");
    printf("2. View all appointments\n");
    printf("3. Search appointment by date\n");
    printf("4. Exit\n");
    printf("---------------------------\n");
}

void schedule_appointment(Appointment appointments[], int* count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Maximum limit of appointments reached.\n");
        return;
    }
    Appointment new_appointment;
    printf("Enter name: ");
    scanf("%s", new_appointment.name);
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", new_appointment.date);
    printf("Enter time (hh:mm AM/PM): ");
    scanf("%s", new_appointment.time);
    appointments[*count] = new_appointment;
    (*count)++;
}

void view_all_appointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Appointments:\n");
    printf("Name\tDate\tTime\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void search_appointment_by_date(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    char search_date[20];
    printf("Enter date to search (mm/dd/yyyy): ");
    scanf("%s", search_date);
    int found = 0;
    printf("Appointments on %s:\n", search_date);
    printf("Name\tTime\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(search_date, appointments[i].date) == 0) {
            printf("%s\t%s\n", appointments[i].name, appointments[i].time);
            found = 1;
        }
    }
    if (!found) {
        printf("No appointments found on %s.\n", search_date);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    printf("Welcome to the Appointment Scheduler!\n");
    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                schedule_appointment(appointments, &count);
                break;
            case 2:
                view_all_appointments(appointments, count);
                break;
            case 3:
                search_appointment_by_date(appointments, count);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}