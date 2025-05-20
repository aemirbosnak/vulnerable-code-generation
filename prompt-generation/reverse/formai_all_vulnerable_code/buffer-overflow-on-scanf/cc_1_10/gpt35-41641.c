//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 30
#define MAX_SECONDS 1800
#define WARMUP_TIME 300

typedef struct {
    int seconds;
    int calories_burned;
} Entry;

int main() {
    int total_seconds = 0;
    int total_calories = 0;
    int entries = 0;
    Entry entry_list[MAX_ENTRIES];

    printf("Welcome to the C Fitness Tracker!\n");
    printf("We will track your exercise routine and calculate the calories burned.\n");
    printf("You have 30 minutes to complete your exercise routine.\n");
    printf("You must have a 5-minute warmup and a 25-minute workout.\n");
    printf("Are you ready to begin? Type 'start' to begin.\n");

    char input[10];
    scanf("%s", input);

    if (strcmp(input, "start") != 0) {
        printf("Invalid input. Exiting program.\n");
        return 0;
    }

    printf("Starting warmup...\n");
    for (int i = 0; i < WARMUP_TIME; i += 30) {
        printf("Time left: %d seconds.\n", WARMUP_TIME - i);
        sleep(1);
    }

    printf("Warmup complete. Starting workout...\n");
    for (int i = WARMUP_TIME; i < MAX_SECONDS; i += 30) {
        printf("Time left: %d seconds.\n", MAX_SECONDS - i);
        printf("Enter calories burned for this interval: ");
        int calories;
        scanf("%d", &calories);
        Entry new_entry = { i, calories };
        entry_list[entries++] = new_entry;
        total_calories += calories;
        total_seconds += 30;
        sleep(1);
    }

    printf("Workout complete. Displaying data...\n\n");
    printf("Total Time: %d seconds\n", total_seconds);
    printf("Total Calories Burned: %d calories\n", total_calories);
    printf("Calories Burned per Minute: %f\n", (float)total_calories / (float)total_seconds * 60);

    printf("Detailed breakdown of calories burned per interval:\n");
    printf("Time (s)\tCalories Burned\n");
    for (int i = 0; i < entries; i++) {
        printf("%d\t\t%d\n", entry_list[i].seconds, entry_list[i].calories_burned);
    }

    printf("Thank you for using the C Fitness Tracker!\n");
    return 0;
}