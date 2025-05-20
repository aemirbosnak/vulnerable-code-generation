//FormAI DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} Song;

Song addSong();
void displaySong(Song s);
void saveSong(Song s);
void searchSong();

int main() {
    int choice;
    printf("\nWelcome to C Music Library Management System!\n");

    while (1) {
        printf("\n\nSelect an option:\n1. Add a Song\n2. Search for a Song\n3. Exit\n");
        fflush(stdin);
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Song s = addSong();
                saveSong(s);
                break;
            }
            case 2: {
                searchSong();
                break;
            }
            case 3: {
                printf("\nExiting Program...\n");
                exit(0);
            }
            default: {
                printf("Invalid option selected. Please try again.\n");
                break;
            }
        }
    }
    return 0;
}

Song addSong() {
    Song s;
    printf("\nEnter Song Title: ");
    fflush(stdin);
    gets(s.title);

    printf("Enter Artist Name: ");
    fflush(stdin);
    gets(s.artist);

    printf("Enter Album Title: ");
    fflush(stdin);
    gets(s.album);

    printf("Enter Release Year: ");
    fflush(stdin);
    scanf("%d", &s.year);

    printf("Enter Song Duration (seconds): ");
    fflush(stdin);
    scanf("%d", &s.duration);

    printf("\nSong added successfully!\n");
    displaySong(s);

    return s;
}

void displaySong(Song s) {
    printf("\nTitle: %s\nArtist: %s\nAlbum: %s\nYear: %d\nDuration: %d seconds\n", s.title, s.artist, s.album, s.year, s.duration);
}

void saveSong(Song s) {
    FILE *fp;
    fp = fopen("songs.dat", "ab");
    if (fp == NULL) {
        printf("Error saving song. Please try again.\n");
        return;
    }
    fwrite(&s, sizeof(Song), 1, fp);
    fclose(fp);
}

void searchSong() {
    Song s;
    char query[50];
    int found = 0;

    printf("\nEnter search query: ");
    fflush(stdin);
    gets(query);
    printf("\nResults:\n\n");

    FILE *fp;
    fp = fopen("songs.dat", "rb");
    if (fp == NULL) {
        printf("No songs found.\n");
        return;
    }
    while (fread(&s, sizeof(Song), 1, fp)) {
        if (strstr(s.title, query) || strstr(s.artist, query) || strstr(s.album, query)) {
            displaySong(s);
            found = 1;
        }
    }
    if (!found) {
        printf("No results found for query '%s'\n", query);
    }
    fclose(fp);
}