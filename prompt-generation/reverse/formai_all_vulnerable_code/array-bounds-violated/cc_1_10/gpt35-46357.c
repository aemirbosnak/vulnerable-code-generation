//FormAI DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

struct Song {
  char title[100];
  char artist[100];
  char genre[50];
  int length; //in seconds
};

int num_songs = 0;
struct Song song_list[MAX_SONGS];

void add_song() {
  if(num_songs >= MAX_SONGS) {
    printf("No more songs can be added to the library\n");
    return;
  }

  struct Song new_song;

  printf("Enter the song title: ");
  fgets(new_song.title, 100, stdin);
  new_song.title[strlen(new_song.title) - 1] = '\0'; //remove newline character

  printf("Enter the artist name: ");
  fgets(new_song.artist, 100, stdin);
  new_song.artist[strlen(new_song.artist) - 1] = '\0';

  printf("Enter the genre: ");
  fgets(new_song.genre, 50, stdin);
  new_song.genre[strlen(new_song.genre) - 1] = '\0';

  printf("Enter the song length in seconds: ");
  scanf("%d", &new_song.length);
  getchar(); //consume newline character

  song_list[num_songs] = new_song;
  num_songs++;

  printf("Song added successfully\n");
}

void list_songs() {
  if(num_songs == 0) {
    printf("No songs in the library\n");
    return;
  }

  printf("%-30s %-30s %-20s %-10s\n", "Title", "Artist", "Genre", "Length");

  for(int i = 0; i < num_songs; i++) {
    printf("%-30s %-30s %-20s %-10d\n", song_list[i].title, song_list[i].artist, song_list[i].genre, song_list[i].length);
  }
}

void handle_user_input(char choice) {
  switch(choice) {
    case 'a':
      add_song();
      break;
    case 'l':
      list_songs();
      break;
    case 'q':
      printf("Exiting the program\n");
      exit(0);
      break;
    default:
      printf("Invalid choice. Please try again\n");
  }
}

int main() {
  printf("C Music Library Management System\n");

  while(1) {
    printf("Enter a choice:\n");
    printf("a - Add a song\n");
    printf("l - List all songs\n");
    printf("q - Quit\n");

    char choice = getchar();
    getchar(); //consume newline character

    handle_user_input(choice);
  }

  return 0;
}