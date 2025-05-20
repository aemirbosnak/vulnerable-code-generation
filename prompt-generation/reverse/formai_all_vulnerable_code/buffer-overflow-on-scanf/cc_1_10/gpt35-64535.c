//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char date[11]; // format yyyy-mm-dd
    char time[6]; // format hh:mm
    char name[50];
    char email[100];
    char phone[20];
    char notes[200];
} Appointment;

void printAppointment(Appointment appt) {
    printf("\nAppointment:\n");
    printf("Date: %s\n", appt.date);
    printf("Time: %s\n", appt.time);
    printf("Name: %s\n", appt.name);
    printf("Email: %s\n", appt.email);
    printf("Phone: %s\n", appt.phone);
    printf("Notes: %s\n", appt.notes);
}

void listAppointments(Appointment *appts, int numAppts) {
    printf("Listing all appointments:\n");
    for (int i = 0; i < numAppts; i++) {
        printf("%d. %s %s %s\n", i+1, appts[i].date, appts[i].time, appts[i].name);
    }
}

void saveAppointment(Appointment appt, char* filename) {
    FILE *fp;
    fp = fopen(filename, "a");
    if(fp == NULL) {
        printf("Error: unable to save appointment.\n");
        return;
    }
    fprintf(fp, "%s,%s,%s,%s,%s,%s\n", appt.date, appt.time, appt.name, appt.email, appt.phone, appt.notes);
    fclose(fp);
}

void loadAppointments(Appointment *appts, int numAppts, char* filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("No appointments found.\n");
        return;
    }
    char buffer[1000];
    while (fgets(buffer, 1000, fp) != NULL) {
        char *token;
        token = strtok(buffer, ",");
        strcpy(appts[numAppts].date, token);
        token = strtok(NULL, ",");
        strcpy(appts[numAppts].time, token);
        token = strtok(NULL, ",");
        strcpy(appts[numAppts].name, token);
        token = strtok(NULL, ",");
        strcpy(appts[numAppts].email, token);
        token = strtok(NULL, ",");
        strcpy(appts[numAppts].phone, token);
        token = strtok(NULL, ",");
        strcpy(appts[numAppts].notes, token);
        numAppts++;
    }
    fclose(fp);
}

int main() {
    printf("Welcome to the Appointment Scheduler\n");

    int numAppts = 0;
    const int maxAppts = 100;
    char* filename = "appointments.txt";
    Appointment appts[maxAppts];

    loadAppointments(appts, numAppts, filename);

    int choice;
    do {
        printf("\n1. Schedule a new appointment\n");
        printf("2. List all appointments\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                Appointment appt;
                printf("Enter appointment details:\n");
                printf("Date (yyyy-mm-dd): ");
                scanf("%s", appt.date);
                printf("Time (hh:mm): ");
                scanf("%s", appt.time);
                printf("Name: ");
                scanf("%[^\n]s", appt.name);
                printf("Email: ");
                scanf("%s", appt.email);
                printf("Phone: ");
                scanf("%s", appt.phone);
                printf("Notes: ");
                scanf("%[^\n]s", appt.notes);

                saveAppointment(appt, filename);

                printf("\nAppointment scheduled successfully!\n");
                printAppointment(appt);

                numAppts++;
                break;
            }
            case 2: {
                listAppointments(appts, numAppts);
                break;
            }
            case 3: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice, please try again.\n");
                break;
            }
        }
    } while (choice != 3);

    return 0;
}