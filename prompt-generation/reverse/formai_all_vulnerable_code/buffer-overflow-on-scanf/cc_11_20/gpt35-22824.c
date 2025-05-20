//FormAI DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    char genre[20];
};

int main() {
    int num_songs = 0;
    int choice = 0;

    printf("Welcome to the Music Library Management System\n");

    while(choice != 6) {
        printf("\nPlease select an option:\n");
        printf("1. Add a song to the library\n");
        printf("2. Remove a song from the library\n");
        printf("3. View all songs in the library\n");
        printf("4. Search for a song by title\n");
        printf("5. Search for a song by artist\n");
        printf("6. Exit the program\n");
        scanf("%d", &choice);

        if(choice == 1) {
            // Add a song to the library
            struct Music song;
            printf("\nEnter the song details:\n");
            printf("Title: ");
            scanf("%s", song.title);
            printf("Artist: ");
            scanf("%s", song.artist);
            printf("Album: ");
            scanf("%s", song.album);
            printf("Year: ");
            scanf("%d", &song.year);
            printf("Genre: ");
            scanf("%s", song.genre);

            FILE* music_library_file = fopen("music_library.txt", "a");
            fprintf(music_library_file, "%s,%s,%s,%d,%s\n", song.title, song.artist, song.album, song.year, song.genre);
            fclose(music_library_file);
            num_songs++;
            printf("\nSong added to the library successfully!\n");
        }
        else if(choice == 2) {
            // Remove a song from the library
            char song_title[50];
            printf("\nEnter the title of the song you want to remove: ");
            scanf("%s", song_title);

            FILE* music_library_file = fopen("music_library.txt", "r");
            FILE* temp_file = fopen("temp.txt", "w");
            char line[256];
            int song_removed = 0;

            while(fgets(line, sizeof(line), music_library_file)) {
                char* token = strtok(line, ",");
                if(strcmp(song_title, token) != 0) {
                    fprintf(temp_file, "%s", line);
                }
                else {
                    song_removed = 1;
                }
            }

            fclose(music_library_file);
            fclose(temp_file);

            remove("music_library.txt");
            rename("temp.txt", "music_library.txt");

            if(song_removed == 1) {
                num_songs--;
                printf("\nSong removed from the library successfully!\n");
            }
            else {
                printf("\nSong not found in the library.\n");
            }
        }
        else if(choice == 3) {
            // View all songs in the library
            FILE* music_library_file = fopen("music_library.txt", "r");
            char line[256];

            if(num_songs == 0) {
                printf("\nThere are no songs in the library yet.\n");
            }
            else {
                printf("\nAll songs in the library:\n");
                while(fgets(line, sizeof(line), music_library_file)) {
                    printf("%s", line);
                }
            }

            fclose(music_library_file);
        }
        else if(choice == 4) {
            // Search for a song by title
            char song_title[50];
            printf("\nEnter the title of the song you want to search for: ");
            scanf("%s", song_title);

            FILE* music_library_file = fopen("music_library.txt", "r");
            char line[256];
            int song_found = 0;

            while(fgets(line, sizeof(line), music_library_file)) {
                if(strstr(line, song_title) != NULL) {
                    printf("%s", line);
                    song_found = 1;
                }
            }

            fclose(music_library_file);

            if(song_found == 0) {
                printf("\nSong not found in the library.\n");
            }
        }
        else if(choice == 5) {
            // Search for a song by artist
            char song_artist[50];
            printf("\nEnter the artist of the song you want to search for: ");
            scanf("%s", song_artist);

            FILE* music_library_file = fopen("music_library.txt", "r");
            char line[256];
            int song_found = 0;

            while(fgets(line, sizeof(line), music_library_file)) {
                if(strstr(line, song_artist) != NULL) {
                    printf("%s", line);
                    song_found = 1;
                }
            }

            fclose(music_library_file);

            if(song_found == 0) {
                printf("\nSong not found in the library.\n");
            }
        }
        else if(choice == 6) {
            printf("\nThank you for using the Music Library Management System!\n");
        }
        else {
            printf("\nInvalid choice. Please choose a number between 1 and 6.\n");
        }
    }

    return 0;
}