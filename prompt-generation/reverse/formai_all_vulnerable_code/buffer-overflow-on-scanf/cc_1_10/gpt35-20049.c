//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random time slots
int generate_random_time_slot() {
    int max_slots = 5; // Maximum number of slots per day
    int slots_available = max_slots; // Slots available to schedule
    srand(time(NULL));
    int random_slot = rand() % max_slots + 1; // Generate random number
    slots_available--; // Decrement slots available
    return random_slot;
}

// Function to book an appointment
void book_appointment(int day, int time_slot) {
    printf("Appointment booked on day %d, time slot %d.\n", day, time_slot);
}

// Function to cancel an appointment
void cancel_appointment(int day, int time_slot) {
    printf("Appointment cancelled on day %d, time slot %d.\n", day, time_slot);
}

int main()
{
    int choice, day, time_slot;
    printf("\t***SURREAL APPOINTMENT SCHEDULER***\n");
    printf("1. Book appointment\n");
    printf("2. Cancel appointment\n");
    printf("3. View schedule\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter day for appointment (1-7): ");
                scanf("%d", &day);
                if (day < 1 || day > 7) {
                    printf("Invalid day. Please enter a valid day between 1 and 7.\n");
                    break;
                }
                time_slot = generate_random_time_slot();
                book_appointment(day, time_slot);
                break;

            case 2:
                printf("\nEnter day for cancellation (1-7): ");
                scanf("%d", &day);
                if (day < 1 || day > 7) {
                    printf("Invalid day. Please enter a valid day between 1 and 7.\n");
                    break;
                }
                printf("\nEnter time slot for cancellation (1-5): ");
                scanf("%d", &time_slot);
                if (time_slot < 1 || time_slot > 5) {
                    printf("Invalid time slot. Please enter a valid time slot between 1 and 5.\n");
                    break;
                }
                cancel_appointment(day, time_slot);
                break;

            case 3:
                printf("\nThis is a surreal appointment scheduler. There is no schedule to view.\n");
                break;

            case 4:
                printf("\nThank you for using the surreal appointment scheduler!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}