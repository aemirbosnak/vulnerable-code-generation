//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESCRIPTION 100

typedef struct {
    char description[MAX_DESCRIPTION];
    char date[11];   // Format: YYYY-MM-DD
    char time[6];    // Format: HH:mm
} Appointment;

void addAppointment(Appointment appointments[], int *count);
void viewAppointments(Appointment appointments[], int count);
void deleteAppointment(Appointment appointments[], int *count);
void displayMenu();

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    printf("🌟 Welcome to the Happy Appointment Scheduler! 🌟\n");

    do {
        displayMenu();
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // Consume the newline after the number

        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                viewAppointments(appointments, count);
                break;
            case 3:
                deleteAppointment(appointments, &count);
                break;
            case 4:
                printf("🎉 Thank you! Have a great day! 🎉\n");
                break;
            default:
                printf("❌ Invalid option! Please try again. ❌\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n========== Menu ==========\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("==========================\n");
}

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("🛑 Appointment list is full! 🛑\n");
        return;
    }

    printf("✨ Enter Appointment Description: ");
    fgets(appointments[*count].description, MAX_DESCRIPTION, stdin);
    appointments[*count].description[strcspn(appointments[*count].description, "\n")] = '\0'; // Remove newline

    printf("📅 Enter Date (YYYY-MM-DD): ");
    fgets(appointments[*count].date, 11, stdin);

    printf("🕒 Enter Time (HH:mm): ");
    fgets(appointments[*count].time, 6, stdin);

    (*count)++;
    printf("🎈 Appointment added! 🎈\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("🛌 No appointments scheduled! 🛌\n");
        return;
    }

    printf("\n✨ Your Appointments ✨\n");
    for (int i = 0; i < count; i++) {
        printf("🔹 Appointment %d:\n", i + 1);
        printf("   Description: %s\n", appointments[i].description);
        printf("   Date: %s\n", appointments[i].date);
        printf("   Time: %s\n", appointments[i].time);
    }
}

void deleteAppointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("🛌 No appointments to delete! 🛌\n");
        return;
    }

    int appointmentNumber;
    printf("🎯 Enter the appointment number to delete: ");
    scanf("%d", &appointmentNumber);
    getchar(); // Consume the newline

    if (appointmentNumber < 1 || appointmentNumber > *count) {
        printf("⚠️ Invalid appointment number! ⚠️\n");
        return;
    }

    for (int i = appointmentNumber - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift appointments
    }
    (*count)--;
    printf("🎉 Appointment deleted! 🎉\n");
}