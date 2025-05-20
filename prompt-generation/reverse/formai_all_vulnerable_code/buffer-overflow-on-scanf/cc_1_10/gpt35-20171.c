//FormAI DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    int year;
    int rating;
};

int main() {

    struct movie m1;
    printf("Enter the movie title: ");
    scanf("%[^\n]%*c", m1.title);

    printf("Enter the year the movie was released: ");
    scanf("%d", &m1.year);

    printf("Enter your rating for the movie (out of 10): ");
    scanf("%d", &m1.rating);

    // Open the file
    FILE *fptr;
    if ((fptr = fopen("movie_ratings.txt", "a")) == NULL) {
        printf("Error! Could not open file.\n");
        exit(1);
    }

    // Write to the file
    fprintf(fptr, "%s\t%d\t%d\n", m1.title, m1.year, m1.rating);
    printf("\nThank you for rating this movie!\n");

    // Close the file
    fclose(fptr);

    // Let's read the file and print out the ratings...
    // Re-open the file
    if ((fptr = fopen("movie_ratings.txt", "r")) == NULL) {
        printf("Error! Could not open file.\n");
        exit(1);
    }

    char buffer[255];
    printf("\n\nMovie Ratings from our Database\n");
    while (fgets(buffer, 255, fptr)) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fptr);

    return 0;
}