//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a year to travel to: ");

    int destinationYear;
    scanf("%d", &destinationYear);

    printf("\nPreparing time machine...\n");
    printf("3... ");
    sleep(1);
    printf("2... ");
    sleep(1);
    printf("1... ");
    sleep(1);
    printf("GO!\n\n");

    int currentYear = 2021;

    if (destinationYear < currentYear) {
        printf("Traveling back in time...\n\n");

        for (int i = currentYear; i >= destinationYear; i--) {
            printf("Year: %d\n", i);
            printf("Events:\n");

            if (i == 1969) {
                printf("- Man walks on the Moon for the first time!\n");
            } else if (i == 1776) {
                printf("- United States declares independence!\n");
            } else if (i == 1492) {
                printf("- Christopher Columbus discovers America!\n");
            } else if (i == 1348) {
                printf("- The Black Death kills millions in Europe.\n");
            } else if (i == 1066) {
                printf("- William the Conqueror conquers England.\n");
            }

            sleep(1);
            printf("\n");
        }

        printf("You have arrived in the year %d!\n", destinationYear);

    } else if (destinationYear > currentYear) {
        printf("Traveling forward in time...\n\n");

        for (int i = currentYear; i <= destinationYear; i++) {
            printf("Year: %d\n", i);
            printf("Events:\n");

            if (i == 2022) {
                printf("- First contact with alien life forms!\n");
            } else if (i == 2045) {
                printf("- Artificial Intelligence becomes self-aware!\n");
            } else if (i == 2057) {
                printf("- First humans on Mars!\n");
            } else if (i == 2100) {
                printf("- Our sun enters its Red Giant phase.\n");
            } else if (i == 2150) {
                printf("- Humans achieve immortality through genetic engineering!\n");
            }

            sleep(1);
            printf("\n");
        }

        printf("You have arrived in the year %d!\n", destinationYear);

    } else {
        printf("You are already in the year %d!\n", destinationYear);
    }

    return 0;
}