//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME_TRAVELERS 10

typedef struct traveler {
    char name[50];
    int year;
    struct traveler *next;
} traveler;

traveler *time_travelers = NULL;

void add_traveler(char *name, int year) {
    traveler *new_traveler = (traveler *) malloc(sizeof(traveler));
    strcpy(new_traveler->name, name);
    new_traveler->year = year;
    new_traveler->next = time_travelers;
    time_travelers = new_traveler;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You have the power to travel through time, but beware!\n");
    printf("You can only travel to the past or future, but each travel has a risk!\n");

    int num_travelers = 0;

    while (num_travelers < MAX_TIME_TRAVELERS) {
        char name[50];
        int year;

        printf("Enter the name of traveler %d: ", num_travelers + 1);
        scanf("%s", name);

        printf("Enter the year of travel (%d is the current year): ", time(NULL) / 365);
        scanf("%d", &year);

        add_traveler(name, year);
        num_travelers++;

        int risk = rand() % 10;

        if (risk > 5) {
            printf("Congratulations! Your travel to %d was successful!\n", year);
        } else {
            printf("Oh no! Your travel to %d failed!\n", year);
        }
    }

    printf("\nThe following travelers have successfully traveled through time:\n");

    traveler *current = time_travelers;

    while (current != NULL) {
        printf("%s (%d)\n", current->name, current->year);
        current = current->next;
    }

    free(time_travelers);

    return 0;
}