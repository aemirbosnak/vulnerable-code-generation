//FormAI DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
} Song;

typedef struct Node {
    Song data;
    struct Node* next;
} Node;

Node* head = NULL;
int songCount = 0;

void addSong() {
    Song newSong;
    printf("Enter Title: ");
    scanf(" %[^\n]s", newSong.title);
    printf("Enter Artist: ");
    scanf(" %[^\n]s", newSong.artist);
    printf("Enter Genre: ");
    scanf(" %[^\n]s", newSong.genre);
    printf("Enter Year: ");
    scanf("%d", &newSong.year);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newSong;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    songCount++;
    printf("Song added successfully.\n");
}

void displaySongs() {
    if (head == NULL) {
        printf("No songs found.\n");
    } else {
        printf("Title\t\tArtist\t\tGenre\t\tYear\n");
        printf("-----------------------------------------------------------\n");
        Node* current = head;
        while (current != NULL) {
            printf("%s\t\t%s\t\t%s\t\t%d\n", current->data.title, current->data.artist, current->data.genre, current->data.year);
            current = current->next;
        }
    }
}

void saveSongs(char* fileName) {
    FILE* fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        fprintf(fp, "%s,%s,%s,%d\n", current->data.title, current->data.artist, current->data.genre, current->data.year);
        current = current->next;
    }
    printf("Songs saved to file.\n");
    fclose(fp);
}

void loadSongs(char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    char buffer[256];
    while (fgets(buffer, 256, fp)) {
        Song newSong;
        char* token = strtok(buffer, ",");
        strcpy(newSong.title, token);
        token = strtok(NULL, ",");
        strcpy(newSong.artist, token);
        token = strtok(NULL, ",");
        strcpy(newSong.genre, token);
        token = strtok(NULL, ",");
        newSong.year = atoi(token);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newSong;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        songCount++;
    }
    printf("Songs loaded from file.\n");
    fclose(fp);
}

void deleteSong(char* title) {
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL && strcmp(current->data.title, title) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Song not found.\n");
        return;
    }
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    songCount--;
    printf("Song deleted successfully.\n");
}

int main() {
    int choice;
    char fileName[100];
    do {
        printf("\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Save Songs to File\n");
        printf("4. Load Songs from File\n");
        printf("5. Delete Song\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Exiting program...\n");
                break;
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                printf("Enter file name: ");
                scanf(" %[^\n]s", fileName);
                saveSongs(fileName);
                break;
            case 4:
                printf("Enter file name: ");
                scanf(" %[^\n]s", fileName);
                loadSongs(fileName);
                break;
            case 5: {
                printf("Enter title of song to delete: ");
                char title[100];
                scanf(" %[^\n]s", title);
                deleteSong(title);
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}