//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter description: ");
    scanf("%s", appointments[num_appointments].description);
    appointments[num_appointments].start_time = time(NULL);
    appointments[num_appointments].end_time = appointments[num_appointments].start_time + 60*60; // 1 hour
    num_appointments++;
    printf("Appointment added!\n");
}

void list_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Upcoming appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s (%ld)\n", appointments[i].name, appointments[i].description, appointments[i].start_time);
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Cheerful Appointment Scheduler!\n");
    int choice;
    do {
        printf("Please choose an option:\n");
        printf("1. Add appointment\n");
        printf("2. List appointments\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                printf("Goodbye! Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);
    return 0;
}