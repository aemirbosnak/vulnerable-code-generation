//FormAI DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    int year;
} Album;

void add_album(Album *albums, int *num_albums) {
    Album new_album;

    printf("--- Add a New Album ---\n");
    printf("Enter Title: ");
    fgets(new_album.title, 50, stdin);
    new_album.title[strcspn(new_album.title, "\n")] = 0;

    printf("Enter Artist: ");
    fgets(new_album.artist, 50, stdin);
    new_album.artist[strcspn(new_album.artist, "\n")] = 0;

    printf("Enter Year: ");
    scanf("%d", &new_album.year);
    getchar();  // consume newline

    albums[*num_albums] = new_album;
    (*num_albums)++;
}

void remove_album(Album *albums, int *num_albums) {
    char title[50];
    int i, found = 0;

    printf("--- Remove an Album ---\n");
    printf("Enter Title of Album to Remove: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    for (i = 0; i < *num_albums; i++) {
        if (strcmp(albums[i].title, title) == 0) {
            found = 1;
            (*num_albums)--;

            // shift all elements after the removed element over by one
            for (; i < *num_albums; i++) {
                albums[i] = albums[i+1];
            }

            printf("%s by %s (%d) successfully removed.\n", title, albums[i-1].artist, albums[i-1].year);
            break;
        }
    }

    if (!found) {
        printf("Album not found.\n");
    }
}

void display_albums(Album *albums, int num_albums) {
    int i;

    printf("--- Display All Albums ---\n");

    if (!num_albums) {
        printf("No albums in library.\n");
    }

    for (i = 0; i < num_albums; i++) {
        printf("%s by %s (%d)\n", albums[i].title, albums[i].artist, albums[i].year);
    }
}

int main() {
    int choice, num_albums = 0;
    Album albums[100];

    while (1) {
        printf("\n--- MUSIC LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1. Add Album\n");
        printf("2. Remove Album\n");
        printf("3. Display All Albums\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        switch (choice) {
            case 1:
                add_album(albums, &num_albums);
                break;
            case 2:
                remove_album(albums, &num_albums);
                break;
            case 3:
                display_albums(albums, num_albums);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}