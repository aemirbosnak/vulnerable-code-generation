//FormAI DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

typedef struct {
    int id;
    char title[50];
    char artist[50];
    int year;
} Song;

char *toLowercase(char *string) {
    char *result = malloc(strlen(string) + 1);
    for (int i = 0; i < strlen(string); i++) {
        result[i] = tolower(string[i]);
    }
    result[strlen(string)] = '\0';
    return result;
}

bool confirmAction() {
    char answer;
    while (true) {
        printf("Are you sure? [y/n] ");
        scanf(" %c", &answer);
        if (tolower(answer) == 'y') {
            return true;
        } else if (tolower(answer) == 'n') {
            return false;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

bool checkIdExists(int id, Song *songs, int songCount) {
    for (int i = 0; i < songCount; i++) {
        if (songs[i].id == id) {
            return true;
        }
    }
    return false;
}

void addSong(Song *songs, int *songCount) {
    printf("Enter song title: ");
    getchar();
    fgets(songs[*songCount].title, 50, stdin);
    songs[*songCount].title[strcspn(songs[*songCount].title, "\n")] = '\0';
    printf("Enter artist name: ");
    fgets(songs[*songCount].artist, 50, stdin);
    songs[*songCount].artist[strcspn(songs[*songCount].artist, "\n")] = '\0';
    printf("Enter year released: ");
    scanf("%d", &songs[*songCount].year);
    songs[*songCount].id = *songCount + 1;
    (*songCount)++;
    printf("Song added successfully!\n");
}

void displaySongs(Song *songs, int songCount) {
    if (songCount == 0) {
        printf("No songs found.\n");
    } else {
        printf("------------------------------\n");
        printf("|%-5s|%-25s|%-20s|%-4s|\n", "ID", "Title", "Artist", "Year");
        printf("------------------------------\n");
        for (int i = 0; i < songCount; i++) {
            printf("|%-5d|%-25s|%-20s|%-4d|\n", songs[i].id, songs[i].title, songs[i].artist, songs[i].year);
        }
        printf("------------------------------\n");
    }
}

void searchSongs(Song *songs, int songCount) {
    char query[50];
    printf("Enter search query: ");
    getchar();
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = '\0';
    printf("------------------------------\n");
    printf("|%-5s|%-25s|%-20s|%-4s|\n", "ID", "Title", "Artist", "Year");
    printf("------------------------------\n");
    for (int i = 0; i < songCount; i++) {
        if (strstr(toLowercase(songs[i].title), toLowercase(query)) != NULL || strstr(toLowercase(songs[i].artist), toLowercase(query)) != NULL) {
            printf("|%-5d|%-25s|%-20s|%-4d|\n", songs[i].id, songs[i].title, songs[i].artist, songs[i].year);
        }
    }
    printf("------------------------------\n");
}

void updateSong(Song *songs, int songCount) {
    int id;
    printf("Enter song ID to update: ");
    scanf("%d", &id);
    if (checkIdExists(id, songs, songCount)) {
        for (int i = 0; i < songCount; i++) {
            if (songs[i].id == id) {
                printf("Enter new song title: ");
                getchar();
                fgets(songs[i].title, 50, stdin);
                songs[i].title[strcspn(songs[i].title, "\n")] = '\0';
                printf("Enter new artist name: ");
                fgets(songs[i].artist, 50, stdin);
                songs[i].artist[strcspn(songs[i].artist, "\n")] = '\0';
                printf("Enter new year released: ");
                scanf("%d", &songs[i].year);
                printf("Song successfully updated!\n");
                return;
            }
        }
    } else {
        printf("Song not found.\n");
    }
}

void deleteSong(Song *songs, int *songCount) {
    int id;
    printf("Enter song ID to delete: ");
    scanf("%d", &id);
    if (checkIdExists(id, songs, *songCount)) {
        if (confirmAction()) {
            int index = 0;
            while (songs[index].id != id) {
                index++;
            }
            for (int i = index; i < *songCount - 1; i++) {
                songs[i] = songs[i+1];
            }
            (*songCount)--;
            printf("Song successfully deleted.\n");
        }
    } else {
        printf("Song not found.\n");
    }
}

int main() {
    int option, songCount = 0;
    Song songs[100];
    while (true) {
        printf("\nC Music Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Search Songs\n");
        printf("4. Update Song\n");
        printf("5. Delete Song\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addSong(songs, &songCount);
                break;
            case 2:
                displaySongs(songs, songCount);
                break;
            case 3:
                searchSongs(songs, songCount);
                break;
            case 4:
                updateSong(songs, songCount);
                break;
            case 5:
                deleteSong(songs, &songCount);
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}