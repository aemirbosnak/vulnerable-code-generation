//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for storing details of music
struct Music {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
    int duration;
    int rating;
};

//Global variables
struct Music library[100];
int num_songs = 0;

//Function for adding a new song to the library
void add_song() {
    printf("Enter title: ");
    scanf("%s", library[num_songs].title);
    printf("Enter artist: ");
    scanf("%s", library[num_songs].artist);
    printf("Enter genre: ");
    scanf("%s", library[num_songs].genre);
    printf("Enter year: ");
    scanf("%d", &library[num_songs].year);
    printf("Enter duration in seconds: ");
    scanf("%d", &library[num_songs].duration);
    printf("Enter rating out of 10: ");
    scanf("%d", &library[num_songs].rating);
    num_songs++;
    printf("Song added to library!\n");
}

//Function for searching for a song in the library
void search_song() {
    char search_title[100];
    printf("Enter title to search for: ");
    scanf("%s", search_title);
    int found = 0;
    for(int i=0; i<num_songs; i++) {
        if(strcmp(search_title, library[i].title) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            printf("Year: %d\n", library[i].year);
            printf("Duration: %d sec\n", library[i].duration);
            printf("Rating: %d/10\n", library[i].rating);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Song not found in library.\n");
    }
}

//Function for displaying the entire music library
void display_library() {
    if(num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }
    printf("Library:\n");
    for(int i=0; i<num_songs; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Genre: %s\n", library[i].genre);
        printf("Year: %d\n", library[i].year);
        printf("Duration: %d sec\n", library[i].duration);
        printf("Rating: %d/10\n\n", library[i].rating);
    }
}

int main() {
    printf("Welcome to the Music Library Management System!\n");
    printf("Commands:\n1. add - to add a new song to the library\n2. search - to search for a song in the library\n3. display - to display the entire library\n4. exit - to exit the program\n");
    char command[10];
    while(1) {
        printf("Enter command: ");
        scanf("%s", command);
        if(strcmp(command, "add") == 0) {
            add_song();
        }
        else if(strcmp(command, "search") == 0) {
            search_song();
        }
        else if(strcmp(command, "display") == 0) {
            display_library();
        }
        else if(strcmp(command, "exit") == 0) {
            printf("Exiting program...");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}