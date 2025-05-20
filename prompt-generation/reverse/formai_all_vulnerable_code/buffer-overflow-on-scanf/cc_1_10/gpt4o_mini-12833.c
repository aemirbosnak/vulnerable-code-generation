//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LEN 50
#define DATE_LEN 11
#define TIME_LEN 6

typedef struct {
    char name[NAME_LEN];
    char date[DATE_LEN]; // Format: YYYY-MM-DD
    char time[TIME_LEN]; // Format: HH:MM
} Appointment;

Appointment schedule[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Oh no! Can't add more appointments, the schedule is full! 🎉🐢\n");
        return;
    }

    Appointment new_appt;
    printf("Let's schedule a new appointment! 🌼\n");

    printf("Enter the name for the appointment: ");
    fgets(new_appt.name, NAME_LEN, stdin);
    new_appt.name[strcspn(new_appt.name, "\n")] = 0; // Remove newline

    printf("Enter the date (YYYY-MM-DD): ");
    fgets(new_appt.date, DATE_LEN, stdin);
    new_appt.date[strcspn(new_appt.date, "\n")] = 0; // Remove newline

    printf("Enter the time (HH:MM): ");
    fgets(new_appt.time, TIME_LEN, stdin);
    new_appt.time[strcspn(new_appt.time, "\n")] = 0; // Remove newline

    schedule[appointment_count++] = new_appt;
    printf("🎉 Appointment for '%s' on %s at %s has been added! 🎊\n", new_appt.name, new_appt.date, new_appt.time);
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("Your schedule is empty! 📅 Let's add some appointments! 🌟\n");
    } else {
        printf("Here are your scheduled appointments: 📅✨\n");
        for (int i = 0; i < appointment_count; i++) {
            printf("%d. %s on %s at %s\n", i + 1, schedule[i].name, schedule[i].date, schedule[i].time);
        }
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("Hmm, nothing to delete! Your schedule is empty! 📅💔\n");
        return;
    }

    int index;
    printf("Enter the number of the appointment to delete (1 to %d): ", appointment_count);
    scanf("%d", &index);
    getchar(); // Consume newline

    if (index < 1 || index > appointment_count) {
        printf("Whoops! That's not a valid appointment number! 🚫😱\n");
        return;
    }

    // Shift appointments down
    for (int i = index - 1; i < appointment_count - 1; i++) {
        schedule[i] = schedule[i + 1];
    }
    
    appointment_count--;
    printf("🎉 Appointment #%d has been successfully deleted! Keep smiling! 😊🌻\n", index);
}

void show_menu() {
    int choice;
    do {
        printf("\n** Appointment Scheduler Menu **\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

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
                printf("Goodbye! Have a wonderful day! 🌈🌟\n");
                break;
            default:
                printf("Oops! Please enter a valid option! 🤗\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Appointment Scheduler! 🥳✨ Let's make your day organized!\n");
    show_menu();
    return 0;
}