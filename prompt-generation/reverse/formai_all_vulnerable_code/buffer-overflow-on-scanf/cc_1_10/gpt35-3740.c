//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10  // maximum number of appointments the scheduler can handle
#define MAX_NAME_LENGTH 30   // maximum length of a name

typedef struct {
    char name[MAX_NAME_LENGTH];   // name of the person with the appointment
    int day;                      // day of the appointment (1-31)
    int hour;                     // hour of the appointment (0-23)
} appointment_t;

appointment_t appointments[MAX_APPOINTMENTS];   // array of appointments
int num_appointments = 0;   // counter for the number of appointments

// print the menu options
void print_menu() {
    printf("\nAppointment Scheduler\n");
    printf("1) Add appointment\n");
    printf("2) View appointments\n");
    printf("3) Exit\n");
}

// get an integer input from the user
int get_int_input() {
    int choice;
    scanf("%d", &choice);
    getchar();   // consume the extra newline character
    return choice;
}

// add an appointment to the scheduler
void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Scheduler is full\n");
        return;
    }

    // get the name, day, and hour of the appointment from the user
    appointment_t appointment;
    printf("Enter name:\n");
    fgets(appointment.name, MAX_NAME_LENGTH, stdin);
    printf("Enter day (1-31):\n");
    scanf("%d", &appointment.day);
    printf("Enter hour (0-23):\n");
    scanf("%d", &appointment.hour);
    getchar();   // consume the extra newline character

    // add the appointment to the array
    appointments[num_appointments] = appointment;
    num_appointments++;
}

// view the appointments in the scheduler
void view_appointments() {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - Day %d, Hour %d\n", appointments[i].name, appointments[i].day, appointments[i].hour);
    }
}

int main() {
    int choice = 0;
    while (choice != 3) {
        print_menu();
        choice = get_int_input();

        switch(choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}