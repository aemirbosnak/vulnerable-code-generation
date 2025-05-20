//FormAI DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structures
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration; // in seconds
} song;

// Function Prototypes
void add_song();
void display_library();
void save_library();
void load_library();
void search_by_title();
void search_by_artist();
void search_by_album();
void print_song_details(song s);

// Global Variables
song library[100];
int song_count = 0;


int main() {
    int choice;

    while(1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Display Library\n");
        printf("3. Search by Title\n");
        printf("4. Search by Artist\n");
        printf("5. Search by Album\n");
        printf("6. Save Library\n");
        printf("7. Load Library\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                display_library();
                break;
            case 3:
                search_by_title();
                break;
            case 4:
                search_by_artist();
                break;
            case 5:
                search_by_album();
                break;
            case 6:
                save_library();
                break;
            case 7:
                load_library();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}


/*
 * Function to add a song to the library
 */
void add_song() {
    song s;

    printf("Enter Song Title: ");
    fflush(stdin);
    fgets(s.title, 50, stdin);
    s.title[strcspn(s.title, "\n")] = 0;

    printf("Enter Artist Name: ");
    fflush(stdin);
    fgets(s.artist, 50, stdin);
    s.artist[strcspn(s.artist, "\n")] = 0;

    printf("Enter Album Name: ");
    fflush(stdin);
    fgets(s.album, 50, stdin);
    s.album[strcspn(s.album, "\n")] = 0;

    printf("Enter Year of Release: ");
    scanf("%d", &s.year);

    printf("Enter Duration (in seconds): ");
    scanf("%d", &s.duration);

    library[song_count++] = s;

    printf("Song Added to Library\n");
}


/*
 * Function to display the entire library
 */
void display_library() {
    int i;

    if(song_count == 0) {
        printf("Library is Empty\n");
        return;
    }

    printf("%-4s| %-50s| %-50s| %-50s| %-6s| %-5s\n", "ID", "Title", "Artist", "Album", "Year", "Duration");

    for(i=0; i<song_count; i++) {
        printf("%-4d| %-50s| %-50s| %-50s| %-6d| %-5d\n", i+1, library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
    }
}


/*
 * Function to search for a song by title
 */
void search_by_title() {
    int i, found = 0;
    char title[50];

    printf("Enter Song Title: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    for(i=0; i<song_count; i++) {
        if(strcasecmp(library[i].title, title) == 0) {
            print_song_details(library[i]);
            found = 1;
        }
    }

    if(!found) {
        printf("Song not found\n");
    }
}


/*
 * Function to search for a song by artist
 */
void search_by_artist() {
    int i, found = 0;
    char artist[50];

    printf("Enter Artist Name: ");
    fflush(stdin);
    fgets(artist, 50, stdin);
    artist[strcspn(artist, "\n")] = 0;

    for(i=0; i<song_count; i++) {
        if(strcasecmp(library[i].artist, artist) == 0) {
            print_song_details(library[i]);
            found = 1;
        }
    }

    if(!found) {
        printf("Song not found\n");
    }
}


/*
 * Function to search for a song by album
 */
void search_by_album() {
    int i, found = 0;
    char album[50];

    printf("Enter Album Name: ");
    fflush(stdin);
    fgets(album, 50, stdin);
    album[strcspn(album, "\n")] = 0;

    for(i=0; i<song_count; i++) {
        if(strcasecmp(library[i].album, album) == 0) {
            print_song_details(library[i]);
            found = 1;
        }
    }

    if(!found) {
        printf("Song not found\n");
    }
}


/*
 * Function to print details of a song
 */
void print_song_details(song s) {
    printf("Title: %s\n", s.title);
    printf("Artist: %s\n", s.artist);
    printf("Album: %s\n", s.album);
    printf("Year: %d\n", s.year);
    printf("Duration: %d seconds\n", s.duration);
}


/*
 * Function to save the library to a file
 */
void save_library() {
    FILE *fp;
    int i;

    fp = fopen("library.txt", "w");

    for(i=0; i<song_count; i++) {
        fprintf(fp, "%s|%s|%s|%d|%d\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].duration);
    }

    fclose(fp);
}


/*
 * Function to load the library from a file
 */
void load_library() {
    FILE *fp;
    char line[256];
    char *token;
    int i = 0;

    fp = fopen("library.txt", "r");

    if(fp == NULL) {
        printf("Library file not found\n");
        return;
    }

    while(fgets(line, sizeof(line), fp)) {
        token = strtok(line, "|");
        strcpy(library[i].title, token);

        token = strtok(NULL, "|");
        strcpy(library[i].artist, token);

        token = strtok(NULL, "|");
        strcpy(library[i].album, token);

        token = strtok(NULL, "|");
        library[i].year = atoi(token);

        token = strtok(NULL, "\n");
        library[i].duration = atoi(token);

        i++;
    }

    song_count = i;

    fclose(fp);

    printf("Library Loaded Successfully\n");
}