//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    time_t timestamp;
    int duration;
    char* activity;
};

int main() {
    FILE* logfile = fopen("fitness_log.txt", "a+");
    if (logfile == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];
    rewind(logfile);
    while (fscanf(logfile, "%ld %d %s\n", &entries[num_entries].timestamp, &entries[num_entries].duration, entries[num_entries].activity)!= EOF) {
        num_entries++;
    }

    fclose(logfile);

    char* activity = malloc(100 * sizeof(char));
    printf("Enter activity name: ");
    scanf("%s", activity);

    time_t start_time = time(NULL);

    while (1) {
        printf("Press's' to start tracking, 'p' to pause, or 'q' to quit.\n");
        char choice;
        scanf(" %c", &choice);

        if (choice =='s' || choice == 'p') {
            if (choice =='s' && num_entries >= MAX_ENTRIES) {
                printf("Log is full. Please delete some entries.\n");
            } else if (choice == 'p' && num_entries == 0) {
                printf("No activity in progress.\n");
            } else {
                if (choice =='s') {
                    start_time = time(NULL);
                } else {
                    time_t end_time = time(NULL);
                    int duration = difftime(end_time, start_time);
                    if (num_entries < MAX_ENTRIES) {
                        num_entries++;
                    } else {
                        printf("Log is full. Deleting oldest entry.\n");
                        num_entries--;
                    }
                    entries[num_entries].timestamp = start_time;
                    entries[num_entries].duration = duration;
                    strcpy(entries[num_entries].activity, activity);
                    fopen("fitness_log.txt", "a+");
                    fprintf(logfile, "%ld %d %s\n", entries[num_entries].timestamp, entries[num_entries].duration, entries[num_entries].activity);
                    fclose(logfile);
                }
            }
        } else if (choice == 'q') {
            break;
        }
    }

    free(activity);
    return 0;
}