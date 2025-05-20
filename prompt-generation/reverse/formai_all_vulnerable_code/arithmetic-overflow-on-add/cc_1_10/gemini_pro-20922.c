//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // For time()

// A simple linked list to store appointments
typedef struct Appointment {
    time_t start;
    time_t end;
    char *description;
    struct Appointment *next;
} Appointment;

// A linked list to store available time slots
typedef struct TimeSlot {
    time_t start;
    time_t end;
    struct TimeSlot *next;
} TimeSlot;

// Create a new appointment
Appointment *create_appointment(time_t start, time_t end, char *description) {
    Appointment *new_appointment = malloc(sizeof(Appointment));
    new_appointment->start = start;
    new_appointment->end = end;
    new_appointment->description = strdup(description);
    new_appointment->next = NULL;
    return new_appointment;
}

// Create a new time slot
TimeSlot *create_time_slot(time_t start, time_t end) {
    TimeSlot *new_time_slot = malloc(sizeof(TimeSlot));
    new_time_slot->start = start;
    new_time_slot->end = end;
    new_time_slot->next = NULL;
    return new_time_slot;
}

// Insert an appointment into the list of appointments
void insert_appointment(Appointment **head, Appointment *new_appointment) {
    if (*head == NULL) {
        *head = new_appointment;
    } else {
        Appointment *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_appointment;
    }
}

// Insert a time slot into the list of time slots
void insert_time_slot(TimeSlot **head, TimeSlot *new_time_slot) {
    if (*head == NULL) {
        *head = new_time_slot;
    } else {
        TimeSlot *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_time_slot;
    }
}

// Find a time slot that can accommodate a new appointment
TimeSlot *find_available_time_slot(TimeSlot *head, time_t start, time_t end) {
    TimeSlot *current = head;
    while (current != NULL) {
        if (current->start >= start && current->end <= end) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Schedule an appointment
void schedule_appointment(Appointment **appointments, TimeSlot **time_slots, time_t start, time_t end, char *description) {
    // Create a new appointment
    Appointment *new_appointment = create_appointment(start, end, description);

    // Find a time slot that can accommodate the new appointment
    TimeSlot *available_time_slot = find_available_time_slot(*time_slots, start, end);

    // If a time slot was found, insert the appointment into the list of appointments and remove the time slot from the list of time slots
    if (available_time_slot != NULL) {
        insert_appointment(appointments, new_appointment);
        TimeSlot *previous = NULL;
        TimeSlot *current = *time_slots;
        while (current != NULL) {
            if (current == available_time_slot) {
                if (previous == NULL) {
                    *time_slots = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                break;
            }
            previous = current;
            current = current->next;
        }
    }
}

// Print the list of appointments
void print_appointments(Appointment *head) {
    Appointment *current = head;
    while (current != NULL) {
        printf("%s: %s - %s\n", current->description, ctime(&current->start), ctime(&current->end));
        current = current->next;
    }
}

// Print the list of time slots
void print_time_slots(TimeSlot *head) {
    TimeSlot *current = head;
    while (current != NULL) {
        printf("%s - %s\n", ctime(&current->start), ctime(&current->end));
        current = current->next;
    }
}

// Free the list of appointments
void free_appointments(Appointment *head) {
    Appointment *current = head;
    while (current != NULL) {
        Appointment *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
}

// Free the list of time slots
void free_time_slots(TimeSlot *head) {
    TimeSlot *current = head;
    while (current != NULL) {
        TimeSlot *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Initialize the list of appointments
    Appointment *appointments = NULL;

    // Initialize the list of time slots
    TimeSlot *time_slots = NULL;

    // Create some time slots
    insert_time_slot(&time_slots, create_time_slot(time(NULL), time(NULL) + 3600));  // 1 hour
    insert_time_slot(&time_slots, create_time_slot(time(NULL) + 3600, time(NULL) + 7200));  // 2 hours
    insert_time_slot(&time_slots, create_time_slot(time(NULL) + 7200, time(NULL) + 10800));  // 3 hours

    // Schedule some appointments
    schedule_appointment(&appointments, &time_slots, time(NULL) + 1800, time(NULL) + 2700, "Lunch");
    schedule_appointment(&appointments, &time_slots, time(NULL) + 4500, time(NULL) + 5400, "Meeting");
    schedule_appointment(&appointments, &time_slots, time(NULL) + 6300, time(NULL) + 7200, "Doctor's appointment");

    // Print the list of appointments
    printf("Appointments:\n");
    print_appointments(appointments);

    // Print the list of time slots
    printf("\nTime slots:\n");
    print_time_slots(time_slots);

    // Free the list of appointments
    free_appointments(appointments);

    // Free the list of time slots
    free_time_slots(time_slots);

    return 0;
}