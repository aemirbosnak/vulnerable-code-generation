//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <pthread.h>

// Define maximum number of songs in the library
#define MAX_SONGS 100

// Define structure for storing song information
struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
};

// Define global array for storing songs in the library
struct Song library[MAX_SONGS];

// Define global variables for tracking number of songs in the library and number of available threads
int num_songs = 0;
int num_threads = 0;

// Define thread function for adding a song to the library
void* add_song(void* arg) {
    if (num_songs >= MAX_SONGS) {
        printf("Error: library is full\n");
        num_threads--;
        pthread_exit(NULL);
    }
    else {
        struct Song new_song = *(struct Song*)arg;
        library[num_songs] = new_song;
        printf("Song added to library: %s - %s\n", new_song.title, new_song.artist);
        num_songs++;
        num_threads--;
        pthread_exit(NULL);
    }
}

// Define thread function for searching for a song in the library
void* search_song(void* arg) {
    char* search_title = (char*)arg;
    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, search_title) == 0) {
            printf("Song found in library: %s - %s\n", library[i].title, library[i].artist);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found in library: %s\n", search_title);
    }
    num_threads--;
    pthread_exit(NULL);
}

int main() {

    // Initialize pthread variables
    pthread_t threads[MAX_SONGS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Initialize library with some example songs
    struct Song example1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 354};
    struct Song example2 = {"Stairway to Heaven", "Led Zeppelin", "IV", 1971, 481};
    struct Song example3 = {"Hotel California", "Eagles", "Hotel California", 1976, 390};
    library[0] = example1;
    library[1] = example2;
    library[2] = example3;
    num_songs = 3;

    // Start user interface loop
    int running = 1;
    while (running) {

        // Print menu
        printf("\nMUSIC LIBRARY MANAGEMENT SYSTEM\n");
        printf("1. Add song to library\n");
        printf("2. Search for song in library\n");
        printf("3. Exit\n");
        printf("Enter selection: ");

        // Get user input
        int selection;
        scanf("%d", &selection);

        // Handle user selection
        switch (selection) {

            // Add song to library
            case 1: {
                if (num_threads < MAX_SONGS) {
                    // Get song information from user
                    struct Song new_song;
                    printf("Enter song title: ");
                    getchar();
                    fgets(new_song.title, 50, stdin);
                    printf("Enter artist name: ");
                    fgets(new_song.artist, 50, stdin);
                    printf("Enter album title: ");
                    fgets(new_song.album, 50, stdin);
                    printf("Enter year of release: ");
                    scanf("%d", &new_song.year);
                    printf("Enter song duration in seconds: ");
                    scanf("%d", &new_song.duration);

                    // Create thread to add new song to library
                    pthread_create(&threads[num_threads], &attr, add_song, (void*)&new_song);
                    printf("Adding song to library...\n");
                    num_threads++;
                }
                else {
                    printf("Error: maximum number of threads reached\n");
                }
                break;
            }

            // Search for song in library
            case 2: {
                if (num_threads < MAX_SONGS) {
                    // Get song title from user
                    char search_title[50];
                    printf("Enter song title to search for: ");
                    getchar();
                    fgets(search_title, 50, stdin);

                    // Create thread to search for song in library
                    pthread_create(&threads[num_threads], &attr, search_song, (void*)search_title);
                    printf("Searching for song in library...\n");
                    num_threads++;
                }
                else {
                    printf("Error: maximum number of threads reached\n");
                }
                break;
            }

            // Exit program
            case 3: {
                running = 0;
                break;
            }

            // Invalid selection
            default: {
                printf("Error: invalid selection\n");
                break;
            }
        }

        // Wait for threads to complete
        for (int i = 0; i < num_threads; i++) {
            pthread_join(threads[i], NULL);
        }
    }

    // Cleanup pthread variables
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);

    return 0;
}