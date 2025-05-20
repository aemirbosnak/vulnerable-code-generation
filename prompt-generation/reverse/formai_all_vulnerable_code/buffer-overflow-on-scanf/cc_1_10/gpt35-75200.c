//FormAI DATASET v1.0 Category: Music Library Management System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct Song {
   char name[30], artist[30], genre[30];
};

struct Node {
   struct Song song;
   struct Node* next;
};

int search_song(struct Node* head, char name[]);
int search_artist(struct Node* head, char artist[]);
int search_genre(struct Node* head, char genre[]);
struct Node* add_song(struct Node* head, struct Song new_song);
void display_playlist(struct Node* head);
struct Node* delete_song(struct Node* head, char name[]);

int main()
{
   struct Node* head = NULL;
   int choice, found;
   char name[30], artist[30], genre[30];
   struct Song new_song;

   while(1) {
      printf("\n1. Add Song\n2. Delete Song\n3. Search by song name\n4. Search by artist\n5. Search by genre\n6. Display Playlist\n7. Exit\nEnter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1: 
            printf("Enter the song name: ");
            scanf("%s", new_song.name);
            printf("Enter the artist name: ");
            scanf("%s", new_song.artist);
            printf("Enter the genre: ");
            scanf("%s", new_song.genre);
            head = add_song(head, new_song);
            break;
         case 2: 
            printf("Enter the song name to be deleted: ");
            scanf("%s", name);
            head = delete_song(head, name);
            break;
         case 3: 
            printf("Enter the song name to be searched: ");
            scanf("%s", name);
            found = search_song(head, name);
            if(found == -1)
               printf("Song not found\n");
            break;
         case 4: 
            printf("Enter the artist name to be searched: ");
            scanf("%s", artist);
            found = search_artist(head, artist);
            if(found == -1)
               printf("Artist not found\n");
            break;
         case 5: 
            printf("Enter the genre to be searched: ");
            scanf("%s", genre);
            found = search_genre(head, genre);
            if(found == -1)
               printf("Genre not found\n");
            break;
         case 6: 
            display_playlist(head);
            break;
         case 7: 
            exit(0);
         default: 
            printf("Invalid input\n");
            break;
      }
   }
   return 0;
}

int search_song(struct Node* head, char name[]) {
   int count = 0;
   while(head != NULL) {
      if(strcmp(head->song.name, name) == 0) {
         printf("Song found: %s by %s\n", head->song.name, head->song.artist);
         return count;
      }
      count++;
      head = head->next;
   }
   return -1;
}

int search_artist(struct Node* head, char artist[]) {
   int count = 0;
   while(head != NULL) {
      if(strcmp(head->song.artist, artist) == 0) {
         printf("Song found: %s by %s\n", head->song.name, head->song.artist);
         return count;
      }     
      count++;
      head = head->next;
   }
   return -1;
}

int search_genre(struct Node* head, char genre[]) {
   int count = 0;
   while(head != NULL) {
      if(strcmp(head->song.genre, genre) == 0) {
         printf("Song found: %s by %s\n", head->song.name, head->song.artist);
         return count;
      }     
      count++;
      head = head->next;
   }
   return -1;
}

struct Node* add_song(struct Node* head, struct Song new_song) {
   struct Node* new_node;
   new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->song = new_song;
   new_node->next = head;
   head = new_node;
   printf("Song added: %s by %s\n", new_song.name, new_song.artist);
   return head;
}

void display_playlist(struct Node* head) {
   printf("--------------Playlist--------------\n");
   while(head != NULL) {
      printf("%s by %s (%s)\n", head->song.name, head->song.artist, head->song.genre);
      head = head->next;
   }
   printf("------------------------------------\n");
}

struct Node* delete_song(struct Node* head, char name[]) {
   struct Node* temp, *prev;
   temp = head;
   prev = NULL;
   while(temp != NULL) {
      if(strcmp(temp->song.name, name) == 0) {
         if(prev == NULL)
            head = temp->next;
         else
            prev->next = temp->next;
         printf("Song deleted: %s by %s\n", temp->song.name, temp->song.artist);
         free(temp);
         return head;
      }
      prev = temp;
      temp = temp->next;
   }
   printf("Song not found\n");
   return head;
}