//FormAI DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    char genre[100];
};

void add_song(struct song *lib, int *size) {
    printf("Enter song title: ");
    fgets(lib[*size].title, 100, stdin);
    
    printf("Enter artist: ");
    fgets(lib[*size].artist, 100, stdin);
    
    printf("Enter album: ");
    fgets(lib[*size].album, 100, stdin);
    
    printf("Enter year: ");
    scanf("%d", &lib[*size].year);
    getchar(); // to remove \n
    
    printf("Enter genre: ");
    fgets(lib[*size].genre, 100, stdin);
    
    (*size)++;
    printf("The song has been added to the library.\n");
}

void display_song(struct song s) {
    printf("Title: %s", s.title);
    printf("Artist: %s", s.artist);
    printf("Album: %s", s.album);
    printf("Year: %d\n", s.year);
    printf("Genre: %s", s.genre);
}

void search_song(struct song *lib, int size) {
    char keyword[100];
    printf("Enter keyword to search: ");
    fgets(keyword, 100, stdin);
    
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(lib[i].title, keyword) != NULL ||
            strstr(lib[i].artist, keyword) != NULL ||
            strstr(lib[i].album, keyword) != NULL ||
            strstr(lib[i].genre, keyword) != NULL) {
            printf("\nResult %d\n", ++count);
            display_song(lib[i]);
        }
    }
    
    if (count == 0) {
        printf("No song found.\n");
    }
}

int main() {
    int size = 0;
    struct song library[100];
    int choice;
    
    printf("Welcome to the C Music Library Management System!\n");
    printf("==============================================\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add new song\n");
        printf("2. Display all songs\n");
        printf("3. Search for a song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to remove \n
        
        switch (choice) {
            case 1:
                add_song(library, &size);
                break;
            case 2:
                printf("\nAll songs:\n");
                for (int i = 0; i < size; i++) {
                    printf("\nSong %d\n", i+1);
                    display_song(library[i]);
                }
                break;
            case 3:
                search_song(library, size);
                break;
            case 4:
                printf("\nGoodbye! Thank you for using the C Music Library Management System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
    } while (choice != 4);
    
    return 0;
}