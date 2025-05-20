//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_REVIEWERS 50

typedef struct {
    char title[100];
    char director[50];
    int length;
    int year;
    float rating;
    int num_reviews;
} Movie;

typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Reviewer;

typedef struct {
    int reviewer_id;
    float rating;
} Review;

Movie movies[MAX_MOVIES];
Reviewer reviewers[MAX_REVIEWERS];
Review reviews[MAX_REVIEWERS][MAX_MOVIES];

int num_movies = 0;
int num_reviewers = 0;

void add_movie() {
    Movie new_movie;
    printf("Enter title: ");
    scanf("%s", new_movie.title);
    printf("Enter director: ");
    scanf("%s", new_movie.director);
    printf("Enter length (in minutes): ");
    scanf("%d", &new_movie.length);
    printf("Enter year: ");
    scanf("%d", &new_movie.year);
    printf("Enter rating (out of 10): ");
    scanf("%f", &new_movie.rating);
    new_movie.num_reviews = 0;
    movies[num_movies] = new_movie;
    num_movies++;
    printf("Movie added successfully!\n");
}

void add_reviewer() {
    Reviewer new_reviewer;
    printf("Enter name: ");
    scanf("%s", new_reviewer.name);
    printf("Enter age: ");
    scanf("%d", &new_reviewer.age);
    printf("Enter occupation: ");
    scanf("%s", new_reviewer.occupation);
    reviewers[num_reviewers] = new_reviewer;
    num_reviewers++;
    printf("Reviewer added successfully!\n");
}

void add_review() {
    int movie_id, reviewer_id;
    float rating;
    printf("Enter movie id: ");
    scanf("%d", &movie_id);
    printf("Enter reviewer id: ");
    scanf("%d", &reviewer_id);
    printf("Enter rating (out of 10): ");
    scanf("%f", &rating);
    Review new_review;
    new_review.reviewer_id = reviewer_id;
    new_review.rating = rating;
    reviews[reviewer_id][movie_id] = new_review;
    movies[movie_id].num_reviews++;
    printf("Review added successfully!\n");
}

void view_movies() {
    printf("***** MOVIES *****\n");
    for (int i = 0; i < num_movies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Length: %d mins\n", movies[i].length);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f/10\n", movies[i].rating);
        printf("Number of reviews: %d\n", movies[i].num_reviews);
        printf("\n");
    }
}

void view_reviewers() {
    printf("***** REVIEWERS *****\n");
    for (int i = 0; i < num_reviewers; i++) {
        printf("Name: %s\n", reviewers[i].name);
        printf("Age: %d\n", reviewers[i].age);
        printf("Occupation: %s\n", reviewers[i].occupation);
        printf("\n");
    }
}

void view_reviews() {
    printf("***** REVIEWS *****\n");
    for (int i = 0; i < num_reviewers; i++) {
        printf("***** %s's Reviews *****\n", reviewers[i].name);
        for (int j = 0; j < num_movies; j++) {
            if (reviews[i][j].reviewer_id != 0) {
                printf("%s: %.1f/10\n", movies[j].title, reviews[i][j].rating);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice = 0;
    while (choice != 5) {
        printf("***** C MOVIE RATING SYSTEM *****\n");
        printf("1. Add Movie\n");
        printf("2. Add Reviewer\n");
        printf("3. Add Review\n");
        printf("4. View Data\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                add_reviewer();
                break;
            case 3:
                add_review();
                break;
            case 4:
                printf("1. View Movies\n");
                printf("2. View Reviewers\n");
                printf("3. View Reviews\n");
                printf("Enter choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        view_movies();
                        break;
                    case 2:
                        view_reviewers();
                        break;
                    case 3:
                        view_reviews();
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}