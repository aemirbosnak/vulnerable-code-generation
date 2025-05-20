//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_APPOINTMENTS 100

// Structure for appointment data
typedef struct {
    char clientName[50];
    char clientPhone[20];
    char appointmentDate[20];
    char appointmentTime[20];
} Appointment;

// Data and function declarations
Appointment appointments[MAX_APPOINTMENTS];
int count = 0;

void addAppointment(char* name, char* phone, char* date, char* time) {
    if (count < MAX_APPOINTMENTS) {
        strcpy(appointments[count].clientName, name);
        strcpy(appointments[count].clientPhone, phone);
        strcpy(appointments[count].appointmentDate, date);
        strcpy(appointments[count].appointmentTime, time);
        count++;
        printf("Appointment added successfully!\n");
    } else {
        printf("Appointment booking is full for the day!\n");
    }
}

void cancelAppointment(int index) {
    if (index < count) {
        for (int i = index; i < count - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        count--;
        printf("Appointment cancelled successfully!\n");
    } else {
        printf("Invalid appointment index!\n");
    }
}

void showAppointments() {
    printf("List of appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment #%d:\n", i + 1);
        printf("Client name: %s\n", appointments[i].clientName);
        printf("Client phone: %s\n", appointments[i].clientPhone);
        printf("Appointment date: %s\n", appointments[i].appointmentDate);
        printf("Appointment time: %s\n\n", appointments[i].appointmentTime);
    }
}

int main() {
    char input[50], name[50], phone[20], date[20], time[20];
    int index;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("What would you like to do?\n");

    while (1) {
        printf("1. Add appointment\n");
        printf("2. Cancel appointment\n");
        printf("3. Show appointments\n");
        printf("4. Exit\n");

        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "1") == 0) {
            printf("Enter client name: ");
            fgets(name, 50, stdin);
            name[strcspn(name, "\n")] = 0;
            printf("Enter client phone number: ");
            fgets(phone, 20, stdin);
            phone[strcspn(phone, "\n")] = 0;
            printf("Enter appointment date (mm/dd/yyyy): ");
            fgets(date, 20, stdin);
            date[strcspn(date, "\n")] = 0;
            printf("Enter appointment time (hh:mm): ");
            fgets(time, 20, stdin);
            time[strcspn(time, "\n")] = 0;
            addAppointment(name, phone, date, time);
        } else if (strcmp(input, "2") == 0) {
            printf("Enter appointment index to cancel: ");
            scanf("%d", &index);
            getchar();
            cancelAppointment(index - 1);
        } else if (strcmp(input, "3") == 0) {
            showAppointments();
        } else if (strcmp(input, "4") == 0) {
            printf("Thank you for using the Appointment Scheduler!\n");
            break;
        } else {
            printf("Invalid input! Please try again.\n");
        }
    }

    return 0;
}