//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a spam filter
typedef struct SpamFilter {
    char *pattern;  // The spam pattern
    int weight;     // The weight of the pattern
} SpamFilter;

// Function to compare two spam filters
int compareSpamFilters(const void *a, const void *b) {
    const SpamFilter *filter1 = (const SpamFilter *)a;
    const SpamFilter *filter2 = (const SpamFilter *)b;
    return strcmp(filter1->pattern, filter2->pattern);
}

// Function to load spam filters from a file
int loadSpamFilters(SpamFilter **filters, int *numFilters, char *filename) {
    FILE *fp;
    char line[1024];

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    // Read the number of filters
    fscanf(fp, "%d", numFilters);

    // Allocate memory for the filters
    *filters = (SpamFilter *)malloc(*numFilters * sizeof(SpamFilter));
    if (*filters == NULL) {
        fclose(fp);
        return -1;
    }

    // Read the filters
    for (int i = 0; i < *numFilters; i++) {
        fscanf(fp, "%s %d", (*filters)[i].pattern, &(*filters)[i].weight);
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Function to check if a message is spam
int isSpam(char *message, SpamFilter *filters, int numFilters) {
    int score = 0;

    // Check for each filter
    for (int i = 0; i < numFilters; i++) {
        if (strstr(message, filters[i].pattern) != NULL) {
            score += filters[i].weight;
        }
    }

    // Return true if the score is greater than 0
    return score > 0;
}

// Function to test the spam detection system
void testSpamDetectionSystem() {
    SpamFilter *filters;
    int numFilters;

    // Load the spam filters
    if (loadSpamFilters(&filters, &numFilters, "spam_filters.txt") != 0) {
        printf("Error loading spam filters.\n");
        return;
    }

    // Sort the filters by pattern
    qsort(filters, numFilters, sizeof(SpamFilter), compareSpamFilters);

    // Test the filters
    char *messages[] = {
        "This is a normal message.",
        "This message is spam.",
        "This message is also spam.",
    };

    for (int i = 0; i < sizeof(messages) / sizeof(char *); i++) {
        if (isSpam(messages[i], filters, numFilters)) {
            printf("Message %d is spam.\n", i + 1);
        } else {
            printf("Message %d is not spam.\n", i + 1);
        }
    }

    // Free the filters
    free(filters);
}

int main() {
    testSpamDetectionSystem();
    return 0;
}