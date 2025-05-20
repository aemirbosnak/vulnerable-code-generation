//FormAI DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_ARTISTS 100

typedef struct {
  char title[50];
  char artist[20];
  char album[20];
  char genre[10];
  int year;
  float duration;
} Song;

typedef struct {
  char name[20];
  Song songs[MAX_SONGS];
  int num_songs;
} Artist;

Artist artists[MAX_ARTISTS];
int num_artists = 0;

int find_artist(char *name) {
  int i;
  for(i = 0; i < num_artists; i++) {
    if(strcmp(artists[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

void add_song() {
  char title[50], artist[20], album[20], genre[10];
  int year;
  float duration;

  printf("Enter song title: ");
  scanf("%s", title);

  printf("Enter artist name: ");
  scanf("%s", artist);

  printf("Enter album title: ");
  scanf("%s", album);

  printf("Enter genre: ");
  scanf("%s", genre);

  printf("Enter year of release: ");
  scanf("%d", &year);

  printf("Enter duration (in minutes): ");
  scanf("%f", &duration);

  int artist_index = find_artist(artist);

  if(artist_index == -1) {
    // Add new artist
    Artist new_artist = {.num_songs = 1};
    strcpy(new_artist.name, artist);
    strcpy(new_artist.songs[0].title, title);
    strcpy(new_artist.songs[0].artist, artist);
    strcpy(new_artist.songs[0].album, album);
    strcpy(new_artist.songs[0].genre, genre);
    new_artist.songs[0].year = year;
    new_artist.songs[0].duration = duration;
    artists[num_artists] = new_artist;
    num_artists++;
  } else {
    // Add to existing artist
    Artist *existing_artist = &artists[artist_index];
    int song_index = existing_artist->num_songs;
    strcpy(existing_artist->songs[song_index].title, title);
    strcpy(existing_artist->songs[song_index].artist, artist);
    strcpy(existing_artist->songs[song_index].album, album);
    strcpy(existing_artist->songs[song_index].genre, genre);
    existing_artist->songs[song_index].year = year;
    existing_artist->songs[song_index].duration = duration;
    existing_artist->num_songs++;
  }

  printf("Song added successfully!\n");
}

void display_songs() {
   printf("\nSong List\n");
   printf("---------\n");

   int i, j;
   for(i = 0; i < num_artists; i++) {
     printf("%s\n", artists[i].name);
     printf("------------------------------\n");
     printf("Title              Artist       Album           Genre       Year     Duration\n");
     printf("----------------------------------------------------------------------------\n");
     for(j = 0; j < artists[i].num_songs; j++) {
       Song song = artists[i].songs[j];
       printf("%-18s ", song.title);
       printf("%-12s ", song.artist);
       printf("%-15s ", song.album);
       printf("%-10s ", song.genre);
       printf("%-9d ", song.year);
       printf("%-5.2f\n", song.duration);
     }
     printf("\n");
   }
}

int main() {
   int choice = 0;

   while(choice != 3) {
     printf("Menu:\n");
     printf("1. Add a song\n");
     printf("2. Display all songs\n");
     printf("3. Exit\n");

     printf("Enter your choice: ");
     scanf("%d", &choice);

     switch(choice) {
       case 1:
         add_song();
         break;
       case 2:
         display_songs();
         break;
       case 3:
        printf("Exiting...\n");
         break;
       default:
         printf("\nInvalid choice. Try again.\n\n");
     }
   }

   return 0;
}