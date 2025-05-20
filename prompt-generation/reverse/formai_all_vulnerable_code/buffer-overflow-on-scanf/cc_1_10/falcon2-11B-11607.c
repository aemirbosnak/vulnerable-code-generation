//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct Song {
    char title[50];
    int duration;
    float rating;
};

void add_song(struct Song* songs, int max_songs, int num_songs) {
    int i;
    if (num_songs >= max_songs) {
        printf("Maximum number of songs reached.\n");
        return;
    }
    for (i = 0; i < num_songs; i++) {
        printf("Enter song details:\n");
        printf("Title: ");
        scanf("%s", songs[i].title);
        printf("Duration (in minutes): ");
        scanf("%d", &songs[i].duration);
        printf("Rating: ");
        scanf("%f", &songs[i].rating);
    }
    printf("Songs added.\n");
}

void display_songs(struct Song* songs, int num_songs) {
    int i;
    for (i = 0; i < num_songs; i++) {
        printf("Song %d:\n", i+1);
        printf("Title: %s\n", songs[i].title);
        printf("Duration: %d minutes\n", songs[i].duration);
        printf("Rating: %.2f\n", songs[i].rating);
    }
}

void delete_song(struct Song* songs, int num_songs, int index) {
    if (index < 0 || index >= num_songs) {
        printf("Invalid song index.\n");
        return;
    }
    for (int i = index; i < num_songs-1; i++) {
        songs[i] = songs[i+1];
    }
    num_songs--;
    printf("Song deleted.\n");
}

void update_song(struct Song* songs, int num_songs, int index, char* new_title, int new_duration, float new_rating) {
    if (index < 0 || index >= num_songs) {
        printf("Invalid song index.\n");
        return;
    }
    for (int i = index; i < num_songs-1; i++) {
        songs[i] = songs[i+1];
    }
    num_songs--;
    if (new_title!= NULL) {
        strcpy(songs[index].title, new_title);
    }
    if (new_duration!= -1) {
        songs[index].duration = new_duration;
    }
    if (new_rating!= -1.0) {
        songs[index].rating = new_rating;
    }
    printf("Song updated.\n");
}

int main() {
    int num_songs, max_songs, song_index;
    struct Song songs[100];

    printf("Welcome to the C Music Library Management System!\n");
    printf("Enter the number of songs to add: ");
    scanf("%d", &num_songs);
    printf("Enter the maximum number of songs: ");
    scanf("%d", &max_songs);

    add_song(songs, max_songs, num_songs);

    printf("Enter the index of the song you want to delete: ");
    scanf("%d", &song_index);
    delete_song(songs, num_songs, song_index);

    printf("Enter the index of the song you want to update: ");
    scanf("%d", &song_index);
    printf("Enter new title (or leave blank to keep the same title): ");
    char new_title[50];
    scanf("%s", new_title);
    printf("Enter new duration (or leave blank to keep the same duration): ");
    int new_duration;
    scanf("%d", &new_duration);
    printf("Enter new rating (or leave blank to keep the same rating): ");
    float new_rating;
    scanf("%f", &new_rating);
    update_song(songs, num_songs, song_index, new_title, new_duration, new_rating);

    display_songs(songs, num_songs);

    return 0;
}