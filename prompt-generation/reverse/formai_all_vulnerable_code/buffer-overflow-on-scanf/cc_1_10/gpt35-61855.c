//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    // Variable declarations
    int date, slot;
    bool is_available = false;

    // Initialize time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Welcome to our appointment scheduling system!\n\n");

    // Display current date and time
    printf("Today's date is %02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    // Get user input for date and time slot
    printf("Please enter a date (dd): ");
    scanf("%d", &date);

    printf("Please enter a time slot (1-3): ");
    scanf("%d", &slot);

    // Check if date is valid
    if (date <= 0 || date > 31) {
        printf("Invalid date entered. Please enter a date between 1-31.\n");
        return 0;
    }

    // Check if time slot is valid
    if (slot < 1 || slot > 3) {
        printf("Invalid time slot entered. Please enter a time slot between 1-3.\n");
        return 0;
    }

    // Generate random number to determine availability
    srand(time(NULL));
    int random = rand() % 10;

    // Check availability
    if (random < 5) {
        is_available = true;
    }

    // Display appointment status
    printf("\nAppointment on %02d/%02d/%d - Slot %d status: %s\n", date, tm.tm_mon + 1, tm.tm_year + 1900, slot, is_available ? "Available" : "Not available");

    return 0;
}