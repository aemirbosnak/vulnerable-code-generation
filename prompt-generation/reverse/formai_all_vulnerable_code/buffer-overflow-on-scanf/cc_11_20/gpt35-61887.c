//FormAI DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_t { // define song structure
    char title[100];
    char artist[100];
    int year;
    float duration;
};

struct artist_t { // define artist structure
    char name[100];
    int num_songs;
    float total_duration;
};

int main() {
    int choice;
    struct song_t songs[100]; // array of song structures
    struct artist_t artists[100]; // array of artist structures
    int num_songs = 0; // count of current number of songs
    int num_artists = 0; // count of current number of artists
    float total_duration = 0.0; // total duration of all songs
    
    do {
        printf("\nMenu:\n1. Add Song\n2. View All Songs\n3. View Songs by Artist\n4. View Artists\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // add song
                if(num_songs == 100) { // maximum number of songs reached
                    printf("Maximum number of songs reached.\n");
                    break;
                }
                struct song_t song;
                printf("Enter song title: ");
                scanf("%s", song.title);
                printf("Enter song artist: ");
                scanf("%s", song.artist);
                printf("Enter year song was released: ");
                scanf("%d", &song.year);
                printf("Enter song duration (in minutes): ");
                scanf("%f", &song.duration);
                songs[num_songs] = song;
                num_songs ++;
                
                // check if artist exists, if not create new artist
                int artist_index = -1;
                for(int i = 0; i < num_artists; i ++) {
                    if(strcmp(artists[i].name, song.artist) == 0) {
                        artist_index = i;
                        break;
                    }
                }
                if(artist_index == -1) { // artist doesn't exist, create new
                    struct artist_t new_artist;
                    strcpy(new_artist.name, song.artist);
                    new_artist.num_songs = 1;
                    new_artist.total_duration = song.duration;
                    artists[num_artists] = new_artist;
                    num_artists ++;
                } else { // artist exists, update artist information
                    artists[artist_index].num_songs ++;
                    artists[artist_index].total_duration += song.duration;
                }
                total_duration += song.duration;
                break;
                
            case 2: // view all songs
                printf("All Songs:\n");
                for(int i = 0; i < num_songs; i ++) {
                    printf("Title: %s\n", songs[i].title);
                    printf("Artist: %s\n", songs[i].artist);
                    printf("Year: %d\n", songs[i].year);
                    printf("Duration: %.2f minutes\n", songs[i].duration);
                }
                printf("Total number of songs: %d\n", num_songs);
                printf("Total duration of all songs: %.2f minutes\n", total_duration);
                break;
                
            case 3: // view songs by artist
                printf("Enter artist name: ");
                char artist_name[100];
                scanf("%s", artist_name);
                int song_count = 0;
                for(int i = 0; i < num_songs; i ++) {
                    if(strcmp(songs[i].artist, artist_name) == 0) {
                        printf("Title: %s\n", songs[i].title);
                        printf("Year: %d\n", songs[i].year);
                        printf("Duration: %.2f minutes\n", songs[i].duration);
                        song_count ++;
                    }
                }
                printf("Total number of songs for %s: %d\n", artist_name, song_count);
                break;
                
            case 4: // view all artists
                printf("All Artists:\n");
                for(int i = 0; i < num_artists; i ++) {
                    printf("Name: %s\n", artists[i].name);
                    printf("Number of Songs: %d\n", artists[i].num_songs);
                    printf("Total Duration of Songs: %.2f minutes\n", artists[i].total_duration);
                }
                printf("Total number of artists: %d\n", num_artists);
                break;
                
            case 5: // exit program
                printf("Exiting program.\n");
                break;
                
            default: // invalid choice
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}