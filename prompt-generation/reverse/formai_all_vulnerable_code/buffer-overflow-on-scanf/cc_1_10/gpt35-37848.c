//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing music metadata
struct music_info {
    char title[50];
    char artist[30];
    char album[50];
    int duration;
};

// Structure for storing a music node in a linked list
struct music_node {
    struct music_info data;
    struct music_node *next;
};

// Function to add a new music node to the linked list
void add_node(struct music_node **head, struct music_info data) {
    struct music_node *new_node = (struct music_node*) malloc(sizeof(struct music_node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct music_node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to search for a music node in the linked list
struct music_node* find_node(struct music_node **head, char title[]) {
    struct music_node *temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->data.title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to display all music nodes in the linked list
void display_all(struct music_node **head) {
    struct music_node *temp = *head;
    while (temp != NULL) {
        printf("Title: %s\n", temp->data.title);
        printf("Artist: %s\n", temp->data.artist);
        printf("Album: %s\n", temp->data.album);
        printf("Duration: %d\n\n", temp->data.duration);
        temp = temp->next;
    }
}

int main() {
    struct music_node *head = NULL;
    int option;
    do {
        printf("MENU:\n");
        printf("1. Add music\n");
        printf("2. Find music\n");
        printf("3. Display all music\n");
        printf("4. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        printf("\n");
        
        switch (option) {
            case 1: {
                struct music_info data;
                printf("Enter title: ");
                scanf("%s", data.title);
                printf("Enter artist: ");
                scanf("%s", data.artist);
                printf("Enter album: ");
                scanf("%s", data.album);
                printf("Enter duration (in seconds): ");
                scanf("%d", &data.duration);
                printf("\n");
                
                add_node(&head, data);
                break;
            }
            
            case 2: {
                char title[50];
                printf("Enter title to search for: ");
                scanf("%s", title);
                printf("\n");
                
                struct music_node *result = find_node(&head, title);
                if (result == NULL) {
                    printf("Music not found.\n\n");
                } else {
                    printf("Title: %s\n", result->data.title);
                    printf("Artist: %s\n", result->data.artist);
                    printf("Album: %s\n", result->data.album);
                    printf("Duration: %d\n\n", result->data.duration);
                }
                break;
            }
            
            case 3: {
                display_all(&head);
                break;
            }
            
            case 4: {
                printf("Goodbye!\n");
                break;
            }
            
            default: {
                printf("Invalid option.\n\n");
                break;
            }
        }
    } while (option != 4);
    
    return 0;
}