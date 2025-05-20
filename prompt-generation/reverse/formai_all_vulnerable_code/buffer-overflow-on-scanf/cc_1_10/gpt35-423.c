//FormAI DATASET v1.0 Category: Music Library Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct album{
   char name[50];
   char artist[50];
   int year;
   int tracks;
};

void add_album(struct album **library, int *size){
   struct album *new_library = realloc(*library, (*size+1)*sizeof(struct album));
   if(new_library != NULL){
      printf("\nEnter album details:\n");
      printf("Name: ");
      scanf("%s", new_library[*size].name);
      printf("Artist: ");
      scanf("%s", new_library[*size].artist);
      printf("Year: ");
      scanf("%d", &new_library[*size].year);
      printf("Number of tracks: ");
      scanf("%d", &new_library[*size].tracks);
      *library = new_library;
      *size += 1;
   }
}

void print_album(struct album album){
   printf("\nName: %s\n", album.name);
   printf("Artist: %s\n", album.artist);
   printf("Year: %d\n", album.year);
   printf("Number of tracks: %d\n", album.tracks);
}

void search_album(struct album *library, int size){
   char search_name[50];
   printf("\nEnter album name to search: ");
   scanf("%s", search_name);
   for(int i = 0; i < size; i++){
      if(strcmp(search_name, library[i].name) == 0){
         print_album(library[i]);
         return;
      }
   }
   printf("Album not found.\n");
}

void print_library(struct album *library, int size){
   printf("\nLibrary contents:\n\n");
   for(int i = 0; i < size; i++){
      print_album(library[i]);
   }
}

int main(){
   struct album *library = NULL;
   int size = 0;
   int choice = -1;
   printf("Welcome to the C Music Library Management System\n\n");
   while(choice != 0){
      printf("Please select an option:\n");
      printf("1. Add album\n");
      printf("2. Search album\n");
      printf("3. Print library\n");
      printf("0. Exit\n");
      scanf("%d", &choice);
      switch(choice){
         case 1:
            add_album(&library, &size);
            break;
         case 2:
            search_album(library, size);
            break;
         case 3:
            print_library(library, size);
            break;
         case 0:
            printf("\nExiting system. Goodbye!\n");
            break;
         default:
            printf("\nInvalid choice. Please choose again.\n");
            break;
      }
   }
   free(library);
   return 0;
}