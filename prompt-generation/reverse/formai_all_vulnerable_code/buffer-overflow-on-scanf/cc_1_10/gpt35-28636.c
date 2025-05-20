//FormAI DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    float duration;
};

void addSong(struct Song* library, int* numOfSongs);
void searchSongs(struct Song* library, int numOfSongs, char* artistName);
void deleteSong(struct Song* library, int* numOfSongs, char* songTitle);

int main() {
    int option, numOfSongs = 0;
    struct Song library[100];

    do {
        printf("\n\n---C Music Library Management System---\n\n");
        printf("1. Add Song\n");
        printf("2. Search Songs by Artist\n");
        printf("3. Delete Song\n");
        printf("4. Exit\n\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: addSong(library, &numOfSongs);
                break;
            case 2: {
                char artistName[100];
                printf("\nEnter the artist name: ");
                scanf("%s", artistName);
                searchSongs(library, numOfSongs, artistName);
                break;
            }
            case 3: {
                char songTitle[100];
                printf("\nEnter the song title: ");
                scanf("%s", songTitle);
                deleteSong(library, &numOfSongs, songTitle);
                break;
            }
            case 4: exit(0);
            default: printf("\nInvalid option. Try again.\n");
        }
    } while (option != 4);

    return 0;
}

void addSong(struct Song* library, int* numOfSongs) {
    printf("\nEnter the song details-\n");
    printf("\nTitle: ");
    scanf("%s", library[*numOfSongs].title);
    printf("Artist: ");
    scanf("%s", library[*numOfSongs].artist);
    printf("Album: ");
    scanf("%s", library[*numOfSongs].album);
    printf("Duration (in minutes): ");
    scanf("%f", &library[*numOfSongs].duration);
    (*numOfSongs)++;
    printf("\nSong added successfully!\n");
}

void searchSongs(struct Song* library, int numOfSongs, char* artistName) {
    printf("\nSongs by the artist %s-\n", artistName);
    for (int i=0; i<numOfSongs; i++) {
        if(strcmp(artistName,library[i].artist) == 0) {
            printf("\nTitle: %s\n", library[i].title);
            printf("Album: %s\n\n", library[i].album);
        }
    }
}

void deleteSong(struct Song* library, int* numOfSongs, char* songTitle) {
    int flag = 0;
    for (int i=0; i<*numOfSongs; i++) {
        if(strcmp(songTitle,library[i].title) == 0) {
            flag = 1;
            for (int j=i; j<*numOfSongs-1; j++) {
                library[j] = library[j+1];
            }
            (*numOfSongs)--;
            printf("\nSong deleted successfully!\n");
            break;
        }
    }
    if (flag == 0) {
        printf("\nThe song %s is not present in the library.\n", songTitle);
    }
}