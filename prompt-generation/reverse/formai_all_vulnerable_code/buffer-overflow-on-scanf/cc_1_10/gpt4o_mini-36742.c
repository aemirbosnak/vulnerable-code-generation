//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char title[50];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void clear_screen() {
    printf("\033[H\033[J");
}

void print_welcome() {
    clear_screen();
    printf("========================================\n");
    printf("      Welcome to Appointment Scheduler   \n");
    printf("========================================\n");
    printf("Thank you for using this scheduler!\n\n");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Sorry, you can't add more appointments. Please remove an existing one first.\n");
        return;
    }
    
    Appointment new_appt;
    printf("Enter appointment title: ");
    fgets(new_appt.title, sizeof(new_appt.title), stdin);
    new_appt.title[strcspn(new_appt.title, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appt.date, sizeof(new_appt.date), stdin);
    new_appt.date[strcspn(new_appt.date, "\n")] = 0; // Remove newline

    printf("Enter appointment time (HH:MM): ");
    fgets(new_appt.time, sizeof(new_appt.time), stdin);
    new_appt.time[strcspn(new_appt.time, "\n")] = 0; // Remove newline

    appointments[appointment_count++] = new_appt;
    printf("Appointment added successfully! Thank you for keeping your time organized.\n");
}

void view_appointments() {
    clear_screen();
    printf("Your Appointments:\n");
    printf("===================\n");
    
    if (appointment_count == 0) {
        printf("No appointments scheduled. Keep planning ahead!\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s at %s\n", i + 1, appointments[i].title, appointments[i].date, appointments[i].time);
    }
    printf("\nThank you for using the system to keep track of your appointments!\n");
}

void delete_appointment() {
    view_appointments();

    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // Clear newline from buffer

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number. Please try again.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    appointment_count--;
    printf("Appointment deleted successfully! We appreciate your focus on time management.\n");
}

void show_menu() {
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

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
                printf("Thank you for using the Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid selection, please choose again. Your time is valuable!\n");
        }
    }
}

int main() {
    print_welcome();
    show_menu();
    return 0;
}