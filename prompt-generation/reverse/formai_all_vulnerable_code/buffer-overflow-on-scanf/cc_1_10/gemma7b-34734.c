//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct MovieRating {
    char title[256];
    int year;
    float rating;
    struct MovieRating* next;
};

void addMovie(struct MovieRating** head) {
    struct MovieRating* newMovie = (struct MovieRating*)malloc(sizeof(struct MovieRating));
    printf("Enter movie title: ");
    scanf("%s", newMovie->title);
    printf("Enter movie year: ");
    scanf("%d", &newMovie->year);
    printf("Enter movie rating: ");
    scanf("%f", &newMovie->rating);

    if (*head == NULL) {
        *head = newMovie;
    } else {
        (*head)->next = newMovie;
    }
    *head = newMovie;
}

void printRatings(struct MovieRating* head) {
    while (head) {
        printf("%s (%d) - %.1f stars\n", head->title, head->year, head->rating);
        head = head->next;
    }
}

int main() {
    struct MovieRating* head = NULL;

    char choice;

    while (1) {
        printf("Enter 'a' to add a movie, 'p' to print ratings, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                addMovie(&head);
                break;
            case 'p':
                printRatings(head);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}