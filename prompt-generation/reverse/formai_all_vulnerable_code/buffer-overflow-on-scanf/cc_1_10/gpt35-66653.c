//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold details of music
struct Music {
    char name[30];
    char artist[30];
    char genre[20];
    int year;
};

// Structure for node
struct Node {
    struct Music musicData;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(struct Music data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->musicData = data;
    newNode->next = NULL;
    return newNode;
}

// Function to search for a particular song
struct Node* searchMusic(struct Node* head, char* searchName) {
    struct Node* current = head;
    while(current != NULL) {
        if(strcmp(current->musicData.name, searchName) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {

    struct Node* head = NULL;
    int n;
    printf("Enter the number of songs: ");
    scanf("%d", &n);

    // Reading details of the songs
    for(int i=1; i<=n; i++) {
        struct Music newMusic;
        printf("\nSong-%d Details:\n", i);
        printf("Name: ");
        scanf(" %[^\n]s", newMusic.name);
        printf("Artist: ");
        scanf(" %[^\n]s", newMusic.artist);
        printf("Genre: ");
        scanf("%s", newMusic.genre);
        printf("Year: ");
        scanf("%d", &newMusic.year);
        struct Node* currentNode = createNode(newMusic);
        if(head == NULL) {
            head = currentNode;
        }
        else {
            currentNode->next = head;
            head = currentNode;
        }
    }

    // Searching for a particular song
    char searchName[30];
    printf("\nEnter the song name to be searched: ");
    scanf(" %[^\n]s", searchName);
    struct Node* result = searchMusic(head, searchName);

    if(result == NULL) {
        printf("\nSong not found.\n");
    }
    else {
        printf("\nSearch Result:\n");
        printf("Name: %s\n", result->musicData.name);
        printf("Artist: %s\n", result->musicData.artist);
        printf("Genre: %s\n", result->musicData.genre);
        printf("Year: %d\n", result->musicData.year);
    }

    return 0;
}