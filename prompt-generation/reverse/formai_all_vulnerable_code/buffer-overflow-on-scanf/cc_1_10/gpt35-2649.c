//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music {
    char title[50];
    char artist[50];
    int ID;
} music;

music tracks[1000];

int numTracks = 0;

void addTrack(char t[50], char a[50]) {
    strcpy(tracks[numTracks].title, t);
    strcpy(tracks[numTracks].artist, a);
    tracks[numTracks].ID = numTracks+1;
    numTracks++;
}

void removeTrack(int id) {
    for(int i=0; i<numTracks; i++) {
        if(tracks[i].ID == id) {
            for(int j=i; j<numTracks; j++) {
                strcpy(tracks[j].title, tracks[j+1].title);
                strcpy(tracks[j].artist, tracks[j+1].artist);
                tracks[j].ID = tracks[j+1].ID;
            }
            numTracks--;
            printf("Track removed.\n");
            return;
        }
    }
    printf("Track not found.\n");
}

void displayLibrary() {
    printf("\n\n--------------------\n");
    printf(" Music Library\n");
    printf("--------------------\n\n");
    if(numTracks > 0) {
        for(int i=0; i<numTracks; i++) {
            printf("%d. %s - %s\n", tracks[i].ID, tracks[i].title, tracks[i].artist);
        }
    } else {
        printf("No tracks in library.\n");
    }
    printf("\n");
}

int main() {
    printf("This is a Music Library Management System.\n");
    printf("Enter '1' to add a new track.\n");
    printf("Enter '2' to remove a track.\n");
    printf("Enter '3' to display the library.\n");
    printf("Enter '0' to exit the program.\n");
    printf("---------------------------------------------------------------------------\n");

    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the track title: ");
                char newTitle[50];
                scanf("%s", newTitle);
                printf("Enter the artist name: ");
                char newArtist[50];
                scanf("%s", newArtist);
                addTrack(newTitle, newArtist);
                printf("Track added to library.\n");
                break;
            case 2:
                printf("Enter the ID of the track to remove: ");
                int idToRemove;
                scanf("%d", &idToRemove);
                removeTrack(idToRemove);
                break;
            case 3:
                displayLibrary();
                break;
            case 0:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while(choice != 0);
    return 0;
}