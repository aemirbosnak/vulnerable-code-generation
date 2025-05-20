//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct song {
  char title[50];
  char artist[50];
  int year;
  int length;
} song;

song songs[MAX_SONGS];
int num_songs = 0;

void add_song() {
  if (num_songs == MAX_SONGS) {
    printf("Error: Cannot add more songs. Library is full.\n");
    return;
  }

  printf("Enter song title: ");
  scanf("%s", songs[num_songs].title);

  printf("Enter song artist: ");
  scanf("%s", songs[num_songs].artist);

  printf("Enter song year: ");
  scanf("%d", &songs[num_songs].year);

  printf("Enter song length (in seconds): ");
  scanf("%d", &songs[num_songs].length);

  num_songs++;
}

void list_songs() {
  if (num_songs == 0) {
    printf("Error: Library is empty. No songs to list.\n");
    return;
  }

  printf("Songs in library:\n");
  for (int i = 0; i < num_songs; i++) {
    printf("%d. %s - %s (%d, %d seconds)\n", i + 1, songs[i].title, songs[i].artist, songs[i].year, songs[i].length);
  }
}

void search_songs() {
  char search_term[50];

  printf("Enter search term: ");
  scanf("%s", search_term);

  for (int i = 0; i < num_songs; i++) {
    if (strstr(songs[i].title, search_term) != NULL || strstr(songs[i].artist, search_term) != NULL) {
      printf("%d. %s - %s (%d, %d seconds)\n", i + 1, songs[i].title, songs[i].artist, songs[i].year, songs[i].length);
    }
  }
}

void delete_song() {
  int song_number;

  printf("Enter song number to delete: ");
  scanf("%d", &song_number);

  if (song_number < 1 || song_number > num_songs) {
    printf("Error: Invalid song number.\n");
    return;
  }

  for (int i = song_number - 1; i < num_songs - 1; i++) {
    songs[i] = songs[i + 1];
  }

  num_songs--;

  printf("Song deleted.\n");
}

void shuffle_songs() {
  for (int i = 0; i < num_songs; i++) {
    int j = rand() % num_songs;
    song temp = songs[i];
    songs[i] = songs[j];
    songs[j] = temp;
  }

  printf("Songs shuffled.\n");
}

int main() {
  int choice;

  do {
    printf("\nMusic Library Management System\n");
    printf("--------------------------------\n");
    printf("1. Add song\n");
    printf("2. List songs\n");
    printf("3. Search songs\n");
    printf("4. Delete song\n");
    printf("5. Shuffle songs\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_song();
        break;
      case 2:
        list_songs();
        break;
      case 3:
        search_songs();
        break;
      case 4:
        delete_song();
        break;
      case 5:
        shuffle_songs();
        break;
      case 6:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 6);

  return 0;
}