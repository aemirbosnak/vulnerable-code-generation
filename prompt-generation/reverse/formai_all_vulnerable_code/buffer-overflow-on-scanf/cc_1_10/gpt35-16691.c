//FormAI DATASET v1.0 Category: Music Library Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[30];
    char album[30];
    float duration;
    int year;
};

void add_song(struct song music[], int *count);
void view_songs(struct song music[], int count);
void search_songs(struct song music[], int count);
void edit_song(struct song music[], int count);
void delete_song(struct song music[], int *count);

int main() {
    struct song music[100];
    int count = 0;
    int choice;

    printf("Welcome to the C Music Library Management System\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a song to the library\n");
        printf("2. View all songs in the library\n");
        printf("3. Search for a song\n");
        printf("4. Edit a song in the library\n");
        printf("5. Delete a song from the library\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(music, &count);
                break;
            case 2:
                view_songs(music, count);
                break;
            case 3:
                search_songs(music, count);
                break;
            case 4:
                edit_song(music, count);
                break;
            case 5:
                delete_song(music, &count);
                break;
            case 6:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}

void add_song(struct song music[], int *count) {
    struct song new_song;
    printf("\nEnter the following details:\n");
    printf("Title: ");
    getchar();
    fgets(new_song.title, 50, stdin);
    printf("Artist: ");
    fgets(new_song.artist, 30, stdin);
    printf("Album: ");
    fgets(new_song.album, 30, stdin);
    printf("Duration: ");
    scanf("%f", &new_song.duration);
    printf("Year: ");
    scanf("%d", &new_song.year);
    music[*count] = new_song;
    printf("\nSong successfully added to the library\n");
    (*count)++;
}

void view_songs(struct song music[], int count) {
    if (count == 0) {
        printf("\nThere are no songs in the library\n");
    } else {
        printf("\nList of all songs in the library:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s by %s, from the album %s, released in %d, duration: %.2f\n", i+1, music[i].title, music[i].artist, music[i].album, music[i].year, music[i].duration);
        }
    }
}

void search_songs(struct song music[], int count) {
    if (count == 0) {
        printf("\nThere are no songs in the library\n");
    } else {
        char keyword[50];
        printf("\nEnter a keyword to search for: ");
        getchar();
        fgets(keyword, 50, stdin);
        printf("\nSearch results for '%s':\n", keyword);
        int result_count = 0;
        for (int i = 0; i < count; i++) {
            if (strstr(music[i].title, keyword) || strstr(music[i].artist, keyword) || strstr(music[i].album, keyword)) {
                printf("%d. %s by %s, from the album %s, released in %d, duration: %.2f\n", i+1, music[i].title, music[i].artist, music[i].album, music[i].year, music[i].duration);
                result_count++;
            }
        }
        if (result_count == 0) {
            printf("No results found\n");
        }
    }
}

void edit_song(struct song music[], int count) {
    if (count == 0) {
        printf("\nThere are no songs in the library\n");
    } else {
        int song_choice;
        printf("\nEnter the number of the song you want to edit: ");
        scanf("%d", &song_choice);
        if (song_choice < 1 || song_choice > count) {
            printf("Invalid song choice\n");
        } else {
            struct song new_song;
            printf("\nEnter the following details:\n");
            printf("Title: ");
            getchar();
            fgets(new_song.title, 50, stdin);
            printf("Artist: ");
            fgets(new_song.artist, 30, stdin);
            printf("Album: ");
            fgets(new_song.album, 30, stdin);
            printf("Duration: ");
            scanf("%f", &new_song.duration);
            printf("Year: ");
            scanf("%d", &new_song.year);
            music[song_choice-1] = new_song;
            printf("\nSong successfully edited\n");
        }
    }
}

void delete_song(struct song music[], int *count) {
    if (*count == 0) {
        printf("\nThere are no songs in the library\n");
    } else {
        int song_choice;
        printf("\nEnter the number of the song you want to delete: ");
        scanf("%d", &song_choice);
        if (song_choice < 1 || song_choice > *count) {
            printf("Invalid song choice\n");
        } else {
            for (int i = song_choice-1; i < *count-1; i++) {
                music[i] = music[i+1];
            }
            (*count)--;
            printf("\nSong successfully deleted\n");
        }
    }
}