//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the phone book structure
typedef struct phone_book {
    char name[100];
    char number[20];
} phone_book;

// Define the thread data structure
typedef struct thread_data {
    int start;
    int end;
    phone_book *phone_book;
    char *search_name;
} thread_data;

// Define the thread function
void *thread_function(void *arg) {
    // Get the thread data
    thread_data *data = (thread_data *)arg;

    // Search for the name in the phone book
    for (int i = data->start; i < data->end; i++) {
        if (strcmp(data->phone_book[i].name, data->search_name) == 0) {
            // Found the name, print the number
            printf("Found %s: %s\n", data->search_name, data->phone_book[i].number);
            return NULL;
        }
    }

    // Not found, return NULL
    return NULL;
}

// Main function
int main() {
    // Create the phone book
    phone_book phone_book[] = {
        {"Alice", "555-1212"},
        {"Bob", "555-1213"},
        {"Carol", "555-1214"},
        {"Dave", "555-1215"},
        {"Eve", "555-1216"}
    };

    // Get the search name from the user
    char search_name[100];
    printf("Enter the name to search for: ");
    scanf("%s", search_name);

    // Create the thread data
    thread_data data;
    data.phone_book = phone_book;
    data.search_name = search_name;
    data.start = 0;
    data.end = sizeof(phone_book) / sizeof(phone_book[0]);

    // Create the thread
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, &data);

    // Join the thread
    pthread_join(thread, NULL);

    return 0;
}