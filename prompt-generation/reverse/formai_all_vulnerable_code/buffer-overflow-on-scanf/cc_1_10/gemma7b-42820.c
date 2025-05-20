//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

void dance_with_the_moon(int stars);

int main() {
    int rating = 0;
    printf("Welcome to the Surrealist C Movie Rating System!\n");
    printf("Please rate a movie from 1 to 5 stars:");
    scanf("%d", &rating);

    switch (rating) {
        case 1:
            dance_with_the_moon(1);
            printf("May the stars whisper secrets in your ear.\n");
            break;
        case 2:
            dance_with_the_moon(2);
            printf("The moon will dance with you, my dear.\n");
            break;
        case 3:
            dance_with_the_moon(3);
            printf("Stars and moon will unite in your honor.\n");
            break;
        case 4:
            dance_with_the_moon(4);
            printf("Prepare for a cosmic ballet.\n");
            break;
        case 5:
            dance_with_the_moon(5);
            printf("You have the power to control the stars and moon.\n");
            break;
        default:
            printf("Invalid rating. Please try again.\n");
    }

    return 0;
}

void dance_with_the_moon(int stars) {
    switch (stars) {
        case 1:
            printf("The moon whispers secrets into the night.\n");
            break;
        case 2:
            printf("The moon dances with fireflies.\n");
            break;
        case 3:
            printf("The moon shines on a river.\n");
            break;
        case 4:
            printf("The moon paints stars on the sky.\n");
            break;
        case 5:
            printf("The moon and stars dance in harmony.\n");
            break;
    }
}