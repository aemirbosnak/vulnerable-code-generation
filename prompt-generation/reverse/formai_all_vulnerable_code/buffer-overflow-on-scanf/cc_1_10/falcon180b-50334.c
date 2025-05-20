//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    char name[50];
    int age;
    int phone;
    char email[50];
    time_t appointment_time;
    int appointment_duration;
} appointment;

void add_appointment(appointment *app) {
    printf("Enter name: ");
    scanf("%s", app->name);
    printf("Enter age: ");
    scanf("%d", &app->age);
    printf("Enter phone: ");
    scanf("%d", &app->phone);
    printf("Enter email: ");
    scanf("%s", app->email);
    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", app->appointment_time);
    printf("Enter appointment duration (in minutes): ");
    scanf("%d", &app->appointment_duration);
}

void display_appointments(appointment *app, int size) {
    printf("\nAppointments:\n");
    for(int i=0; i<size; i++) {
        printf("Name: %s\n", app[i].name);
        printf("Age: %d\n", app[i].age);
        printf("Phone: %d\n", app[i].phone);
        printf("Email: %s\n", app[i].email);
        printf("Appointment Time: %s\n", ctime(&app[i].appointment_time));
        printf("Appointment Duration: %d minutes\n\n", app[i].appointment_duration);
    }
}

void schedule_appointment(appointment *app, int size) {
    int choice;
    while(1) {
        printf("\nChoose an option:\n1. Schedule an appointment\n2. View appointments\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_appointment(&app[size]);
                size++;
                break;
            case 2:
                display_appointments(app, size);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    int size=0;
    appointment app[100];
    schedule_appointment(app, size);
    return 0;
}