//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Artist {
   char name[50];
   int age;
};

struct Album {
   char title[100];
   int release_year;
   struct Artist artist;
};

struct Song {
   char title[100];
   int length_in_seconds;
   struct Artist artist;
   struct Album album;
};

struct Playlist {
   char name[100];
   int num_songs;
   struct Song *songs;
};

void add_artist(struct Artist *artists, int *num_artists) {
   printf("\nEnter artist name: ");
   scanf("%s", artists[*num_artists].name);
   printf("Enter artist age: ");
   scanf("%d", &artists[*num_artists].age);
   (*num_artists)++;
}

void add_album(struct Album *albums, int *num_albums, struct Artist *artists, int num_artists) {
   printf("\nEnter album title: ");
   scanf("%s", albums[*num_albums].title);
   printf("Enter album release year: ");
   scanf("%d", &albums[*num_albums].release_year);

   // Select artist
   int artist_index;
   do {
      printf("Select an artist: \n");
      for(int i=0; i<num_artists; i++) {
         printf("%d. %s\n", i+1, artists[i].name);
      }
      printf("Enter artist number: ");
      scanf("%d", &artist_index);
   } while(artist_index < 1 || artist_index > num_artists);
   albums[*num_albums].artist = artists[artist_index-1];

   (*num_albums)++;
}

void add_song(struct Song *songs, int *num_songs, struct Artist *artists, int num_artists, struct Album *albums, int num_albums) {
   printf("\nEnter song title: ");
   scanf("%s", songs[*num_songs].title);
   printf("Enter song length in seconds: ");
   scanf("%d", &songs[*num_songs].length_in_seconds);

   // Select artist
   int artist_index;
   do {
      printf("Select an artist: \n");
      for(int i=0; i<num_artists; i++) {
         printf("%d. %s\n", i+1, artists[i].name);
      }
      printf("Enter artist number: ");
      scanf("%d", &artist_index);
   } while(artist_index < 1 || artist_index > num_artists);
   songs[*num_songs].artist = artists[artist_index-1];

   // Select album
   int album_index;
   do {
      printf("Select an album: \n");
      for(int i=0; i<num_albums; i++) {
         printf("%d. %s\n", i+1, albums[i].title);
      }
      printf("Enter album number: ");
      scanf("%d", &album_index);
   } while(album_index < 1 || album_index > num_albums);
   songs[*num_songs].album = albums[album_index-1];

   (*num_songs)++;
}

void add_to_playlist(struct Playlist *playlist, int *num_playlists, struct Song *songs, int num_songs) {
   printf("\nEnter playlist name: ");
   scanf("%s", playlist[*num_playlists].name);

   // Select songs
   int num_selected_songs;
   int *selected_song_indices = malloc(num_songs * sizeof(int));
   do {
      printf("Select songs to add to playlist: \n");
      for(int i=0; i<num_songs; i++) {
         printf("%d. %s (%s - %s)\n", i+1, songs[i].title, songs[i].artist.name, songs[i].album.title);
      }
      printf("Enter song number to add (-1 to finish): ");
      scanf("%d", &selected_song_indices[num_selected_songs]);
      num_selected_songs++;

      // Realloc to increase size of selected_song_indices if needed
      selected_song_indices = realloc(selected_song_indices, num_selected_songs * sizeof(int));
   } while(selected_song_indices[num_selected_songs-1] != -1);

   // Allocate songs array for playlist
   playlist[*num_playlists].songs = malloc(num_selected_songs * sizeof(struct Song));

   // Add selected songs to playlist
   for(int i=0; i<num_selected_songs-1; i++) {
      playlist[*num_playlists].songs[i] = songs[selected_song_indices[i]-1];
   }

   playlist[*num_playlists].num_songs = num_selected_songs-1;
   (*num_playlists)++;
}

void search_song(struct Song *songs, int num_songs) {
   char search_query[100];
   printf("\nEnter search query: ");
   scanf("%s", search_query);

   printf("\nSearch results:\n");

   // Search by title, artist, or album
   for(int i=0; i<num_songs; i++) {
      if(strstr(songs[i].title, search_query) != NULL || strstr(songs[i].artist.name, search_query) != NULL || strstr(songs[i].album.title, search_query) != NULL) {
         printf("%s (%s - %s)\n", songs[i].title, songs[i].artist.name, songs[i].album.title);
      }
   }
}

int main() {
   int num_artists = 0;
   struct Artist *artists = malloc(100 * sizeof(struct Artist));
   int num_albums = 0;
   struct Album *albums = malloc(100 * sizeof(struct Album));
   int num_songs = 0;
   struct Song *songs = malloc(1000 * sizeof(struct Song));
   int num_playlists = 0;
   struct Playlist *playlists = malloc(100 * sizeof(struct Playlist));

   int menu_choice;
   do {
      printf("\nChoose an option:\n");
      printf("1. Add artist\n");
      printf("2. Add album\n");
      printf("3. Add song\n");
      printf("4. Add playlist\n");
      printf("5. Search song\n");
      printf("6. Exit\n");
      printf("\nEnter choice: ");
      scanf("%d", &menu_choice);

      switch(menu_choice) {
         case 1:
            add_artist(artists, &num_artists);
            break;
         case 2:
            add_album(albums, &num_albums, artists, num_artists);
            break;
         case 3:
            add_song(songs, &num_songs, artists, num_artists, albums, num_albums);
            break;
         case 4:
            add_to_playlist(playlists, &num_playlists, songs, num_songs);
            break;
         case 5:
            search_song(songs, num_songs);
            break;
         case 6:
            printf("\nExiting.\n");
            break;
         default:
            printf("\nInvalid choice, try again.\n");
      }
   } while(menu_choice != 6);

   // Free memory
   free(artists);
   free(albums);
   free(songs);
   for(int i=0; i<num_playlists; i++) {
      free(playlists[i].songs);
   }
   free(playlists);

   return 0;
}