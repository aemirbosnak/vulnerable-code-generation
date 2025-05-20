//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLES 100
#define MAX_ARTISTS 100
#define MAX_ALBUMS 100

typedef struct {
    char title[100];
    char artist[100];
    char album[100];
} Music;

void addMusic(Music* music) {
    int i = 0;
    while (i < MAX_TITLES && music[i].title[0]!= '\0') {
        i++;
    }
    strcpy(music[i].title, "");
    strcpy(music[i].artist, "");
    strcpy(music[i].album, "");
}

void removeMusic(Music* music, int index) {
    int i = 0;
    while (i < index) {
        strcpy(music[i].title, music[i+1].title);
        strcpy(music[i].artist, music[i+1].artist);
        strcpy(music[i].album, music[i+1].album);
        i++;
    }
    strcpy(music[i].title, "");
    strcpy(music[i].artist, "");
    strcpy(music[i].album, "");
}

void printMusic(Music* music) {
    int i = 0;
    while (i < MAX_TITLES && music[i].title[0]!= '\0') {
        printf("Title: %s\nArtist: %s\nAlbum: %s\n\n", music[i].title, music[i].artist, music[i].album);
        i++;
    }
}

int main() {
    Music music[MAX_TITLES];
    int choice, index;
    char title[100], artist[100], album[100];

    do {
        printf("Music Library Management System\n");
        printf("1. Add Music\n2. Remove Music\n3. Print Music\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Title: ");
                scanf("%s", title);
                printf("Enter Artist: ");
                scanf("%s", artist);
                printf("Enter Album: ");
                scanf("%s", album);
                addMusic(music);
                break;
            case 2:
                printf("Enter Index of Music to Remove: ");
                scanf("%d", &index);
                removeMusic(music, index);
                break;
            case 3:
                printMusic(music);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice!= 4);

    return 0;
}