//FormAI DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>

// Movie struct declaration
struct movie {
    char title[100];
    int year;
    char genre[50];
    float rating;
};

// Function definition to add a movie to inventory
void add_movie(struct movie m[], int *count) {
    printf("Enter movie title: ");
    scanf("%s", m[*count].title);
    printf("Enter movie year: ");
    scanf("%d", &m[*count].year);
    printf("Enter movie genre: ");
    scanf("%s", m[*count].genre);
    printf("Enter movie rating: ");
    scanf("%f", &m[*count].rating);
    (*count)++;
    printf("Movie added successfully!\n\n");
}

// Function definition to display all movies in inventory
void display_movies(struct movie m[], int count) {
    if(count == 0) {
        printf("No movies in inventory!\n\n");
    } else {
        printf("Movie Title\t\tYear\tGenre\tRating\n");
        printf("---------------------------------------------------------\n");
        for(int i=0; i<count; i++) {
            printf("%s\t\t%d\t%s\t%f\n", m[i].title, m[i].year, m[i].genre, m[i].rating);
        }
        printf("\n");
    }
}

// Function definition to display all movies with a rating above a certain value
void display_movies_above_rating(struct movie m[], int count) {
    printf("Enter rating to filter by: ");
    float rating;
    scanf("%f", &rating);
    printf("Movies with rating above %f:\n", rating);
    printf("Movie Title\t\tYear\tGenre\tRating\n");
    printf("---------------------------------------------------------\n");
    for(int i=0; i<count; i++) {
        if(m[i].rating > rating) {
            printf("%s\t\t%d\t%s\t%f\n", m[i].title, m[i].year, m[i].genre, m[i].rating);
        }
    }
    printf("\n");
}

// Main function to execute program
int main() {
    // Movie inventory
    struct movie movies[100];
    int count = 0;

    // Display options
    int option;
    do {
        printf("What would you like to do?\n");
        printf("1. Add a movie\n");
        printf("2. Display all movies\n");
        printf("3. Display movies above a certain rating\n");
        printf("4. Exit\n");
        printf("Enter option number: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                display_movies(movies, count);
                break;
            case 3:
                display_movies_above_rating(movies, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option!\n\n");
                break;
        }

    } while(option != 4);

    return 0;
}