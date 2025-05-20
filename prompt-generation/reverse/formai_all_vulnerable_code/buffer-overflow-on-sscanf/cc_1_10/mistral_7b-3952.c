//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>

#define MAX_SIZE 100
#define FILENAME "music.txt"

typedef struct Music {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char album[MAX_SIZE];
    int year;
    char genre[MAX_SIZE];
} Music;

void readFile(FILE *file) {
    Music library[MAX_SIZE];
    int i = 0;
    char line[MAX_SIZE];

    while (fgets(line, MAX_SIZE, file) != NULL) {
        sscanf(line, "%s %s %s %d %s", library[i].title, library[i].artist, library[i].album, &library[i].year, library[i].genre);
        i++;
    }

    fclose(file);
}

void writeFile(FILE *file, Music music) {
    char line[MAX_SIZE];

    sprintf(line, "%s %s %s %d %s\n", music.title, music.artist, music.album, music.year, music.genre);

    fputs(line, file);
}

void addMusic(Music music) {
    FILE *file = fopen(FILENAME, "r+");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    readFile(file);
    fseek(file, 0, SEEK_END);

    writeFile(file, music);

    fclose(file);

    printf("Music added successfully.\n");
}

void displayLibrary() {
    Music library[MAX_SIZE];
    int i = 0;
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    while (fscanf(file, "%s %s %s %d %s", library[i].title, library[i].artist, library[i].album, &library[i].year, library[i].genre) != EOF) {
        printf("%s - %s (%d) - %s\n", library[i].title, library[i].artist, library[i].year, library[i].genre);
        i++;
    }

    fclose(file);
}

int main() {
    Music music;

    while (1) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Music\n");
        printf("2. Display Library\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", music.title);
                printf("Enter artist: ");
                scanf("%s", music.artist);
                printf("Enter album: ");
                scanf("%s", music.album);
                printf("Enter year: ");
                scanf("%d", &music.year);
                printf("Enter genre: ");
                scanf("%s", music.genre);

                addMusic(music);
                break;

            case 2:
                displayLibrary();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}