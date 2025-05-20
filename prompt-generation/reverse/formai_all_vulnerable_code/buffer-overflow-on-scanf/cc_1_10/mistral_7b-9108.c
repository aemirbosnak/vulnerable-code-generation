//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TRACKS 1000
#define MAX_CHARS 50

typedef struct {
 char artist[MAX_CHARS];
 char title[MAX_CHARS];
 int track_num;
} Track;

Track tracks[MAX_TRACKS];
int num_tracks = 0;

void add_track(char *artist, char *title, int track_num) {
 if (num_tracks >= MAX_TRACKS) {
 printf("\nError: Music Library is Full!\n");
 return;
 }
 strcpy(tracks[num_tracks].artist, artist);
 strcpy(tracks[num_tracks].title, title);
 tracks[num_tracks].track_num = track_num;
 num_tracks++;
}

void search_track(int track_num) {
 int i;
 for (i = 0; i < num_tracks; i++) {
 if (tracks[i].track_num == track_num) {
 printf("\nArtist: %s", tracks[i].artist);
 printf("\nTitle: %s", tracks[i].title);
 printf("\nTrack Number: %d\n", tracks[i].track_num);
 return;
 }
 }
 printf("\nError: Track Not Found!\n");
}

void print_library() {
 int i;
 for (i = 0; i < num_tracks; i++) {
 printf("\n%d. %s - %s", i+1, tracks[i].artist, tracks[i].title);
 }
}

int main() {
 char artist[MAX_CHARS], title[MAX_CHARS];
 int track_num, choice, search;
 while (1) {
 printf("\n1. Add Track\n2. Search Track\n3. Display Library\n4. Exit\nEnter Choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("\nEnter Artist: ");
 scanf("%s", artist);
 printf("\nEnter Title: ");
 scanf("%s", title);
 printf("\nEnter Track Number: ");
 scanf("%d", &track_num);
 add_track(artist, title, track_num);
 break;
 case 2:
 printf("\nEnter Track Number to Search: ");
 scanf("%d", &search);
 search_track(search);
 break;
 case 3:
 print_library();
 break;
 case 4:
 printf("\nExiting Music Library Management System...\n");
 exit(0);
 }
 }
}

// Beware! This library is a mystery box!