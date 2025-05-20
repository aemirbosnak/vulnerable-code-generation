//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define APPOINTMENT_LENGTH 60

typedef struct {
    char name[50];
    int start_time;
    int end_time;
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int count;
} Scheduler;

void print_menu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. Delete Appointment\n");
    printf("3. List Appointments\n");
    printf("4. Quit\n");
}

int is_valid_time(int time) {
    return time >= 0 && time <= 23 * 60;
}

int add_appointment(Scheduler* scheduler, const char* name, int start_time, int end_time) {
    if (scheduler->count == MAX_APPOINTMENTS) {
        return 1;
    }

    if (!is_valid_time(start_time) || !is_valid_time(end_time)) {
        return 2;
    }

    if (end_time < start_time) {
        return 3;
    }

    strcpy(scheduler->appointments[scheduler->count].name, name);
    scheduler->appointments[scheduler->count].start_time = start_time;
    scheduler->appointments[scheduler->count].end_time = end_time;
    scheduler->count++;

    return 0;
}

void delete_appointment(Scheduler* scheduler, int index) {
    if (index < 0 || index >= scheduler->count) {
        printf("Invalid index\n");
        return;
    }

    memmove(&scheduler->appointments[index], &scheduler->appointments[index + 1],
             (scheduler->count - index - 1) * sizeof(Appointment));
    scheduler->count--;
}

void list_appointments(const Scheduler* scheduler) {
    for (int i = 0; i < scheduler->count; i++) {
        printf("%s: %02d:%02d - %02d:%02d\n", scheduler->appointments[i].name,
               scheduler->appointments[i].start_time / 60, scheduler->appointments[i].start_time % 60,
               scheduler->appointments[i].end_time / 60, scheduler->appointments[i].end_time % 60);
    }
}

int main() {
    Scheduler scheduler = {0};

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                int start_time, end_time;
                printf("Enter appointment name: ");
                scanf("%s", name);
                printf("Enter start time (HHMM): ");
                scanf("%d", &start_time);
                printf("Enter end time (HHMM): ");
                scanf("%d", &end_time);
                int result = add_appointment(&scheduler, name, start_time, end_time);
                if (result) {
                    printf("Error: %s\n", result == 1 ? "Maximum appointments reached" :
                                             result == 2 ? "Invalid time" : "Invalid end time");
                }
                break;
            }
            case 2: {
                int index;
                printf("Enter index of appointment to delete: ");
                scanf("%d", &index);
                delete_appointment(&scheduler, index);
                break;
            }
            case 3: {
                list_appointments(&scheduler);
                break;
            }
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}