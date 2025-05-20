//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 200

typedef struct Appointment {
    int day;
    int month;
    int year;
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESC_LENGTH];
} Appointment;

typedef struct Scheduler {
    int num_of_appointments;
    Appointment appointments[100];
} Scheduler;

void print_menu() {
    printf("---------- MENU ----------\n\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n\n");
}

void add_appointment(Scheduler *scheduler) {
    if (scheduler->num_of_appointments == 100) {
        printf("Maximum limit of appointments reached!\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter date of the appointment (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &new_appointment.day, &new_appointment.month, &new_appointment.year);

    printf("Enter name of the appointment: ");
    fflush(stdin);
    fgets(new_appointment.name,MAX_NAME_LENGTH,stdin);

    printf("Enter description of the appointment: ");
    fflush(stdin);
    fgets(new_appointment.desc,MAX_DESC_LENGTH,stdin);

    scheduler->appointments[scheduler->num_of_appointments++] = new_appointment;

    printf("Appointment added successfully!\n");
}

void view_appointments(Scheduler *scheduler) {
    if (scheduler->num_of_appointments == 0) {
        printf("No appointments found!\n");
        return;
    }

    printf("---------- APPOINTMENTS ----------\n\n");

    for (int i = 0; i < scheduler->num_of_appointments; i++) {
        printf("Appointment %d:\n\n", i + 1);
        printf("Date: %d/%d/%d\n", scheduler->appointments[i].day, scheduler->appointments[i].month, scheduler->appointments[i].year);
        printf("Name: %s\n", scheduler->appointments[i].name);
        printf("Description: %s\n", scheduler->appointments[i].desc);
        printf("\n");
    }
}

void delete_appointment(Scheduler *scheduler) {
    if (scheduler->num_of_appointments == 0) {
        printf("No appointments found!\n");
        return;
    }

    int index;

    printf("Enter the appointment index to delete (1 - %d): ", scheduler->num_of_appointments);
    scanf("%d", &index);

    if (index < 1 || index > scheduler->num_of_appointments) {
        printf("Invalid appointment index! Try again.\n");
        return;
    }

    printf("Are you sure you want to delete the following appointment?\n\n");
    printf("Date: %d/%d/%d\n", scheduler->appointments[index - 1].day, scheduler->appointments[index - 1].month, scheduler->appointments[index - 1].year);
    printf("Name: %s\n", scheduler->appointments[index - 1].name);
    printf("Description: %s\n", scheduler->appointments[index - 1].desc);

    char confirmation;

    printf("Enter Y for Yes and N for No: ");
    scanf(" %c", &confirmation);

    if (confirmation == 'Y' || confirmation == 'y') {
        for (int i = index - 1; i < scheduler->num_of_appointments - 1; i++) {
            scheduler->appointments[i] = scheduler->appointments[i + 1];
        }

        scheduler->num_of_appointments--;

        printf("Appointment deleted successfully!\n");
    }
}

int main() {
    Scheduler scheduler;
    scheduler.num_of_appointments = 0;

    int option;

    do {
        print_menu();

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_appointment(&scheduler);
                break;
            case 2:
                view_appointments(&scheduler);
                break;
            case 3:
                delete_appointment(&scheduler);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
                break;
        }

        printf("\n");

    } while (1);

    return 0;
}