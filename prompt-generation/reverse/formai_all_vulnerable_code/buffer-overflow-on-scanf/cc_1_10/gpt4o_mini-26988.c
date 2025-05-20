//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char director[100];
    int year;
    float rating; // From 0.0 to 10.0
} Movie;

typedef struct Node {
    Movie movie;
    struct Node *next;
} Node;

Node *head = NULL;

void add_movie(const char *title, const char *director, int year, float rating) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strncpy(new_node->movie.title, title, sizeof(new_node->movie.title));
    strncpy(new_node->movie.director, director, sizeof(new_node->movie.director));
    new_node->movie.year = year;
    new_node->movie.rating = rating;
    new_node->next = head;
    head = new_node;
    printf("Movie added: %s\n", title);
}

void display_movies() {
    Node *current = head;
    if (current == NULL) {
        printf("No movies to display.\n");
        return;
    }
    printf("\n--- Movie List ---\n");
    while (current) {
        printf("Title: %s | Director: %s | Year: %d | Rating: %.1f\n", 
            current->movie.title, 
            current->movie.director, 
            current->movie.year, 
            current->movie.rating);
        current = current->next;
    }
}

void search_movie(const char *title) {
    Node *current = head;
    while (current) {
        if (strcasecmp(current->movie.title, title) == 0) {
            printf("\nFound Movie!\n");
            printf("Title: %s | Director: %s | Year: %d | Rating: %.1f\n", 
                current->movie.title, 
                current->movie.director, 
                current->movie.year, 
                current->movie.rating);
            return;
        }
        current = current->next;
    }
    printf("Movie not found: %s\n", title);
}

void delete_movie(const char *title) {
    Node *current = head;
    Node *previous = NULL;

    while (current) {
        if (strcasecmp(current->movie.title, title) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            printf("Movie deleted: %s\n", title);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Movie not found for deletion: %s\n", title);
}

void free_memory() {
    Node *current = head;
    Node *next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int choice;
    char title[100], director[100];
    int year;
    float rating;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Movie Title: ");
                scanf(" %[^\n]", title);
                printf("Enter Director: ");
                scanf(" %[^\n]", director);
                printf("Enter Year: ");
                scanf("%d", &year);
                printf("Enter Rating (0.0 to 10.0): ");
                scanf("%f", &rating);
                if (rating < 0.0 || rating > 10.0) {
                    printf("Invalid rating! Must be between 0.0 to 10.0.\n");
                } else {
                    add_movie(title, director, year, rating);
                }
                break;

            case 2:
                display_movies();
                break;

            case 3:
                printf("Enter Movie Title to Search: ");
                scanf(" %[^\n]", title);
                search_movie(title);
                break;

            case 4:
                printf("Enter Movie Title to Delete: ");
                scanf(" %[^\n]", title);
                delete_movie(title);
                break;

            case 5:
                free_memory();
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}