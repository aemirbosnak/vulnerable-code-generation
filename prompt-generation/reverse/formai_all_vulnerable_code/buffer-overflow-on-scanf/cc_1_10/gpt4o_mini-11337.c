//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char title[MAX_NAME_LENGTH];
    char director[MAX_NAME_LENGTH];
    int year;
    float rating;
} Movie;

typedef struct {
    Movie movies[MAX_MOVIES];
    int count;
} MovieCollection;

void initializeCollection(MovieCollection *collection) {
    collection->count = 0;
}

void addMovie(MovieCollection *collection, const char *title, const char *director, int year, float rating) {
    if (collection->count < MAX_MOVIES) {
        strncpy(collection->movies[collection->count].title, title, MAX_NAME_LENGTH);
        strncpy(collection->movies[collection->count].director, director, MAX_NAME_LENGTH);
        collection->movies[collection->count].year = year;
        collection->movies[collection->count].rating = rating;
        collection->count++;
    } else {
        printf("Unable to add movie. Collection is full.\n");
    }
}

void displayMovies(const MovieCollection *collection) {
    printf("\nMovie Collection:\n");
    for (int i = 0; i < collection->count; i++) {
        printf("Title: %s, Director: %s, Year: %d, Rating: %.1f\n",
               collection->movies[i].title,
               collection->movies[i].director,
               collection->movies[i].year,
               collection->movies[i].rating);
    }
}

void rateMovie(MovieCollection *collection, const char *title, float newRating) {
    for (int i = 0; i < collection->count; i++) {
        if (strcmp(collection->movies[i].title, title) == 0) {
            collection->movies[i].rating = newRating;
            printf("Updated rating for '%s' to %.1f\n", title, newRating);
            return;
        }
    }
    printf("Movie not found for rating.\n");
}

void displayTopRatedMovies(const MovieCollection *collection) {
    printf("\nTop Rated Movies:\n");
    for (int i = 0; i < collection->count; i++) {
        if (collection->movies[i].rating >= 4.0) {
            printf("Title: %s, Rating: %.1f\n", collection->movies[i].title, collection->movies[i].rating);
        }
    }
}

void saveToFile(const MovieCollection *collection, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(collection, sizeof(MovieCollection), 1, file);
    fclose(file);
    printf("Movie collection saved to %s\n", filename);
}

void loadFromFile(MovieCollection *collection, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    fread(collection, sizeof(MovieCollection), 1, file);
    fclose(file);
    printf("Movie collection loaded from %s, %d movies found.\n", filename, collection->count);
}

int main() {
    MovieCollection myCollection;
    initializeCollection(&myCollection);
    
    int choice;
    char title[MAX_NAME_LENGTH], director[MAX_NAME_LENGTH], filename[MAX_NAME_LENGTH];
    int year;
    float rating;

    while (1) {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Rate Movie\n");
        printf("4. Display Top Rated Movies\n");
        printf("5. Save Collection to File\n");
        printf("6. Load Collection from File\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, MAX_NAME_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter director: ");
                fgets(director, MAX_NAME_LENGTH, stdin);
                director[strcspn(director, "\n")] = 0; // Remove newline
                printf("Enter release year: ");
                scanf("%d", &year);
                printf("Enter rating (0-5): ");
                scanf("%f", &rating);
                addMovie(&myCollection, title, director, year, rating);
                break;
            case 2:
                displayMovies(&myCollection);
                break;
            case 3:
                printf("Enter movie title to rate: ");
                fgets(title, MAX_NAME_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter new rating (0-5): ");
                scanf("%f", &rating);
                rateMovie(&myCollection, title, rating);
                break;
            case 4:
                displayTopRatedMovies(&myCollection);
                break;
            case 5:
                printf("Enter filename to save: ");
                fgets(filename, MAX_NAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                saveToFile(&myCollection, filename);
                break;
            case 6:
                printf("Enter filename to load: ");
                fgets(filename, MAX_NAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                loadFromFile(&myCollection, filename);
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}