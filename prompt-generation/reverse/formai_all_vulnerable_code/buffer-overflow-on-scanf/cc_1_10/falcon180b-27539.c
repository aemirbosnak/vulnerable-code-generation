//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    char phone[15];
    char email[50];
    int appointment_time;
} Appointment;

void add_appointment(Appointment appointments[], int size, int index) {
    printf("Enter name: ");
    scanf("%s", appointments[index].name);

    printf("Enter age: ");
    scanf("%d", &appointments[index].age);

    printf("Enter phone number: ");
    scanf("%s", appointments[index].phone);

    printf("Enter email: ");
    scanf("%s", appointments[index].email);

    printf("Enter appointment time (in minutes from now): ");
    scanf("%d", &appointments[index].appointment_time);

    printf("\nAppointment added successfully!\n");
}

void view_appointments(Appointment appointments[], int size) {
    printf("\nAppointments:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Age: %d\n", appointments[i].age);
        printf("Phone number: %s\n", appointments[i].phone);
        printf("Email: %s\n", appointments[i].email);
        printf("Appointment time: %d minutes from now\n\n", appointments[i].appointment_time);
    }
}

void schedule_appointment(Appointment appointments[], int size) {
    system("clear");
    printf("\nSchedule an appointment:\n");

    int choice;
    printf("1. Add appointment\n");
    printf("2. View appointments\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter the size of the appointment array: ");
            scanf("%d", &size);

            Appointment* new_appointments = (Appointment*)malloc(size * sizeof(Appointment));

            for (int i = 0; i < size; i++) {
                add_appointment(new_appointments, size, i);
            }

            free(appointments);
            appointments = new_appointments;
            break;

        case 2:
            view_appointments(appointments, size);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    system("clear");
    int size = 0;
    Appointment* appointments = NULL;

    while (1) {
        schedule_appointment(appointments, size);
    }

    return 0;
}