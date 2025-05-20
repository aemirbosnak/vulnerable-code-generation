//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NOT_FOUND -1

typedef struct {
    char title[50];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment schedule[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("The infinite void of time is full. Cannot add more appointments.\n");
        return;
    }

    Appointment new_appointment;

    printf("In the realm of spiraling thoughts, what is the title of your appointment? ");
    fgets(new_appointment.title, sizeof(new_appointment.title), stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove trailing newline

    printf("What date breathes life into this moment (YYYY-MM-DD)? ");
    fgets(new_appointment.date, sizeof(new_appointment.date), stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // Remove trailing newline

    printf("At which hour does the sun whisper (HH:MM)? ");
    fgets(new_appointment.time, sizeof(new_appointment.time), stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = 0; // Remove trailing newline

    schedule[appointment_count++] = new_appointment;

    printf("Your appointment with the cosmos has been etched into the fabric of reality.\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("The calendar is devoid of events, like a dream without a dreamer.\n");
        return;
    }

    printf("\nThe appointments dance before you:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. [%s] at %s - \"%s\"\n", i + 1, schedule[i].date, schedule[i].time, schedule[i].title);
    }
}

int find_appointment(char *title) {
    for (int i = 0; i < appointment_count; i++) {
        if (strcmp(schedule[i].title, title) == 0) {
            return i;
        }
    }
    return NOT_FOUND;
}

void delete_appointment() {
    char title[50];
    printf("Which appointment shall we release back into the ether? ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove trailing newline

    int index = find_appointment(title);

    if (index == NOT_FOUND) {
        printf("The appointment you seek is but a wisp, lost in the abyss.\n");
        return;
    }

    // Shift appointments left to fill the gap
    for (int i = index; i < appointment_count - 1; i++) {
        schedule[i] = schedule[i + 1];
    }
    appointment_count--;

    printf("The appointment has been unshackled from our fragile existence.\n");
}

void menu() {
    while (1) {
        printf("\n--- Surreal Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit to the Hypnotic Void\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline left after scanf

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
                printf("As you exit, may the dreams of tomorrow guide you.\n");
                return;
            default:
                printf("In this dreamscape, such choices are but illusions. Try again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Surreal Appointment Scheduler!\n");
    menu();

    return 0;
}