//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRARY_SIZE 100

// Struct for music collection
struct Music {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
};

// Function prototypes
void addSong(struct Music library[], int *size);
void printLibrary(struct Music library[], int size);

int main() {
    struct Music library[LIBRARY_SIZE];
    int size = 0;
    int choice;

    printf("==================\n");
    printf("MUSIC LIBRARY SYSTEM\n");
    printf("==================\n");

    do {
        printf("MENU OPTIONS\n");
        printf("1. Add song\n");
        printf("2. Print library\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong(library, &size);
                break;
            case 2:
                printLibrary(library, size);
                break;
            case 3:
                printf("Exiting program...");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

void addSong(struct Music library[], int *size) {
    printf("ADDING SONG\n");
    if(*size >= LIBRARY_SIZE) {
        printf("Music library is full. Cannot add song.\n");
        return;
    }

    // Get song information from user
    printf("Enter title of song: ");
    scanf(" %[^\n]%*c", library[*size].title);

    printf("Enter artist of song: ");
    scanf(" %[^\n]%*c", library[*size].artist);

    printf("Enter genre of song: ");
    scanf(" %[^\n]%*c", library[*size].genre);

    printf("Enter year of song: ");
    scanf("%d", &library[*size].year);

    (*size)++;
}

void printLibrary(struct Music library[], int size) {
    printf("PRINTING MUSIC LIBRARY\n");
    if(size == 0) {
        printf("Music library is empty.\n");
        return;
    }

    for(int i = 0; i < size; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Genre: %s\n", library[i].genre);
        printf("Year: %d\n\n", library[i].year);
    }
}