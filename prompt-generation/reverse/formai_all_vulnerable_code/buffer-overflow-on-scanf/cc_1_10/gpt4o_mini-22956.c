//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void showMenu() {
    printf("\n🎉 Welcome to the Appointment Scheduler! 🎉\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("🚫 Sorry, you can't add more appointments! The schedule is full!\n");
        return;
    }

    Appointment newAppointment;

    printf("Enter the name of the appointment: ");
    scanf("%s", newAppointment.name);

    printf("Enter a brief description: ");
    getchar();  // to consume newline
    fgets(newAppointment.description, MAX_DESC_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0; // remove newline

    printf("Enter the date (DD MM YYYY): ");
    scanf("%d %d %d", &newAppointment.day, &newAppointment.month, &newAppointment.year);

    printf("Enter the time (HH MM): ");
    scanf("%d %d", &newAppointment.hour, &newAppointment.minute);

    appointments[appointment_count] = newAppointment;
    appointment_count++;

    printf("🎉 Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("😢 No appointments found! Let's fill that schedule!\n");
        return;
    }

    printf("\n📅 Your Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("\tName: %s\n", appointments[i].name);
        printf("\tDescription: %s\n", appointments[i].description);
        printf("\tDate: %02d/%02d/%04d\n", appointments[i].day, appointments[i].month, appointments[i].year);
        printf("\tTime: %02d:%02d\n", appointments[i].hour, appointments[i].minute);
    }
}

void deleteAppointment() {
    if (appointment_count == 0) {
        printf("😢 No appointments to delete!\n");
        return;
    }

    viewAppointments();
    int appointmentNumber;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &appointmentNumber);

    if (appointmentNumber < 1 || appointmentNumber > appointment_count) {
        printf("❌ Invalid appointment number!\n");
        return;
    }

    for (int i = appointmentNumber - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("🎉 Appointment deleted successfully!\n");
}

int main() {
    while (1) {
        showMenu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("😊 Thank you for using the Appointment Scheduler! Have a great day! 🎈\n");
                exit(0);
            default:
                printf("❌ That's not a valid option! Please try again.\n");
        }
    }

    return 0;
}