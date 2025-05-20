//FormAI DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

void addMovie(Movie movies[], int *count) {
    char title[50], director[50];
    int year;
    float rating;

    printf("Enter movie title: ");
    scanf(" %[^\n]s", title);

    printf("Enter director's name: ");
    scanf(" %[^\n]s", director);

    printf("Enter the year of release: ");
    scanf("%d", &year);

    printf("Enter the movie rating (out of 10): ");
    scanf("%f", &rating);

    strcpy(movies[*count].title, title);
    strcpy(movies[*count].director, director);
    movies[*count].year = year;
    movies[*count].rating = rating;

    printf("Movie added successfully!\n");
    (*count)++;
}

void displayMovies(Movie movies[], int count) {
    printf("\nTitle\t\tDirector\tYear of Release\t\tRating\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t%s\t\t%d\t\t\t%.1f/10\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }
}

void searchByTitle(Movie movies[], int count) {
    char title[50];
    printf("Enter the title to search for: ");
    scanf(" %[^\n]s", title);

    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            printf("\nTitle\t\tDirector\tYear of Release\t\tRating\n");
            printf("%s\t%s\t\t%d\t\t\t%.1f/10\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Movie with title %s not found!\n", title);
    }
}

void searchByDirector(Movie movies[], int count) {
    char director[50];
    printf("Enter the director's name to search for: ");
    scanf(" %[^\n]s", director);

    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(movies[i].director, director) == 0) {
            printf("\nTitle\t\tDirector\tYear of Release\t\tRating\n");
            printf("%s\t%s\t\t%d\t\t\t%.1f/10\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
            found = 1;
        }
    }

    if(!found) {
        printf("Movie directed by %s not found!\n", director);
    }
}

void editMovie(Movie movies[], int count) {
    char title[50];
    printf("Enter the title of the movie you want to edit: ");
    scanf(" %[^\n]s", title);

    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            char director[50];
            int year;
            float rating;

            printf("\nEnter new director's name (or enter '-' to skip): ");
            scanf(" %[^\n]s", director);
            
            printf("Enter new year of release (or enter 0 to skip): ");
            scanf("%d", &year);

            printf("Enter new movie rating (out of 10) (or enter 0.0 to skip): ");
            scanf("%f", &rating);

            if(strcmp(director, "-") != 0) {
                strcpy(movies[i].director, director);
            }

            if(year != 0) {
                movies[i].year = year;
            }

            if(rating != 0.0) {
                movies[i].rating = rating;
            }

            printf("Movie details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Movie with title %s not found!\n", title);
    }
}

int main() {
    Movie movies[50];
    int count = 0, choice;

    do {
        printf("\n***** C MOVIE RATING SYSTEM *****\n");
        printf("1. Add movie\n");
        printf("2. Display all movies\n");
        printf("3. Search by title\n");
        printf("4. Search by director\n");
        printf("5. Edit movie\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMovie(movies, &count);
                break;

            case 2:
                if(count == 0) {
                    printf("No movies to display!\n");
                }
                else {
                    displayMovies(movies, count);
                }
                break;

            case 3:
                if(count == 0) {
                    printf("No movies to search!\n");
                }
                else {
                    searchByTitle(movies, count);
                }
                break;

            case 4:
                if(count == 0) {
                    printf("No movies to search!\n");
                }
                else {
                    searchByDirector(movies, count);
                }
                break;

            case 5:
                if(count == 0) {
                    printf("No movies to edit!\n");
                }
                else {
                    editMovie(movies, count);
                }
                break;

            case 6:
                printf("Thank you for using the C Movie Rating System.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 6);

    return 0;
}