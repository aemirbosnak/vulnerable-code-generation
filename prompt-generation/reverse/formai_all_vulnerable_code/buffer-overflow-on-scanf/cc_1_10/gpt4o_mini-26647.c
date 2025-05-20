//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 250

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char date[11];  // Format: YYYY-MM-DD
    char time[6];   // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void clear_screen() {
    printf("\033[H\033[J");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Whoa there! We've hit the limit of appointments! Please delete one before adding another.\n");
        return;
    }
    
    Appointment new_appointment;

    printf("🎉 Let's add a new appointment! 🎉\n");
    printf("Enter the title of the appointment: ");
    getchar();  // Clear the newline character from the buffer
    fgets(new_appointment.title, MAX_TITLE_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0;  // Remove newline character

    printf("Enter the description of the appointment: ");
    fgets(new_appointment.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0;  // Remove newline character
    
    printf("Enter the date of appointment (YYYY-MM-DD): ");
    fgets(new_appointment.date, sizeof(new_appointment.date), stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0;  // Remove newline character
    
    printf("Enter the time of appointment (HH:MM): ");
    fgets(new_appointment.time, sizeof(new_appointment.time), stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = 0;  // Remove newline character

    appointments[appointment_count++] = new_appointment;

    printf("✨ Appointment added! You'll never forget this one! ✨\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("📅 No appointments to show! It's all free time, woohoo! 📅\n");
        return;
    }

    printf("🌟 Here are your appointments! 🌟\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("---------------------------\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("😱 Nothing to delete! Your schedule is clear!\n");
        return;
    }
    
    int index;
    printf("🤔 Which appointment number would you like to delete? (1-%d): ", appointment_count);
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("🚨 That's not a valid appointment number! Please try again.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    appointment_count--;
    printf("🎊 Appointment %d deleted! What a bold choice! 🎊\n", index);
}

void display_menu() {
    printf("\n🔥 Appointment Scheduler Menu 🔥\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

int main() {
    int choice;
    
    while (1) {
        clear_screen();
        display_menu();
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
                printf("🚪 Exiting the Appointment Scheduler. Until next time! 🌈\n");
                exit(0);
            default:
                printf("❌ Oops! That's not a valid choice! Please choose between 1 and 4.\n");
        }
        printf("Press Enter to continue...\n");
        getchar();  // Wait for user to press enter
        getchar();  // To consume the newline character
    }

    return 0;
}