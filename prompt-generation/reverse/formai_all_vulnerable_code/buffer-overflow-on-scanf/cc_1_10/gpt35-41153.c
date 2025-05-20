//FormAI DATASET v1.0 Category: Music Library Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct to hold music data
struct music {
    char title[100];
    char artist[100];
    int year;
    int duration;
    char genre[100];
};

// Declare functions
void add_song();
void display_all_songs();
void search_by_artist();
void search_by_genre();

// Declare global variables
struct music library[100];
int count = 0;

int main() {
    int option;

    do {
        printf("Welcome to the C Music Library Management System!\n");
        printf("Please select an option:\n");
        printf("1. Add Song\n");
        printf("2. Display All Songs\n");
        printf("3. Search By Artist\n");
        printf("4. Search By Genre\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1: add_song();
                    break;
            case 2: display_all_songs();
                    break;
            case 3: search_by_artist();
                    break;
            case 4: search_by_genre();
                    break;
            case 5: printf("Thank you for using the C Music Library Management System.\n");
                    break;
            default: printf("Invalid option. Please select a valid option.\n");
                     break;
        }

    } while (option != 5);

    return 0;
}

void add_song() {
    printf("Adding Song...\n");

    struct music new_song;

    printf("Title: ");
    scanf("%s", new_song.title);

    printf("Artist: ");
    scanf("%s", new_song.artist);

    printf("Year: ");
    scanf("%d", &new_song.year);

    printf("Duration (in seconds): ");
    scanf("%d", &new_song.duration);

    printf("Genre: ");
    scanf("%s", new_song.genre);

    library[count] = new_song;
    count++;

    printf("Song successfully added.\n");
}

void display_all_songs() {
    printf("Displaying All Songs...\n");

    if (count == 0) {
        printf("No songs in library.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %d seconds\n", library[i].duration);
            printf("Genre: %s\n", library[i].genre);
            printf("\n");
        }
    }
}

void search_by_artist() {
    printf("Searching By Artist...\n");

    char search_artist[100];
    int found = 0;

    printf("Enter artist name:");
    scanf("%s", search_artist);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].artist, search_artist) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %d seconds\n", library[i].duration);
            printf("Genre: %s\n", library[i].genre);
            printf("\n");
            found = 1;
        }
    }

    if (found == 0) {
        printf("Artist not found.\n");
    }
}

void search_by_genre() {
    printf("Searching By Genre...\n");

    char search_genre[100];
    int found = 0;

    printf("Enter genre:");
    scanf("%s", search_genre);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].genre, search_genre) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %d seconds\n", library[i].duration);
            printf("Genre: %s\n", library[i].genre);
            printf("\n");
            found = 1;
        }
    }

    if (found == 0) {
        printf("Genre not found.\n");
    }
}