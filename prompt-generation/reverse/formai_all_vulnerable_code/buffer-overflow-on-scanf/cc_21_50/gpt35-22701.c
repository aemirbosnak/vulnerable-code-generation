//FormAI DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the Retro Movie Rating System!\n");
    printf("Please rate the following movies from 1 to 10:\n\n");

    printf("1. The Godfather: ");
    scanf("%d", &rating);

    if (rating < 1 || rating > 10) {
        printf("Invalid rating, please rate from 1 to 10.\n");
        printf("1. The Godfather: ");
        scanf("%d", &rating);
    } 

    switch (rating) {
        case 1:
            printf("You rated The Godfather 1 out of 10. Did you even watch the movie?\n");
            break;
        case 2:
            printf("You rated The Godfather 2 out of 10. You clearly don't appreciate cinematic masterpieces.\n");
            break;
        case 3:
            printf("You rated The Godfather 3 out of 10. Your opinion is wrong but at least you tried.\n");
            break;
        case 4:
            printf("You rated The Godfather 4 out of 10. That's obviously not its actual rating, but okay.\n");
            break;
        case 5:
            printf("You rated The Godfather 5 out of 10. Could be better, could be worse.\n");
            break;
        case 6:
            printf("You rated The Godfather 6 out of 10. Not bad, but it's definitely overrated.\n");
            break;
        case 7:
            printf("You rated The Godfather 7 out of 10. Good choice, it's a classic for a reason.\n");
            break;
        case 8:
            printf("You rated The Godfather 8 out of 10. Excellent choice, it deserves all the praise.\n");
            break;
        case 9:
            printf("You rated The Godfather 9 out of 10. A true cinephile, your taste is impeccable.\n");
            break;
        case 10:
            printf("You rated The Godfather 10 out of 10. Finally, someone who appreciates greatness.\n");
            break;
    }

    printf("\n");

    printf("2. Pulp Fiction: ");
    scanf("%d", &rating);

    if (rating < 1 || rating > 10) {
        printf("Invalid rating, please rate from 1 to 10.\n");
        printf("2. Pulp Fiction: ");
        scanf("%d", &rating);
    }

    switch (rating) {
        case 1:
            printf("You rated Pulp Fiction 1 out of 10. You probably never heard of Tarantino.\n");
            break;
        case 2:
            printf("You rated Pulp Fiction 2 out of 10. Clearly not your cup of tea.\n");
            break;
        case 3:
            printf("You rated Pulp Fiction 3 out of 10. You must be fun at parties.\n");
            break;
        case 4:
            printf("You rated Pulp Fiction 4 out of 10. You tried to be edgy but failed.\n");
            break;
        case 5:
            printf("You rated Pulp Fiction 5 out of 10. It's decent but not everyone's favorite.\n");
            break;
        case 6:
            printf("You rated Pulp Fiction 6 out of 10. A good choice, but not Tarantino's best work.\n");
            break;
        case 7:
            printf("You rated Pulp Fiction 7 out of 10. Solid choice, the dialogue is amazing.\n");
            break;
        case 8:
            printf("You rated Pulp Fiction 8 out of 10. Excellent choice, clearly you appreciate good movies.\n");
            break;
        case 9:
            printf("You rated Pulp Fiction 9 out of 10. You have great taste in movies and appreciate Tarantino's genius.\n");
            break;
        case 10:
            printf("You rated Pulp Fiction 10 out of 10. Bravo, you have a true appreciation for cinema.\n");
            break;
    }

    printf("\n");

    printf("3. Blade Runner: ");
    scanf("%d", &rating);

    if (rating < 1 || rating > 10) {
        printf("Invalid rating, please rate from 1 to 10.\n");
        printf("3. Blade Runner: ");
        scanf("%d", &rating);
    }

    switch (rating) {
        case 1:
            printf("You rated Blade Runner 1 out of 10. Did you even understand the plot?\n");
            break;
        case 2:
            printf("You rated Blade Runner 2 out of 10. Clearly it's not your type of movie.\n");
            break;
        case 3:
            printf("You rated Blade Runner 3 out of 10. It's not for everyone.\n");
            break;
        case 4:
            printf("You rated Blade Runner 4 out of 10. It's a classic but not as impressive as other sci-fi movies.\n");
            break;
        case 5:
            printf("You rated Blade Runner 5 out of 10. A decent score for an iconic movie.\n");
            break;
        case 6:
            printf("You rated Blade Runner 6 out of 10. You appreciate sci-fi and the movie's aesthetic, but it could be better.\n");
            break;
        case 7:
            printf("You rated Blade Runner 7 out of 10. A great choice, the visuals are stunning.\n");
            break;
        case 8:
            printf("You rated Blade Runner 8 out of 10. An excellent score, it's truly a one-of-a-kind sci-fi movie.\n");
            break;
        case 9:
            printf("You rated Blade Runner 9 out of 10. You have an eye for good movies, and Blade Runner is your favorite sci-fi.\n");
            break;
        case 10:
            printf("You rated Blade Runner 10 out of 10. You're a true fan of Ridley Scott and his vision for Blade Runner.\n");
            break;
    }

    printf("\n");

    printf("Thank you for participating in the Retro Movie Rating System! See you at the cinema!\n");
    return 0;
}