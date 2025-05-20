//FormAI DATASET v1.0 Category: Music Library Management System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct song { // A structure to hold information about a song
    char title[100];
    char artist[100];
    char album[100];
    int year;
} Song;

typedef struct node { // A linked list to store the songs
    Song song;
    struct node* next;
} Node;


Node* head = NULL; // Initialize the head node
int song_count = 0; // Keep track of the number of songs in the library

void add_song() {
    Song new_song; // Create a new song instance
    printf("Enter Song title:\n");
    scanf("%s", new_song.title);
    printf("Enter Artist name:\n");
    scanf("%s", new_song.artist);
    printf("Enter Album name:\n");
    scanf("%s", new_song.album);
    printf("Enter Song release year:\n");
    scanf("%d", &new_song.year);

    Node* new_node = (Node*)malloc(sizeof(Node)); // Create a new node to store the song
    new_node->song = new_song;
    new_node->next = NULL;

    if (head == NULL) { // The list is empty
        head = new_node; // Make the new node the head of the list
    } else {
        Node* cur = head;
        while (cur->next != NULL) { // Traverse to the end of the list
            cur = cur->next;
        }
        cur->next = new_node; // Append the new node to the end of the list
    }

    song_count++; // Increment the song count
    printf("Song added successfully!\n\n");
}

void list_songs() {
    Node* cur = head;
    if (cur == NULL) { // The list is empty
        printf("The library is empty!\n");
    } else {
        printf("Song Title\tArtist Name\tAlbum Name\tYear Released\n");
        printf("----------------------------------------------------------\n");

        while (cur != NULL) { // Traverse the list and print out each song
            printf("%s\t%s\t%s\t%d\n", cur->song.title, cur->song.artist, cur->song.album, cur->song.year);
            cur = cur->next;
        }
    }
}

void delete_song() {
    if (head == NULL) { // The list is empty
        printf("The library is empty!\n");
    } else {
        char title[100];
        printf("Enter the title of the song you want to delete:\n");
        scanf("%s", title);

        Node* cur = head;
        Node* prev = NULL;
        while (cur != NULL && strcmp(cur->song.title, title) != 0) { // Traverse the list looking for the song with the specified title
            prev = cur;
            cur = cur->next;
        }

        if (cur == NULL) { // Song not found
            printf("Song not found!\n\n");
        } else {
            if (prev == NULL) { // The song is the head of the list
                head = cur->next; // Make the next node the head of the list
            } else {
                prev->next = cur->next; // Remove the current node from the list
            }
            free(cur); // Free the memory used by the node
            song_count--; // Decrement the song count
            printf("Song deleted successfully!\n\n");
        }
    }
}

int main() {
    int choice;

    while (1) { // Keep looping until the user chooses to exit
        printf("Welcome to the Music Library Management System\n");
        printf("1. Add a song\n");
        printf("2. List all songs\n");
        printf("3. Delete a song\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                list_songs();
                break;
            case 3:
                delete_song();
                break;
            case 4:
                printf("Thank you for using Music Library Management System! Goodbye!\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }

    return 0;
}