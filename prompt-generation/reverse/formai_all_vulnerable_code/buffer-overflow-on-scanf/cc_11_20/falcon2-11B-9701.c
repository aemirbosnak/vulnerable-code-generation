//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int duration;
} Music;

int main() {
    int option = 0;
    Music library[100];
    int num_songs = 0;
    int i;

    printf("Welcome to the Music Library Management System!\n");
    printf("Please select an option:\n");
    printf("1. Add a song to the library\n");
    printf("2. Delete a song from the library\n");
    printf("3. Search for a song in the library\n");
    printf("4. Play a song from the library\n");
    printf("5. Display the music library\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &option);

    while (option!= 6) {
        switch (option) {
            case 1:
                printf("Enter the name of the song: ");
                scanf("%s", library[num_songs].name);
                printf("Enter the artist name: ");
                scanf("%s", library[num_songs].artist);
                printf("Enter the album name: ");
                scanf("%s", library[num_songs].album);
                printf("Enter the genre: ");
                scanf("%s", library[num_songs].genre);
                printf("Enter the duration of the song (in minutes): ");
                scanf("%d", &library[num_songs].duration);
                num_songs++;
                break;
            case 2:
                printf("Enter the name of the song to delete: ");
                scanf("%s", library[num_songs].name);
                for (i = 0; i < num_songs; i++) {
                    if (strcmp(library[i].name, library[num_songs].name) == 0) {
                        break;
                    }
                }
                if (i == num_songs) {
                    printf("Song not found in the library\n");
                } else {
                    for (int j = i; j < num_songs - 1; j++) {
                        library[j] = library[j + 1];
                    }
                    num_songs--;
                }
                break;
            case 3:
                printf("Enter the name of the song to search for: ");
                scanf("%s", library[num_songs].name);
                for (i = 0; i < num_songs; i++) {
                    if (strcmp(library[i].name, library[num_songs].name) == 0) {
                        printf("Song Name: %s\n", library[i].name);
                        printf("Artist: %s\n", library[i].artist);
                        printf("Album: %s\n", library[i].album);
                        printf("Genre: %s\n", library[i].genre);
                        printf("Duration: %d minutes\n", library[i].duration);
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter the index of the song to play: ");
                scanf("%d", &i);
                printf("Playing song %s - %s - %s - %s (%d minutes)\n", library[i].name, library[i].artist, library[i].album, library[i].genre, library[i].duration);
                break;
            case 5:
                printf("Music Library:\n");
                for (i = 0; i < num_songs; i++) {
                    printf("Song Name: %s\n", library[i].name);
                    printf("Artist: %s\n", library[i].artist);
                    printf("Album: %s\n", library[i].album);
                    printf("Genre: %s\n", library[i].genre);
                    printf("Duration: %d minutes\n", library[i].duration);
                }
                break;
            default:
                printf("Invalid option\n");
        }
        printf("Enter your choice (1-6): ");
        scanf("%d", &option);
    }
    printf("Exiting the Music Library Management System\n");
    return 0;
}