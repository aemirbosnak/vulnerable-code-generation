//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include<stdio.h>
#include<string.h>

struct rating {
    char movie_title[50];
    char director[50];
    int year;
    float score;
    char genre[50];
};

void add_movie(struct rating movies[], int *num_movies) {
    if(*num_movies >= 10) {
        printf("Sorry, you can only enter up to 10 movies!\n");
        return;
    }
    printf("Enter title of the movie:\n");
    scanf(" %[^\n]s", movies[*num_movies].movie_title);
    printf("Enter name of director:\n");
    scanf(" %[^\n]s", movies[*num_movies].director);
    printf("Enter the year of release:\n");
    scanf("%d", &movies[*num_movies].year);
    printf("Enter the score (out of 10):\n");
    scanf("%f", &movies[*num_movies].score);
    printf("Enter genre of the movie:\n");
    scanf(" %[^\n]s", movies[*num_movies].genre);
    (*num_movies)++;
    printf("Movie added successfully!\n");
}

void rate_movie(struct rating movies[], int num_movies) {
    if(num_movies <= 0) {
        printf("You have not added any movies yet!\n");
        return;
    }
    printf("Enter movie title:\n");
    char movie_title[50];
    scanf(" %[^\n]s", movie_title);
    for(int i=0; i<num_movies; i++) {
        if(strcmp(movies[i].movie_title, movie_title) == 0) {
            printf("Enter new score (out of 10):\n");
            scanf("%f", &movies[i].score);
            printf("Score updated successfully!\n");
            return;
        }
    }
    printf("Movie not found!\n");
}

void display_movies(struct rating movies[], int num_movies) {
    if(num_movies <= 0) {
        printf("You have not added any movies yet!\n");
        return;
    }
    printf("\nMovie Title\t| Director\t| Year\t| Genre\t| Score\n");
    printf("----------------------------------------------------------\n");
    for(int i=0; i<num_movies; i++) {
        printf("%s\t\t| %s\t| %d\t| %s\t| %.1f\n", movies[i].movie_title,
            movies[i].director, movies[i].year, movies[i].genre, movies[i].score);
    }
    printf("----------------------------------------------------------\n");
}

int main() {
    struct rating movies[10];
    int num_movies = 0;
    int choice;
    do {
        printf("\n1. Add movie\n");
        printf("2. Rate movie\n");
        printf("3. Display movies\n");
        printf("4. Quit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                rate_movie(movies, num_movies);
                break;
            case 3:
                display_movies(movies, num_movies);
                break;
            case 4:
                printf("Thank you for using the movie rating system!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}