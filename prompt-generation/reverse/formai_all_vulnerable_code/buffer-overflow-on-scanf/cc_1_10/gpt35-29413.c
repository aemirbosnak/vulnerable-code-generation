//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct song{
    char title[50];
    char artist[50];
    int release_year;
    char genre[20];
};

typedef struct song Song;

Song library[100]; //assumed to have maximum of 100 songs in library
int library_size = 0;

// function to add a new song to the library
void add_song(){
    if(library_size == 100){
        printf("Library is full. Cannot add new song.\n");
        return;
    }

    Song new_song;

    printf("Enter song title: ");
    scanf("%s", new_song.title);

    printf("Enter artist name: ");
    scanf("%s", new_song.artist);

    printf("Enter release year: ");
    scanf("%d", &new_song.release_year);

    printf("Enter genre: ");
    scanf("%s", new_song.genre);

    library[library_size] = new_song;
    library_size++;

    printf("Song added to library successfully.\n");
}

// function to search for a song in the library
void search_song(){
    char search_query[50];
    int found = 0;

    printf("Enter search query (song title or artist name): ");
    scanf("%s", search_query);

    for(int i=0; i<library_size; i++){
        if(strcmp(search_query, library[i].title) == 0){
            printf("Song found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Release year: %d\n", library[i].release_year);
            printf("Genre: %s\n", library[i].genre);
            found = 1;
            break;
        }
        else if(strcmp(search_query, library[i].artist) == 0){
            printf("Song found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Release year: %d\n", library[i].release_year);
            printf("Genre: %s\n", library[i].genre);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Song not found in library.\n");
    }
}

// function to display all songs in the library
void display_library(){
    if(library_size == 0){
        printf("Library is empty.\n");
        return;
    }

    printf("Displaying library:\n");
    for(int i=0; i<library_size; i++){
        printf("%d. %s - %s [%d]\n", i+1, library[i].title, library[i].artist, library[i].release_year);
    }
}

// main function
int main(){
    int choice;

    while(1){
        printf("\nWelcome to the Music Library Management System.\n");
        printf("1. Add a new song to the library\n");
        printf("2. Search for a song in the library\n");
        printf("3. Display all songs in the library\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                display_library();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}