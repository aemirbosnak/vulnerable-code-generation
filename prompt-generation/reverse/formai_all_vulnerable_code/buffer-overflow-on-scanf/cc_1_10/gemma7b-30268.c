//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rating;
    float score;

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1-5: ");
    scanf("%d", &rating);

    printf("Please enter your score for the movie (out of 10): ");
    scanf("%f", &score);

    if (rating < 1 || rating > 5) {
        printf("Invalid rating. Please try again.\n");
        return 1;
    }

    if (score < 0 || score > 10) {
        printf("Invalid score. Please try again.\n");
        return 1;
    }

    switch (rating) {
        case 1:
            printf("Your rating: 1/5\n");
            printf("Movie: Meh. I've seen better.\n");
            break;
        case 2:
            printf("Your rating: 2/5\n");
            printf("Movie: Passable. I wouldn't recommend it.\n");
            break;
        case 3:
            printf("Your rating: 3/5\n");
            printf("Movie: Good. I enjoyed it.\n");
            break;
        case 4:
            printf("Your rating: 4/5\n");
            printf("Movie: Great. I highly recommend it.\n");
            break;
        case 5:
            printf("Your rating: 5/5\n");
            printf("Movie: Masterpiece. A must-see.\n");
            break;
    }

    printf("Thank you for rating the movie. Please enjoy the rest of your day.\n");

    return 0;
}