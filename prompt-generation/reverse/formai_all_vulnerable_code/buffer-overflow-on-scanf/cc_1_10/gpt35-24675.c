//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct appointment {
    char name[MAX_NAME_LEN];
    int day, month, year, hour, minute;
} Appointment;

void print_menu() {
    printf("Welcome to my Appointment Scheduler! Choose an option: \n");
    printf("1. Schedule an appointment\n");
    printf("2. View all appointments\n");
    printf("3. Cancel an appointment\n");
    printf("4. Exit\n");
}

void schedule_appointment(Appointment* appointments, int num_appointments) {
    getchar(); // Remove newline
    printf("What is the name of the appointment? \n");
    fgets(appointments[num_appointments].name, MAX_NAME_LEN, stdin);

    printf("What day is the appointment (dd)? \n");
    scanf("%d", &appointments[num_appointments].day);

    printf("What month is the appointment (mm)? \n");
    scanf("%d", &appointments[num_appointments].month);

    printf("What year is the appointment (yyyy)? \n");
    scanf("%d", &appointments[num_appointments].year);

    printf("What hour is the appointment (hh)? \n");
    scanf("%d", &appointments[num_appointments].hour);

    printf("What minute is the appointment (mm)? \n");
    scanf("%d", &appointments[num_appointments].minute);

    printf("Appointment scheduled successfully!\n");
}

void view_appointments(Appointment* appointments, int num_appointments) {
    if(num_appointments == 0) {
        printf("There are no appointments\n");
        return;
    } 

    printf("Here are all of the appointments:\n");
    for(int i = 0; i < num_appointments; i++) {
        printf("Name: %s", appointments[i].name);
        printf("Date: %02d/%02d/%04d\n", appointments[i].day, appointments[i].month, appointments[i].year);
        printf("Time: %02d:%02d\n", appointments[i].hour, appointments[i].minute);
        printf("\n");
    }
}

void cancel_appointment(Appointment* appointments, int num_appointments) {
    if(num_appointments == 0) {
        printf("There are no appointments to cancel\n");
        return;
    }

    getchar(); // Remove newline
    printf("What is the name of the appointment? \n");
    char name[MAX_NAME_LEN];
    fgets(name, MAX_NAME_LEN, stdin);

    int found_appointment = 0;
    int index;
    for(int i = 0; i < num_appointments; i++) {
        if(strcmp(name, appointments[i].name) == 0) {
            found_appointment = 1;
            index = i;
            break;
        }
    }

    if(found_appointment == 0) {
        printf("Appointment not found\n");
        return;
    }

    for(int i = index; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i+1];
    }

    printf("Appointment cancelled successfully!\n");
}

int main() {
    int option;
    int num_appointments = 0;
    int max_appointments = 50;
    Appointment *appointments = malloc(max_appointments * sizeof(Appointment));

    printf("Hello! I'm your friendly Appointment Scheduler bot!\n");
    printf("I'm here to help you manage your schedule.\n");

    do {
        print_menu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                if(num_appointments == max_appointments) {
                    printf("Unfortunately, you've reached the maximum amount of appointments.\n");
                    printf("Please cancel an appointment to make room for a new one.\n");
                } 
                else {
                    schedule_appointment(appointments, num_appointments);
                    num_appointments++;
                }
                break;
            case 2:
                view_appointments(appointments, num_appointments);
                break;
            case 3:
                cancel_appointment(appointments, num_appointments);
                num_appointments--;
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option\n");
        }

    } while(option != 4);

    free(appointments);
    return 0;
}