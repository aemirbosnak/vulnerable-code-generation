//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_ARTISTS 100

struct artist {
    char name[50];
    int num_songs;
};

struct song {
    char name[50];
    char artist[50];
    int duration;
};

int main() {
    struct artist artists[MAX_ARTISTS];
    struct song songs[MAX_SIZE];
    int num_artists = 0;
    int num_songs = 0;
    int num_records = 0;
    int num_search_results = 0;
    int choice, artist_num, song_num, search_num, search_result, song_duration;
    char artist_name[50], song_name[50], search_string[50];

    do {
        printf("Music Library Management System\n");
        printf("-----------------------------\n");
        printf("1. Add Artist\n");
        printf("2. Add Song\n");
        printf("3. Search Song\n");
        printf("4. Print All Artists\n");
        printf("5. Print All Songs\n");
        printf("6. Print All Songs by Artist\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter artist name: ");
                fgets(artist_name, sizeof(artist_name), stdin);
                strcpy(artists[num_artists].name, artist_name);
                artists[num_artists].num_songs = 0;
                num_artists++;
                break;
            case 2:
                printf("Enter song name: ");
                fgets(song_name, sizeof(song_name), stdin);
                strcpy(songs[num_songs].name, song_name);
                printf("Enter artist name: ");
                fgets(artist_name, sizeof(artist_name), stdin);
                strcpy(songs[num_songs].artist, artist_name);
                printf("Enter song duration (in minutes): ");
                scanf("%d", &song_duration);
                songs[num_songs].duration = song_duration;
                num_songs++;
                break;
            case 3:
                printf("Enter search string: ");
                fgets(search_string, sizeof(search_string), stdin);
                printf("Search results:\n");
                for(int i = 0; i < num_songs; i++) {
                    if(strstr(songs[i].name, search_string)!= NULL || strstr(songs[i].artist, search_string)!= NULL) {
                        num_search_results++;
                        printf("Song: %s, Artist: %s\n", songs[i].name, songs[i].artist);
                    }
                }
                break;
            case 4:
                printf("Artists:\n");
                for(int i = 0; i < num_artists; i++) {
                    printf("Artist: %s, Number of songs: %d\n", artists[i].name, artists[i].num_songs);
                }
                break;
            case 5:
                printf("Songs:\n");
                for(int i = 0; i < num_songs; i++) {
                    printf("Song: %s, Artist: %s, Duration: %d minutes\n", songs[i].name, songs[i].artist, songs[i].duration);
                }
                break;
            case 6:
                printf("Songs by Artist:\n");
                for(int i = 0; i < num_songs; i++) {
                    if(strcmp(songs[i].artist, artist_name) == 0) {
                        printf("Song: %s, Artist: %s, Duration: %d minutes\n", songs[i].name, songs[i].artist, songs[i].duration);
                    }
                }
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 7);

    return 0;
}