//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int duration;
    int calories;
    int distance;
} Entry;

int main() {
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];

    while (num_entries < MAX_ENTRIES) {
        printf("Enter workout name (up to %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", entries[num_entries].name);

        printf("Enter workout description (up to %d characters): ", MAX_DESCRIPTION_LENGTH - 1);
        scanf("%s", entries[num_entries].description);

        printf("Enter workout duration in minutes: ");
        scanf("%d", &entries[num_entries].duration);

        printf("Enter workout calories burned: ");
        scanf("%d", &entries[num_entries].calories);

        printf("Enter workout distance in meters: ");
        scanf("%d", &entries[num_entries].distance);

        num_entries++;
    }

    printf("\nEntries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\n", entries[i].name);
        printf("Description: %s\n", entries[i].description);
        printf("Duration: %d minutes\n", entries[i].duration);
        printf("Calories burned: %d\n", entries[i].calories);
        printf("Distance: %d meters\n\n", entries[i].distance);
    }

    return 0;
}