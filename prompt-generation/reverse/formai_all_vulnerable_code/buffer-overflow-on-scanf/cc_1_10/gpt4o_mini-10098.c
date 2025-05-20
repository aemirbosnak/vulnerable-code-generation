//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
    char title[100];
    int year;
    float rating;
};

void addMovie(struct Movie *movieList, int *count) {
    printf("Enter movie title: ");
    getchar(); // consume newline from previous input
    fgets(movieList[*count].title, 100, stdin);
    movieList[*count].title[strcspn(movieList[*count].title, "\n")] = 0; // remove newline

    printf("Enter release year: ");
    scanf("%d", &movieList[*count].year);
    
    printf("Enter movie rating (0.0 - 10.0): ");
    scanf("%f", &movieList[*count].rating);
    
    (*count)++;
    printf("Movie added successfully!\n\n");
}

void displayMovies(struct Movie *movieList, int count) {
    printf("Movie List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (%d) - Rating: %.1f\n", i + 1, movieList[i].title, movieList[i].year, movieList[i].rating);
    }
    printf("\n");
}

void averageRating(struct Movie *movieList, int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += movieList[i].rating;
    }
    float avg = (count > 0) ? (sum / count) : 0.0;
    printf("Average Rating: %.1f\n\n", avg);
}

void searchMovie(struct Movie *movieList, int count) {
    char searchTerm[100];
    printf("Enter movie title to search: ");
    getchar(); // consume newline
    fgets(searchTerm, 100, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline

    int found = 0;
    printf("Search Results:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(movieList[i].title, searchTerm) != NULL) {
            printf("%d. %s (%d) - Rating: %.1f\n", i + 1, movieList[i].title, movieList[i].year, movieList[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found matching '%s'.\n", searchTerm);
    }
    printf("\n");
}

void deleteMovie(struct Movie *movieList, int *count) {
    int movieNumber;
    displayMovies(movieList, *count);
    printf("Enter the number of the movie to delete: ");
    scanf("%d", &movieNumber);
    
    if (movieNumber < 1 || movieNumber > *count) {
        printf("Invalid movie number!\n\n");
        return;
    }

    for (int i = movieNumber - 1; i < *count - 1; i++) {
        movieList[i] = movieList[i + 1];
    }
    
    (*count)--;
    printf("Movie deleted successfully!\n\n");
}

void movieMenu() {
    struct Movie movieList[100];
    int count = 0;
    int choice;

    do {
        printf("Movie Rating System Menu:\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Average Rating\n");
        printf("4. Search Movie\n");
        printf("5. Delete Movie\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movieList, &count);
                break;
            case 2:
                displayMovies(movieList, count);
                break;
            case 3:
                averageRating(movieList, count);
                break;
            case 4:
                searchMovie(movieList, count);
                break;
            case 5:
                deleteMovie(movieList, &count);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    } while (choice != 6);
}

int main() {
    movieMenu();
    return 0;
}