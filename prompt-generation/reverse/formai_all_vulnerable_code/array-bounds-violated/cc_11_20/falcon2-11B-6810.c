//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPTS 10

typedef struct {
    int id;
    char name[50];
    int duration;
    int start_time;
    int end_time;
    int status;
} Appointment;

int main(int argc, char *argv[]) {
    // Create an array to store appointments
    Appointment appts[MAX_APPTS];

    // Initialize the array with dummy values
    int i;
    for (i = 0; i < MAX_APPTS; i++) {
        appts[i].id = i;
        strcpy(appts[i].name, "Appointment ");
        appts[i].duration = 60;
        appts[i].start_time = 0;
        appts[i].end_time = 0;
        appts[i].status = 0;
    }

    // Prompt user to add an appointment
    int choice = 0;
    while (choice!= 5) {
        printf("1. Add an appointment\n2. View appointments\n3. Modify an appointment\n4. Delete an appointment\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter appointment details:\n");
                printf("Appointment Name: ");
                scanf("%s", appts[choice].name);
                printf("Duration (minutes): ");
                scanf("%d", &appts[choice].duration);
                printf("Start Time (HH:MM): ");
                scanf("%d", &appts[choice].start_time);
                printf("End Time (HH:MM): ");
                scanf("%d", &appts[choice].end_time);
                printf("Status (0 - pending, 1 - confirmed, 2 - cancelled): ");
                scanf("%d", &appts[choice].status);
                printf("Appointment added successfully.\n");
                break;
            case 2:
                printf("Appointments:\n");
                for (i = 0; i < MAX_APPTS; i++) {
                    if (appts[i].status == 0) {
                        printf("%d. %s - %d - %d - %d\n", i + 1, appts[i].name, appts[i].duration, appts[i].start_time, appts[i].end_time);
                    }
                }
                break;
            case 3:
                printf("Enter appointment ID: ");
                scanf("%d", &choice);
                if (choice < 0 || choice > MAX_APPTS) {
                    printf("Invalid appointment ID.\n");
                } else {
                    printf("Enter new appointment details:\n");
                    printf("Appointment Name: ");
                    scanf("%s", appts[choice].name);
                    printf("Duration (minutes): ");
                    scanf("%d", &appts[choice].duration);
                    printf("Start Time (HH:MM): ");
                    scanf("%d", &appts[choice].start_time);
                    printf("End Time (HH:MM): ");
                    scanf("%d", &appts[choice].end_time);
                    printf("Status (0 - pending, 1 - confirmed, 2 - cancelled): ");
                    scanf("%d", &appts[choice].status);
                    printf("Appointment modified successfully.\n");
                }
                break;
            case 4:
                printf("Enter appointment ID: ");
                scanf("%d", &choice);
                if (choice < 0 || choice > MAX_APPTS) {
                    printf("Invalid appointment ID.\n");
                } else {
                    printf("Are you sure you want to delete appointment %d? (y/n): ", choice);
                    char choice2;
                    scanf(" %c", &choice2);
                    if (choice2 == 'y') {
                        appts[choice].status = 2;
                        printf("Appointment deleted successfully.\n");
                    } else {
                        printf("Appointment not deleted.\n");
                    }
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}