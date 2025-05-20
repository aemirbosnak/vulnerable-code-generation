//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LOG_ENTRIES 10000
#define MAX_LOG_ENTRY_SIZE 1024

// Log entry structure
typedef struct log_entry {
    char message[MAX_LOG_ENTRY_SIZE];
    int timestamp;
} log_entry;

// Log buffer
log_entry log_buffer[MAX_LOG_ENTRIES];

// Log buffer lock
pthread_mutex_t log_buffer_lock = PTHREAD_MUTEX_INITIALIZER;

// Log buffer head and tail indices
int log_buffer_head = 0;
int log_buffer_tail = 0;

// Log analysis thread
void *log_analysis_thread(void *arg) {
    while (1) {
        // Acquire the log buffer lock
        pthread_mutex_lock(&log_buffer_lock);

        // Check if the log buffer is empty
        if (log_buffer_head == log_buffer_tail) {
            // Release the log buffer lock
            pthread_mutex_unlock(&log_buffer_lock);
            
            // Sleep for a while
            sleep(1);
            
            // Continue the loop
            continue;
        }

        // Get the next log entry
        log_entry *log_entry = &log_buffer[log_buffer_tail];

        // Increment the tail index
        log_buffer_tail = (log_buffer_tail + 1) % MAX_LOG_ENTRIES;

        // Release the log buffer lock
        pthread_mutex_unlock(&log_buffer_lock);

        // Analyze the log entry
        printf("%s\n", log_entry->message);
    }

    return NULL;
}

// Main function
int main() {
    // Create the log analysis thread
    pthread_t log_analysis_thread_id;
    pthread_create(&log_analysis_thread_id, NULL, log_analysis_thread, NULL);

    // Start reading log entries from a file or stream
    while (1) {
        // Read a log entry
        log_entry log_entry;
        scanf("%s %d", log_entry.message, &log_entry.timestamp);

        // Acquire the log buffer lock
        pthread_mutex_lock(&log_buffer_lock);

        // Add the log entry to the log buffer
        log_buffer[log_buffer_head] = log_entry;

        // Increment the head index
        log_buffer_head = (log_buffer_head + 1) % MAX_LOG_ENTRIES;

        // Release the log buffer lock
        pthread_mutex_unlock(&log_buffer_lock);
    }

    return 0;
}