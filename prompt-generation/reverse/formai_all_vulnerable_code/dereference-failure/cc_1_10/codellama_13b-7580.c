//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
// music_library_management_system.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
  char name[50];
  char artist[50];
  char genre[50];
  int play_count;
  int rating;
} Song;

typedef struct {
  char name[50];
  char password[50];
  Song* library;
  int library_size;
} User;

// Function prototypes
void add_song(User* user, Song* song);
void remove_song(User* user, int index);
void play_song(User* user, int index);
void rate_song(User* user, int index, int rating);
void print_library(User* user);

// Main function
int main() {
  User user1 = {"John", "password", NULL, 0};
  User user2 = {"Jane", "password", NULL, 0};

  Song song1 = {"Song 1", "Artist 1", "Genre 1", 0, 0};
  Song song2 = {"Song 2", "Artist 2", "Genre 2", 0, 0};
  Song song3 = {"Song 3", "Artist 3", "Genre 3", 0, 0};

  add_song(&user1, &song1);
  add_song(&user1, &song2);
  add_song(&user2, &song3);

  print_library(&user1);
  print_library(&user2);

  return 0;
}

// Function definitions
void add_song(User* user, Song* song) {
  if (user->library_size == 0) {
    user->library = (Song*) malloc(sizeof(Song));
  } else {
    user->library = (Song*) realloc(user->library, (user->library_size + 1) * sizeof(Song));
  }

  user->library[user->library_size] = *song;
  user->library_size++;
}

void remove_song(User* user, int index) {
  if (index < 0 || index >= user->library_size) {
    printf("Invalid index\n");
    return;
  }

  for (int i = index; i < user->library_size - 1; i++) {
    user->library[i] = user->library[i + 1];
  }

  user->library_size--;
}

void play_song(User* user, int index) {
  if (index < 0 || index >= user->library_size) {
    printf("Invalid index\n");
    return;
  }

  user->library[index].play_count++;
}

void rate_song(User* user, int index, int rating) {
  if (index < 0 || index >= user->library_size) {
    printf("Invalid index\n");
    return;
  }

  user->library[index].rating = rating;
}

void print_library(User* user) {
  printf("Library of %s:\n", user->name);
  for (int i = 0; i < user->library_size; i++) {
    printf("Song %d: %s by %s in %s (play count: %d, rating: %d)\n", i, user->library[i].name, user->library[i].artist, user->library[i].genre, user->library[i].play_count, user->library[i].rating);
  }
}