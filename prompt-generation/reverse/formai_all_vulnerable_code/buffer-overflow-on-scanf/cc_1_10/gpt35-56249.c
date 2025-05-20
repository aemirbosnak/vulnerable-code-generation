//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    int id;
    char name[50];
    char date[20];
    char time[10];
};

struct appointment calendar[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if(num_appointments >= MAX_APPOINTMENTS) {
        printf("Calendar is full. Cannot add more appointments.\n");
        return;
    }

    struct appointment appt;

    printf("Enter name: ");
    scanf("%s", appt.name);

    printf("Enter date (format: mm/dd/yyyy): ");
    scanf("%s", appt.date);

    printf("Enter time (format: hh:mm AM/PM): ");
    scanf("%s", appt.time);

    appt.id = num_appointments + 1;
    calendar[num_appointments] = appt;
    num_appointments++;

    printf("Appointment added successfully.\n");
}

void delete_appointment() {
    int id;

    printf("\nEnter appointment ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < num_appointments; i++) {
        if(calendar[i].id == id) {
            for(int j = i; j < num_appointments - 1; j++) {
                calendar[j] = calendar[j+1];
            }
            num_appointments--;
            printf("Appointment deleted successfully.\n");
            return;
        }
    }

    printf("Invalid appointment ID.\n");
}

void view_calendar() {
    printf("\nAppointments:\n\n");
    printf("%-5s%-20s%-15s%-10s\n\n", "ID", "Name", "Date", "Time");
    for(int i = 0; i < num_appointments; i++) {
        printf("%-5d%-20s%-15s%-10s\n", calendar[i].id, calendar[i].name, calendar[i].date, calendar[i].time);
    }
}

int main() {
    int choice;

    while(true) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. View calendar\n");
        printf("4. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                delete_appointment();
                break;
            case 3:
                view_calendar();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}