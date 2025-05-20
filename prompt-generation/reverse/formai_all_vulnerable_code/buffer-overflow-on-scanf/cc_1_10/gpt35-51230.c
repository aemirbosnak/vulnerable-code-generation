//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[20];
    int year;
} Song;

void addSong(Song* library, int size) {
    Song newSong;
    printf("Title: ");
    scanf("%s", newSong.title);
    printf("Artist: ");
    scanf("%s", newSong.artist);
    printf("Year: ");
    scanf("%d", &newSong.year);
    library[size] = newSong;
    printf("Song successfully added to the library!\n\n");
}

void removeSong(Song* library, int* size, char* title) {
    int index = -1;
    for(int i = 0; i < *size; i++) {
        if(strcmp(library[i].title, title) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Song not found in the library.\n\n");
        return;
    } else {
        for(int i = index; i < *size - 1; i++) {
            library[i] = library[i + 1];
        }
        (*size)--;
        printf("Song successfully removed from the library!\n\n");
    }
}

void displayLibrary(Song* library, int size) {
    printf("\n");
    printf("%-25s %-20s %-10s\n", "Title", "Artist", "Year");
    printf("---------------------------------------------------------\n");
    for(int i = 0; i < size; i++) {
        printf("%-25s %-20s %-10d\n", library[i].title, library[i].artist, library[i].year);
    }
    printf("\n");
}

int main() {
    Song library[50];
    int size = 0;
    char choice;
    char search[50];

    printf("Welcome to the C Music Library Management System!\n\n");

    while(1) {
        printf("Please select an option:\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Search the library\n");
        printf("4. Display the library\n");
        printf("5. Quit\n\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if(size >= 50) {
                    printf("The library is full. Please remove a song to add a new one.\n\n");
                } else {
                    addSong(library, size);
                    size++;
                }
                break;
            case '2':
                printf("Please enter the title of the song you would like to remove: ");
                scanf("%s", search);
                removeSong(library, &size, search);
                break;
            case '3':
                printf("Sorry, searching is not yet implemented.\n\n");
                break;
            case '4':
                displayLibrary(library, size);
                break;
            case '5':
                printf("Thank you for using the C Music Library Management System!\n");
                return 0;
            default:
                printf("Invalid option. Please choose a number from the list.\n\n");
        }
    }

    return 0;
}