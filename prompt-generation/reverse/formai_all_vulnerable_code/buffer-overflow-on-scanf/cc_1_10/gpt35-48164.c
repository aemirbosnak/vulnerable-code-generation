//FormAI DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIBRARY_SIZE 100

struct song {
    char title[50];
    char artist[50];
    int duration;
};

struct library {
    struct song songs[MAX_LIBRARY_SIZE];
    int num_songs;
};

void add_song(struct library* l, struct song s) {
    if (l->num_songs < MAX_LIBRARY_SIZE) {
        l->songs[l->num_songs] = s;
        l->num_songs++;
        printf("%s by %s with duration %d added to library.\n", s.title, s.artist, s.duration);
    } else {
        printf("Library is full. Could not add %s by %s with duration %d.\n", s.title, s.artist, s.duration);
    }
}

void print_library(struct library l) {
    printf("Current Library:\n");
    for (int i = 0; i < l.num_songs; i++) {
        printf("%d. %s by %s with duration %d\n", i+1, l.songs[i].title, l.songs[i].artist, l.songs[i].duration);
    }
}

int find_song(struct library l, char* title) {
    for (int i = 0; i < l.num_songs; i++) {
        if (strcmp(l.songs[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

void remove_song(struct library* l, char* title) {
    int index = find_song(*l, title);
    if (index != -1) {
        printf("%s by %s with duration %d removed from library.\n", l->songs[index].title, l->songs[index].artist, l->songs[index].duration);
        for (int i = index; i < l->num_songs-1; i++) {
            l->songs[i] = l->songs[i+1];
        }
        l->num_songs--;
    } else {
        printf("Could not find %s.\n", title);
    }
}

int main() {
    struct library my_library;
    my_library.num_songs = 0;

    printf("Welcome to the Music Library Management System!\n");

    while (1) {
        printf("\nEnter 1 to add a song to the library.\n");
        printf("Enter 2 to remove a song from the library.\n");
        printf("Enter 3 to print the current library.\n");
        printf("Enter 4 to exit.\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the song title: ");
                char title[50];
                scanf("%s", title);
                printf("Enter the artist name: ");
                char artist[50];
                scanf("%s", artist);
                printf("Enter the song duration (in seconds): ");
                int duration;
                scanf("%d", &duration);
                struct song new_song = {title, artist, duration};
                add_song(&my_library, new_song);
                break;
            case 2:
                printf("Enter the title of the song you want to remove: ");
                char remove_title[50];
                scanf("%s", remove_title);
                remove_song(&my_library, remove_title);
                break;
            case 3:
                print_library(my_library);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}