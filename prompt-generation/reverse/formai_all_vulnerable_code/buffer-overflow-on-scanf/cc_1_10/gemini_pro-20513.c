//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: curious
// Behold, a grand cinematic escapade awaits!

#include <stdio.h>

// Our esteemed jury shall cast their discerning eyes upon these cinematic wonders.
int jury[5];

// An array to capture the hushed whispers of the audience.
char audience[101];

// Let us unveil the masterpieces that will grace our screens.
char movies[5][101];

// Each film, a symphony of emotions, invites our solemn deliberations.
void rateMovies() {
    for (int i = 0; i < 5; i++) {
        printf("Esteemed jury, favored by the muses, cast your gaze upon %s: ", movies[i]);
        scanf("%d", &jury[i]);
    }
}

// The audience, ever so eloquent, shall share their verdict.
void gatherAudienceReviews() {
    printf("Oh, erudite audience, lend thy voices to %s: ", movies[0]);
    scanf("%s", audience);
}

// Let us weave together the tapestry of film, jury, and audience.
void printResults() {
    printf("\nBehold, the cinematic tapestry!\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: Jury: %d/5, Audience: %s\n", movies[i], jury[i], audience);
    }
}

// A grand spectacle unfolds, where cinema, criticism, and public opinion converge.
int main() {
    // Let us gather our masterworks.
    for (int i = 0; i < 5; i++) {
        printf("Unveil the cinematic masterpiece that shall enthrall us: ");
        scanf("%s", movies[i]);
    }

    // The jury, in their infinite wisdom, shall judge.
    rateMovies();

    // The audience, our collective voice, shall speak.
    gatherAudienceReviews();

    // Now, let us weave the threads of our cinematic tapestry.
    printResults();

    return 0;
}