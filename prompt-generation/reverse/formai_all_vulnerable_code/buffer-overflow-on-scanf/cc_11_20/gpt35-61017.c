//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>

int main() {
    int hour = 9;
    int minute = 0;
    int appointments[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Start with an empty schedule

    printf("Welcome to the wackiest appointment scheduler in the world!\n");
    printf("Let's start by scheduling some appointments!\n");

    while (1) {
        char decision;

        printf("Current time: %02d:%02d\n", hour, minute);
        printf("A - Schedule an appointment\n");
        printf("B - Cancel an appointment\n");
        printf("C - View schedule\n");
        printf("D - Do something random\n");
        printf("X - Exit\n");

        printf("Enter your decision: ");
        scanf(" %c", &decision);

        switch (decision) {
            case 'A': {
                int appointment_hour, appointment_minute;

                printf("Enter appointment time (hh:mm): ");
                scanf("%d:%d", &appointment_hour, &appointment_minute);

                if (appointment_hour < hour || (appointment_hour == hour && appointment_minute <= minute)) {
                    printf("Sorry, that time has already passed!\n");
                    break;
                }

                if (appointment_hour > hour + 4) {
                    printf("Sorry, we are not open that late!\n");
                    break;
                }

                if (appointments[(appointment_hour - 9) * 4 + appointment_minute / 15] != 0) {
                    printf("Sorry, that time is already taken!\n");
                    break;
                }

                appointments[(appointment_hour - 9) * 4 + appointment_minute / 15] = 1;
                printf("Appointment scheduled at %02d:%02d!\n", appointment_hour, appointment_minute);
                break;
            }

            case 'B': {
                int appointment_hour, appointment_minute;

                printf("Enter appointment time to cancel (hh:mm): ");
                scanf("%d:%d", &appointment_hour, &appointment_minute);

                if (appointments[(appointment_hour - 9) * 4 + appointment_minute / 15] == 0) {
                    printf("Sorry, there is no appointment at that time to cancel!\n");
                    break;
                }

                appointments[(appointment_hour - 9) * 4 + appointment_minute / 15] = 0;
                printf("Appointment at %02d:%02d cancelled!\n", appointment_hour, appointment_minute);
                break;
            }

            case 'C': {
                printf("Schedule:\n");

                for (int i = 0; i < 16; i++) {
                    int appointment_hour = i / 4 + 9;
                    int appointment_minute = (i % 4) * 15;

                    if (appointments[i] == 0) {
                        printf("%02d:%02d - Free\n", appointment_hour, appointment_minute);
                    } else {
                        printf("%02d:%02d - Busy\n", appointment_hour, appointment_minute);
                    }

                }

                break;
            }

            case 'D': {
                printf("I'm a random decision!\n");
                break;
            }

            case 'X': {
                printf("Thanks for using the wackiest appointment scheduler in the world!\n");
                return 0;
            }

            default: {
                printf("Sorry, I don't know what that means!\n");
                break;
            }
        }
    }
}