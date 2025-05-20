//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;
pthread_mutex_t diary_mutex;

void *add_entry(void *arg) {
    char date[11], entry[MAX_LENGTH];
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", date);
    
    printf("Enter your diary entry: ");
    getchar(); //To consume previous newline
    fgets(entry, sizeof(entry), stdin);
    // Remove newline character from fgets
    entry[strcspn(entry, "\n")] = 0;

    pthread_mutex_lock(&diary_mutex);
    
    if (entry_count < MAX_ENTRIES) {
        strcpy(diary[entry_count].date, date);
        strcpy(diary[entry_count].entry, entry);
        entry_count++;
        printf("Entry added successfully!\n");
    } else {
        printf("Diary is full! Cannot add more entries.\n");
    }
    
    pthread_mutex_unlock(&diary_mutex);
    
    return NULL;
}

void *view_entries(void *arg) {
    pthread_mutex_lock(&diary_mutex);
    
    if (entry_count == 0) {
        printf("No entries found.\n");
    } else {
        printf("Diary Entries:\n");
        for (int i = 0; i < entry_count; i++) {
            printf("[%s] %s\n", diary[i].date, diary[i].entry);
        }
    }
    
    pthread_mutex_unlock(&diary_mutex);
    
    return NULL;
}

void *search_entries(void *arg) {
    char date[11];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%10s", date);
    
    pthread_mutex_lock(&diary_mutex);
    
    int found = 0;
    printf("Searching entries for date: %s\n", date);
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("[%s] %s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No entries found for this date.\n");
    }
    
    pthread_mutex_unlock(&diary_mutex);
    
    return NULL;
}


int main() {
    pthread_t add_thread, view_thread, search_thread;
    char command;

    pthread_mutex_init(&diary_mutex, NULL);

    while (1) {
        printf("Welcome to your digital diary!\n");
        printf("Choose an action: (a) Add Entry, (v) View Entries, (s) Search Entries, (q) Quit: ");
        scanf(" %c", &command);
        
        switch (command) {
            case 'a':
                pthread_create(&add_thread, NULL, add_entry, NULL);
                pthread_join(add_thread, NULL);
                break;
            case 'v':
                pthread_create(&view_thread, NULL, view_entries, NULL);
                pthread_join(view_thread, NULL);
                break;
            case 's':
                pthread_create(&search_thread, NULL, search_entries, NULL);
                pthread_join(search_thread, NULL);
                break;
            case 'q':
                printf("Exiting the diary. Goodbye!\n");
                pthread_mutex_destroy(&diary_mutex);
                return 0;
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
    }
    
    return 0;
}