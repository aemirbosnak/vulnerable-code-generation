//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 20

typedef struct {
    char activity[50];
    int duration;
    int calories;
    int heartRate;
    time_t timestamp;
} Entry;

void addEntry() {
    Entry newEntry;
    printf("Enter activity: ");
    scanf("%s", newEntry.activity);
    printf("Enter duration (in minutes): ");
    scanf("%d", &newEntry.duration);
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.calories);
    printf("Enter heart rate (in bpm): ");
    scanf("%d", &newEntry.heartRate);
    time(&newEntry.timestamp);
    FILE *file = fopen("fitness.log", "a");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    fprintf(file, "%s %d %d %d %ld\n", newEntry.activity, newEntry.duration, newEntry.calories, newEntry.heartRate, newEntry.timestamp);
    fclose(file);
    printf("Entry added successfully.\n");
}

void viewEntries() {
    FILE *file = fopen("fitness.log", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;
    while (fscanf(file, "%s %d %d %d %ld\n", entries[numEntries].activity, &entries[numEntries].duration, &entries[numEntries].calories, &entries[numEntries].heartRate, &entries[numEntries].timestamp)!= EOF) {
        numEntries++;
        if (numEntries == MAX_ENTRIES) {
            break;
        }
    }
    fclose(file);
    printf("Fitness log:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s %d minutes %d calories %d bpm %s\n", entries[i].activity, entries[i].duration, entries[i].calories, entries[i].heartRate, ctime(&entries[i].timestamp));
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add entry\n2. View log\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}