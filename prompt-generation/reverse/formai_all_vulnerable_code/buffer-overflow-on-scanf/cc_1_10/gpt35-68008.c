//FormAI DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store movie details
struct movie {
    char name[50];
    int rating;
};

// Function to add new movie to the collection
void add_movie(struct movie *coll, int *count) {
    printf("Enter Movie Name: ");
    scanf("%s", coll[*count].name);
    printf("Enter Movie Rating (0 - 10): ");
    scanf("%d", &coll[*count].rating);
    if (coll[*count].rating > 10)
        coll[*count].rating = 10;
    else if (coll[*count].rating < 0)
        coll[*count].rating = 0;
    printf("Movie Added Successfully!\n");
    *count += 1;
}

// Function to display all movies in the collection
void display_movies(struct movie *coll, int count) {
    if (count == 0) {
        printf("No Movies Found!\n");
        return;
    }
    printf("Movie Name\t\tRating\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t\t%d\n", coll[i].name, coll[i].rating);
    }
}

// Function to display top rated movies in the collection
void top_rated_movies(struct movie *coll, int count) {
    if (count == 0) {
        printf("No Movies Found!\n");
        return;
    }
    printf("Top Rated Movies:\n");
    printf("Movie Name\t\tRating\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (coll[i].rating >= 8)
            printf("%s\t\t\t%d\n", coll[i].name, coll[i].rating);
    }
}

// Function to delete a movie from the collection
void delete_movie(struct movie *coll, int *count) {
    if (*count == 0) {
        printf("No Movies Found!\n");
        return;
    }
    char movie_name[50];
    printf("Enter Movie Name: ");
    scanf("%s", movie_name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(movie_name, coll[i].name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                coll[j] = coll[j + 1];
            }
            printf("Movie Deleted Successfully!\n");
            *count -= 1;
            return;
        }
    }
    printf("Movie Not Found!\n");
}

int main() {
    struct movie movie_collection[50];
    int count = 0, choice = 0;
    while (1) {
        printf("\nEnter Your Choice:\n");
        printf("1. Add Movie\n");
        printf("2. Display All Movies\n");
        printf("3. Top Rated Movies\n");
        printf("4. Delete Movie\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_movie(movie_collection, &count);
                break;
            case 2:
                display_movies(movie_collection, count);
                break;
            case 3:
                top_rated_movies(movie_collection, count);
                break;
            case 4:
                delete_movie(movie_collection, &count);
                break;
            case 5:
                printf("Exiting Movie Rating System...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}