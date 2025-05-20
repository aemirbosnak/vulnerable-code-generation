//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    int duration;
} Song;

int main() {
    Song library[MAX_SONGS];
    int numSongs = 0;

    char choice;
    do {
        printf("Welcome to the Music Library Management System!\n");
        printf("Please choose an option:\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Play a song\n");
        printf("4. Display library\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numSongs == MAX_SONGS) {
                    printf("Library is full. Cannot add song.\n");
                } else {
                    printf("Enter song title: ");
                    scanf("%s", library[numSongs].title);
                    printf("Enter artist name: ");
                    scanf("%s", library[numSongs].artist);
                    printf("Enter song duration in seconds: ");
                    scanf("%d", &library[numSongs].duration);
                    numSongs++;
                    printf("Song added successfully.\n");
                }
                break;
            case '2':
                if(numSongs == 0) {
                    printf("Library is empty. Cannot remove song.\n");
                } else {
                    printf("Enter song title to remove: ");
                    char title[50];
                    scanf("%s", title);
                    int i;
                    for(i=0; i<numSongs; i++) {
                        if(strcmp(title, library[i].title) == 0) {
                            numSongs--;
                            printf("Song removed successfully.\n");
                            break;
                        }
                    }
                }
                break;
            case '3':
                if(numSongs == 0) {
                    printf("Library is empty. Cannot play song.\n");
                } else {
                    printf("Enter song title to play: ");
                    char title[50];
                    scanf("%s", title);
                    int i;
                    for(i=0; i<numSongs; i++) {
                        if(strcmp(title, library[i].title) == 0) {
                            printf("Playing %s by %s (%d seconds)\n", library[i].title, library[i].artist, library[i].duration);
                            break;
                        }
                    }
                }
                break;
            case '4':
                printf("Library:\n");
                for(int i=0; i<numSongs; i++) {
                    printf("%d. %s by %s (%d seconds)\n", i+1, library[i].title, library[i].artist, library[i].duration);
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '5');

    return 0;
}