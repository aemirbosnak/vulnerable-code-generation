//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_TRACKS 100
#define NAME_LEN 100

typedef struct {
    char name[NAME_LEN];
    char artist[NAME_LEN];
} Track;

typedef struct {
    Track tracks[MAX_TRACKS];
    int count;
    pthread_mutex_t lock;
} MusicLibrary;

MusicLibrary library;

void* add_track(void* arg) {
    Track* new_track = (Track*)arg;
    pthread_mutex_lock(&library.lock);
    
    if (library.count < MAX_TRACKS) {
        library.tracks[library.count] = *new_track;
        library.count++;
        printf("Added track: %s by %s\n", new_track->name, new_track->artist);
    } else {
        printf("Failed to add track: Library is full\n");
    }
    
    pthread_mutex_unlock(&library.lock);
    free(new_track);
    return NULL;
}

void* delete_track(void* arg) {
    char* track_name = (char*)arg;
    pthread_mutex_lock(&library.lock);
    
    for (int i = 0; i < library.count; i++) {
        if (strcmp(library.tracks[i].name, track_name) == 0) {
            printf("Deleted track: %s by %s\n", library.tracks[i].name, library.tracks[i].artist);
            for (int j = i; j < library.count - 1; j++) {
                library.tracks[j] = library.tracks[j + 1];
            }
            library.count--;
            break;
        }
    }
    
    pthread_mutex_unlock(&library.lock);
    return NULL;
}

void* search_track(void* arg) {
    char* track_name = (char*)arg;
    pthread_mutex_lock(&library.lock);
    
    for (int i = 0; i < library.count; i++) {
        if (strcmp(library.tracks[i].name, track_name) == 0) {
            printf("Found track: %s by %s\n", library.tracks[i].name, library.tracks[i].artist);
            pthread_mutex_unlock(&library.lock);
            return NULL;
        }
    }
    
    printf("Track '%s' not found.\n", track_name);
    pthread_mutex_unlock(&library.lock);
    return NULL;
}

int main() {
    pthread_t threads[100];
    int thread_count = 0;
    library.count = 0;
    pthread_mutex_init(&library.lock, NULL);

    while (1) {
        int choice;
        printf("Music Library Management System\n");
        printf("1. Add Track\n2. Delete Track\n3. Search Track\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Track* new_track = (Track*)malloc(sizeof(Track));
            printf("Enter track name: ");
            scanf("%s", new_track->name);
            printf("Enter artist name: ");
            scanf("%s", new_track->artist);
            pthread_create(&threads[thread_count++], NULL, add_track, (void*)new_track);
        } else if (choice == 2) {
            char* track_name = (char*)malloc(NAME_LEN);
            printf("Enter track name to delete: ");
            scanf("%s", track_name);
            pthread_create(&threads[thread_count++], NULL, delete_track, (void*)track_name);
        } else if (choice == 3) {
            char* track_name = (char*)malloc(NAME_LEN);
            printf("Enter track name to search: ");
            scanf("%s", track_name);
            pthread_create(&threads[thread_count++], NULL, search_track, (void*)track_name);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&library.lock);
    printf("Exiting Music Library Management System. Goodbye!\n");
    return 0;
}