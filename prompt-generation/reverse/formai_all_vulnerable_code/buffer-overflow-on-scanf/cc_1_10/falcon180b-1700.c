//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char title[MAX_SIZE];
    char author[MAX_SIZE];
    char genre[MAX_SIZE];
    int year;
} Music;

void addMusic(Music* music) {
    printf("Enter the title of the music: ");
    scanf("%s", music->title);
    printf("Enter the author of the music: ");
    scanf("%s", music->author);
    printf("Enter the genre of the music: ");
    scanf("%s", music->genre);
    printf("Enter the year of the music: ");
    scanf("%d", &music->year);
}

void displayMusic(Music* music) {
    printf("Title: %s\nAuthor: %s\nGenre: %s\nYear: %d\n", music->title, music->author, music->genre, music->year);
}

int main() {
    Music music;
    int choice;
    char filename[MAX_SIZE];

    printf("Enter the name of the library: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Cannot create file %s\n", filename);
        exit(1);
    }

    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add music\n2. Display music\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic(&music);
                fprintf(file, "Title: %s\nAuthor: %s\nGenre: %s\nYear: %d\n", music.title, music.author, music.genre, music.year);
                printf("\nMusic added to library!\n");
                break;
            case 2:
                rewind(file);
                while (fgets(filename, MAX_SIZE, file)!= NULL) {
                    Music temp;
                    sscanf(filename, "Title: %s\nAuthor: %s\nGenre: %s\nYear: %d\n", temp.title, temp.author, temp.genre, &temp.year);
                    displayMusic(&temp);
                }
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice!= 3);

    fclose(file);
    return 0;
}