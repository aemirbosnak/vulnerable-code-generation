//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 100

// Structure to store movie information
typedef struct {
    char name[MAX_NAME_LENGTH];
    float rating;
    char genre[MAX_NAME_LENGTH];
    int year;
} Movie;

// Function prototypes
void addMovie(Movie movies[], int *count);
void viewMovies(const Movie movies[], int count);
void findHighestRated(const Movie movies[], int count);
void searchByGenre(const Movie movies[], int count);
void sortMovies(Movie movies[], int count);
void printMenu();

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                viewMovies(movies, count);
                break;
            case 3:
                findHighestRated(movies, count);
                break;
            case 4:
                searchByGenre(movies, count);
                break;
            case 5:
                sortMovies(movies, count);
                printf("Movies sorted by rating.\n");
                break;
            case 6:
                printf("Exiting the Movie Rating System.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void printMenu() {
    printf("\n***** Movie Rating System *****\n");
    printf("1. Add a Movie\n");
    printf("2. View All Movies\n");
    printf("3. Find Highest Rated Movie\n");
    printf("4. Search Movies by Genre\n");
    printf("5. Sort Movies by Rating\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Cannot add more movies. Limit reached.\n");
        return;
    }

    printf("Enter movie name: ");
    getchar(); // Clear input buffer
    fgets(movies[*count].name, MAX_NAME_LENGTH, stdin);
    strtok(movies[*count].name, "\n"); // Remove newline character

    printf("Enter movie rating (0.0 - 10.0): ");
    scanf("%f", &movies[*count].rating);

    printf("Enter movie genre: ");
    getchar(); // Clear input buffer
    fgets(movies[*count].genre, MAX_NAME_LENGTH, stdin);
    strtok(movies[*count].genre, "\n"); // Remove newline character

    printf("Enter release year: ");
    scanf("%d", &movies[*count].year);

    (*count)++;
    printf("Movie '%s' added successfully!\n", movies[*count - 1].name);
}

void viewMovies(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies added yet.\n");
        return;
    }

    printf("\nList of Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Rating: %.1f, Genre: %s, Year: %d)\n", 
               i + 1, movies[i].name, movies[i].rating, movies[i].genre, movies[i].year);
    }
}

void findHighestRated(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to evaluate.\n");
        return;
    }

    float highestRating = 0.0;
    int highestIndex = -1;

    for (int i = 0; i < count; i++) {
        if (movies[i].rating > highestRating) {
            highestRating = movies[i].rating;
            highestIndex = i;
        }
    }

    printf("Highest Rated Movie: %s (Rating: %.1f, Genre: %s, Year: %d)\n",
           movies[highestIndex].name, movies[highestIndex].rating, movies[highestIndex].genre, movies[highestIndex].year);
}

void searchByGenre(const Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to search.\n");
        return;
    }

    char genre[MAX_NAME_LENGTH];
    printf("Enter genre to search: ");
    getchar(); // Clear input buffer
    fgets(genre, MAX_NAME_LENGTH, stdin);
    strtok(genre, "\n"); // Remove newline character

    printf("Movies in genre '%s':\n", genre);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("%s (Rating: %.1f, Year: %d)\n",
                   movies[i].name, movies[i].rating, movies[i].year);
            found++;
        }
    }
    if (found == 0) {
        printf("No movies found in genre '%s'.\n", genre);
    }
}

void sortMovies(Movie movies[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}