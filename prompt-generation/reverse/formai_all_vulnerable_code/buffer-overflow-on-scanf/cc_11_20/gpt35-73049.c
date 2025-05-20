//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include<stdio.h>
#include<string.h>

struct appointment {
    char name[20];
    int time;
};

int main() {

    struct appointment app[5]; // Create an array of 5 appointment structures
    int i, j, time_slot, count, choice;

    for(i=0; i<5; i++) {
        printf("Enter name for appointment %d: ", i+1);
        scanf("%s", app[i].name);

        // Keep prompting user until a valid time slot is entered
        while(1) {
            printf("Enter time slot for appointment %d (1-5): ", i+1);
            scanf("%d", &time_slot);

            // Check if time slot is already taken
            count = 0;
            for(j=0; j<i; j++) {
                if(app[j].time == time_slot)
                    count++;
            }

            if(count == 0)
                break;
            else
                printf("Time slot is already taken. Please select another slot.\n");
        }

        app[i].time = time_slot;
        printf("Appointment scheduled for %s at %d\n", app[i].name, app[i].time);
    }

    // Display list of appointments
    printf("\nAppointment Schedule:\n");
    for(i=1; i<=5; i++) {
        printf("Time Slot %d: ", i);
        count = 0;
        for(j=0; j<5; j++) {
            if(app[j].time == i) {
                printf("%s\n", app[j].name);
                count++;
            }
        }

        if(count == 0)
            printf("Empty\n");
    }

    // Prompt user to cancel an appointment
    printf("Do you want to cancel an appointment? (Enter 1 for Yes or 2 for No): ");
    scanf("%d", &choice);

    if(choice == 1) {
        char name[20];
        printf("Enter the name of the appointment you want to cancel: ");
        scanf("%s", name);

        count = 0;
        for(i=0; i<5; i++) {
            if(strcmp(name, app[i].name) == 0) {
                app[i].time = 0; // Mark time slot as available (0)
                printf("Appointment cancelled for %s\n", app[i].name);
                count++;
                break;
            }
        }

        if(count == 0)
            printf("Appointment not found\n");

        // Display updated list of appointments
        printf("\nUpdated Appointment Schedule:\n");
        for(i=1; i<=5; i++) {
            printf("Time Slot %d: ", i);
            count = 0;
            for(j=0; j<5; j++) {
                if(app[j].time == i) {
                    printf("%s\n", app[j].name);
                    count++;
                }
            }

            if(count == 0)
                printf("Empty\n");
        }
    }

    return 0;
}