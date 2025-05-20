//FormAI DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information for a music album
typedef struct Album {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
    char record_label[100];
} Album;

// Define a struct to hold information for a node in the linked list
typedef struct Node {
    Album album;
    struct Node* next;
} Node;

// Define a struct to hold the head of the linked list
typedef struct List {
    Node* head;
    int length;
} List;

// Function to add a new album to the library
void add_album(List* list) {
    // Allocate memory for a new node
    Node* new_node = (Node*) malloc(sizeof(Node));
    
    // Ask for user input and store it in new_node
    printf("Enter the album title: ");
    scanf(" %[^\n]", new_node->album.title);
    printf("Enter the artist name: ");
    scanf(" %[^\n]", new_node->album.artist);
    printf("Enter the genre: ");
    scanf(" %[^\n]", new_node->album.genre);
    printf("Enter the year of release: ");
    scanf("%d", &new_node->album.year);
    printf("Enter the record label: ");
    scanf(" %[^\n]", new_node->album.record_label);
    
    // Add the new_node to the beginning of the list
    new_node->next = list->head;
    list->head = new_node;
    list->length++;
    
    printf("\nAlbum added successfully!\n\n");
}

// Function to display all the albums in the library
void display_albums(List* list) {
    // Check if the list is empty
    if(list->length == 0) {
        printf("No albums in the library.\n\n");
        return;
    }
    
    printf("All albums in the library:\n\n");
    
    // Loop through each node in the list and print its contents
    Node* current = list->head;
    while(current != NULL) {
        printf("Title: %s\n", current->album.title);
        printf("Artist: %s\n", current->album.artist);
        printf("Genre: %s\n", current->album.genre);
        printf("Year of release: %d\n", current->album.year);
        printf("Record label: %s\n\n", current->album.record_label);
        current = current->next;
    }
}

// Function to search for an album in the library
void search_album(List* list) {
    // Check if the list is empty
    if(list->length == 0) {
        printf("No albums in the library.\n\n");
        return;
    }
    
    // Ask for user input and search for a matching album
    char search_term[100];
    printf("Enter the album title or artist name to search: ");
    scanf(" %[^\n]", search_term);
    
    Node* current = list->head;
    int found = 0;
    while(current != NULL) {
        if(strcmp(current->album.title, search_term) == 0 
           || strcmp(current->album.artist, search_term) == 0) {
            printf("Album found:\n\n");
            printf("Title: %s\n", current->album.title);
            printf("Artist: %s\n", current->album.artist);
            printf("Genre: %s\n", current->album.genre);
            printf("Year of release: %d\n", current->album.year);
            printf("Record label: %s\n\n", current->album.record_label);
            found = 1;
            break;
        }
        current = current->next;
    }
    
    if(found == 0) {
        printf("Album not found.\n\n");
    }
}

int main() {
    List* music_library = (List*) malloc(sizeof(List));
    music_library->head = NULL;
    music_library->length = 0;
    
    // Display menu and perform user-selected action
    int choice = 0;
    while(choice != 4) {
        printf("Menu:\n");
        printf("1. Add a new album\n");
        printf("2. Display all albums\n");
        printf("3. Search for an album\n");
        printf("4. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_album(music_library);
                break;
            case 2:
                display_albums(music_library);
                break;
            case 3:
                search_album(music_library);
                break;
            case 4:
                printf("Exiting music library management system.\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
    
    return 0;
}