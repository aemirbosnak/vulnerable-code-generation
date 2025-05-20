//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct music {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char album[MAX_SIZE];
    int year;
};

typedef struct music Music;

void add_song(Music[], int*);
void delete_song(Music[], int*);
void display_songs(Music[], int);
void search_song(Music[], int);

int main() {
    Music library[MAX_SIZE];
    int num_songs = 0;
    int choice;
    
    do {
        printf("\nWelcome to the C Music Library Management System!\n");
        printf("1. Add a song\n");
        printf("2. Delete a song\n");
        printf("3. Display all songs\n");
        printf("4. Search for a song\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_song(library, &num_songs);
                break;
            case 2:
                delete_song(library, &num_songs);
                break;
            case 3:
                display_songs(library, num_songs);
                break;
            case 4:
                search_song(library, num_songs);
                break;
            case 5:
                printf("\nThank you for using the C Music Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
    } while(choice != 5);
    
    return 0;
}

void add_song(Music library[], int *num_songs) {
    getchar(); // Remove newline character from input buffer
    
    printf("\nEnter song title: ");
    fgets(library[*num_songs].title, MAX_SIZE, stdin);
    library[*num_songs].title[strcspn(library[*num_songs].title, "\n")] = '\0';
    
    printf("Enter artist name: ");
    fgets(library[*num_songs].artist, MAX_SIZE, stdin);
    library[*num_songs].artist[strcspn(library[*num_songs].artist, "\n")] = '\0';
    
    printf("Enter album name: ");
    fgets(library[*num_songs].album, MAX_SIZE, stdin);
    library[*num_songs].album[strcspn(library[*num_songs].album, "\n")] = '\0';
    
    printf("Enter year: ");
    scanf("%d", &library[*num_songs].year);
    
    (*num_songs)++;
    
    printf("\nSong added successfully!\n");
}

void delete_song(Music library[], int *num_songs) {
    getchar(); // Remove newline character from input buffer
    
    char search[MAX_SIZE];
    int index = -1;
    
    printf("\nEnter song title to delete: ");
    fgets(search, MAX_SIZE, stdin);
    search[strcspn(search, "\n")] = '\0';
    
    for(int i = 0; i < *num_songs; i++) {
        if(strcmp(search, library[i].title) == 0) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("\nSong not found.\n");
    } else {
        for(int i = index; i < *num_songs - 1; i++) {
            library[i] = library[i+1];
        }
        
        (*num_songs)--;
        
        printf("\nSong deleted successfully!\n");
    }
}

void display_songs(Music library[], int num_songs) {
    printf("\n");
    if(num_songs == 0) {
        printf("No songs in library.\n");
    } else {
        printf("Title\tArtist\tAlbum\tYear\n");
        for(int i = 0; i < num_songs; i++) {
            printf("%s\t%s\t%s\t%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
        }
    }
}

void search_song(Music library[], int num_songs) {
    getchar(); // Remove newline character from input buffer
    
    char search[MAX_SIZE];
    int index = -1;
    
    printf("\nEnter song title to search: ");
    fgets(search, MAX_SIZE, stdin);
    search[strcspn(search, "\n")] = '\0';
    
    for(int i = 0; i < num_songs; i++) {
        if(strcmp(search, library[i].title) == 0) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("\nSong not found.\n");
    } else {
        printf("\nTitle\tArtist\tAlbum\tYear\n");
        printf("%s\t%s\t%s\t%d\n", library[index].title, library[index].artist, library[index].album, library[index].year);
    }
}