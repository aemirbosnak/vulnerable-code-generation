//FormAI DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_DATABASE 1000

struct Music {
    int id;
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
};

//Declare variables
struct Music musicAlbum[MAX_DATABASE]; 
int numberOfAlbums = 0;

//Function prototypes
void addAlbum();
void deleteAlbum();
void searchAlbum();
void printAllAlbums();

int main() {
    int exit = 0;
    char userOption;

    while (!exit) {
        printf("\n\n    Music Library Management System\n");
        printf("-----  ------ ------- --------- ------\n");
        printf("        1 - Add Album \n");
        printf("        2 - Delete Album \n");
        printf("        3 - Search Album \n");
        printf("        4 - Show All Albums \n");
        printf("        0 - Exit Program \n");
        printf("-----  ------ ------- --------- ------\n");
        printf("    Please select an option: ");

        userOption = getchar();

        switch (userOption) {
            case '1':
                getchar(); //Consume the newline character in the buffer
                addAlbum();
                break;
            case '2':
                getchar();
                deleteAlbum();
                break;
            case '3':
                getchar();
                searchAlbum();
                break;
            case '4':
                getchar();
                printAllAlbums();
                break;
            case '0':
                getchar();
                exit = 1;
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }
}

void addAlbum() {
    printf("Please enter album title: ");
    fgets(musicAlbum[numberOfAlbums].title, MAX_LENGTH, stdin);
    musicAlbum[numberOfAlbums].title[strlen(musicAlbum[numberOfAlbums].title)-1] = '\0'; //Removes the newline character
    printf("Please enter artist name: ");
    fgets(musicAlbum[numberOfAlbums].artist, MAX_LENGTH, stdin);
    musicAlbum[numberOfAlbums].artist[strlen(musicAlbum[numberOfAlbums].artist)-1] = '\0';
    printf("Please enter album name: ");
    fgets(musicAlbum[numberOfAlbums].album, MAX_LENGTH, stdin);
    musicAlbum[numberOfAlbums].album[strlen(musicAlbum[numberOfAlbums].album)-1] = '\0';
    musicAlbum[numberOfAlbums].id = numberOfAlbums + 1;
    numberOfAlbums++;
    printf("Album added successfully!\n");
}

void deleteAlbum() {
    int i, albumId, foundAlbum = 0;

    printf("Please enter album id: ");
    scanf("%d", &albumId);

    for (i = 0; i < numberOfAlbums; i++) {
        if (musicAlbum[i].id == albumId) {
            foundAlbum = 1;
            break;
        }
    }

    if (foundAlbum) {
        for (i = albumId - 1; i < numberOfAlbums - 1; i++) {
            musicAlbum[i] = musicAlbum[i+1];
            musicAlbum[i].id--;
        }
        numberOfAlbums--;
        printf("Album deleted successfully!\n");
    } else {
        printf("Album not found!\n");
    }
}

void searchAlbum() {
    int i, foundAlbum = 0;
    char keyword[MAX_LENGTH];

    printf("Please enter keyword to search for: ");
    fgets(keyword, MAX_LENGTH, stdin);
    keyword[strlen(keyword)-1] = '\0'; //Removes the newline character

    printf("\nSearch Results: \n");
    printf("-------------------------------------------------------------\n");
    printf("ID        TITLE                   ARTIST              ALBUM\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < numberOfAlbums; i++) {
        if (strstr(musicAlbum[i].title, keyword) != NULL || strstr(musicAlbum[i].artist, keyword) != NULL || strstr(musicAlbum[i].album, keyword) != NULL) {
            printf("%-10d%-24s%-20s%s\n", musicAlbum[i].id, musicAlbum[i].title, musicAlbum[i].artist, musicAlbum[i].album);
            foundAlbum = 1;
        }
    }

    if (!foundAlbum) {
        printf("No albums found with the keyword %s! \n", keyword);
    }
}

void printAllAlbums() {
    int i;

    printf("ID        TITLE                   ARTIST              ALBUM\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < numberOfAlbums; i++) {
        printf("%-10d%-24s%-20s%s\n", musicAlbum[i].id, musicAlbum[i].title, musicAlbum[i].artist, musicAlbum[i].album);
    }

    printf("-------------------------------------------------------------\n");
}