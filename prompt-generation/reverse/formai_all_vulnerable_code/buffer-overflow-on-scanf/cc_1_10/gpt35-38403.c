//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct song {
    char title[50];
    char artist[50];
    int length;
} Song;

Song library[MAX_ITEMS];
int num_items = 0;

void add_song() {
    if (num_items == MAX_ITEMS) {
        printf("The library is already full!\n");
        return;
    }

    Song new_song;
    printf("Enter the song title: ");
    fgets(new_song.title, 50, stdin);
    new_song.title[strcspn(new_song.title, "\n")] = 0; // remove the newline character
    printf("Enter the artist name: ");
    fgets(new_song.artist, 50, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = 0;
    printf("Enter the song length in seconds: ");
    scanf("%d", &new_song.length);
    getchar(); // consume the newline character left in the input buffer

    library[num_items++] = new_song;
    printf("Song added successfully to the library.\n");
}

void remove_song() {
    if (num_items == 0) {
        printf("The library is already empty!\n");
        return;
    }

    char title_to_remove[50];
    printf("Enter the title of the song to remove: ");
    fgets(title_to_remove, 50, stdin);
    title_to_remove[strcspn(title_to_remove, "\n")] = 0;

    int removed_index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(library[i].title, title_to_remove) == 0) {
            removed_index = i;
            break;
        }
    }

    if (removed_index == -1) {
        printf("That song was not found in the library.\n");
    } else {
        for (int i = removed_index; i < num_items-1; i++) {
            library[i] = library[i+1];
        }
        num_items--;
        printf("Song removed successfully from the library.\n");
    }
}

void list_songs() {
    if (num_items == 0) {
        printf("The library is empty!\n");
        return;
    }

    printf("%-30s%-30sLength (seconds)\n", "Title", "Artist");
    for (int i = 0; i < num_items; i++) {
        printf("%-30s%-30s%d\n", library[i].title, library[i].artist, library[i].length);
    }
}

int main() {
    int choice;

    while (1) {
        printf("Welcome to the Music Library Management System!\n");
        printf("What would you like to do?\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. List all songs\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");

        scanf("%d", &choice);
        getchar(); // consume the newline character left in the input buffer

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                remove_song();
                break;
            case 3:
                list_songs();
                break;
            case 4:
                printf("Thanks for using the Music Library Management System!");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}