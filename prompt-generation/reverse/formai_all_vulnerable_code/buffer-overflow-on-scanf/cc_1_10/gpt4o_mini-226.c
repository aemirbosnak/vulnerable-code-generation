//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Music {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
} Music;

typedef struct Node {
    Music music;
    struct Node* next;
} Node;

Node* head = NULL;

void addMusic() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Enter Music Title: ");
    getchar();  // to consume the newline character left by previous input
    fgets(newNode->music.title, sizeof(newNode->music.title), stdin);
    newNode->music.title[strcspn(newNode->music.title, "\n")] = 0; // remove trailing newline

    printf("Enter Artist Name: ");
    fgets(newNode->music.artist, sizeof(newNode->music.artist), stdin);
    newNode->music.artist[strcspn(newNode->music.artist, "\n")] = 0;

    printf("Enter Genre: ");
    fgets(newNode->music.genre, sizeof(newNode->music.genre), stdin);
    newNode->music.genre[strcspn(newNode->music.genre, "\n")] = 0;

    printf("Enter Release Year: ");
    scanf("%d", &newNode->music.year);

    newNode->next = head;
    head = newNode;

    printf("Music Added Successfully!\n");
}

void displayMusic() {
    Node* tmp = head;
    if (tmp == NULL) {
        printf("No music available.\n");
        return;
    }
    
    printf("\n--- Music Library ---\n");
    while (tmp != NULL) {
        printf("Title: %s\n", tmp->music.title);
        printf("Artist: %s\n", tmp->music.artist);
        printf("Genre: %s\n", tmp->music.genre);
        printf("Year: %d\n", tmp->music.year);
        printf("---------------------\n");
        tmp = tmp->next;
    }
}

void searchMusic() {
    char searchTitle[100];
    printf("Enter Music Title to Search: ");
    getchar();  // to consume the newline character
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // remove trailing newline
    
    Node* tmp = head;
    int found = 0;
    
    while (tmp != NULL) {
        if (strcasecmp(tmp->music.title, searchTitle) == 0) {
            printf("Found:\n");
            printf("Title: %s\n", tmp->music.title);
            printf("Artist: %s\n", tmp->music.artist);
            printf("Genre: %s\n", tmp->music.genre);
            printf("Year: %d\n", tmp->music.year);
            found = 1;
            break;
        }
        tmp = tmp->next;
    }
    
    if (!found) {
        printf("Music titled '%s' not found in the library.\n", searchTitle);
    }
}

void deleteMusic() {
    char deleteTitle[100];
    printf("Enter Music Title to Delete: ");
    getchar();  // to consume the newline character
    fgets(deleteTitle, sizeof(deleteTitle), stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0; // remove trailing newline

    Node *current = head, *previous = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcasecmp(current->music.title, deleteTitle) == 0) {
            if (previous == NULL) {
                head = current->next; // Deleting the head
            } else {
                previous->next = current->next; // Bypassing the current
            }
            free(current);
            found = 1;
            printf("Music titled '%s' has been deleted.\n", deleteTitle);
            break;
        }
        previous = current;
        current = current->next;
    }

    if (!found) {
        printf("Music titled '%s' not found in the library.\n", deleteTitle);
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Music\n");
        printf("2. Display All Music\n");
        printf("3. Search Music\n");
        printf("4. Delete Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                displayMusic();
                break;
            case 3:
                searchMusic();
                break;
            case 4:
                deleteMusic();
                break;
            case 5:
                printf("Exiting the Music Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}