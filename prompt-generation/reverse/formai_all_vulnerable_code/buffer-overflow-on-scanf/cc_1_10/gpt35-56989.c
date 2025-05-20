//FormAI DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

int main() {

    // Create an array of 10 integers to store movie ratings
    int ratings[10];

    int i, sum = 0;

    // Prompt the user to enter 10 movie ratings from 1 to 5
    printf("Please enter 10 movie ratings from 1 to 5: \n");

    for(i = 0; i < 10; i++) {
        scanf("%d", &ratings[i]);

        // Validate the user input
        while(ratings[i] < 1 || ratings[i] > 5) {
            printf("Please enter a rating between 1 and 5: \n");
            scanf("%d", &ratings[i]);
        }

        // Calculate the sum of all movie ratings
        sum += ratings[i];
    }

    // Calculate the average movie rating
    float average = (float) sum / 10;

    printf("\nMovie Ratings:\n");

    // Print out each movie rating and its corresponding symbol
    for(i = 0; i < 10; i++) {
        printf("Movie #%d: ", i + 1);
        switch(ratings[i]) {
            case 1:
                printf("*\n");
                break;
            case 2:
                printf("**\n");
                break;
            case 3:
                printf("***\n");
                break;
            case 4:
                printf("****\n");
                break;
            case 5:
                printf("*****\n");
                break;
            default:
                printf("\n");
                break;
        }
    }

    printf("Average Movie Rating: %.2f\n", average);

    printf("Press any key to exit.\n");

    getchar(); // To clear buffer
    getchar(); // To exit program

    return 0;
}