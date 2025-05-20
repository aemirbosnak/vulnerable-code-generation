//FormAI DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the maximum size of library and song title
#define MAX_LIB_SIZE 100
#define MAX_SONG_TITLE 50

// defining the structure of a song
struct Song {
  int id;
  char title[MAX_SONG_TITLE];
  char artist[MAX_SONG_TITLE];
  char album[MAX_SONG_TITLE];
  int year;
  double duration;
};

// defining the structure of the music library
struct MusicLibrary {
  struct Song songs[MAX_LIB_SIZE];
  int size;
};

// function to add a new song to the library
void addSong(struct MusicLibrary *lib) {
  struct Song newSong;
  printf("Enter the song title: ");
  fgets(newSong.title, MAX_SONG_TITLE, stdin);

  // remove the newline character from the end of the title string
  strtok(newSong.title, "\n");

  printf("Enter the artist name: ");
  fgets(newSong.artist, MAX_SONG_TITLE, stdin);
  strtok(newSong.artist, "\n");

  printf("Enter the album name: ");
  fgets(newSong.album, MAX_SONG_TITLE, stdin);
  strtok(newSong.album, "\n");

  printf("Enter the year the song was released: ");
  scanf("%d", &newSong.year);

  printf("Enter the song duration in minutes: ");
  scanf("%lf", &newSong.duration);

  // generate an id for the new song
  newSong.id = lib->size + 1;

  // add the new song to the library
  lib->songs[lib->size] = newSong;
  lib->size++;

  printf("Song added successfully!\n");
}

// helper function to print a song
void printSong(struct Song song) {
  printf("%d. Title: %s\n", song.id, song.title);
  printf("   Artist: %s\n", song.artist);
  printf("   Album: %s\n", song.album);
  printf("   Year: %d\n", song.year);
  printf("   Duration: %.2lf minutes\n", song.duration);
}

// function to print all the songs in the library
void printAllSongs(struct MusicLibrary lib) {
  printf("List of all songs in the library:\n");
  for(int i = 0; i < lib.size; i++) {
    printSong(lib.songs[i]);
  }
}

int main() {
  struct MusicLibrary library;
  library.size = 0;

  printf("Welcome to the C Music Library Management System!\n");

  while(1) {
    printf("What would you like to do?\n");
    printf("1. Add a new song\n");
    printf("2. Print all songs\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addSong(&library);
        break;
      case 2:
        printAllSongs(library);
        break;
      case 3:
        printf("Thank you for using the Music Library Management System!\n");
        exit(0);
      default:
        printf("Invalid choice! Please try again.\n");
    }
  }

  return 0;
}