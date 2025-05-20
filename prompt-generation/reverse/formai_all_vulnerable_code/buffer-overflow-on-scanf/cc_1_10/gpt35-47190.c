//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

// Custom structure to hold appointment details.
typedef struct Appointment {
    char date[11];
    char time[6];
    char name[50];
    char phone[15];
} Appointment;

// Function that checks if the given date and time slot is available or not.
int isAvailable(char date[], char time[], Appointment appointments[], int n) {
    for(int i=0; i<n; i++) {
        if(strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
            return 0;
        }
    }
    return 1;
}

// Function that prints all the appointment details.
void printAppointments(Appointment appointments[], int n) {
    printf("Date\t\tTime\t\tName\t\tPhone\n");
    printf("-----------------------------------------------------\n");
    for(int i=0; i<n; i++) {
        printf("%s\t%s\t%s\t\t%s\n", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].phone);
    }
}

int main() {
    Appointment appointments[MAX]; // Array to hold all the appointment details.
    int n = 0; // Number of appointments scheduled so far.
    int choice;
    srand(time(0)); // Seed for the random number generator.

    do {
        printf("\n\nC Appointment Scheduler\n\n");
        printf("1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char date[11], time[6], name[50], phone[15];
                int availableSlots[10], slotCount = 0;

                // Get the user details.
                printf("\nEnter date (DD/MM/YYYY): ");
                scanf("%s", date);
                printf("Enter time (24-hour format, HH:MM): ");
                scanf("%s", time);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);

                // Check if the requested slot is available.
                if(isAvailable(date, time, appointments, n)) {
                    // Add the appointment to the array.
                    strcpy(appointments[n].date, date);
                    strcpy(appointments[n].time, time);
                    strcpy(appointments[n].name, name);
                    strcpy(appointments[n].phone, phone);
                    n++;
                    printf("\nAppointment scheduled successfully!\n");
                } else {
                    printf("\nThe requested time slot is not available. Please choose a different time.\n");

                    // Suggest available slots to the user.
                    printf("Here are the available slots for the requested date:\n");
                    for(int i=0; i<24; i++) {
                        if(i == 12) {
                            printf("\n");
                        }
                        if(i < 10) {
                            printf("0%d:00 ", i);
                        } else {
                            printf("%d:00 ", i);
                        }
                        // Check for available slots and add them to the array.
                        if(isAvailable(date, time, appointments, n)) {
                            availableSlots[slotCount] = i;
                            slotCount++;
                        }
                    }

                    if(slotCount > 0) {
                        int randomSlot = availableSlots[rand() % slotCount];
                        printf("\nWould you like to schedule an appointment at %02d:00 instead? (Y/N) ", randomSlot);
                        char response[5];
                        scanf("%s", response);
                        if(strcmp(response, "Y") == 0) {
                            char newTime[6];
                            sprintf(newTime, "%02d:00", randomSlot);
                            strcpy(appointments[n].date, date);
                            strcpy(appointments[n].time, newTime);
                            strcpy(appointments[n].name, name);
                            strcpy(appointments[n].phone, phone);
                            n++;
                            printf("\nAppointment scheduled successfully at %s!\n", newTime);
                        }
                    } else {
                        printf("\nNo available slots. Please choose a different date.\n");
                    }
                }

                break;
            }

            case 2: {
                if(n == 0) {
                    printf("\nNo appointments scheduled yet.\n");
                } else {
                    printAppointments(appointments, n);
                }
                break;
            }

            case 3: {
                printf("\nExiting program...\n");
                break;
            }

            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    } while(choice != 3);

    return 0;
}