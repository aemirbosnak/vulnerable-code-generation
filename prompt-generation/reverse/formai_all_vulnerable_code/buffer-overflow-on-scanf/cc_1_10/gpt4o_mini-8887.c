//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char director[100];
    int year;
    float rating;
} Movie;

typedef struct Node {
    Movie movie;
    struct Node* next;
} Node;

Node* head = NULL;

void addMovie() {
    Node* newMovieNode = (Node*)malloc(sizeof(Node));
    if (newMovieNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    printf("Enter movie title: ");
    getchar(); // To consume newline from previous input
    fgets(newMovieNode->movie.title, sizeof(newMovieNode->movie.title), stdin);
    newMovieNode->movie.title[strcspn(newMovieNode->movie.title, "\n")] = 0; // Remove newline

    printf("Enter movie director: ");
    fgets(newMovieNode->movie.director, sizeof(newMovieNode->movie.director), stdin);
    newMovieNode->movie.director[strcspn(newMovieNode->movie.director, "\n")] = 0; // Remove newline

    printf("Enter release year: ");
    scanf("%d", &newMovieNode->movie.year);

    printf("Enter movie rating (0-10): ");
    scanf("%f", &newMovieNode->movie.rating);

    newMovieNode->next = head;
    head = newMovieNode;

    printf("Movie added successfully!\n");
}

void displayMovies() {
    if (head == NULL) {
        printf("No movies in the database.\n");
        return;
    }
    
    Node* current = head;
    printf("\nList of Movies:\n");
    printf("------------------------\n");
    while (current != NULL) {
        printf("Title: %s\nDirector: %s\nYear: %d\nRating: %.1f\n", current->movie.title, current->movie.director, current->movie.year, current->movie.rating);
        printf("------------------------\n");
        current = current->next;
    }
}

void deleteMovie() {
    if (head == NULL) {
        printf("No movies to delete.\n");
        return;
    }

    char title[100];
    printf("Enter the title of the movie to delete: ");
    getchar(); // To consume newline from previous input
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    Node *current = head, *previous = NULL;

    while (current != NULL && strcmp(current->movie.title, title) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Movie not found.\n");
        return;
    }

    if (previous == NULL) {
        head = current->next; // Delete head
    } else {
        previous->next = current->next; // Bypass the node
    }

    free(current);
    printf("Movie deleted successfully!\n");
}

void freeMemory() {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMovie Rating System\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Delete Movie\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            case 3:
                deleteMovie();
                break;
            case 4:
                freeMemory();
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}