//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

int compareActivities(const void *a, const void *b) {
    Activity *activity1 = (Activity *)a;
    Activity *activity2 = (Activity *)b;
    return activity1->end - activity2->end;
}

Activity *readActivitiesFromFile(const char *filename, int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fscanf(file, "%d", n);
    Activity *activities = malloc(*n * sizeof(Activity));
    if (!activities) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d %d", &activities[i].start, &activities[i].end);
    }

    fclose(file);
    return activities;
}

void selectActivities(Activity *activities, int n) {
    // Sort activities based on their end time
    qsort(activities, n, sizeof(Activity), compareActivities);

    printf("Selected activities are:\n");
    int i = 0; // First activity always gets selected
    printf("Activity %d: [%d, %d]\n", i + 1, activities[i].start, activities[i].end);

    for (int j = 1; j < n; j++) {
        // If this activity starts after or when the last selected activity ends
        if (activities[j].start >= activities[i].end) {
            printf("Activity %d: [%d, %d]\n", j + 1, activities[j].start, activities[j].end);
            i = j; // Update the index of the last selected activity
        }
    }
}

void freeActivities(Activity *activities) {
    free(activities);
}

int main() {
    int n;
    const char *filename = "activities.txt";

    // Reading activities from a file
    Activity *activities = readActivitiesFromFile(filename, &n);
    if (activities == NULL) {
        return EXIT_FAILURE;
    }

    // Selecting and displaying the maximum number of activities
    selectActivities(activities, n);

    // Free allocated memory
    freeActivities(activities);

    return EXIT_SUCCESS;
}