//FormAI DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct c_music_library {
   char title[50];
   char artist[50];
   char album[50];
   int year;
} c_music_t;

#define MAX_SIZE 1000

c_music_t music_collection[MAX_SIZE];
int collection_size = 0;

pthread_mutex_t mutex;

void add_music(char title[], char artist[], char album[], int year) 
{
  c_music_t new_music;
  strcpy(new_music.title, title);
  strcpy(new_music.artist, artist);
  strcpy(new_music.album, album);
  new_music.year = year;
    
  pthread_mutex_lock(&mutex);
  music_collection[collection_size++] = new_music;
  pthread_mutex_unlock(&mutex);
}

void remove_music(char title[], char artist[]) 
{
  bool found = false;
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < collection_size; ++i) {
    if (strcmp(music_collection[i].title, title) == 0 && strcmp(music_collection[i].artist, artist) == 0) {
      // remove from collection
      for (int j = i; j < collection_size - 1; ++j) {
        music_collection[j] = music_collection[j+1];
      }
      collection_size--;
      found = true;
      break;
    }
  }
  pthread_mutex_unlock(&mutex);
  
  if (!found) {
    printf("Music not found in collection\n");
  }
}

void display_collection() 
{
  pthread_mutex_lock(&mutex);
  if (collection_size == 0) {
    printf("Collection is empty\n");
  } else {
    printf("\nTitle\tArtist\tAlbum\tYear\n");
    for (int i = 0; i < collection_size; ++i) {
      printf("%s\t%s\t%s\t%d\n", music_collection[i].title, music_collection[i].artist, music_collection[i].album, music_collection[i].year);
    }
  }
  pthread_mutex_unlock(&mutex);
}

void *async_add_music(void *args) 
{
  char title[50];
  char artist[50];
  char album[50];
  int year;
  printf("Enter music details\n");
  printf("Title: ");
  fgets(title, 50, stdin);
  printf("Artist: ");
  fgets(artist, 50, stdin);
  printf("Album: ");
  fgets(album, 50, stdin);
  printf("Year: ");
  scanf("%d", &year);
  add_music(title, artist, album, year);
  printf("Added music to collection!\n");
}

void *async_remove_music(void *args) 
{
  char title[50];
  char artist[50];
  printf("Enter music details\n");
  printf("Title: ");
  fgets(title, 50, stdin);
  printf("Artist: ");
  fgets(artist, 50, stdin);
  remove_music(title, artist);
  printf("Removed music from collection!\n");
}

void *async_display_collection(void *args) 
{
  display_collection();
}

int main() 
{
  int option;
  pthread_t tid[3];
  pthread_mutex_init(&mutex, NULL);

  while (true) {
    printf("\n1. Add music to collection\n");
    printf("2. Remove music from collection\n");
    printf("3. Display collection\n");
    printf("4. Exit program\n");
    printf("Choose an option: ");
    scanf("%d", &option);
    getchar(); // to capture newline character

    if (option == 4) {
      printf("Exiting program...\n");
      break;
    }

    switch(option) {
      case 1: 
        pthread_create(&tid[0], NULL, async_add_music, NULL);
        pthread_join(tid[0], NULL);
        break;
      case 2:
        pthread_create(&tid[1], NULL, async_remove_music, NULL);
        pthread_join(tid[1], NULL);
        break;
      case 3:
        pthread_create(&tid[2], NULL, async_display_collection, NULL);
        pthread_join(tid[2], NULL);
        break;
      default:
        printf("Invalid option. Please choose again.\n");
        break;
    }
  }

  pthread_mutex_destroy(&mutex);
  return 0;
}