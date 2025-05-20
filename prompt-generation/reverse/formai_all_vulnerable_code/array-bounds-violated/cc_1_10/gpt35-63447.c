//FormAI DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int movies[10]; // max number of movies that can be rated at a time
    int ratings[10]; // array to store the ratings
    char names[10][30]; // max character limit for movie names

    printf("Welcome to the Medieval Movie Rating System!\n");
    printf("Please rate the following movies on a scale of 1-5:\n");

    for(int i = 0; i < 5; i++) {
        printf("Enter the name of movie %d: ", i+1);
        fgets(names[i], 30, stdin);
        names[i][strlen(names[i])-1] = '\0'; // replace newline character with null terminator
        printf("Enter your rating for %s: ", names[i]);
        scanf("%d", &ratings[i]);
        getchar(); // flush input buffer
        while(ratings[i] < 1 || ratings[i] > 5) { // ensure valid rating input
            printf("Invalid rating! Please rate on a scale of 1-5: ");
            scanf("%d", &ratings[i]);
            getchar();
        }
        movies[i] = i+1; // assign movie number
        printf("\n"); // newline for readability
    }

    // insertion sort to sort the movies based on ratings
    for(int i = 1; i < 5; i++) {
        int j = i;
        while(j > 0 && ratings[j-1] < ratings[j]) {
            // swap the ratings array
            int temp = ratings[j-1];
            ratings[j-1] = ratings[j];
            ratings[j] = temp;
            // swap the movies array
            temp = movies[j-1];
            movies[j-1] = movies[j];
            movies[j] = temp;
            // swap the names array
            char tempstr[30];
            strcpy(tempstr, names[j-1]);
            strcpy(names[j-1], names[j]);
            strcpy(names[j], tempstr);
            j--;
        }
    }

    printf("Here are the movies sorted by rating:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d. %s - %d\n", movies[i], names[i], ratings[i]);
    }

    return 0;
}