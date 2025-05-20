//FormAI DATASET v1.0 Category: Music Library Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
  char title[50];
  char artist[50];
  char album[50];
  char genre[50];
} Song;

typedef struct Node {
  Song song;
  struct Node* next;
} Node;

Node* head = NULL;

void displayMenu() {
  printf("\n\nMusic Library Management System\n\n");
  printf("-----------------------------\n");
  printf("1. Add Song\n");
  printf("2. Delete Song\n");
  printf("3. Display All Songs\n");
  printf("4. Search Song\n");
  printf("5. Exit\n");
  printf("-----------------------------\n");
}

void addSong() {
  Node* temp = (Node*)malloc(sizeof(Node));
  printf("Enter Title: ");
  scanf("%s", temp->song.title);
  printf("Enter Artist: ");
  getchar();
  fgets(temp->song.artist, 50, stdin);
  printf("Enter Album: ");
  scanf("%s", temp->song.album);
  printf("Enter Genre: ");
  getchar();
  fgets(temp->song.genre, 50, stdin);
  temp->next = head;
  head = temp;
  printf("Song Added Successfully!\n");
}

void deleteSong() {
  Node* temp = NULL;
  Node* currNode = head;
  char title[50];
  printf("Enter Title: ");
  scanf("%s", title);
  while (currNode != NULL && strcmp(currNode->song.title, title) != 0) {
    temp = currNode;
    currNode = currNode->next;
  }
  if (currNode == NULL) {
    printf("Song Not Found!\n");
    return;
  }
  if (temp == NULL) {
    head = currNode->next;
  } else {
    temp->next = currNode->next;
  }
  free(currNode);
  printf("Song Deleted Successfully!\n");
}

void displaySongs() {
  if (head == NULL) {
    printf("No Songs Found!\n");
    return;
  }
  Node* currNode = head;
  printf("All Songs:\n");
  while (currNode != NULL) {
    printf("Title: %s\n", currNode->song.title);
    printf("Artist: %s", currNode->song.artist);
    printf("Album: %s\n", currNode->song.album);
    printf("Genre: %s", currNode->song.genre);
    printf("------------------------\n");
    currNode = currNode->next;
  }
}

void searchSong() {
  Node* currNode = head;
  char title[50];
  printf("Enter Title: ");
  scanf("%s", title);
  while (currNode != NULL && strcmp(currNode->song.title, title) != 0) {
    currNode = currNode->next;
  }
  if (currNode == NULL) {
    printf("Song Not Found!\n");
    return;
  }
  printf("Title: %s\n", currNode->song.title);
  printf("Artist: %s", currNode->song.artist);
  printf("Album: %s\n", currNode->song.album);
  printf("Genre: %s", currNode->song.genre);
}

int main() {
  int choice = 0;
  while (choice != 5) {
    displayMenu();
    printf("Enter Choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addSong();
        break;
      case 2:
        deleteSong();
        break;
      case 3:
        displaySongs();
        break;
      case 4:
        searchSong();
        break;
      case 5:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid Choice!\n");
        break;
    }
  }
  return 0;
}