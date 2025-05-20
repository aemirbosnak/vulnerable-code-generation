//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELERS 10

typedef struct {
    char name[32];
    int age;
    int year_of_birth;
} TimeTraveler;

TimeTraveler time_travelers[MAX_TIME_TRAVELERS];

int main() {
    int num_time_travelers;
    int i;

    // Get the number of time travelers.
    printf("Enter the number of time travelers: ");
    scanf("%d", &num_time_travelers);

    // Get the details of each time traveler.
    for (i = 0; i < num_time_travelers; i++) {
        printf("Enter the name of time traveler %d: ", i + 1);
        scanf("%s", time_travelers[i].name);

        printf("Enter the age of time traveler %d: ", i + 1);
        scanf("%d", &time_travelers[i].age);

        printf("Enter the year of birth of time traveler %d: ", i + 1);
        scanf("%d", &time_travelers[i].year_of_birth);
    }

    // Print the details of each time traveler.
    printf("\nTime Travelers:\n");
    for (i = 0; i < num_time_travelers; i++) {
        printf("%s\n", time_travelers[i].name);
        printf("%d\n", time_travelers[i].age);
        printf("%d\n", time_travelers[i].year_of_birth);
        printf("\n");
    }

    // Get the year to which the time travelers want to travel.
    int year_to_travel;
    printf("Enter the year to which the time travelers want to travel: ");
    scanf("%d", &year_to_travel);

    // Calculate the time difference between the current year and the year to which the time travelers want to travel.
    int time_difference = year_to_travel - time_travelers[0].year_of_birth;

    // Update the age of each time traveler.
    for (i = 0; i < num_time_travelers; i++) {
        time_travelers[i].age += time_difference;
    }

    // Print the details of each time traveler after time travel.
    printf("\nTime Travelers After Time Travel:\n");
    for (i = 0; i < num_time_travelers; i++) {
        printf("%s\n", time_travelers[i].name);
        printf("%d\n", time_travelers[i].age);
        printf("%d\n", time_travelers[i].year_of_birth);
        printf("\n");
    }

    return 0;
}