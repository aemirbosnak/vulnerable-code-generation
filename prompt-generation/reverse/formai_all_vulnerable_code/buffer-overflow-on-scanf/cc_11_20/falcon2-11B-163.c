//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 100
#define MAX_SLOTS_PER_DAY 24
#define MAX_APPOINTMENTS_PER_SLOT 10

typedef struct {
    int day;
    int slot;
    int appointments[MAX_APPOINTMENTS_PER_SLOT];
} Appointment;

int main() {
    int num_days, num_slots_per_day, num_appointments_per_slot;
    int num_appointments;

    printf("Enter the number of days: ");
    scanf("%d", &num_days);

    printf("Enter the number of slots per day: ");
    scanf("%d", &num_slots_per_day);

    printf("Enter the number of appointments per slot: ");
    scanf("%d", &num_appointments_per_slot);

    Appointment* appointments = (Appointment*)malloc(num_days * num_slots_per_day * sizeof(Appointment));

    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_slots_per_day; j++) {
            appointments[i * num_slots_per_day + j].day = i;
            appointments[i * num_slots_per_day + j].slot = j;
            appointments[i * num_slots_per_day + j].appointments[0] = i;
        }
    }

    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_slots_per_day; j++) {
            for (int k = 0; k < num_appointments_per_slot; k++) {
                if (j + k >= num_slots_per_day) {
                    break;
                }
                if (appointments[i * num_slots_per_day + j].appointments[k]!= i) {
                    appointments[i * num_slots_per_day + j].appointments[k] = i;
                }
            }
        }
    }

    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_slots_per_day; j++) {
            if (appointments[i * num_slots_per_day + j].appointments[0] == i) {
                printf("Day %d, Slot %d: Appointment at %d\n", appointments[i * num_slots_per_day + j].day, appointments[i * num_slots_per_day + j].slot, appointments[i * num_slots_per_day + j].appointments[0]);
            }
        }
    }

    return 0;
}