//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    char name[30];
    int frequency; // occurrences per year
    float probability; // Event probability, in percentage
} AlienEvent;

void initialize_events(AlienEvent events[], int count) {
    // Example events
    for (int i = 0; i < count; i++) {
        snprintf(events[i].name, sizeof(events[i].name), "Event %d", i + 1);
        events[i].frequency = rand() % 3 + 1; // Random frequency between 1 and 3
        events[i].probability = 1.0 / (i + 1) * 100; // Decreasing probability
    }
}

float calculate_total_probability(AlienEvent events[], int count) {
    float total_probability = 0.0;
    for (int i = 0; i < count; i++) {
        total_probability += events[i].frequency * events[i].probability;
    }
    return total_probability;
}

void display_events(AlienEvent events[], int count) {
    printf("Alien Events and their probabilities:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Frequency: %d, Probability: %.2f%%\n", 
               events[i].name, events[i].frequency, events[i].probability);
    }
}

void user_input_configuration(AlienEvent events[], int *count) {
    printf("Enter the number of alien invasion events (max %d): ", MAX_EVENTS);
    scanf("%d", count);

    if (*count <= 0 || *count > MAX_EVENTS) {
        printf("Invalid number of events. Setting to default (5).\n");
        *count = 5;
    }

    for (int i = 0; i < *count; i++) {
        printf("Enter name for event %d: ", i + 1);
        scanf("%s", events[i].name);
        printf("Enter frequency for event %d (occurrences per year): ", i + 1);
        scanf("%d", &events[i].frequency);
        events[i].probability = 1.0 / (i + 1) * 100; // Keep this logic or modify for user-defined
    }
}

int main() {
    srand(time(NULL));

    AlienEvent events[MAX_EVENTS];
    int event_count;

    user_input_configuration(events, &event_count);

    display_events(events, event_count);

    float total_probability = calculate_total_probability(events, event_count);
    printf("Total Alien Invasion Probability: %.2f%%\n", total_probability);

    if (total_probability > 100) {
        printf("Warning: Total probability exceeds 100%%!\n");
    } else if (total_probability > 0) {
        printf("There is a chance of alien invasion!\n");
    } else {
        printf("No chance of alien invasion detected.\n");
    }

    return 0;
}