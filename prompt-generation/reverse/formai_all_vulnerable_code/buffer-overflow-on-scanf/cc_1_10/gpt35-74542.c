//FormAI DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max size of the music library
#define MAX_SIZE 100

// Define music data structure
typedef struct music {
  char title[50];
  char artist[50];
  char album[50];
  char genre[50];
  int year;
  int duration; // in seconds
} Music;

// Define music library data structure
typedef struct music_library {
  Music musics[MAX_SIZE];
  int size;
} MusicLibrary;

// Initialize the music library with empty values
void init_music_library(MusicLibrary* library);

// Add a new music to the library
void add_music(MusicLibrary* library);

// Display all music in the library
void display_all_music(MusicLibrary* library);

// Search for music in the library by title
void search_music_by_title(MusicLibrary* library);

// Search for music in the library by artist
void search_music_by_artist(MusicLibrary* library);

// Delete music from the library by title
void delete_music_by_title(MusicLibrary* library);

int main() {
  MusicLibrary library;
  char option;

  // Initialize the music library with empty values
  init_music_library(&library);

  do {
    printf("Welcome to the C Music Library Management System!\n");
    printf("Select an option:\n");
    printf("1. Add new music\n");
    printf("2. Display all music\n");
    printf("3. Search music by title\n");
    printf("4. Search music by artist\n");
    printf("5. Delete music by title\n");
    printf("6. Exit\n");
    printf("Option: ");
    scanf(" %c", &option);

    switch (option) {
      case '1':
        add_music(&library);
        break;
      case '2':
        display_all_music(&library);
        break;
      case '3':
        search_music_by_title(&library);
        break;
      case '4':
        search_music_by_artist(&library);
        break;
      case '5':
        delete_music_by_title(&library);
        break;
      case '6':
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid option\n");
    }

    printf("\n");
  } while (option != '6');

  return 0;
}

// Initialize the music library with empty values
void init_music_library(MusicLibrary* library) {
  library->size = 0;
}

// Add a new music to the library
void add_music(MusicLibrary* library) {
  Music music;

  // Prompt user for details of new music
  printf("Enter title: ");
  scanf(" %[^\n]s", music.title);
  printf("Enter artist: ");
  scanf(" %[^\n]s", music.artist);
  printf("Enter album: ");
  scanf(" %[^\n]s", music.album);
  printf("Enter genre: ");
  scanf(" %[^\n]s", music.genre);
  printf("Enter year: ");
  scanf(" %d", &music.year);
  printf("Enter duration (in seconds): ");
  scanf(" %d", &music.duration);

  // Add new music to the library
  library->musics[library->size] = music;
  library->size++;

  printf("\nMusic added successfully!\n");
}

// Display all music in the library
void display_all_music(MusicLibrary* library) {
  if (library->size == 0) {
    printf("No music found in library\n");
    return;
  }

  printf("Title\t\tArtist\t\tAlbum\t\tGenre\t\tYear\t\tDuration (s)\n");

  for (int i = 0; i < library->size; i++) {
    printf("%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",
           library->musics[i].title,
           library->musics[i].artist,
           library->musics[i].album,
           library->musics[i].genre,
           library->musics[i].year,
           library->musics[i].duration);
  }
}

// Search for music in the library by title
void search_music_by_title(MusicLibrary* library) {
  char title[50];
  int found = 0;

  printf("Enter title to search: ");
  scanf(" %[^\n]s", title);

  for (int i = 0; i < library->size; i++) {
    if (strcmp(library->musics[i].title, title) == 0) {
      printf("%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",
             library->musics[i].title,
             library->musics[i].artist,
             library->musics[i].album,
             library->musics[i].genre,
             library->musics[i].year,
             library->musics[i].duration);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("No music found with title \"%s\"\n", title);
  }
}

// Search for music in the library by artist
void search_music_by_artist(MusicLibrary* library) {
  char artist[50];
  int found = 0;

  printf("Enter artist to search: ");
  scanf(" %[^\n]s", artist);

  for (int i = 0; i < library->size; i++) {
    if (strcmp(library->musics[i].artist, artist) == 0) {
      printf("%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",
             library->musics[i].title,
             library->musics[i].artist,
             library->musics[i].album,
             library->musics[i].genre,
             library->musics[i].year,
             library->musics[i].duration);
      found = 1;
    }
  }

  if (!found) {
    printf("No music found with artist \"%s\"\n", artist);
  }
}

// Delete music from the library by title
void delete_music_by_title(MusicLibrary* library) {
  char title[50];
  int found = 0;

  printf("Enter title to delete: ");
  scanf(" %[^\n]s", title);

  for (int i = 0; i < library->size; i++) {
    if (strcmp(library->musics[i].title, title) == 0) {
      for (int j = i; j < library->size - 1; j++) {
        library->musics[j] = library->musics[j+1];
      }
      library->size--;
      found = 1;
      printf("Music with title \"%s\" deleted successfully!\n", title);
      break;
    }
  }

  if (!found) {
    printf("No music found with title \"%s\"\n", title);
  }
}