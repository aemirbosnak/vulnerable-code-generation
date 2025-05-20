//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 20
#define NAME_LENGTH 50

struct Appointment {
    char name[NAME_LENGTH];
    time_t date_time;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Alas! The appointment book is full. No more appointments can be added.\n");
        return;
    }

    struct Appointment new_appointment;

    printf("Whom do you wish to meet, my dear Watson? ");
    getchar();  // Clear the newline character
    fgets(new_appointment.name, NAME_LENGTH, stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = 0; // Remove trailing newline

    printf("When will this rendezvous take place? (format: YYYY-MM-DD HH:MM): ");
    struct tm tm = {0};
    char date_input[20];
    fgets(date_input, sizeof(date_input), stdin);
    strptime(date_input, "%Y-%m-%d %H:%M", &tm);
    new_appointment.date_time = mktime(&tm);

    appointments[appointment_count] = new_appointment;
    appointment_count++;

    printf("Truly, an appointment with %s has been secured for you.\n", new_appointment.name);
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("The calendar seems empty, my dear Watson. No appointments scheduled.\n");
        return;
    }

    printf("Here are the scheduled appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        char buffer[26];
        struct tm* tm_info = localtime(&appointments[i].date_time);
        strftime(buffer, 26, "%Y-%m-%d %H:%M", tm_info);
        printf("%d. Appointment with %s at %s\n", i + 1, appointments[i].name, buffer);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("There are no appointments to erase, Watson.\n");
        return;
    }

    view_appointments();
    printf("Which appointment would you like to remove? (1-%d): ", appointment_count);
    int choice;
    scanf("%d", &choice);
    choice--; // Convert to zero-based index

    if (choice < 0 || choice >= appointment_count) {
        printf("An erroneous selection, indeed! Please choose a valid appointment number.\n");
        return;
    }

    for (int i = choice; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("The appointment with %s has been excised from the records.\n", appointments[choice].name);
}

int main() {
    int choice;

    printf("Welcome to the Assistant of Sherlock Holmes!\n");
    printf("I shall aid you in maintaining your appointments with utmost precision.\n");

    do {
        printf("\n1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("What shall it be, Watson? Please choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("Goodbye, Watson! May your days be filled with intrigue and excitement.\n");
                break;
            default:
                printf("A most perplexing choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}