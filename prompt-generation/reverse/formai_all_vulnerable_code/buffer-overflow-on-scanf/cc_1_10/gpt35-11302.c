//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 50
#define MAX_APPTS 10

struct appointment {
    char name[MAX_LEN];
    int month;
    int day;
    int hour;
    int min;
};

struct appointment appts[MAX_APPTS];
int num_appts = 0;

void add_appt();
void display_appts();

int main() {
    int choice;

    printf("=== Cyberpunk Appointment Scheduler ===\n");

    do {
        printf("\nEnter your choice:\n");
        printf("1) Add appointment\n");
        printf("2) Display appointments\n");
        printf("3) Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_appt();
                break;
            case 2:
                display_appts();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void add_appt() {
    if (num_appts == MAX_APPTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }
    
    printf("\nEnter appointment name: ");
    scanf("%s", appts[num_appts].name);
    
    do {
        printf("Enter appointment month (1-12): ");
        scanf("%d", &appts[num_appts].month);
    } while (appts[num_appts].month < 1 || appts[num_appts].month > 12);
    
    do {
        printf("Enter appointment day (1-31): ");
        scanf("%d", &appts[num_appts].day);
    } while (appts[num_appts].day < 1 || appts[num_appts].day > 31);
    
    do {
        printf("Enter appointment hour (0-23): ");
        scanf("%d", &appts[num_appts].hour);
    } while (appts[num_appts].hour < 0 || appts[num_appts].hour > 23);
    
    do {
        printf("Enter appointment minute (0-59): ");
        scanf("%d", &appts[num_appts].min);
    } while (appts[num_appts].min < 0 || appts[num_appts].min > 59);
    
    printf("Appointment added successfully!\n");
    
    num_appts++;
}

void display_appts() {
    if (num_appts == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    printf("\n=== Appointments ===\n");
    
    for (int i = 0; i < num_appts; i++) {
        printf("Name: %s\n", appts[i].name);
        printf("Date: %d/%d\n", appts[i].month, appts[i].day);
        printf("Time: %d:%02d\n", appts[i].hour, appts[i].min);
        printf("\n");
    }
}