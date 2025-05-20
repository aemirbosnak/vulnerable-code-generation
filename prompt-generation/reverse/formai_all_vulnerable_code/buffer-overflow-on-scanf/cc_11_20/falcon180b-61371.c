//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int green_sec = 30, yellow_sec = 5, red_sec = 25, wait_sec = 0;
    char choice;

    printf("Welcome to the traffic light controller program!\n");
    printf("Please select a mode:\n");
    printf("1. Automatic mode\n");
    printf("2. Manual mode\n");
    scanf("%c", &choice);

    if (choice == '1') {
        while (1) {
            printf("Starting automatic mode...\n");
            for (int i = 0; i < green_sec; i++) {
                printf("Green light on...\n");
                fflush(stdout);
                wait_sec = rand() % 5 + 1;
                sleep(wait_sec);
            }
            for (int i = 0; i < yellow_sec; i++) {
                printf("Yellow light on...\n");
                fflush(stdout);
                wait_sec = rand() % 5 + 1;
                sleep(wait_sec);
            }
            for (int i = 0; i < red_sec; i++) {
                printf("Red light on...\n");
                fflush(stdout);
                wait_sec = rand() % 5 + 1;
                sleep(wait_sec);
            }
        }
    } else if (choice == '2') {
        while (1) {
            printf("Starting manual mode...\n");
            printf("Enter 1 for green light, 2 for yellow light, and 3 for red light:\n");
            scanf("%d", &wait_sec);

            if (wait_sec == 1) {
                for (int i = 0; i < green_sec; i++) {
                    printf("Green light on...\n");
                    fflush(stdout);
                    wait_sec = rand() % 5 + 1;
                    sleep(wait_sec);
                }
            } else if (wait_sec == 2) {
                for (int i = 0; i < yellow_sec; i++) {
                    printf("Yellow light on...\n");
                    fflush(stdout);
                    wait_sec = rand() % 5 + 1;
                    sleep(wait_sec);
                }
            } else if (wait_sec == 3) {
                for (int i = 0; i < red_sec; i++) {
                    printf("Red light on...\n");
                    fflush(stdout);
                    wait_sec = rand() % 5 + 1;
                    sleep(wait_sec);
                }
            }

            printf("Press any key to continue...\n");
            getchar();
        }
    } else {
        printf("Invalid choice. Please select 1 or 2.\n");
    }

    return 0;
}