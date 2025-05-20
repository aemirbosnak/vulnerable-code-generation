//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structs for appointments and time slots
typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    int day;
    Time time;
} Appointment;

typedef struct {
    Time start;
    Time end;
} TimeSlot;

// Define function to check if two time slots overlap
int checkOverlap(TimeSlot slot1, TimeSlot slot2) {
    if (slot1.start.hour > slot2.end.hour || slot2.start.hour > slot1.end.hour) {
        return 0;
    } else if (slot1.start.hour == slot2.end.hour && slot1.start.minute > slot2.end.minute) {
        return 0;
    } else if (slot2.start.hour == slot1.end.hour && slot2.start.minute > slot1.end.minute) {
        return 0;
    } else {
        return 1;
    }
}

// Define function to print available time slots
void printTimeslots(TimeSlot slots[], int num_slots) {
    printf("Available time slots:\n");
    for (int i = 0; i < num_slots; i++) {
        printf("%d:%02d - %d:%02d\n", slots[i].start.hour, slots[i].start.minute, 
               slots[i].end.hour, slots[i].end.minute);
    }
}

// Main function
int main() {
    int num_appointments;
    printf("How many appointments do you have today? ");
    scanf("%d", &num_appointments);

    // Dynamically allocate memory for appointment array
    Appointment* appointments = malloc(num_appointments * sizeof(Appointment));

    // Get input for each appointment
    for (int i = 0; i < num_appointments; i++) {
        printf("\nEnter details for Appointment %d:\n", i+1);

        // Get input for day
        printf("Day (1-31): ");
        scanf("%d", &appointments[i].day);

        // Get input for time
        printf("Time (in HH:MM format): ");
        scanf("%d:%d", &appointments[i].time.hour, &appointments[i].time.minute);
    }

    // Define available time slots
    Time startTime = {9, 0};
    Time endTime = {17, 0};
    TimeSlot workHours = {startTime, endTime};
    
    int num_slots = (workHours.end.hour - workHours.start.hour) * 2;
    TimeSlot* slots = malloc(num_slots * sizeof(TimeSlot));
    
    Time current = startTime;
    for (int i = 0; i < num_slots; i++) {
        slots[i].start = current;
        current.minute += 30;
        if (current.minute == 60) {
            current.hour++;
            current.minute = 0;
        }
        slots[i].end = current;
    }

    // Remove slots that overlap with appointments
    for (int i = 0; i < num_appointments; i++) {
        for (int j = 0; j < num_slots; j++) {
            TimeSlot apptSlot = {appointments[i].time, appointments[i].time};
            if (checkOverlap(apptSlot, slots[j])) {
                slots[j].start.hour = -1;
            }
        }
    }

    // Print available time slots
    printTimeslots(slots, num_slots);

    // Free dynamically allocated memory
    free(appointments);
    free(slots);

    return 0;
}