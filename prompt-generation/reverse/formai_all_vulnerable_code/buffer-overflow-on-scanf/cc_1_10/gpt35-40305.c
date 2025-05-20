//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    char genre[50];
    struct song *next;
};

struct song *head = NULL;

void add_song() {
    struct song *new_song = (struct song*) malloc(sizeof(struct song));
    printf("Enter Song Title: ");
    scanf("%s", new_song->title);
    printf("Enter Artist Name: ");
    scanf("%s", new_song->artist);
    printf("Enter Album Name: ");
    scanf("%s", new_song->album);
    printf("Enter Year of Release: ");
    scanf("%d", &new_song->year);
    printf("Enter Genre: ");
    scanf("%s", new_song->genre);
    new_song->next = NULL;
    
    if (head == NULL) {
        head = new_song;
    } else {
        struct song *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_song;
    }
    printf("Song added successfully!\n");
}

void delete_song(char* title) {
    if (head == NULL) {
        printf("The Music Library is currently empty!\n");
        return;
    }
    struct song *current = head;
    struct song *previous = NULL;
    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Song not found in the Music Library!\n");
        return;
    }
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    printf("Song deleted successfully!\n");
}

void search_song(char* title) {
    if (head == NULL) {
        printf("The Music Library is currently empty!\n");
        return;
    }
    struct song *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("Song Title: %s\n", temp->title);
            printf("Artist Name: %s\n", temp->artist);
            printf("Album Name: %s\n", temp->album);
            printf("Year of Release: %d\n", temp->year);
            printf("Genre: %s\n", temp->genre);
            return;
        }
        temp = temp->next;
    }
    printf("Song not found in the Music Library!\n");
}

void display_all() {
    if (head == NULL) {
        printf("The Music Library is currently empty!\n");
        return;
    }
    struct song *temp = head;
    while (temp != NULL) {
        printf("Song Title: %s\n", temp->title);
        printf("Artist Name: %s\n", temp->artist);
        printf("Album Name: %s\n", temp->album);
        printf("Year of Release: %d\n", temp->year);
        printf("Genre: %s\n", temp->genre);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char title[50];
    while (1) {
        printf("\nMusic Library Management System\n");
        printf("================================\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Search Song\n");
        printf("4. Display All Songs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                printf("Enter Song Title: ");
                scanf("%s", title);
                delete_song(title);
                break;
            case 3:
                printf("Enter Song Title: ");
                scanf("%s", title);
                search_song(title);
                break;
            case 4:
                display_all();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}