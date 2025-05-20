//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char activity[50];
    int duration;
    time_t timestamp;
} Entry;

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    file = fopen("fitness_log.txt", "a+");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (1) {
        printf("Fitness Tracker\n");
        printf("1. Add activity\n");
        printf("2. View log\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter activity: ");
            scanf("%s", entries[num_entries].activity);
            printf("Enter duration (in minutes): ");
            scanf("%d", &entries[num_entries].duration);
            entries[num_entries].timestamp = time(NULL);
            num_entries++;
            break;

        case '2':
            for (int i = 0; i < num_entries; i++) {
                fprintf(file, "%s (%d minutes) - %s\n", entries[i].activity, entries[i].duration, ctime(&entries[i].timestamp));
            }
            break;

        case '3':
            fclose(file);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}