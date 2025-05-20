//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

struct Appointment {
    int hour;
    int minute;
    char name[50];
};

int menu() {
    int choice;
    printf("MENU\n");
    printf("1. Add appointment\n");
    printf("2. Cancel appointment\n");
    printf("3. View appointments for the day\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addAppointment(struct Appointment *appts, int count) {
    if (count >= MAX) {
        printf("Sorry, no more appointments can be added today.\n");
        return;
    }

    printf("Enter the appointment time in 24-hour format (HH:MM): ");
    scanf("%d:%d", &appts[count].hour, &appts[count].minute);
    printf("Enter the name of the appointment: ");
    scanf("%s", appts[count].name);
    printf("Appointment added successfully!\n");
}

void cancelAppointment(struct Appointment *appts, int count) {
    int hour, minute, i;
    bool found = false;

    printf("Enter the appointment time in 24-hour format (HH:MM) that you wish to cancel: ");
    scanf("%d:%d", &hour, &minute);

    for (i = 0; i < count; i++) {
        if (appts[i].hour == hour && appts[i].minute == minute) {
            found = true;
            break;
        }
    }

    if (found) {
        printf("Are you sure you want to cancel the appointment with %s at %02d:%02d? (Y/n) ", appts[i].name, hour, minute);
        char response;
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y') {
            for (int j = i; j < count - 1; j++) {
                appts[j] = appts[j+1];
            }
            printf("Appointment cancelled successfully.\n");
        } else {
            printf("Appointment was NOT cancelled.\n");
        }
    } else {
        printf("Sorry, appointment not found.\n");
    }
}

void viewAppointments(struct Appointment *appts, int count) {
    printf("Today's Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%02d:%02d - %s\n", appts[i].hour, appts[i].minute, appts[i].name);
    }
}

int main() {
    struct Appointment appointments[MAX];
    int count = 0;
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                addAppointment(appointments, count);
                count++;
                break;
            case 2:
                cancelAppointment(appointments, count);
                count--;
                break;
            case 3:
                viewAppointments(appointments, count);
                break;
            case 4:
                printf("Program terminated.");
                break;
            default:
                printf("Sorry, invalid choice.");
        }
        printf("\n");
    } while (choice != 4);
   
   return 0;
}