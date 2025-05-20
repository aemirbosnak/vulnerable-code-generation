//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating categories
enum rating {
    ABYSMAL,
    DETESTABLE,
    REPULSIVE,
    UNBEARABLE,
    NAUSEATING,
    ABOMINABLE,
    HORRENDOUS,
    ATROCIOUS,
    DREADFUL,
    APPALLING
};

// Define the surrealist movie rating system
struct surrealist_rating {
    enum rating rating;
    char *description;
};

// Define the surrealist movie rating system database
struct surrealist_rating surrealist_ratings[] = {
    { ABYSMAL, "A cinematic abyss that plunges the viewer into an unfathomable depths of despair." },
    { DETESTABLE, "A loathsome celluloid nightmare that haunts the viewer long after the credits roll." },
    { REPULSIVE, "A repulsive concoction that leaves the viewer feeling unclean and violated." },
    { UNBEARABLE, "An intolerable cinematic torture that weighs heavily upon the viewer's soul." },
    { NAUSEATING, "A sickening cinematic experience that turns the viewer's stomach and leaves them reeling." },
    { ABOMINABLE, "A revolting cinematic abomination that defies description." },
    { HORRENDOUS, "A cinematic horror that chills the viewer to the bone and leaves them trembling in fear." },
    { ATROCIOUS, "A cinematic atrocity that scars the viewer's psyche permanently." },
    { DREADFUL, "A cinematic nightmare that haunts the viewer's dreams and fills them with dread." },
    { APPALLING, "A cinematic disgrace that is so bad it is almost laughable." }
};

// Get the user's rating for a movie
enum rating get_user_rating() {
    int rating;
    printf("Please rate the movie on a scale of 1 to 10, where 1 is the worst and 10 is the best:\n");
    scanf("%d", &rating);
    return (enum rating)(rating - 1);
}

// Print the surrealist rating for a movie
void print_surrealist_rating(enum rating rating) {
    printf("Your surrealist rating for this movie is:\n\n");
    printf("%s\n", surrealist_ratings[rating].description);
}

// Main function
int main() {
    // Get the user's rating for the movie
    enum rating rating = get_user_rating();

    // Print the surrealist rating for the movie
    print_surrealist_rating(rating);

    return 0;
}