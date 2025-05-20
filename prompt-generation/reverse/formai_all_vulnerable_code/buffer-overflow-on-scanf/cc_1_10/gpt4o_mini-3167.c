//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define NAME_LENGTH 100

struct Movie {
    char name[NAME_LENGTH];
    float rating;
    int year;
};

// Function prototypes
void addMovie(struct Movie movies[], int *count);
void displayMovies(const struct Movie movies[], int count);
void sortMovies(struct Movie movies[], int count);
void searchMovie(const struct Movie movies[], int count);
void deleteMovie(struct Movie movies[], int *count);

void clearBuffer() {
    while (getchar() != '\n');
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Sort Movies by Rating\n");
        printf("4. Search for a Movie\n");
        printf("5. Delete a Movie\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                displayMovies(movies, count);
                break;
            case 3:
                sortMovies(movies, count);
                printf("Movies sorted by rating!\n");
                break;
            case 4:
                searchMovie(movies, count);
                break;
            case 5:
                deleteMovie(movies, &count);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}

void addMovie(struct Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full.\n");
        return;
    }

    printf("Enter movie name: ");
    fgets(movies[*count].name, NAME_LENGTH, stdin);
    movies[*count].name[strcspn(movies[*count].name, "\n")] = '\0'; // Remove newline

    printf("Enter rating (0.0 to 10.0): ");
    scanf("%f", &movies[*count].rating);
    clearBuffer(); // Clear buffer

    printf("Enter year of release: ");
    scanf("%d", &movies[*count].year);
    clearBuffer(); // Clear buffer

    (*count)++;
    printf("Movie added successfully!\n");
}

void displayMovies(const struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies added yet.\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Rating: %.1f | Year: %d\n", movies[i].name, movies[i].rating, movies[i].year);
    }
}

void sortMovies(struct Movie movies[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                struct Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

void searchMovie(const struct Movie movies[], int count) {
    char name[NAME_LENGTH];
    printf("Enter movie name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].name, name) == 0) {
            printf("Found: %s | Rating: %.1f | Year: %d\n", movies[i].name, movies[i].rating, movies[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found.\n");
    }
}

void deleteMovie(struct Movie movies[], int *count) {
    char name[NAME_LENGTH];
    printf("Enter movie name to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcasecmp(movies[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*count)--;
            found = 1;
            printf("Movie deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Movie not found for deletion.\n");
    }
}