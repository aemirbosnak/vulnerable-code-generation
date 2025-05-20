//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char date[15];
    char time[10];
    char place[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void displayAppointments() {
    printf("\n--- The Schedule of Love's Appointments ---\n");
    if (appointmentCount == 0) {
        printf("No appointments yet, my dear tragic lovers!\n");
        return;
    }
    for (int i = 0; i < appointmentCount; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("   Name: %s\n", appointments[i].name);
        printf("   Date: %s\n", appointments[i].date);
        printf("   Time: %s\n", appointments[i].time);
        printf("   Place: %s\n", appointments[i].place);
        printf("------------------------------------------\n");
    }
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Oh woe! The scheduler is full of forbidden trysts!\n");
        return;
    }
    
    printf("Enter the name of the star-crossed lover: ");
    scanf(" %[^\n]", appointments[appointmentCount].name);
    printf("When shall we meet? (date): ");
    scanf(" %[^\n]", appointments[appointmentCount].date);
    printf("At what hour shall we rendezvous? (time): ");
    scanf(" %[^\n]", appointments[appointmentCount].time);
    printf("Where shall our hearts convene? (place): ");
    scanf(" %[^\n]", appointments[appointmentCount].place);

    appointmentCount++;
    printf("A new appointment has been forged in the fires of passion!\n");
}

void searchAppointment() {
    char searchName[NAME_LENGTH];
    printf("Whose appointment dost thou seek? (name): ");
    scanf(" %[^\n]", searchName);

    int found = 0;
    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].name, searchName) == 0) {
            printf("Found appointment for %s:\n", searchName);
            printf("   Date: %s\n", appointments[i].date);
            printf("   Time: %s\n", appointments[i].time);
            printf("   Place: %s\n", appointments[i].place);
            printf("------------------------------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Alas! No appointment found for %s!\n", searchName);
    }
}

void deleteAppointment() {
    char deleteName[NAME_LENGTH];
    printf("Whose appointment do you wish to erase from fate? (name): ");
    scanf(" %[^\n]", deleteName);

    int found = 0;
    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].name, deleteName) == 0) {
            found = 1;
            for (int j = i; j < appointmentCount - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            appointmentCount--;
            printf("The appointment has been banished! Farewell, %s!\n", deleteName);
            break;
        }
    }
    if (!found) {
        printf("No appointment was found to remove from the pages of destiny!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Welcome to the Appointment Scheduler of Montague and Capulet ---\n");
        printf("1. Add an Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Search for an Appointment\n");
        printf("4. Delete an Appointment\n");
        printf("5. Exit the world of love's scheduling\n");
        printf("Choose thy fate (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                searchAppointment();
                break;
            case 4:
                deleteAppointment();
                break;
            case 5:
                printf("Farewell! May love guide your path!\n");
                break;
            default:
                printf("Entreaty for a valid choice! Retry, noble heart!\n");
        }
    } while (choice != 5);

    return 0;
}