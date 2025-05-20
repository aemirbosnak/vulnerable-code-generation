//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_APPTS 100

// Define struct for appointment
typedef struct {
    char name[MAX_NAME_LEN];
    int day;
    int hour;
} Appointment;

// Define global variables
Appointment appointments[MAX_APPTS];
int num_appts = 0;

// Define function to print appointments
void print_appts() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("%s | Day: %d | Hour: %d\n", appointments[i].name, appointments[i].day, appointments[i].hour);
    }
}

int main() {
    int choice = 0;
    while (choice != 3) {
        printf("-------- Appointment Scheduler Program --------\n");
        printf("1. Create an appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Create an appointment
                if (num_appts >= MAX_APPTS) {
                    printf("Maximum appointments reached.\n");
                    break;
                }
                printf("Enter name (max %d characters): ", MAX_NAME_LEN-1);
                scanf("%s", appointments[num_appts].name);
                printf("Enter day (1-30): ");
                scanf("%d", &appointments[num_appts].day);
                if (appointments[num_appts].day > 30 || appointments[num_appts].day < 1) {
                    printf("Invalid day.\n");
                    break;
                }
                printf("Enter hour (0-23): ");
                scanf("%d", &appointments[num_appts].hour);
                if (appointments[num_appts].hour < 0 || appointments[num_appts].hour > 23) {
                    printf("Invalid hour.\n");
                    break;
                }

                printf("Appointment created.\n");
                num_appts++;
                break;
            case 2:
                // View appointments
                print_appts();
                break;
            case 3:
                // Exit program
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}