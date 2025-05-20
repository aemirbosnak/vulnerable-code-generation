//FormAI DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Music {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char album[MAX_SIZE];
    int year;
} Music;

typedef struct Node {
  Music data;
  struct Node *next;
} Node;

Node *head = NULL;

void addMusic() {
    Music newMusic;
    printf("\nEnter the details of the song:\n");
    printf("Title: ");
    scanf("\n%[^\n]s", newMusic.title);
    printf("Artist: ");
    scanf("\n%[^\n]s", newMusic.artist);
    printf("Album: ");
    scanf("\n%[^\n]s", newMusic.album);
    printf("Year: ");
    scanf("%d", &newMusic.year);
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newMusic;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    printf("\nAdded Song: %s\n", newMusic.title);
}

void displayList() {
    if (head == NULL) {
        printf("\nMusic library is empty.\n");
    } else {
        printf("\nMusic Library\n");
        printf("-----------------------------------\n");
        Node *current = head;
        int count = 1;
        while (current != NULL) {
            printf("\n%d. %s", count, current->data.title);
            printf("\nArtist: %s", current->data.artist);
            printf("\nAlbum: %s", current->data.album);
            printf("\nYear: %d\n", current->data.year);
            current = current->next;
            count++;
        }
    }   
}

void searchMusic(char title[]) {
    if (head == NULL) {
        printf("\nMusic library is empty.\n");
    } else {
        Node *current = head;
        while (current != NULL) {
            if (strcmp(current->data.title, title) == 0) {
                printf("\n%s", current->data.title);
                printf("\nArtist: %s", current->data.artist);
                printf("\nAlbum: %s", current->data.album);
                printf("\nYear: %d\n", current->data.year);
                return;
            }
            current = current->next;
        }
        printf("\nSong not found.\n");
    }
}

void deleteMusic(char title[]) {
    if (head == NULL) {
        printf("\nMusic library is empty.\n");
    } else {
        Node *current = head;
        Node *previous = NULL;
        while (current != NULL) {
            if (strcmp(current->data.title, title) == 0) {
                if (previous == NULL) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                printf("\n%s deleted successfully.\n", title);
                return;
            }
            previous = current;
            current = current->next;
        }
        printf("\nSong not found.\n");
    }
}

int main() {
    int choice;
    char title[MAX_SIZE];
    do {
        printf("\nMusic Library Management System\n");
        printf("------------------------------------------\n");
        printf("1. Add a Song\n");
        printf("2. Display the Music Library\n");
        printf("3. Search for a Song\n");
        printf("4. Delete a Song\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addMusic();
                    break;
            case 2: displayList();
                    break;
            case 3: printf("\nEnter the title of the song: ");
                    scanf("\n%[^\n]s", title);
                    searchMusic(title);
                    break;
            case 4: printf("\nEnter the title of the song: ");
                    scanf("\n%[^\n]s", title);
                    deleteMusic(title);
                    break;
            case 5: printf("\nExiting the application.\n");
                    break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
        
    } while (choice != 5);
    
    return 0;
}