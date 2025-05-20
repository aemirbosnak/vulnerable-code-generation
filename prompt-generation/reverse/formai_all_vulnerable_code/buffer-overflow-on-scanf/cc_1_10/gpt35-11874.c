//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[30];
    char phone[15];
    Date date;
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    Appointment new_appointment;
    printf("Enter name: ");
    scanf("%s", new_appointment.name);
    printf("Enter phone number: ");
    scanf("%s", new_appointment.phone);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &new_appointment.date.day, &new_appointment.date.month, &new_appointment.date.year);
    appointments[num_appointments++] = new_appointment;
}

void view_appointments() {
    printf("\nName\t\tPhone\t\tDate\n");
    for(int i = 0; i < num_appointments; i++) {
        printf("%s\t\t%s\t\t%d/%d/%d\n", appointments[i].name, appointments[i].phone, appointments[i].date.day, appointments[i].date.month, appointments[i].date.year);
    }
}

void menu() {
    int choice;
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            add_appointment();
            menu();
            break;
        case 2:
            view_appointments();
            menu();
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter again.\n");
            menu();
            break;
    }
}

int main() {
    menu();
    return 0;
}