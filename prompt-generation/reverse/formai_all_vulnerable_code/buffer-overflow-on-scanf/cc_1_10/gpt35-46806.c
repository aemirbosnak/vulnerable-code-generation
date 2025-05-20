//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_menu();
bool is_valid_time_slot(int time);

int main() {
    int available_times[10] = {8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int booked_times[10] = {0};
    int option = 0;
    int time_selected = 0;

    while (true) {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nAvailable Time Slots:\n");
                for (int i = 0; i < 10; i++) {
                    if (booked_times[i] == 0) {
                        printf("%d:00 - Available\n", available_times[i]);
                    } else {
                        printf("%d:00 - Booked\n", available_times[i]);
                    }
                }
                printf("\n");
                break;

            case 2:
                printf("\nEnter the time you wish to book (i.e. 8 for 8:00): ");
                scanf("%d", &time_selected);

                if (is_valid_time_slot(time_selected) && booked_times[time_selected-8] == 0) {
                    booked_times[time_selected-8] = 1;
                    printf("\nBooked Successfully!\n");
                } else {
                    printf("\nInvalid Time Slot or Already Booked. Please try again.\n");
                }
                break;

            case 3:
                printf("\nExiting Program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid Option Selected. Please Try Again.\n");
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("\n----------- Appointment Scheduler -----------\n");
    printf("1. View Available Time Slots\n");
    printf("2. Book a Time Slot\n");
    printf("3. Exit\n");
}

bool is_valid_time_slot(int time) {
    if (time < 8 || time > 17) {
        return false;
    } else {
        return true;
    }
}