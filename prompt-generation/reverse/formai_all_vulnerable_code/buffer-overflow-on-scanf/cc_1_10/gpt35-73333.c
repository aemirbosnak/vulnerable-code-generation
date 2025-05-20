//FormAI DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for storing album information
struct album {
    char title[50];
    char artist[30];
    int year;
    char genre[20];
};

// structure for storing node information
struct node {
    struct album data;
    struct node *next;
};

// function to add an album to the library
void add_album(struct node **head_ref, char title[], char artist[], int year, char genre[]) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->data.title, title);
    strcpy(new_node->data.artist, artist);
    new_node->data.year = year;
    strcpy(new_node->data.genre, genre);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("\nAlbum added successfully.\n\n");
}

// function to display the library
void display_library(struct node *head) {
    if(head == NULL) {
        printf("\n\nThere are no albums in the library.\n\n");
        return;
    }
    printf("\n\n--- CURRENT LIBRARY ---\n\n");
    while(head != NULL) {
        printf("Title: %s\n", head->data.title);
        printf("Artist: %s\n", head->data.artist);
        printf("Year: %d\n", head->data.year);
        printf("Genre: %s\n\n", head->data.genre);
        head = head->next;
    }
}

// function to search for an album in the library
void search_album(struct node *head, char title[]) {
    while(head != NULL) {
        if(strcmp(head->data.title, title) == 0) {
            printf("\n\nTitle: %s\n", head->data.title);
            printf("Artist: %s\n", head->data.artist);
            printf("Year: %d\n", head->data.year);
            printf("Genre: %s\n\n", head->data.genre);
            return;
        }
        head = head->next;
    }
    printf("\n\nAlbum not found.\n\n");
}

// function to delete an album from the library
void delete_album(struct node **head_ref, char title[]) {
    struct node *temp = *head_ref, *prev;

    if(temp != NULL && strcmp(temp->data.title, title) == 0) {
        *head_ref = temp->next;
        free(temp);
        printf("\n\nAlbum deleted successfully.\n\n");
        return;
    }
    while(temp != NULL && strcmp(temp->data.title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("\n\nAlbum not found.\n\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("\n\nAlbum deleted successfully.\n\n");
}

// function to generate a menu for the user to select from
int menu() {
    int choice = 0;
    printf("Welcome to the Music Library Management System!\n\n");
    printf("Please select from the following options:\n");
    printf("1. Add an album to the library\n");
    printf("2. Display the entire library\n");
    printf("3. Search for a specific album\n");
    printf("4. Delete an album from the library\n");
    printf("5. Exit the program\n\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    return choice;
}

// main function
int main() {
    struct node *head = NULL;
    int choice;
    char title[50], artist[30], genre[20];
    int year;

    while(1) {
        choice = menu();
        switch(choice) {
            case 1:
                printf("\n\nEnter the following album details:\n");
                printf("Title: ");
                scanf(" %s", title);
                printf("Artist: ");
                scanf(" %s", artist);
                printf("Year: ");
                scanf("%d", &year);
                printf("Genre: ");
                scanf(" %s", genre);

                add_album(&head, title, artist, year, genre);
                break;

            case 2:
                display_library(head);
                break;

            case 3:
                printf("\n\nEnter the title of the album: ");
                scanf(" %s", title);
                search_album(head, title);
                break;

            case 4:
                printf("\n\nEnter the title of the album to delete: ");
                scanf(" %s", title);
                delete_album(&head, title);
                break;

            case 5:
                printf("\n\nExiting the program...\n\n");
                exit(0);
                break;

            default:
                printf("\n\nInvalid choice. Please enter a valid choice (1-5).\n\n");
        }
    }
    return 0;
}