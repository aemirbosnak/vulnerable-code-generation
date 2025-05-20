//FormAI DATASET v1.0 Category: Movie Rating System ; Style: innovative
#include <stdio.h>
#include <string.h>

struct movie {
    char title[100];
    float rating;
};

void add_movie(struct movie *database, int *count) {
    printf("\nEnter movie title: ");
    getchar();
    fgets(database[*count].title, 100, stdin);

    printf("\nEnter movie rating (out of 10): ");
    scanf("%f", &database[*count].rating);

    *count += 1;

    printf("\nMovie added successfully!\n");
}

void show_movies(struct movie *database, int count) {
    printf("\nCurrent Movie Database:\n");

    if (count == 0) {
        printf("\nNo movies available in the database.\n");
    }
    else {
        for (int i = 0; i < count; i++) {
            printf("\n%s\t%.1f/10\n", database[i].title, database[i].rating);
        }
    }
}

void sort_movies(struct movie *database, int count) {
    struct movie temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (database[i].rating < database[j].rating) {
                temp = database[i];
                database[i] = database[j];
                database[j] = temp;
            }
        }
    }

    printf("\nMovies sorted successfully!\n");
}

int main() {
    struct movie database[100];
    int count = 0, choice;

    printf("\nWelcome to Movie Rating System!\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Add a movie\n");
        printf("2. Show all movies\n");
        printf("3. Sort movies by rating\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(database, &count);
                break;

            case 2:
                show_movies(database, count);
                break;

            case 3:
                sort_movies(database, count);
                break;

            case 4:
                printf("\nThank you for using Movie Rating System!\n");
                break;

            default:
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}