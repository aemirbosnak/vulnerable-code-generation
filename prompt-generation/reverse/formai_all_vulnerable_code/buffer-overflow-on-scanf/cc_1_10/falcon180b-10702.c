//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NOTES 1000
#define MAX_SONGS 100

typedef struct {
    int note;
    int duration;
} Note;

typedef struct {
    int num_notes;
    Note notes[MAX_NOTES];
} Song;

void read_notes(Song *song) {
    int i;
    printf("Enter the number of notes in the song: ");
    scanf("%d", &song->num_notes);
    for (i = 0; i < song->num_notes; i++) {
        printf("Enter note %d: ", i+1);
        scanf("%d", &song->notes[i].note);
        printf("Enter duration of note %d: ", i+1);
        scanf("%d", &song->notes[i].duration);
    }
}

void play_song(Song *song) {
    int i;
    for (i = 0; i < song->num_notes; i++) {
        printf("Playing note %d for %d seconds...\n", song->notes[i].note, song->notes[i].duration);
        sleep(song->notes[i].duration);
        printf("Note %d finished.\n", song->notes[i].note);
    }
}

int main() {
    Song song1, song2;
    printf("Enter the number of songs to play: ");
    scanf("%d", &song1.num_notes);
    read_notes(&song1);
    play_song(&song1);
    printf("Enter the number of songs to play: ");
    scanf("%d", &song2.num_notes);
    read_notes(&song2);
    play_song(&song2);
    return 0;
}