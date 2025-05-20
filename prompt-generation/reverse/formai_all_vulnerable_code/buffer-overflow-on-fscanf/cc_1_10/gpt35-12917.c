//FormAI DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char title[50];
    char artist[50];
    char genre[20];
    int year;
} Song;

typedef struct node {
    Song data;
    struct node *next;
} Node;

Node *head = NULL;

void addSong(Song newSong) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = newSong;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
    } else {
        Node *traverse = head;
        while(traverse->next != NULL) {
            traverse = traverse->next;
        }
        traverse->next = temp;
    }
}

void display() {
    if(head == NULL) {
        printf("The music library is empty!\n");
    } else {
        printf("%-30s%-30s%-20s%-10s\n", "Title", "Artist", "Genre", "Year");
        Node *traverse = head;
        while(traverse != NULL) {
            printf("%-30s%-30s%-20s%-10d\n", traverse->data.title, traverse->data.artist, traverse->data.genre, traverse->data.year);
            traverse = traverse->next;
        }
    }
}

void loadMusicLibrary() {
    FILE *fp = fopen("musicLibrary.txt", "r");
    if(fp == NULL) {
        printf("Failed to open file!\n");
        return;
    }
    while(!feof(fp)) {
        Song tempSong;
        fscanf(fp, "%[^,],%[^,],%[^,],%d\n", tempSong.title, tempSong.artist, tempSong.genre, &tempSong.year);
        addSong(tempSong);
    }
    printf("Music library loaded successfully!\n");
    fclose(fp);
}

void saveMusicLibrary() {
    FILE *fp = fopen("musicLibrary.txt", "w");
    if(fp == NULL) {
        printf("Failed to open file!\n");
        return;
    }
    Node *traverse = head;
    while(traverse != NULL) {
        fprintf(fp, "%s,%s,%s,%d\n", traverse->data.title, traverse->data.artist, traverse->data.genre, traverse->data.year);
        traverse = traverse->next;
    }
    printf("Music library saved successfully!\n");
    fclose(fp);
}

void searchByTitle(char *searchTerm) {
    Node *traverse = head;
    int found = 0;
    while(traverse != NULL) {
        if(strcmp(traverse->data.title, searchTerm) == 0) {
            printf("%-30s%-30s%-20s%-10s\n", "Title", "Artist", "Genre", "Year");
            printf("%-30s%-30s%-20s%-10d\n", traverse->data.title, traverse->data.artist, traverse->data.genre, traverse->data.year);
            found = 1;
            break;
        }
        traverse = traverse->next;
    }
    if(!found) {
        printf("Song with title '%s' not found.\n", searchTerm);
    }
}

void searchByArtist(char *searchTerm) {
    Node *traverse = head;
    int found = 0;
    while(traverse != NULL) {
        if(strcmp(traverse->data.artist, searchTerm) == 0) {
            printf("%-30s%-30s%-20s%-10s\n", "Title", "Artist", "Genre", "Year");
            printf("%-30s%-30s%-20s%-10d\n", traverse->data.title, traverse->data.artist, traverse->data.genre, traverse->data.year);
            found = 1;
        }
        traverse = traverse->next;
    }
    if(!found) {
        printf("Songs by artist '%s' not found.\n", searchTerm);
    }
}

void searchByGenre(char *searchTerm) {
    Node *traverse = head;
    int found = 0;
    while(traverse != NULL) {
        if(strcmp(traverse->data.genre, searchTerm) == 0) {
            printf("%-30s%-30s%-20s%-10s\n", "Title", "Artist", "Genre", "Year");
            printf("%-30s%-30s%-20s%-10d\n", traverse->data.title, traverse->data.artist, traverse->data.genre, traverse->data.year);
            found = 1;
        }
        traverse = traverse->next;
    }
    if(!found) {
        printf("Songs in genre '%s' not found.\n", searchTerm);
    }
}

void deleteSong(char *searchTerm) {
    Node *traverse = head;
    Node *previousNode = NULL;
    int found = 0;
    while(traverse != NULL) {
        if(strcmp(traverse->data.title, searchTerm) == 0) {
            printf("Song '%s' deleted successfully!\n", searchTerm);
            if(previousNode == NULL) {
                head = traverse->next;
            } else {
                previousNode->next = traverse->next;
            }
            free(traverse);
            found = 1;
            break;
        }
        previousNode = traverse;
        traverse = traverse->next;
    }
    if(!found) {
        printf("Song with title '%s' not found.\n", searchTerm);
    }
}

int main() {
    int choice = 0;
    while(1) {
        printf("\n*** C MUSIC LIBRARY MANAGEMENT SYSTEM ***\n");
        printf("1. Add Song\n");
        printf("2. Display all songs\n");
        printf("3. Load Music Library from file\n");
        printf("4. Save Music Library to file\n");
        printf("5. Search for song by title\n");
        printf("6. Search for song by artist\n");
        printf("7. Search for song by genre\n");
        printf("8. Delete song\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                Song newSong;
                printf("Enter song title: ");
                scanf(" %[^\n]s", newSong.title);
                printf("Enter song artist: ");
                scanf(" %[^\n]s", newSong.artist);
                printf("Enter song genre: ");
                scanf(" %[^\n]s", newSong.genre);
                printf("Enter year of release: ");
                scanf("%d", &newSong.year);
                addSong(newSong);
                printf("Song added successfully!\n");
                break;
            }
            case 2: {
                display();
                break;
            }
            case 3: {
                loadMusicLibrary();
                break;
            }
            case 4: {
                saveMusicLibrary();
                break;
            }
            case 5: {
                char searchTerm[50];
                printf("Enter song title to search: ");
                scanf(" %[^\n]s", searchTerm);
                searchByTitle(searchTerm);
                break;
            }
            case 6: {
                char searchTerm[50];
                printf("Enter artist name to search: ");
                scanf(" %[^\n]s", searchTerm);
                searchByArtist(searchTerm);
                break;
            }
            case 7: {
                char searchTerm[50];
                printf("Enter genre to search: ");
                scanf(" %[^\n]s", searchTerm);
                searchByGenre(searchTerm);
                break;
            }
            case 8: {
                char searchTerm[50];
                printf("Enter song title to delete: ");
                scanf(" %[^\n]s", searchTerm);
                deleteSong(searchTerm);
                break;
            }
            case 9: {
                exit(0);
            }
            default: {
                printf("Invalid choice! Please try again.\n");
            }
        }
    }
    return 0;
}