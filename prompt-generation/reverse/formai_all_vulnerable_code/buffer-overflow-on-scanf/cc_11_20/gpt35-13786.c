//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include<stdio.h>

/* 
Welcome to the C Movie Rating System!
We rate movies on a scale of 1 to 10 bananas, because, well, why not?
The more bananas, the better the movie!
*/

int main(){
    int rating; // rating of the movie
    printf("Welcome to the C Movie Rating System!\n");
    printf("Please rate the movie based on your experience (1-10): ");
    scanf("%d", &rating);

    // Checking if rating is within acceptable range
    if (rating < 1 || rating > 10){
        printf("Invalid rating! Please rate the movie again: ");
        scanf("%d", &rating);
    }

    printf("Calculating movie rating...\n");

    // Delay to increase the dramatic effect
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 100000000; j++);
        printf(".");
    }
    printf("\n");

    // Rating judgment time!
    switch (rating){
        case 1:
        case 2:
        case 3:
            printf("Yikes, that movie was worse than a banana peel! You should have picked a better movie.\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("Meh, that movie was just okay. Not great, not terrible, just okay.\n");
            break;
        case 7:
        case 8:
            printf("Solid choice! That movie was as good as a monkey eating a banana!\n");
            break;
        case 9:
            printf("Wow, that movie was amazing! You must have had a blast! I would give you a whole bunch of bananas if I could!\n");
            break;
        case 10:
            printf("Holy banana peel, that movie was fantastic! You clearly have an exquisite taste!\n");
            break;
        default:
            // Just for safety, should never enter here
            printf("Hmm.. It seems there is something wrong in the rating calculations. Please try rating again!\n");
            break;
    }

    return 0;
}