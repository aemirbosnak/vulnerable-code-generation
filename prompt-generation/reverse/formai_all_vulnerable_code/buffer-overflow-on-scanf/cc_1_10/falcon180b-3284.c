//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 20
#define MAX_YEAR_LEN 10
#define MAX_TRACK_NUMBER_LEN 10
#define MAX_FILE_PATH_LEN 200
#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_EXT_LEN 10

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    char year[MAX_YEAR_LEN];
    char track_number[MAX_TRACK_NUMBER_LEN];
    char file_path[MAX_FILE_PATH_LEN];
    char file_name[MAX_FILE_NAME_LEN];
    char file_ext[MAX_FILE_EXT_LEN];
} MusicFile;

int main() {
    MusicFile library[100];
    int num_files = 0;

    printf("Welcome to the Music Library Management System!\n\n");

    while (num_files < 100) {
        printf("Enter 1 to add a new music file, or 0 to exit: ");
        char choice;
        scanf("%c", &choice);

        if (choice == '1') {
            printf("Enter the file path: ");
            char file_path[MAX_FILE_PATH_LEN];
            scanf("%s", file_path);

            MusicFile file;
            strcpy(file.file_path, file_path);

            printf("Enter the file name: ");
            scanf("%s", file.file_name);

            printf("Enter the file extension: ");
            scanf("%s", file.file_ext);

            strcpy(file.title, file.file_name);
            strcpy(file.artist, "");
            strcpy(file.album, "");
            strcpy(file.genre, "");
            strcpy(file.year, "");
            strcpy(file.track_number, "");

            library[num_files] = file;
            num_files++;

            printf("\nFile added successfully!\n\n");
        } else if (choice == '0') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n\n");
        }
    }

    printf("\nMusic Library:\n\n");
    for (int i = 0; i < num_files; i++) {
        printf("%d. %s - %s\n", i+1, library[i].file_name, library[i].file_path);
    }

    return 0;
}