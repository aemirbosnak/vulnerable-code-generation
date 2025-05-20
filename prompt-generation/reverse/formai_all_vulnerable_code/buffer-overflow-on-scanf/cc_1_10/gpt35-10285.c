//FormAI DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ENTRIES 1000

typedef struct {
    char *date;
    char *entry;
    pthread_mutex_t mutex; // For thread safety
} diary_entry_t;

diary_entry_t diary[MAX_ENTRIES]; // global diary array
int num_entries = 0; // number of entries in diary

void *add_entry(void *param) {
    diary_entry_t *diary_entry = param;
    pthread_mutex_lock(&diary_entry->mutex); // Lock mutex for thread safety
    if (num_entries < MAX_ENTRIES) { // Ensure we are not exceeding the limit of entries
        diary[num_entries++] = *diary_entry;
        printf("Entry added successfully!\n");
    } else {
        printf("Maximum number of entries exceeded\n");
    }
    pthread_mutex_unlock(&diary_entry->mutex); // Unlock mutex
    return NULL;
}

int main() {
    pthread_t thread;
    char date[50], entry[500];
    diary_entry_t diary_entry;

    pthread_mutex_init(&diary_entry.mutex, NULL); // Initialize mutex

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);
        if (strcmp(date, "exit") == 0) break; // Exit program if user enters "exit"
        printf("Enter diary entry: ");
        scanf("%s", entry);

        diary_entry.date = strdup(date); // Allocate memory for date string
        diary_entry.entry = strdup(entry); // Allocate memory for entry string
        pthread_create(&thread, NULL, &add_entry, &diary_entry); // Create thread to add entry
        pthread_join(thread, NULL); // Wait for thread to finish
    }

    pthread_mutex_destroy(&diary_entry.mutex); // Destroy mutex

    printf("\nDiary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }

    return 0;
}