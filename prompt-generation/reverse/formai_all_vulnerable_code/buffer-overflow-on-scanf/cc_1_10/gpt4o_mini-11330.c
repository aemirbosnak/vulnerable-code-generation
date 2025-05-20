//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float rating;
    char review[200];
} MovieRating;

void displayMovieRatings(MovieRating *movies, int count) {
    printf("\nList of Movies and their Ratings:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. '%s', a fair star's discretion: %.2f/10\n", i + 1, movies[i].name, movies[i].rating);
        printf("   Review: %s\n\n", movies[i].review);
    }
}

void addNewRating(MovieRating *movies, int *count) {
    if (*count < 100) {
        printf("Speak thy title, fair movie: ");
        scanf(" %[^\n]", movies[*count].name);
        printf("What wisdom dost thou bestow on it? (0.0 - 10.0): ");
        scanf("%f", &movies[*count].rating);
        printf("Give a fair review of thy chosen: ");
        scanf(" %[^\n]", movies[*count].review);

        (*count)++;
        printf("A new rating hath been added.\n");
    } else {
        printf("Alas! The tome hath reached its limits.\n");
    }
}

void editRating(MovieRating *movies, int count) {
    int index;
    printf("Whence dost thou seek to amend? (1 to %d): ", count);
    scanf("%d", &index);

    if (index > 0 && index <= count) {
        index--; // To convert to zero-index
        printf("New rating for '%s' shall be: ", movies[index].name);
        scanf("%f", &movies[index].rating);
        printf("New review for '%s': ", movies[index].name);
        scanf(" %[^\n]", movies[index].review);
        printf("The changes made, a new fate awaits!\n");
    } else {
        printf("What folly hath led thee here? Invalid choice!\n");
    }
}

void deleteRating(MovieRating *movies, int *count) {
    int index;
    printf("Which one shalt thou let go? (1 to %d): ", *count);
    scanf("%d", &index);

    if (index > 0 && index <= *count) {
        index--; // To convert to zero-index
        for (int i = index; i < *count - 1; i++) {
            movies[i] = movies[i + 1];
        }
        (*count)--;
        printf("Gone, but not forgotten. One movie rating hath passed.\n");
    } else {
        printf("What folly hath led thee here? Invalid choice!\n");
    }
}

int main() {
    MovieRating movies[100];
    int count = 0;
    int choice;

    printf("Welcome to the Montague and Capulet Movie Ratings!\n");

    do {
        printf("\nA world of choices, what thou wishest to do:\n");
        printf("1. Add a new movie rating\n");
        printf("2. Edit an existing movie rating\n");
        printf("3. Delete a movie rating\n");
        printf("4. Display all movie ratings\n");
        printf("5. Depart this mortal coil\n");
        printf("Choose thy fate (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewRating(movies, &count);
                break;
            case 2:
                editRating(movies, count);
                break;
            case 3:
                deleteRating(movies, &count);
                break;
            case 4:
                displayMovieRatings(movies, count);
                break;
            case 5:
                printf("Farewell and good night, until our paths cross again!\n");
                break;
            default:
                printf("What a tangled web we weave! Choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}