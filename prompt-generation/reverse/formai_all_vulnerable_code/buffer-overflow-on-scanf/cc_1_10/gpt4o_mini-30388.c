//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_REVIEW_LENGTH 250

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int year;
    float rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

int movie_count = 0;
Movie movie_list[MAX_MOVIES];

void add_movie() {
    if (movie_count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    Movie new_movie;
    
    printf("Enter movie title: ");
    getchar(); 
    fgets(new_movie.title, MAX_TITLE_LENGTH, stdin);
    new_movie.title[strcspn(new_movie.title, "\n")] = '\0'; // Remove newline character
    
    printf("Enter genre: ");
    fgets(new_movie.genre, MAX_GENRE_LENGTH, stdin);
    new_movie.genre[strcspn(new_movie.genre, "\n")] = '\0'; // Remove newline character

    printf("Enter release year: ");
    scanf("%d", &new_movie.year);

    printf("Enter rating (0-10): ");
    scanf("%f", &new_movie.rating);

    printf("Enter review: ");
    getchar(); // To consume the newline character left by scanf
    fgets(new_movie.review, MAX_REVIEW_LENGTH, stdin);
    new_movie.review[strcspn(new_movie.review, "\n")] = '\0'; // Remove newline character

    movie_list[movie_count] = new_movie; // Add new movie to the list
    movie_count++;
    printf("Movie added successfully!\n");
}

void view_movies() {
    if (movie_count == 0) {
        printf("No movies rated yet.\n");
        return;
    }

    printf("\n--- Movie List ---\n");
    for (int i = 0; i < movie_count; i++) {
        printf("%d. %s (%d)\n", i + 1, movie_list[i].title, movie_list[i].year);
        printf("   Genre: %s\n", movie_list[i].genre);
        printf("   Rating: %.1f\n", movie_list[i].rating);
        printf("   Review: %s\n", movie_list[i].review);
        printf("-------------------------\n");
    }
}

void search_movie() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter movie title to search: ");
    getchar(); 
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < movie_count; i++) {
        if (strcasecmp(movie_list[i].title, title) == 0) {
            printf("Found movie: %s (%d)\n", movie_list[i].title, movie_list[i].year);
            printf("Genre: %s\n", movie_list[i].genre);
            printf("Rating: %.1f\n", movie_list[i].rating);
            printf("Review: %s\n", movie_list[i].review);
            return;
        }
    }
    printf("Movie not found.\n");
}

void delete_movie() {
    int index;
    printf("Enter the movie number you want to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > movie_count) {
        printf("Invalid movie number.\n");
        return;
    }

    for (int i = index - 1; i < movie_count - 1; i++) {
        movie_list[i] = movie_list[i + 1]; // Shift movies down
    }
    movie_count--; // Reduce the count
    printf("Movie deleted successfully!\n");
}

void display_menu() {
    printf("\n--- Movie Rating System ---\n");
    printf("1. Add Movie\n");
    printf("2. View Movies\n");
    printf("3. Search Movie\n");
    printf("4. Delete Movie\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main(int argc, char *argv[]) {
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                view_movies();
                break;
            case 3:
                search_movie();
                break;
            case 4:
                delete_movie();
                break;
            case 5:
                printf("Exiting the Movie Rating System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}