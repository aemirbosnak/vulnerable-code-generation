//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int length;
};

void print_song(struct song s) {
    printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %d\nLength: %d\n", s.title, s.artist, s.album, s.year, s.length);
}

int main() {
    struct song songs[100];
    int num_songs = 0;

    while (1) {
        char command[50];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            struct song s;
            scanf("%s %s %s %d %d", s.title, s.artist, s.album, &s.year, &s.length);
            songs[num_songs] = s;
            num_songs++;
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < num_songs; i++) {
                print_song(songs[i]);
            }
        } else if (strcmp(command, "find") == 0) {
            char search_title[50];
            scanf("%s", search_title);
            for (int i = 0; i < num_songs; i++) {
                if (strcmp(songs[i].title, search_title) == 0) {
                    print_song(songs[i]);
                }
            }
        } else if (strcmp(command, "delete") == 0) {
            char delete_title[50];
            scanf("%s", delete_title);
            for (int i = 0; i < num_songs; i++) {
                if (strcmp(songs[i].title, delete_title) == 0) {
                    songs[i] = songs[num_songs - 1];
                    num_songs--;
                    break;
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}