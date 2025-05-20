//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: grateful
// Music Library Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structures
typedef struct {
  char *artist;
  char *title;
  char *genre;
  int year;
  float length;
} Song;

typedef struct {
  char *name;
  char *email;
  char *password;
  int age;
  char *address;
} User;

// Functions
bool is_unique_song(Song song, Song *songs, int num_songs) {
  for (int i = 0; i < num_songs; i++) {
    if (strcmp(song.artist, songs[i].artist) == 0 && strcmp(song.title, songs[i].title) == 0) {
      return false;
    }
  }
  return true;
}

void add_song(Song *songs, int *num_songs, Song song) {
  if (is_unique_song(song, songs, *num_songs)) {
    songs[*num_songs] = song;
    (*num_songs)++;
  }
}

void print_songs(Song *songs, int num_songs) {
  for (int i = 0; i < num_songs; i++) {
    printf("%s - %s (%s, %d)\n", songs[i].artist, songs[i].title, songs[i].genre, songs[i].year);
  }
}

void print_user(User *users, int num_users, int index) {
  printf("%s (%s)\n", users[index].name, users[index].email);
}

int main() {
  Song songs[100];
  int num_songs = 0;
  User users[100];
  int num_users = 0;
  char command[100];

  while (true) {
    printf("Enter command: ");
    scanf("%s", command);

    if (strcmp(command, "add_song") == 0) {
      Song song;
      printf("Enter artist: ");
      scanf("%s", song.artist);
      printf("Enter title: ");
      scanf("%s", song.title);
      printf("Enter genre: ");
      scanf("%s", song.genre);
      printf("Enter year: ");
      scanf("%d", &song.year);
      printf("Enter length: ");
      scanf("%f", &song.length);
      add_song(songs, &num_songs, song);
    } else if (strcmp(command, "print_songs") == 0) {
      print_songs(songs, num_songs);
    } else if (strcmp(command, "add_user") == 0) {
      User user;
      printf("Enter name: ");
      scanf("%s", user.name);
      printf("Enter email: ");
      scanf("%s", user.email);
      printf("Enter password: ");
      scanf("%s", user.password);
      printf("Enter age: ");
      scanf("%d", &user.age);
      printf("Enter address: ");
      scanf("%s", user.address);
      users[num_users] = user;
      num_users++;
    } else if (strcmp(command, "print_users") == 0) {
      for (int i = 0; i < num_users; i++) {
        print_user(users, num_users, i);
      }
    } else if (strcmp(command, "exit") == 0) {
      break;
    } else {
      printf("Invalid command\n");
    }
  }

  return 0;
}