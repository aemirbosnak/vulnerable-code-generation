//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APP 10
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    char date[11];
    char time[6];
    char reason[MAX_NAME];
} Appointment;

void displayMenu() {
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Options:\n");
    printf("1. Schedule an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel an Appointment\n");
    printf("4. Exit (And take a nap)\n");
    printf("Choose your weapon (1-4): ");
}

void scheduleAppointment(Appointment *appointments, int *count) {
    if (*count >= MAX_APP) {
        printf("Oops! You can't squeeze in another appointment. Maximum appointments reached!\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", appointments[*count].name);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", appointments[*count].date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", appointments[*count].time);
    printf("What’s the reason for the appointment? (Make it funny!): ");
    scanf(" %[^\n]", appointments[*count].reason);

    printf("You’ve scheduled a %s appointment for %s at %s!\n", appointments[*count].reason, appointments[*count].date, appointments[*count].time);
    (*count)++;
}

void viewAppointments(Appointment *appointments, int count) {
    if (count == 0) {
        printf("No appointments in the calendar! Maybe the universe is telling you to chill?\n");
        return;
    }
    printf("Here are your scheduled appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment #%d: %s on %s at %s for %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].reason);
    }
}

void cancelAppointment(Appointment *appointments, int *count) {
    if (*count == 0) {
        printf("No appointments to cancel! Go ahead, you can sleep in peace!\n");
        return;
    }
    
    int appt_num;
    printf("Enter the appointment number you want to cancel (1 to %d): ", *count);
    scanf("%d", &appt_num);

    if (appt_num < 1 || appt_num > *count) {
        printf("Invalid appointment number! You have the memory of a goldfish!\n");
        return;
    }

    printf("Cancelling appointment for %s on %s at %s. Bye-bye!\n", appointments[appt_num - 1].name, appointments[appt_num - 1].date, appointments[appt_num - 1].time);
    
    // Shift appointments down the array
    for (int i = appt_num - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    (*count)--;
}

int main() {
    Appointment appointments[MAX_APP];
    int count = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scheduleAppointment(appointments, &count);
                break;
            case 2:
                viewAppointments(appointments, count);
                break;
            case 3:
                cancelAppointment(appointments, &count);
                break;
            case 4:
                printf("Alright, it's time to take that nap! May your dreams be filled with successful appointments!\n");
                break;
            default:
                printf("Oops! That’s not a valid option! Did you forget to charge your brain?\n");
        }
    } while (choice != 4);

    return 0;
}