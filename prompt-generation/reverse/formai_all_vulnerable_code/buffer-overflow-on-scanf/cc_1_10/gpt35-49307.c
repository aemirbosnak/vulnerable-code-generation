//FormAI DATASET v1.0 Category: Music Library Management System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

void addSong(struct song songs[], int *count) {
    printf("\n=== ADD SONG ===\n");
    printf("Enter song title: ");
    scanf("%s", songs[*count].title);
    printf("Enter artist name: ");
    scanf("%s", songs[*count].artist);
    printf("Enter album name: ");
    scanf("%s", songs[*count].album);
    printf("Enter year: ");
    scanf("%d", &songs[*count].year);
    (*count)++;
}

void displaySongs(struct song songs[], int count) {
    printf("\n=== LIST OF SONGS ===\n");
    printf("TITLE\t\tARTIST\t\tALBUM\t\tYEAR\n");
    for(int i=0; i<count; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
    }
}

void searchSong(struct song songs[], int count) {
    char title[50];
    printf("\n=== SEARCH SONG ===\n");
    printf("Enter song title: ");
    scanf("%s", title);
    for(int i=0; i<count; i++) {
        if(strcmp(songs[i].title, title) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%d\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
            return;
        }
    }
    printf("Song not found!\n");
}

int main() {
    int choice = 0;
    int count = 0;
    struct song songs[50];
    while(choice != 4) {
        printf("\n===== C MUSIC LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add a song\n");
        printf("2. Display all songs\n");
        printf("3. Search a song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addSong(songs, &count);
                break;
            case 2:
                displaySongs(songs, count);
                break;
            case 3:
                searchSong(songs, count);
                break;
            case 4:
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}