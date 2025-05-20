//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("The refrigerator of time is full! You can't add more appointments.\n");
        return;
    }

    Appointment newAppointment;
    printf("In the garden of dreams, enter the title of your appointment: ");
    scanf(" %[^\n]", newAppointment.title);
    printf("Now, add a dash of description to flavor your appointment: ");
    scanf(" %[^\n]", newAppointment.description);

    printf("When shall we meet in this ludicrous universe? (YYYY-MM-DD HH:MM): ");
    char timeString[20];
    scanf(" %s", timeString);

    strptime(timeString, "%Y-%m-%d %H:%M", &newAppointment.time);
    
    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added to the cosmic ledger of existence.\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("The void swallows your schedule. No appointments to show.\n");
        return;
    }

    printf("Here is the eclectic ensemble of your appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &appointments[i].time);
        printf("%d. Title: \"%s\", Description: \"%s\", Time: %s\n",
               i + 1, appointments[i].title, appointments[i].description, buffer);
    }
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("The blank canvas holds no brush strokes. Nothing to delete.\n");
        return;
    }

    viewAppointments();
    printf("Which appointment shall dissolve into the ether? (1-%d): ", appointmentCount);
    int index;
    scanf("%d", &index);

    if (index < 1 || index > appointmentCount) {
        printf("The number wavers in the cosmic dust, please choose a valid one.\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("The appointment has vanished like a whisper in the wind.\n");
}

void surrealMenu() {
    while (1) {
        printf("\n-- Surreal Appointment Scheduler --\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit into oblivion\n");
        printf("What does your heart yearn for? (1-4): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAppointment(); break;
            case 2: viewAppointments(); break;
            case 3: deleteAppointment(); break;
            case 4: 
                printf("You have chosen to exit. The curtain falls...\n");
                return;
            default: 
                printf("The shapeshifting shadows do not allow such choices. Try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the surreal realm of your mind's appointments...\n");
    surrealMenu();
    return 0;
}