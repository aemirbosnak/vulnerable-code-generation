//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct appointment { //struct to hold appointment information
    char name[50];
    char date[20];
    char time[10];
} Appointment;

int main() {
    int choice, num_appts = 0;
    Appointment appts[10]; //array to hold up to 10 appointments
    do {
        printf("\n\nAppointment Scheduler Menu\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if (num_appts < 10) { //if there's room for a new appointment
                    printf("\nEnter name: ");
                    scanf(" %[^\n]s", appts[num_appts].name);
                    printf("\nEnter date (MM/DD/YYYY): ");
                    scanf(" %[^\n]s", appts[num_appts].date);
                    printf("\nEnter time (HH:MM AM/PM): ");
                    scanf(" %[^\n]s", appts[num_appts].time);
                    printf("\nAppointment successfully added!");
                    num_appts++;
                } else {
                    printf("\nSorry, the schedule is full.");
                }
                break;
            case 2:
                if (num_appts == 0) {
                    printf("\nThere are no appointments scheduled.");
                } else {
                    printf("\nScheduled Appointments:\n");
                    for (int i = 0; i < num_appts; i++) {
                        printf("%d. Name: %s, Date: %s, Time: %s\n", i+1, appts[i].name, appts[i].date, appts[i].time);
                    }
                }
                break;
            case 3:
                if (num_appts == 0) {
                    printf("\nThere are no appointments scheduled.");
                } else {
                    int appointment_id;
                    printf("\nEnter the number of the appointment you wish to delete: ");
                    scanf("%d", &appointment_id);
                    if (appointment_id < 1 || appointment_id > num_appts) {
                        printf("\nInvalid appointment number.");
                    } else {
                        for (int j = appointment_id-1; j < num_appts; j++) {
                            strcpy(appts[j].name, appts[j+1].name); //shift subsequent appointments up one index in array
                            strcpy(appts[j].date, appts[j+1].date);
                            strcpy(appts[j].time, appts[j+1].time);
                        }
                        num_appts--;
                        printf("\nAppointment successfully deleted.");
                    }
                }
                break;
            case 4:
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid choice, please try again.");
        }
    } while (choice != 4);
    return 0;
}