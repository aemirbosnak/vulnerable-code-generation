//Code Llama-13B DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_SONGS 100
#define MAX_SONG_NAME_LEN 100
#define MAX_SONG_ARTIST_LEN 100
#define MAX_SONG_ALBUM_LEN 100
#define MAX_SONG_GENRE_LEN 100
#define MAX_SONG_COMMENT_LEN 100

typedef struct {
  char name[MAX_SONG_NAME_LEN];
  char artist[MAX_SONG_ARTIST_LEN];
  char album[MAX_SONG_ALBUM_LEN];
  char genre[MAX_SONG_GENRE_LEN];
  char comment[MAX_SONG_COMMENT_LEN];
} Song;

void print_song(Song song) {
  printf("Song Name: %s\n", song.name);
  printf("Artist: %s\n", song.artist);
  printf("Album: %s\n", song.album);
  printf("Genre: %s\n", song.genre);
  printf("Comment: %s\n", song.comment);
}

void print_songs(Song songs[], int num_songs) {
  for (int i = 0; i < num_songs; i++) {
    print_song(songs[i]);
  }
}

int add_song(Song songs[], int num_songs, Song song) {
  if (num_songs >= MAX_SONGS) {
    printf("Error: song limit reached\n");
    return -1;
  }

  songs[num_songs] = song;
  return 0;
}

int delete_song(Song songs[], int num_songs, char *song_name) {
  int song_index = -1;
  for (int i = 0; i < num_songs; i++) {
    if (strcmp(songs[i].name, song_name) == 0) {
      song_index = i;
      break;
    }
  }

  if (song_index < 0) {
    printf("Error: song not found\n");
    return -1;
  }

  for (int i = song_index; i < num_songs - 1; i++) {
    songs[i] = songs[i + 1];
  }

  return 0;
}

int main() {
  Song songs[MAX_SONGS];
  int num_songs = 0;

  while (1) {
    printf("Enter command: ");
    char command[100];
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      Song song;
      printf("Enter song name: ");
      scanf("%s", song.name);
      printf("Enter artist: ");
      scanf("%s", song.artist);
      printf("Enter album: ");
      scanf("%s", song.album);
      printf("Enter genre: ");
      scanf("%s", song.genre);
      printf("Enter comment: ");
      scanf("%s", song.comment);
      add_song(songs, num_songs, song);
      num_songs++;
    } else if (strcmp(command, "delete") == 0) {
      char song_name[MAX_SONG_NAME_LEN];
      printf("Enter song name: ");
      scanf("%s", song_name);
      delete_song(songs, num_songs, song_name);
      num_songs--;
    } else if (strcmp(command, "print") == 0) {
      print_songs(songs, num_songs);
    } else if (strcmp(command, "exit") == 0) {
      break;
    } else {
      printf("Error: unknown command\n");
    }
  }

  return 0;
}