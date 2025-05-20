//FormAI DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Song {
    char* title;
    char* artist;
    char* genre;
    int duration;
} Song;

Song songDatabase[MAX_RECORDS];
int numRecords = 0;

void addSong(char* title, char* artist, char* genre, int duration) {
    if(numRecords >= MAX_RECORDS) {
        printf("Song database is full.\n");
        return;
    }

    Song newSong = {title, artist, genre, duration};
    songDatabase[numRecords++] = newSong;
    printf("%s by %s has been added to the database.\n", title, artist);
}

void displaySongs() {
    if(numRecords == 0) {
        printf("Sorry, there are no songs in the database.\n");
        return;
    }

    printf("Title\t\tArtist\t\tGenre\t\tDuration\n");
    for(int i=0; i<numRecords; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\n",
               songDatabase[i].title,
               songDatabase[i].artist,
               songDatabase[i].genre,
               songDatabase[i].duration);
    }
}

void searchSongs(char* keyword) {
    if(numRecords == 0) {
        printf("Sorry, there are no songs in the database.\n");
        return;
    }

    printf("Title\t\tArtist\t\tGenre\t\tDuration\n");
    for(int i=0; i<numRecords; i++) {
        if(strstr(songDatabase[i].title, keyword) ||
           strstr(songDatabase[i].artist, keyword) ||
           strstr(songDatabase[i].genre, keyword)) {
            printf("%s\t\t%s\t\t%s\t\t%d\n",
                   songDatabase[i].title,
                   songDatabase[i].artist,
                   songDatabase[i].genre,
                   songDatabase[i].duration);
        }
    }
}

int main() {
    int choice;
    char title[30], artist[30], genre[30], keyword[30];
    int duration;

    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add New Song\n");
        printf("2. Display Songs\n");
        printf("3. Search Songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter title of the song: ");
                scanf("%s", title);
                printf("Enter artist of the song: ");
                scanf("%s", artist);
                printf("Enter genre of the song: ");
                scanf("%s", genre);
                printf("Enter duration of the song (in seconds): ");
                scanf("%d", &duration);
                addSong(title, artist, genre, duration);
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                printf("Enter keyword to search: ");
                scanf("%s", keyword);
                searchSongs(keyword);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please enter a number between 1-4.\n");
                break;
        }

    } while(choice != 4);

    return 0;
}