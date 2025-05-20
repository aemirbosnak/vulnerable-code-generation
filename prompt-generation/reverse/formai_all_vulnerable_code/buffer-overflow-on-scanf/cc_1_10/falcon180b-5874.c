//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_NUM 100
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 50
#define MAX_FILE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    char file[MAX_FILE_LEN];
} Music;

Music music_list[MAX_MUSIC_NUM];
int music_num = 0;

void add_music() {
    char name[MAX_NAME_LEN], artist[MAX_ARTIST_LEN], album[MAX_ALBUM_LEN], genre[MAX_GENRE_LEN], file[MAX_FILE_LEN];
    printf("Enter music name: ");
    scanf("%s", name);
    printf("Enter music artist: ");
    scanf("%s", artist);
    printf("Enter music album: ");
    scanf("%s", album);
    printf("Enter music genre: ");
    scanf("%s", genre);
    printf("Enter music file path: ");
    scanf("%s", file);

    strcpy(music_list[music_num].name, name);
    strcpy(music_list[music_num].artist, artist);
    strcpy(music_list[music_num].album, album);
    strcpy(music_list[music_num].genre, genre);
    strcpy(music_list[music_num].file, file);

    music_num++;
}

void display_music() {
    printf("\nMusic Library:\n");
    for (int i = 0; i < music_num; i++) {
        printf("%d. %s - %s\n", i+1, music_list[i].name, music_list[i].artist);
    }
}

void search_music() {
    char search_name[MAX_NAME_LEN];
    printf("\nEnter music name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < music_num; i++) {
        if (strcmp(music_list[i].name, search_name) == 0) {
            printf("\nMusic found:\n");
            printf("%s - %s\n", music_list[i].name, music_list[i].artist);
            printf("%s - %s\n", music_list[i].album, music_list[i].genre);
            printf("%s\n", music_list[i].file);
        }
    }

    if (strcmp(search_name, "") == 0) {
        printf("\nNo music found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add music\n");
        printf("2. Display music\n");
        printf("3. Search music\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_music();
                break;
            case 2:
                display_music();
                break;
            case 3:
                search_music();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}