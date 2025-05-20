//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: random
/*
 * Music Library Management System
 *
 * This program allows users to manage a library of music.
 *
 * Usage:
 * 1. Compile the program with the command: gcc -o music_library music_library.c
 * 2. Run the program with the command: ./music_library
 *
 * Commands:
 * 1. help - display a list of commands
 * 2. add - add a new song to the library
 * 3. delete - delete a song from the library
 * 4. list - list all songs in the library
 * 5. play - play a song from the library
 * 6. exit - exit the program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_SONG_NAME_LEN 50

typedef struct {
  char name[MAX_SONG_NAME_LEN];
  int length;
} Song;

Song songs[MAX_SONGS];
int num_songs = 0;

void print_help() {
  printf("Music Library Management System\n");
  printf("Commands:\n");
  printf("  help - display a list of commands\n");
  printf("  add - add a new song to the library\n");
  printf("  delete - delete a song from the library\n");
  printf("  list - list all songs in the library\n");
  printf("  play - play a song from the library\n");
  printf("  exit - exit the program\n");
}

void add_song(char* name, int length) {
  if (num_songs >= MAX_SONGS) {
    printf("Song limit reached.\n");
    return;
  }

  strcpy(songs[num_songs].name, name);
  songs[num_songs].length = length;
  num_songs++;
}

void delete_song(int index) {
  if (index < 0 || index >= num_songs) {
    printf("Invalid song index.\n");
    return;
  }

  for (int i = index; i < num_songs - 1; i++) {
    songs[i] = songs[i + 1];
  }
  num_songs--;
}

void list_songs() {
  printf("Song Library:\n");
  for (int i = 0; i < num_songs; i++) {
    printf("%d. %s (%d seconds)\n", i + 1, songs[i].name, songs[i].length);
  }
}

void play_song(int index) {
  if (index < 0 || index >= num_songs) {
    printf("Invalid song index.\n");
    return;
  }

  printf("Playing %s...\n", songs[index].name);
  sleep(songs[index].length);
}

int main() {
  char command[10];

  print_help();

  while (1) {
    printf("Enter a command: ");
    scanf("%s", command);

    if (strcmp(command, "help") == 0) {
      print_help();
    } else if (strcmp(command, "add") == 0) {
      char name[MAX_SONG_NAME_LEN];
      int length;
      printf("Enter song name: ");
      scanf("%s", name);
      printf("Enter song length (seconds): ");
      scanf("%d", &length);
      add_song(name, length);
    } else if (strcmp(command, "delete") == 0) {
      int index;
      printf("Enter song index: ");
      scanf("%d", &index);
      delete_song(index);
    } else if (strcmp(command, "list") == 0) {
      list_songs();
    } else if (strcmp(command, "play") == 0) {
      int index;
      printf("Enter song index: ");
      scanf("%d", &index);
      play_song(index);
    } else if (strcmp(command, "exit") == 0) {
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}