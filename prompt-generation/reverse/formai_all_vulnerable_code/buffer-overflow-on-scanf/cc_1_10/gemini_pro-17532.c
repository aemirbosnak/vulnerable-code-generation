//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a song
typedef struct Song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int duration; // in seconds
} Song;

// Function to create a new song
Song* createSong(char *title, char *artist, char *album, int year, int duration) {
  Song *song = (Song*)malloc(sizeof(Song));
  strcpy(song->title, title);
  strcpy(song->artist, artist);
  strcpy(song->album, album);
  song->year = year;
  song->duration = duration;
  return song;
}

// Function to print a song
void printSong(Song *song) {
  printf("Title: %s\n", song->title);
  printf("Artist: %s\n", song->artist);
  printf("Album: %s\n", song->album);
  printf("Year: %d\n", song->year);
  printf("Duration: %d seconds\n\n", song->duration);
}

// Function to compare two songs by title
int compareSongsByTitle(const void *a, const void *b) {
  Song *song1 = (Song*)a;
  Song *song2 = (Song*)b;
  return strcmp(song1->title, song2->title);
}

// Function to compare two songs by artist
int compareSongsByArtist(const void *a, const void *b) {
  Song *song1 = (Song*)a;
  Song *song2 = (Song*)b;
  return strcmp(song1->artist, song2->artist);
}

// Function to compare two songs by album
int compareSongsByAlbum(const void *a, const void *b) {
  Song *song1 = (Song*)a;
  Song *song2 = (Song*)b;
  return strcmp(song1->album, song2->album);
}

// Function to compare two songs by year
int compareSongsByYear(const void *a, const void *b) {
  Song *song1 = (Song*)a;
  Song *song2 = (Song*)b;
  return song1->year - song2->year;
}

// Function to compare two songs by duration
int compareSongsByDuration(const void *a, const void *b) {
  Song *song1 = (Song*)a;
  Song *song2 = (Song*)b;
  return song1->duration - song2->duration;
}

// Function to print the menu
void printMenu() {
  printf("1. Add a song\n");
  printf("2. Print all songs\n");
  printf("3. Sort songs by title\n");
  printf("4. Sort songs by artist\n");
  printf("5. Sort songs by album\n");
  printf("6. Sort songs by year\n");
  printf("7. Sort songs by duration\n");
  printf("8. Quit\n");
}

// Function to get the user's choice
int getChoice() {
  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

// Function to add a song to the library
void addSong(Song **songs, int *numSongs) {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int duration;

  printf("Enter the song title: ");
  scanf(" %[^\n]%*c", title);
  printf("Enter the artist name: ");
  scanf(" %[^\n]%*c", artist);
  printf("Enter the album name: ");
  scanf(" %[^\n]%*c", album);
  printf("Enter the year of release: ");
  scanf("%d", &year);
  printf("Enter the duration in seconds: ");
  scanf("%d", &duration);

  // Create a new song
  Song *song = createSong(title, artist, album, year, duration);

  // Add the song to the library
  songs[*numSongs] = song;
  (*numSongs)++;
}

// Function to print all songs in the library
void printAllSongs(Song **songs, int numSongs) {
  for (int i = 0; i < numSongs; i++) {
    printSong(songs[i]);
  }
}

// Function to sort songs by title
void sortByTitle(Song **songs, int numSongs) {
  qsort(songs, numSongs, sizeof(Song*), compareSongsByTitle);
}

// Function to sort songs by artist
void sortByArtist(Song **songs, int numSongs) {
  qsort(songs, numSongs, sizeof(Song*), compareSongsByArtist);
}

// Function to sort songs by album
void sortByAlbum(Song **songs, int numSongs) {
  qsort(songs, numSongs, sizeof(Song*), compareSongsByAlbum);
}

// Function to sort songs by year
void sortByYear(Song **songs, int numSongs) {
  qsort(songs, numSongs, sizeof(Song*), compareSongsByYear);
}

// Function to sort songs by duration
void sortByDuration(Song **songs, int numSongs) {
  qsort(songs, numSongs, sizeof(Song*), compareSongsByDuration);
}

int main() {
  // Initialize the music library
  Song *songs[100];
  int numSongs = 0;

  // Print the menu
  printMenu();

  // Get the user's choice
  int choice = getChoice();

  // Loop until the user quits
  while (choice != 8) {
    switch (choice) {
      case 1:
        addSong(songs, &numSongs);
        break;
      case 2:
        printAllSongs(songs, numSongs);
        break;
      case 3:
        sortByTitle(songs, numSongs);
        break;
      case 4:
        sortByArtist(songs, numSongs);
        break;
      case 5:
        sortByAlbum(songs, numSongs);
        break;
      case 6:
        sortByYear(songs, numSongs);
        break;
      case 7:
        sortByDuration(songs, numSongs);
        break;
      default:
        printf("Invalid choice. Please enter a number from 1 to 8.\n");
    }

    // Print the menu again
    printMenu();

    // Get the user's choice
    choice = getChoice();
  }

  return 0;
}