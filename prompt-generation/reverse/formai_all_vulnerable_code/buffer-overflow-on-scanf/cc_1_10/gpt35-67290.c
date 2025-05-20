//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char name[100];
    char artist[100];
    char album[100];
    int year;
    int duration;
    char genre[100];
    struct song *next;
};

typedef struct song Song;

int printMenu();
void printList(Song *head);
void addSong(Song **head);
void deleteSong(Song **head, char *name);
void searchSong(Song *head, char *name);

int main() {
    Song *head = NULL;
    int choice = 0;
    char searchName[100];
    char deleteName[100];
    
    do {
        choice = printMenu();
        
        switch(choice) {
            case 1:
                addSong(&head);
                break;
            case 2:
                printf("\nEnter the name of the song to search: ");
                scanf("%s", searchName);
                searchSong(head, searchName);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("\nEnter the name of the song to delete: ");
                scanf("%s", deleteName);
                deleteSong(&head, deleteName);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}

int printMenu() {
    int choice;
    
    printf("\nMusic Library Management System");
    printf("\n--------------------------------");
    printf("\n1. Add Song");
    printf("\n2. Search Song");
    printf("\n3. Print Library");
    printf("\n4. Delete Song");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    return choice;
}

void printList(Song *head) {
    Song *current = head;
    
    if(current == NULL) {
        printf("\nYour music library is empty.\n");
        return;
    }
    
    printf("\nSong Name\tArtist Name\tAlbum Name\tYear\tDuration\tGenre\n");
    
    while(current != NULL) {
        printf("%s\t\t%s\t\t%s\t\t%d\t%d\t\t%s\n", current->name, current->artist, current->album, current->year, current->duration, current->genre);
        current = current->next;
    }
}

void addSong(Song **head) {
    Song *newSong = (Song*) malloc(sizeof(Song));
    
    printf("\nEnter song details:\n");
    printf("Song name: ");
    scanf("%s", newSong->name);
    printf("Artist name: ");
    scanf("%s", newSong->artist);
    printf("Album name: ");
    scanf("%s", newSong->album);
    printf("Year: ");
    scanf("%d", &newSong->year);
    printf("Duration (in seconds): ");
    scanf("%d", &newSong->duration);
    printf("Genre: ");
    scanf("%s", newSong->genre);
    newSong->next = NULL;

    if(*head == NULL) {
        *head = newSong;
    } else {
        Song *current = *head;
        
        while(current->next != NULL) {
            current = current->next;
        }
        
        current->next = newSong;
    }
    
    printf("\nSong added successfully!\n");
}

void searchSong(Song *head, char *name) {
    Song *current = head;
    int found = 0;
    
    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            found = 1;
            printf("\nSong found!\n");
            printf("Song name: %s\n", current->name);
            printf("Artist name: %s\n", current->artist);
            printf("Album name: %s\n", current->album);
            printf("Year: %d\n", current->year);
            printf("Duration: %d\n", current->duration);
            printf("Genre: %s\n", current->genre);
            break;
        }
        
        current = current->next;
    }
    
    if(!found) {
        printf("\nSong not found!\n");
    }
}

void deleteSong(Song **head, char *name) {
    Song *current = *head;
    Song *previous = NULL;
    int found = 0;
    
    while(current != NULL) {        
        if(strcmp(current->name, name) == 0) {
            found = 1;
            
            if(previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            
            free(current);
            printf("\nSong deleted successfully!\n");
            break;
        }
        
        previous = current;
        current = current->next;
    }
    
    if(!found) {
        printf("\nSong not found!\n");
    }
}