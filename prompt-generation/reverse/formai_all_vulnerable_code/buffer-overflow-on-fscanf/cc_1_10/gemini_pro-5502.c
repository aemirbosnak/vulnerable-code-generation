//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

// Define the maximum number of songs that can be stored in the library
#define MAX_SONGS 100

// Define the maximum length of a song title
#define MAX_TITLE_LENGTH 50

// Define the maximum length of an artist name
#define MAX_ARTIST_LENGTH 50

// Define the maximum length of a genre name
#define MAX_GENRE_LENGTH 50

// Define the maximum length of a string representing a time duration
#define MAX_DURATION_LENGTH 10

// Define the maximum length of a file path
#define MAX_FILE_PATH_LENGTH 255

// Define the number of threads that will be used to handle asynchronous tasks
#define NUM_THREADS 4

// Define the structure of a song
typedef struct song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char duration[MAX_DURATION_LENGTH];
    char file_path[MAX_FILE_PATH_LENGTH];
} song;

// Define the structure of a library
typedef struct library {
    song songs[MAX_SONGS];
    int num_songs;
} library;

// Define the structure of a thread parameter
typedef struct thread_parameter {
    library *lib;
    int start_index;
    int end_index;
} thread_parameter;

// Declare the global library
library lib;

// Declare the global thread pool
pthread_t thread_pool[NUM_THREADS];

// Declare the global thread parameter array
thread_parameter thread_parameters[NUM_THREADS];

// Define the function that will be executed by each thread
void *thread_function(void *param) {
    // Cast the thread parameter to the correct type
    thread_parameter *p = (thread_parameter *)param;
    
    // Loop through the songs and print their information
    for (int i = p->start_index; i < p->end_index; i++) {
        printf("%s - %s - %s - %s - %s\n", 
            p->lib->songs[i].title, 
            p->lib->songs[i].artist, 
            p->lib->songs[i].genre, 
            p->lib->songs[i].duration, 
            p->lib->songs[i].file_path);
    }
    
    // Return NULL to indicate that the thread has finished executing
    return NULL;
}

// Define the function that will be called when the user presses Ctrl+C
void signal_handler(int signum) {
    // Cancel all of the threads in the thread pool
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_cancel(thread_pool[i]);
    }
    
    // Join all of the threads in the thread pool
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_pool[i], NULL);
    }
    
    // Exit the program
    exit(0);
}

// Define the main function
int main() {
    // Register the signal handler
    signal(SIGINT, signal_handler);
    
    // Initialize the library
    lib.num_songs = 0;
    
    // Load the songs from the file
    FILE *fp = fopen("songs.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    while (!feof(fp)) {
        fscanf(fp, "%s - %s - %s - %s - %s\n", 
            lib.songs[lib.num_songs].title, 
            lib.songs[lib.num_songs].artist, 
            lib.songs[lib.num_songs].genre, 
            lib.songs[lib.num_songs].duration, 
            lib.songs[lib.num_songs].file_path);
        lib.num_songs++;
    }
    
    fclose(fp);
    
    // Create the thread pool
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_parameters[i].lib = &lib;
        thread_parameters[i].start_index = i * (lib.num_songs / NUM_THREADS);
        thread_parameters[i].end_index = (i + 1) * (lib.num_songs / NUM_THREADS);
        pthread_create(&thread_pool[i], NULL, thread_function, &thread_parameters[i]);
    }
    
    // Join the thread pool
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_pool[i], NULL);
    }
    
    return 0;
}