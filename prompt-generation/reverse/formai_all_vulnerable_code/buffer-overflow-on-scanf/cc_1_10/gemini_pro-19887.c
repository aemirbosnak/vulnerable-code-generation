//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define the ratings
enum rating { G, PG, PG_13, R, NC_17 };

// Get the rating from the user
enum rating get_rating(void) {
    char input[4];
    while (1) {
        printf("Enter the rating (G, PG, PG-13, R, NC-17): ");
        scanf("%s", input);
        if (strcmp(input, "G") == 0) {
            return G;
        } else if (strcmp(input, "PG") == 0) {
            return PG;
        } else if (strcmp(input, "PG-13") == 0) {
            return PG_13;
        } else if (strcmp(input, "R") == 0) {
            return R;
        } else if (strcmp(input, "NC-17") == 0) {
            return NC_17;
        } else {
            printf("Invalid rating. Please enter a valid rating.\n");
        }
    }
}

// Print the rating
void print_rating(enum rating rating) {
    switch (rating) {
        case G:
            printf("G - General Audiences\n");
            break;
        case PG:
            printf("PG - Parental Guidance Suggested\n");
            break;
        case PG_13:
            printf("PG-13 - Parents Strongly Cautioned\n");
            break;
        case R:
            printf("R - Restricted\n");
            break;
        case NC_17:
            printf("NC-17 - No One 17 and Under Admitted\n");
            break;
    }
}

int main(void) {
    // Get the rating from the user
    enum rating rating = get_rating();

    // Print the rating
    print_rating(rating);

    return 0;
}