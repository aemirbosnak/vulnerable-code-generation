//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
// Scene 1: Introduction 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    int id;
    char title[50];
    char artist[50];
    float duration;
} library[100];

int num_of_songs = 0;

int main() {
    printf("Enter the number of songs you want to add to your library: ");
    scanf("%d", &num_of_songs);
    printf("Great! Let's start adding songs to your C Music Library.\n\n");
    
    // Scene 2: Adding Songs
    
    int i;
    for (i = 0; i < num_of_songs; i++) {
        printf("Song #%d\n", i+1);
        printf("Enter the song title: ");
        scanf("%s", &library[i].title);
        printf("Enter the artist name: ");
        scanf("%s", &library[i].artist);
        printf("Enter the duration of the song in minutes: ");
        scanf("%f", &library[i].duration);
        library[i].id = i + 1;
        printf("Song #%d successfully added!\n\n", i+1);
    }
    
    // Scene 3: Total Duration
    
    float total_duration = 0.0;
    for (i = 0; i < num_of_songs; i++) {
        total_duration += library[i].duration;
    }
    int hours = (int) total_duration / 60;
    int minutes = (int) total_duration % 60;
    printf("Your C Music Library now contains %d songs with a total duration of %d hours and %d minutes.\n\n", num_of_songs, hours, minutes);

    // Scene 4: Finding Songs
    
    char search_title[50];
    printf("Enter the title of the song you want to find: ");
    scanf("%s", &search_title);
    int found = 0;
    for (i = 0; i < num_of_songs; i++) {
        if (strcmp(search_title, library[i].title) == 0) {
            printf("Song Found!\n\n");
            printf("Song ID: %d\n", library[i].id);
            printf("Song Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Duration: %.2f minutes\n\n", library[i].duration);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found in your library.\n\n");
    }

    // Scene 5: Saying Goodbye
    
    printf("Thank you for using C Music Library Management System. Have a great day!");
    return 0;
}