//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    int rating;
};

void print_menu() {
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("1. Add a Movie\n");
    printf("2. Delete a Movie\n");
    printf("3. Rate a Movie\n");
    printf("4. View Highest Rated Movie\n");
    printf("5. View Lowest Rated Movie\n");
    printf("6. View Average Movie Rating\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void add_movie(struct Movie database[], int *movie_count) {
    printf("Enter the title of the movie: ");
    char title[50];
    scanf("%s", title);
    for (int i = 0; i < *movie_count; i++) {
        if (strcmp(database[i].title, title) == 0) {
            printf("Movie already exists in database.\n");
            return;
        }
    }
    if (*movie_count < 50) {
        strncpy(database[*movie_count].title, title, sizeof(database[*movie_count].title));
        printf("Movie added successfully.\n");
        (*movie_count)++;
    } else {
        printf("Database full. Cannot add new movie.\n");
    }
}

void delete_movie(struct Movie database[], int *movie_count) {
    printf("Enter the title of the movie to delete: ");
    char title[50];
    scanf("%s", title);
    int delete_index = -1;
    for (int i = 0; i < *movie_count; i++) {
        if (strcmp(database[i].title, title) == 0) {
            delete_index = i;
            break;
        }
    }
    if (delete_index == -1) {
        printf("Movie not found in database.\n");
    } else {
        for (int i = delete_index; i < *movie_count - 1; i++) {
            database[i] = database[i+1];
        }
        (*movie_count)--;
        printf("Movie deleted successfully.\n");
    }
}

void rate_movie(struct Movie database[], int movie_count) {
    printf("Enter the title of the movie to rate: ");
    char title[50];
    scanf("%s", title);
    int rating;
    printf("Enter the rating (1-10): ");
    scanf("%d", &rating);
    int found = 0;
    for (int i = 0; i < movie_count; i++) {
        if (strcmp(database[i].title, title) == 0) {
            database[i].rating = rating;
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Rating added successfully.\n");
    } else {
        printf("Movie not found in database.\n");
    }
}

void view_highest(struct Movie database[], int movie_count) {
    int max_rating = -1;
    char max_title[50];
    for (int i = 0; i < movie_count; i++) {
        if (database[i].rating > max_rating) {
            max_rating = database[i].rating;
            strncpy(max_title, database[i].title, sizeof(max_title));
        }
    }
    if (max_rating == -1) {
        printf("No movies in database.\n");
    } else {
        printf("The highest rated movie is %s with a rating of %d.\n", max_title, max_rating);
    }
}

void view_lowest(struct Movie database[], int movie_count) {
    int min_rating = 11;
    char min_title[50];
    for (int i = 0; i < movie_count; i++) {
        if (database[i].rating < min_rating) {
            min_rating = database[i].rating;
            strncpy(min_title, database[i].title, sizeof(min_title));
        }
    }
    if (min_rating == 11) {
        printf("No movies in database.\n");
    } else {
        printf("The lowest rated movie is %s with a rating of %d.\n", min_title, min_rating);
    }
}

void view_average(struct Movie database[], int movie_count) {
    if (movie_count == 0) {
        printf("No movies in database.\n");
    } else {
        int total_rating = 0;
        for (int i = 0; i < movie_count; i++) {
            total_rating += database[i].rating;
        }
        float average_rating = (float) total_rating / movie_count;
        printf("The average movie rating is %.2f.\n", average_rating);
    }
}

int main() {
    struct Movie database[50];
    int movie_count = 0;
    int choice = -1;
    while (choice != 0) {
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_movie(database, &movie_count);
                break;
            case 2:
                delete_movie(database, &movie_count);
                break;
            case 3:
                rate_movie(database, movie_count);
                break;
            case 4:
                view_highest(database, movie_count);
                break;
            case 5:
                view_lowest(database, movie_count);
                break;
            case 6:
                view_average(database, movie_count);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}