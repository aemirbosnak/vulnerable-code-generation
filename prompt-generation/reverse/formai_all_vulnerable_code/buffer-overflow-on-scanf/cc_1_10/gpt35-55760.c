//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_SIZE 100

typedef struct Song {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
    int runtime;
} Song;

void addSong(Song library[], int *size) {
    Song newSong;
    printf("Enter song title: ");
    fgets(newSong.title, MAX_LENGTH, stdin);
    printf("Enter artist name: ");
    fgets(newSong.artist, MAX_LENGTH, stdin);
    printf("Enter genre: ");
    fgets(newSong.genre, MAX_LENGTH, stdin);
    printf("Enter year: ");
    scanf("%d", &newSong.year);
    printf("Enter runtime (in seconds): ");
    scanf("%d", &newSong.runtime);

    library[*size] = newSong;
    (*size)++;
    fflush(stdin);
}

void displayByYear(Song library[], int size) {
    int year;
    printf("Enter year to search for: ");
    scanf("%d", &year);

    printf("%-30s|%-20s|%-10s|%-6s|%-10s\n", "Title", "Artist", "Genre", "Year", "Runtime");
    for(int i = 0; i < size; i++) {
        if(library[i].year == year) {
            printf("%-30s|%-20s|%-10s|%-6d|%-10d\n", library[i].title, library[i].artist, library[i].genre, library[i].year, library[i].runtime);
        }
    }
    fflush(stdin);
}

int main() {
    Song library[MAX_SIZE];
    int size = 0;
    int option = 0;

    while(option != 3) {
        printf("\n-------Music Library Management System-------\n\n");
        printf("1. Add song\n");
        printf("2. Display songs by year\n");
        printf("3. Exit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addSong(library, &size);
                break;
            case 2:
                displayByYear(library, size);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                fflush(stdin);
                break;
        }
    }

    return 0;
}