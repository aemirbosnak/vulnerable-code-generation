//FormAI DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100

struct Album {
   char title[50];
   char artist[50];
   int year;
};

typedef struct Album Album;

Album library[MAX_ALBUMS];
int numAlbums = 0;

int searchAlbum(char title[]) {
   int i;
   for (i = 0; i < numAlbums; i++) {
      if (strcmp(library[i].title, title) == 0)
         return i;
   }
   return -1;
}

void addAlbum() {
   Album newAlbum;
   printf("Enter the album title: ");
   scanf("%s", newAlbum.title);
   printf("Enter the artist name: ");
   scanf("%s", newAlbum.artist);
   printf("Enter the year it was released: ");
   scanf("%d", &newAlbum.year);
   library[numAlbums++] = newAlbum;
   printf("Album added to the library!\n");
}

void displayAlbum(int index) {
   printf("%s - %s (%d)\n", library[index].artist, library[index].title, library[index].year);
}

void printLibrary() {
   int i;
   for (i = 0; i < numAlbums; i++)
      displayAlbum(i);
}

void searchOrAddAlbum() {
   char title[50];
   int albumIndex;
   printf("Enter the title of the album you want to search for (or add if it doesn't exist): ");
   scanf("%s", title);
   albumIndex = searchAlbum(title);
   if (albumIndex == -1) {
      printf("Album not found, adding it to the library...\n");
      addAlbum();
   }
   else
      displayAlbum(albumIndex);
}

int main() {
   int option;
   printf("=== C Music Library Management System ===\n");
   do {
      printf("\nOptions:\n");
      printf("1. Add album to the library\n");
      printf("2. Display all albums in the library\n");
      printf("3. Search for an album (or add if it doesn't exist in the library)\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &option);
      printf("\n");
      switch(option) {
         case 1:
            addAlbum();
            break;
         case 2:
            if (numAlbums == 0)
               printf("Library is empty!\n");
            else
               printLibrary();
            break;
         case 3:
            searchOrAddAlbum();
            break;
         case 4:
            printf("Thank you for using the C Music Library Management System!\n");
            break;
         default:
            printf("Invalid option! Please enter a number from 1 to 4.\n");
            break;
      }
   } while(option != 4);
   return 0;
}