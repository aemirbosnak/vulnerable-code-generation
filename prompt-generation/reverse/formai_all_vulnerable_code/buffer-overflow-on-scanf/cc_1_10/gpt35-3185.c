//FormAI DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct album {
   char title[MAX_SIZE];
   char artist[MAX_SIZE];
   int year;
   float rating;
};

void addAlbum(struct album[], int*);
void searchAlbum(struct album[], int);
void deleteAlbum(struct album[], int*);
void displayAlbums(struct album[], int);

int main() {
   int choice, count=0;
   struct album musicLibrary[MAX_SIZE];
   do {
      printf("\n--- C MUSIC LIBRARY MANAGEMENT SYSTEM ---\n");
      printf("1. Add New Album\n");
      printf("2. Search Album\n");
      printf("3. Delete Album\n");
      printf("4. Display All Albums\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            addAlbum(musicLibrary, &count);
            break;
         case 2:
            searchAlbum(musicLibrary, count);
            break;
         case 3:
            deleteAlbum(musicLibrary, &count);
            break;
         case 4:
            displayAlbums(musicLibrary, count);
            break;
         case 5:
            printf("\nThank you for using C MUSIC LIBRARY MANAGEMENT SYSTEM!\n");
            break;
         default:
            printf("\nInvalid choice. Please try again.\n");
            break;
      }
   } while(choice != 5);
   return 0;
}

void addAlbum(struct album musicLibrary[], int *count) {
   if(*count == MAX_SIZE) {
      printf("\nError: The music library is full.\n");
      return;
   }
   printf("\nEnter album title: ");
   scanf(" %[^\n]", musicLibrary[*count].title);
   printf("Enter artist name: ");
   scanf(" %[^\n]", musicLibrary[*count].artist);
   printf("Enter release year: ");
   scanf("%d", &musicLibrary[*count].year);
   printf("Enter album rating: ");
   scanf("%f", &musicLibrary[*count].rating);
   printf("\nAlbum added successfully!\n");
   (*count)++;
}

void searchAlbum(struct album musicLibrary[], int count) {
   char title[MAX_SIZE];
   int i, found=0;
   printf("\nEnter album title to search for: ");
   scanf(" %[^\n]", title);
   for(i=0; i<count; i++) {
      if(strcmp(title, musicLibrary[i].title) == 0) {
         found=1;
         printf("\nAlbum Title: %s\nArtist Name: %s\nRelease Year: %d\nRating: %.1f/10\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year, musicLibrary[i].rating);
      }
   }
   if(!found)
      printf("\nAlbum not found.\n");
}

void deleteAlbum(struct album musicLibrary[], int *count) {
   char title[MAX_SIZE];
   int i, found=0;
   printf("\nEnter album title to delete: ");
   scanf(" %[^\n]", title);
   for(i=0; i<*count; i++) {
      if(strcmp(title, musicLibrary[i].title) == 0) {
         found=1;
         while(i<*count-1) {
            strcpy(musicLibrary[i].title, musicLibrary[i+1].title);
            strcpy(musicLibrary[i].artist, musicLibrary[i+1].artist);
            musicLibrary[i].year = musicLibrary[i+1].year;
            musicLibrary[i].rating = musicLibrary[i+1].rating;
            i++;
         }
         (*count)--;
         printf("\nAlbum deleted successfully!\n");
         break;
      }
   }
   if(!found)
      printf("\nAlbum not found.\n");
}

void displayAlbums(struct album musicLibrary[], int count) {
   int i;
   if(count == 0) {
      printf("\nNo albums found.\n");
      return;
   }
   printf("\n--- LIST OF ALBUMS ---\n");
   for(i=0; i<count; i++) {
      printf("\nAlbum Title: %s\nArtist Name: %s\nRelease Year: %d\nRating: %.1f/10\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].year, musicLibrary[i].rating);
   }
}