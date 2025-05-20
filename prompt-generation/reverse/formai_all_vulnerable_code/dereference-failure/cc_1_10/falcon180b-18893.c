//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
struct node {
    char song_name[MAX_SIZE];
    struct node* next;
};

// Function to add a song to the library
void add_song(struct node** head, char* song_name) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->song_name, song_name);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to display all songs in the library
void display_songs(struct node* head) {
    printf("Library:\n");
    while (head!= NULL) {
        printf("%s\n", head->song_name);
        head = head->next;
    }
}

// Function to search for a song in the library
void search_song(struct node* head, char* song_name) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->song_name, song_name) == 0) {
            printf("Song found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Song not found.\n");
}

// Function to delete a song from the library
void delete_song(struct node** head, char* song_name) {
    struct node* temp = *head;
    struct node* prev = NULL;

    while (temp!= NULL && strcmp(temp->song_name, song_name)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song not found.\n");
    } else {
        if (prev == NULL) {
            *head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Song deleted.\n");
    }
}

int main() {
    struct node* head = NULL;

    // Add songs to the library
    add_song(&head, "Stairway to Heaven");
    add_song(&head, "Bohemian Rhapsody");
    add_song(&head, "Hotel California");

    // Display all songs in the library
    display_songs(head);

    // Search for a song in the library
    search_song(head, "Bohemian Rhapsody");

    // Delete a song from the library
    delete_song(&head, "Stairway to Heaven");

    // Display all songs in the library again
    display_songs(head);

    return 0;
}