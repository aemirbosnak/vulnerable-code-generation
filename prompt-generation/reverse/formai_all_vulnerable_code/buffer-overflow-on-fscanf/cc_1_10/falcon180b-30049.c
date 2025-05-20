//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char exercise[50];
    char duration[10];
    time_t timestamp;
} Entry;

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    time_t current_time;

    // Open the file for reading and writing
    file = fopen("fitness_tracker.txt", "a+");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read in existing entries
    rewind(file);
    while (fscanf(file, "%s %s %ld\n", entries[num_entries].exercise, entries[num_entries].duration, &entries[num_entries].timestamp)!= EOF) {
        num_entries++;
    }

    do {
        printf("Fitness Tracker Menu:\n");
        printf("1. Add an exercise\n");
        printf("2. View entries\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the exercise: ");
                scanf("%s", entries[num_entries].exercise);
                printf("Enter the duration (in minutes): ");
                scanf("%s", entries[num_entries].duration);
                time(&current_time);
                entries[num_entries].timestamp = current_time;
                num_entries++;
                break;
            case 2:
                printf("Entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s %s %s\n", entries[i].exercise, entries[i].duration, ctime(&entries[i].timestamp));
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    // Write out updated entries
    rewind(file);
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s %s %ld\n", entries[i].exercise, entries[i].duration, entries[i].timestamp);
    }

    fclose(file);
    return 0;
}