//FormAI DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[50];
    char artist[50];
    int year;
    float duration;
};

struct Node {
    struct Song song;
    struct Node* next;
};

struct Library {
    struct Node* head;
    int size;
};

void addSong(struct Library* library, struct Song song) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->song = song;
    newNode->next = NULL;
    
    if (library->head == NULL) {
        library->head = newNode;
    } else {
        struct Node* current = library->head;
        
        while (current->next != NULL) {
            current = current->next;
        }
        
        current->next = newNode;
    }
    
    library->size++;
}

void displaySong(struct Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Year: %d\n", song.year);
    printf("Duration: %.2f\n", song.duration);
}

void displayLibrary(struct Library library) {
    if (library.size == 0) {
        printf("The library is empty.\n");
    } else {
        struct Node* current = library.head;
        
        while (current != NULL) {
            displaySong(current->song);
            printf("\n");
            current = current->next;
        }
    }
}

void deleteSong(struct Library* library, char title[]) {
    if (library->size == 0) {
        printf("The library is already empty.\n");
    } else {
        struct Node* current = library->head;
        struct Node* previous = NULL;
        
        while (current != NULL) {
            if (strcmp(current->song.title, title) == 0) {
                if (previous == NULL) {
                    library->head = current->next;
                } else {
                    previous->next = current->next;
                }
                
                free(current);
                library->size--;
                return;
            }
            
            previous = current;
            current = current->next;
        }
        
        printf("The song does not exist in the library.\n");
    }
}

int main() {
    struct Library library;
    library.head = NULL;
    library.size = 0;
    
    printf("Welcome to the Music Library Management System!\n");
    printf("Type 'add' to add a song, 'display' to display the library, 'delete' to delete a song, or 'exit' to quit.\n");
    
    char input[10];
    
    while (strcmp(input, "exit") != 0) {
        printf("> ");
        scanf("%s", input);
        
        if (strcmp(input, "add") == 0) {
            struct Song song;
            printf("Title: ");
            scanf("%s", song.title);
            printf("Artist: ");
            scanf("%s", song.artist);
            printf("Year: ");
            scanf("%d", &song.year);
            printf("Duration: ");
            scanf("%f", &song.duration);
            
            addSong(&library, song);
            printf("Song added successfully!\n");
        } else if (strcmp(input, "display") == 0) {
            displayLibrary(library);
        } else if (strcmp(input, "delete") == 0) {
            printf("Title: ");
            char title[50];
            scanf("%s", title);
            
            deleteSong(&library, title);
            printf("Song deleted successfully!\n");
        }
    }
    
    printf("Thank you for using the Music Library Management System!\n");
    
    return 0;
}