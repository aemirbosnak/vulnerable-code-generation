//FormAI DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct song {
    char name[30];
    char artist[30];
    int year;
} Song;

int main() {
    int choice;
    int num_songs = 0;
    Song* songs = NULL;

    while (1) {
        printf("Welcome to the Music Library Management System!\n");
        printf("Choose an option:\n");
        printf("1. Add song\n");
        printf("2. Remove song\n");
        printf("3. View library\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Name: ");
                char n[30];
                scanf("%s", n);
                printf("Artist: ");
                char a[30];
                scanf("%s", a);
                printf("Year: ");
                int y;
                scanf("%d", &y);
                if (num_songs == 0) {
                    songs = malloc(sizeof(Song));
                } else {
                    songs = realloc(songs, (num_songs + 1) * sizeof(Song));
                }
                sprintf(songs[num_songs].name, "%s", n);
                sprintf(songs[num_songs].artist, "%s", a);
                songs[num_songs].year = y;
                num_songs++;
                printf("Song added to library.\n");
                break;

            case 2:
                if (num_songs == 0) {
                    printf("Library is empty. Cannot remove song.\n");
                    break;
                }
                printf("Enter the name of the song to remove: ");
                char remove[30];
                scanf("%s", remove);
                int remove_index = -1;
                for (int i = 0; i < num_songs; i++) {
                    if (strcmp(songs[i].name, remove) == 0) {
                        remove_index = i;
                    }
                }
                if (remove_index == -1) {
                    printf("Song not found in library.\n");
                } else {
                    for (int i = remove_index; i < num_songs-1; i++) {
                        songs[i] = songs[i+1];
                    }
                    num_songs--;
                    if (num_songs == 0) {
                        free(songs);
                        songs = NULL;
                    } else {
                        songs = realloc(songs, num_songs * sizeof(Song));
                    }
                    printf("Song removed from library.\n");
                }
                break;

            case 3:
                if (num_songs == 0) {
                    printf("Library is empty.\n");
                } else {
                    printf("Library:\n");
                    for (int i = 0; i < num_songs; i++) {
                        printf("Name: %s | Artist: %s | Year: %d\n", songs[i].name, songs[i].artist, songs[i].year);
                    }
                }
                break;

            case 4:
                if (songs) {
                    free(songs);
                }
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}