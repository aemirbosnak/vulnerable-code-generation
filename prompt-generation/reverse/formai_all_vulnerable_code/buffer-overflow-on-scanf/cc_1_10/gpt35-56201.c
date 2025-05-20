//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold metadata information
struct metadata {
   char *title;
   char *artist;
   char *album;
   char *genre;
   int year;
};

int main() {
   printf("Welcome to the C Metadata Extractor!\n");
   printf("Please enter the file location: ");

   // Read file location
   char file_location[100];
   scanf("%s", file_location);

   // Open file
   FILE *fp;
   fp = fopen(file_location, "r");

   if (fp == NULL) {
      printf("File not found!\n");
      return 1;
   }

   // Allocate memory for metadata struct
   struct metadata *song_info = (struct metadata *) malloc(sizeof(struct metadata));
   song_info->title = (char *) malloc(sizeof(char) * 100);
   song_info->artist = (char *) malloc(sizeof(char) * 100);
   song_info->album = (char *) malloc(sizeof(char) * 100);
   song_info->genre = (char *) malloc(sizeof(char) * 100);

   // Read file line by line
   char line[100];
   while (fgets(line, sizeof(line), fp)) {
      printf("Analyzing line: %s", line);

      // Check for title
      if (strstr(line, "Title:")) {
         char *title = strtok(line, ":");
         title = strtok(NULL, ":");
         strcpy(song_info->title, title);
         printf("Title found: %s\n", song_info->title);
      }

      // Check for artist
      if (strstr(line, "Artist:")) {
         char *artist = strtok(line, ":");
         artist = strtok(NULL, ":");
         strcpy(song_info->artist, artist);
         printf("Artist found: %s\n", song_info->artist);
      }

      // Check for album
      if (strstr(line, "Album:")) {
         char *album = strtok(line, ":");
         album = strtok(NULL, ":");
         strcpy(song_info->album, album);
         printf("Album found: %s\n", song_info->album);
      }

      // Check for genre
      if (strstr(line, "Genre:")) {
         char *genre = strtok(line, ":");
         genre = strtok(NULL, ":");
         strcpy(song_info->genre, genre);
         printf("Genre found: %s\n", song_info->genre);
      }

      // Check for year
      if (strstr(line, "Year:")) {
         char *year = strtok(line, ":");
         year = strtok(NULL, ":");
         song_info->year = atoi(year);
         printf("Year found: %d\n", song_info->year);
      }
   }

   // Close file
   fclose(fp);

   // Print metadata
   printf("\n=== METADATA ===\n");
   printf("Title: %s\n", song_info->title);
   printf("Artist: %s\n", song_info->artist);
   printf("Album: %s\n", song_info->album);
   printf("Genre: %s\n", song_info->genre);
   printf("Year: %d\n", song_info->year);

   // Free allocated memory
   free(song_info->title);
   free(song_info->artist);
   free(song_info->album);
   free(song_info->genre);
   free(song_info);

   return 0;
}