//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIME_TRAVELERS 10
#define MAX_TIME_TRAVELS 100

typedef struct {
    char name[50];
    int age;
    time_t time_of_birth;
    time_t time_of_travel;
    int destination_year;
} time_traveler;

time_traveler time_travelers[MAX_TIME_TRAVELERS];
int num_time_travelers = 0;

void add_time_traveler(char *name, int age, time_t time_of_birth, time_t time_of_travel, int destination_year) {
    if (num_time_travelers >= MAX_TIME_TRAVELERS) {
        printf("Error: Maximum number of time travelers reached.\n");
        return;
    }

    strcpy(time_travelers[num_time_travelers].name, name);
    time_travelers[num_time_travelers].age = age;
    time_travelers[num_time_travelers].time_of_birth = time_of_birth;
    time_travelers[num_time_travelers].time_of_travel = time_of_travel;
    time_travelers[num_time_travelers].destination_year = destination_year;

    num_time_travelers++;
}

void print_time_travelers() {
    for (int i = 0; i < num_time_travelers; i++) {
        printf("Time traveler %d:\n", i + 1);
        printf("Name: %s\n", time_travelers[i].name);
        printf("Age: %d\n", time_travelers[i].age);
        printf("Time of birth: %s", ctime(&time_travelers[i].time_of_birth));
        printf("Time of travel: %s", ctime(&time_travelers[i].time_of_travel));
        printf("Destination year: %d\n\n", time_travelers[i].destination_year);
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Add some time travelers
    add_time_traveler("John Smith", 30, time(NULL) - 30 * 365 * 24 * 60 * 60, time(NULL), 2050);
    add_time_traveler("Jane Doe", 25, time(NULL) - 25 * 365 * 24 * 60 * 60, time(NULL), 2075);
    add_time_traveler("Michael Jones", 40, time(NULL) - 40 * 365 * 24 * 60 * 60, time(NULL), 2100);

    // Print the time travelers
    print_time_travelers();

    return 0;
}