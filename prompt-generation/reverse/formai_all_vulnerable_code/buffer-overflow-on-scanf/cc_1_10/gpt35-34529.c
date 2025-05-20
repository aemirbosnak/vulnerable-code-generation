//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_APPOINTMENTS 10
#define NAME_LEN 20

struct Appointment {
    char name[NAME_LEN];
    int time;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void printMenu() {
    printf("Welcome to the Appointment Scheduler\n");
    printf("------------------------------------\n");
    printf("1. Schedule an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel an Appointment\n");
    printf("4. Exit\n");
}

void scheduleAppointment() {
    if(numAppointments == MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments are available.\n");
        return;
    }

    struct Appointment newAppt;
    printf("Please enter your name: ");
    fgets(newAppt.name, NAME_LEN, stdin);
    printf("Please enter the appointment time (in 24-hour format): ");
    scanf("%d", &newAppt.time);
    getchar(); // To consume the extra newline character

    appointments[numAppointments++] = newAppt;
    printf("Appointment scheduled successfully!\n");
}

void viewAppointments() {
    if(numAppointments == 0) {
        printf("No appointments scheduled at the moment.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    printf("-----------------------\n");
    for(int i=0; i<numAppointments; i++) {
        printf("%d. Name: %sTime: %d\n", i+1, appointments[i].name, appointments[i].time);
    }
}

void cancelAppointment() {
    if(numAppointments == 0) {
        printf("No appointments scheduled at the moment.\n");
        return;
    }

    int index;
    printf("Please enter the appointment number you want to cancel: ");
    scanf("%d", &index);
    getchar(); // To consume the extra newline character

    if(index < 1 || index > numAppointments) {
        printf("Invalid appointment number!\n");
        return;
    }

    index--;
    for(int i=index; i<numAppointments-1; i++) {
        appointments[i] = appointments[i+1];
    }
    numAppointments--;
    printf("Appointment canceled successfully!\n");
}

int main() {
    while(1) {
        printMenu();

        int choice;
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the extra newline character

        switch(choice) {
            case 1: scheduleAppointment();
                break;

            case 2: viewAppointments();
                break;

            case 3: cancelAppointment();
                break;

            case 4: printf("Thank you for using the Appointment Scheduler.\n");
                    exit(0);

            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}