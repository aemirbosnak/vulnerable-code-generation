//FormAI DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIB_SIZE 20 // maximum size of the library

struct song {
    char name[50];
    char artist[50];
    int year;
    float duration;
};

struct library {
    struct song songs[MAX_LIB_SIZE];
    int num_songs;
};

// function to add a new song to the library
void add_song(struct library *lib) {
    if (lib->num_songs >= MAX_LIB_SIZE) {
        printf("Library is full. Cannot add more songs.\n");
        return;
    }

    struct song new_song;
    printf("Enter song name: ");
    scanf("%s", new_song.name);
    printf("Enter artist name: ");
    scanf("%s", new_song.artist);
    printf("Enter year of release: ");
    scanf("%d", &new_song.year);
    printf("Enter song duration (in minutes): ");
    scanf("%f", &new_song.duration);

    lib->songs[lib->num_songs] = new_song;
    lib->num_songs++;
}

// function to display all songs in the library
void display_songs(struct library *lib) {
    if (lib->num_songs == 0) {
        printf("Library is empty. No songs to display.\n");
        return;
    }

    printf("S.No.\tName\t\tArtist\t\tYear\tDuration\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%d\t%s\t\t%s\t\t%d\t%.2f min\n", i+1, lib->songs[i].name, lib->songs[i].artist, lib->songs[i].year, lib->songs[i].duration);
    }
}

// function to search for a song based on its name
void search_song(struct library *lib) {
    if (lib->num_songs == 0) {
        printf("Library is empty. No songs to search for.\n");
        return;
    }

    char name[50];
    printf("Enter name of the song to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(name, lib->songs[i].name) == 0) {
            found = 1;
            printf("Song found:\n");
            printf("Name: %s\nArtist: %s\nYear: %d\nDuration: %.2f min\n", lib->songs[i].name, lib->songs[i].artist, lib->songs[i].year, lib->songs[i].duration);
            break;
        }
    }

    if (!found) {
        printf("Song not found in the library.\n");
    }
}

// function to remove a song from the library
void remove_song(struct library *lib) {
    if (lib->num_songs == 0) {
        printf("Library is empty. No songs to remove.\n");
        return;
    }

    char name[50];
    printf("Enter name of the song to remove: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(name, lib->songs[i].name) == 0) {
            found = 1;
            for (int j = i; j < lib->num_songs-1; j++) {
                lib->songs[j] = lib->songs[j+1];
            }
            lib->num_songs--;
            printf("Song removed from the library.\n");
            break;
        }
    }

    if (!found) {
        printf("Song not found in the library.\n");
    }
}

int main() {
    struct library lib;
    lib.num_songs = 0;

    int choice;
    do {
        printf("\n----------- C Music Library Management System ----------\n");
        printf("1. Add song to the library\n2. Display all songs in the library\n3. Search for a song\n4. Remove a song\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(&lib);
                break;
            case 2:
                display_songs(&lib);
                break;
            case 3:
                search_song(&lib);
                break;
            case 4:
                remove_song(&lib);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}