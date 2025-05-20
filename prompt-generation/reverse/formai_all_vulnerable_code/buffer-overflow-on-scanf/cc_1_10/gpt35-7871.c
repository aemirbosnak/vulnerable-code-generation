//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for album data */
typedef struct Album {
    char title[30];
    char artist[30];
    char genre[20];
    int release_year;
} Album;

/* Function to print all albums */
void print_albums(Album albums[], int num_albums) {
    printf("Title\t\tArtist\t\tGenre\t\tRelease Year\n");
    for (int i = 0; i < num_albums; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", albums[i].title, albums[i].artist, albums[i].genre, albums[i].release_year);
    }
    printf("\n");
}

int main() {
    Album albums[50];
    int num_albums = 0;
    int choice, album_choice;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add an album\n");
        printf("2. Remove an album\n");
        printf("3. Print all albums\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter album title:\n");
                scanf("%s", albums[num_albums].title);
                printf("Enter artist:\n");
                scanf("%s", albums[num_albums].artist);
                printf("Enter genre:\n");
                scanf("%s", albums[num_albums].genre);
                printf("Enter release year:\n");
                scanf("%d", &albums[num_albums].release_year);
                num_albums++;
                printf("Album added successfully!\n\n");
                break;

            case 2:
                printf("Enter album number to remove:\n");
                scanf("%d", &album_choice);
                if (album_choice <= num_albums && album_choice > 0) {
                    for (int i = album_choice - 1; i < num_albums - 1; i++) {
                        strcpy(albums[i].title, albums[i + 1].title);
                        strcpy(albums[i].artist, albums[i + 1].artist);
                        strcpy(albums[i].genre, albums[i + 1].genre);
                        albums[i].release_year = albums[i + 1].release_year;
                    }
                    num_albums--;
                    printf("Album removed successfully!\n\n");
                } else {
                    printf("Invalid album number!\n\n");
                }
                break;

            case 3:
                if (num_albums > 0) {
                    print_albums(albums, num_albums);
                } else {
                    printf("No albums found!\n\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }

    return 0;
}