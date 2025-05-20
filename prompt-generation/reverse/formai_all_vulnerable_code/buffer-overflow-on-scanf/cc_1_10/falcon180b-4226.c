//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TIME_SLOTS 10

struct appointment {
    char name[50];
    int date;
    int time;
    int duration;
};

struct time_slot {
    int start_time;
    int end_time;
    int duration;
    int is_available;
};

void generate_time_slots(struct time_slot slots[], int num_slots) {
    int i, j;
    for (i = 0; i < num_slots; i++) {
        slots[i].is_available = 1;
        for (j = 0; j < i; j++) {
            if (slots[i].start_time <= slots[j].end_time) {
                slots[i].is_available = 0;
                break;
            }
        }
        slots[i].start_time = i * 15;
        slots[i].end_time = slots[i].start_time + 15;
        slots[i].duration = 15;
    }
}

int find_available_slot(struct time_slot slots[], int num_slots, int duration) {
    int i;
    for (i = 0; i < num_slots; i++) {
        if (slots[i].is_available && slots[i].duration >= duration) {
            return i;
        }
    }
    return -1;
}

int main() {
    int num_appointments, num_slots, i, j, slot_index;
    struct appointment appointments[MAX_APPOINTMENTS];
    struct time_slot slots[MAX_TIME_SLOTS];

    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    printf("Enter the number of time slots: ");
    scanf("%d", &num_slots);

    generate_time_slots(slots, num_slots);

    printf("\nEnter the details of the appointments:\n");
    for (i = 0; i < num_appointments; i++) {
        printf("Enter the name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);
        printf("Enter the date for appointment %d: ", i+1);
        scanf("%d", &appointments[i].date);
        printf("Enter the time for appointment %d: ", i+1);
        scanf("%d", &appointments[i].time);
        printf("Enter the duration for appointment %d: ", i+1);
        scanf("%d", &appointments[i].duration);
    }

    for (i = 0; i < num_appointments; i++) {
        slot_index = find_available_slot(slots, num_slots, appointments[i].duration);
        if (slot_index == -1) {
            printf("\nNo available slot found for appointment %s on %d/%d/%d at %d.\n", appointments[i].name, appointments[i].date, appointments[i].date, appointments[i].time);
        } else {
            slots[slot_index].is_available = 0;
            printf("\nAppointment %s on %d/%d/%d at %d has been scheduled in slot %d.\n", appointments[i].name, appointments[i].date, appointments[i].date, appointments[i].time, appointments[i].time, slot_index+1);
        }
    }

    return 0;
}