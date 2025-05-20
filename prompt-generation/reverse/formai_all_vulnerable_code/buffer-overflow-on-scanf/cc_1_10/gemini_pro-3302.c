//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct
typedef struct
{
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int track;
  char genre[50];
} song;

// define functions
void addSong(song *library, int *numSongs);
void deleteSong(song *library, int *numSongs);
void listSongs(song *library, int numSongs);
void searchSongs(song *library, int numSongs);
void sortSongs(song *library, int numSongs);

// main function
int main()
{
  // variables
  song library[100];
  int numSongs = 0;

  // menu
  int choice;
  do
  {
    printf("\nMusic Library Management System\n");
    printf("1. Add song\n");
    printf("2. Delete song\n");
    printf("3. List songs\n");
    printf("4. Search songs\n");
    printf("5. Sort songs\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // call functions
    switch (choice)
    {
    case 1:
      addSong(library, &numSongs);
      break;
    case 2:
      deleteSong(library, &numSongs);
      break;
    case 3:
      listSongs(library, numSongs);
      break;
    case 4:
      searchSongs(library, numSongs);
      break;
    case 5:
      sortSongs(library, numSongs);
      break;
    }
  } while (choice != 6);

  return 0;
}

// functions
void addSong(song *library, int *numSongs)
{
  // get song details
  printf("Enter song title: ");
  scanf("%s", library[*numSongs].title);
  printf("Enter artist name: ");
  scanf("%s", library[*numSongs].artist);
  printf("Enter album name: ");
  scanf("%s", library[*numSongs].album);
  printf("Enter year released: ");
  scanf("%d", &library[*numSongs].year);
  printf("Enter track number: ");
  scanf("%d", &library[*numSongs].track);
  printf("Enter genre: ");
  scanf("%s", library[*numSongs].genre);

  // increment number of songs
  (*numSongs)++;
}

void deleteSong(song *library, int *numSongs)
{
  // get song title
  char title[50];
  printf("Enter song title to delete: ");
  scanf("%s", title);

  // find song
  int i;
  for (i = 0; i < *numSongs; i++)
  {
    if (strcmp(library[i].title, title) == 0)
    {
      break;
    }
  }

  // if song found, delete it
  if (i < *numSongs)
  {
    for (int j = i; j < *numSongs - 1; j++)
    {
      library[j] = library[j + 1];
    }
    (*numSongs)--;
    printf("Song deleted successfully.\n");
  }
  else
  {
    printf("Song not found.\n");
  }
}

void listSongs(song *library, int numSongs)
{
  // print songs
  for (int i = 0; i < numSongs; i++)
  {
    printf("%s - %s - %s - %d - %d - %s\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].track, library[i].genre);
  }
}

void searchSongs(song *library, int numSongs)
{
  // get search term
  char term[50];
  printf("Enter search term: ");
  scanf("%s", term);

  // search songs
  int found = 0;
  for (int i = 0; i < numSongs; i++)
  {
    if (strstr(library[i].title, term) != NULL || strstr(library[i].artist, term) != NULL || strstr(library[i].album, term) != NULL || strstr(library[i].genre, term) != NULL)
    {
      printf("%s - %s - %s - %d - %d - %s\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].track, library[i].genre);
      found = 1;
    }
  }

  // if no songs found, print message
  if (!found)
  {
    printf("No songs found.\n");
  }
}

void sortSongs(song *library, int numSongs)
{
  // sort songs by title
  for (int i = 0; i < numSongs - 1; i++)
  {
    for (int j = i + 1; j < numSongs; j++)
    {
      if (strcmp(library[i].title, library[j].title) > 0)
      {
        song temp = library[i];
        library[i] = library[j];
        library[j] = temp;
      }
    }
  }

  // print songs
  listSongs(library, numSongs);
}