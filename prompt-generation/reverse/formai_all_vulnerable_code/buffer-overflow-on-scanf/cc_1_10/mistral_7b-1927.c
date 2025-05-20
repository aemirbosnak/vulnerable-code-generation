//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_APPT_NUM 50
#define MAX_APPT_LEN 50

typedef struct {
    char name[MAX_APPT_LEN];
    int start_time;
    int end_time;
} appointment;

appointment schedule[MAX_APPT_NUM];
int num_appts = 0;

void print_schedule() {
    printf("\n-------- Schedule ---------\n");
    for (int i = 0; i < num_appts; i++) {
        printf("%d. %s: %d:%02d - %d:%02d\n", i+1, schedule[i].name, schedule[i].start_time/60, schedule[i].start_time%60, schedule[i].end_time/60, schedule[i].end_time%60);
    }
}

void add_appointment(char *name, int start, int end) {
    if (num_appts >= MAX_APPT_NUM) {
        printf("\nSchedule is full!\n");
        return;
    }

    strcpy(schedule[num_appts].name, name);
    schedule[num_appts].start_time = start;
    schedule[num_appts].end_time = end;

    num_appts++;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Random Appointment Scheduler!\n");
    int choice;

    while (1) {
        printf("\n1. Add Appointment\n2. Print Schedule\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_APPT_LEN];
                int start, end;

                printf("Enter appointment name: ");
                scanf("%s", name);
                printf("Enter start time (hhmm): ");
                scanf("%d%d", &start, &end);

                add_appointment(name, start*60 + end, start*60 + end + rand()%(60*2) + 1); // add random duration
                printf("Appointment added successfully!\n");
                break;
            }

            case 2:
                print_schedule();
                break;

            case 3:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}