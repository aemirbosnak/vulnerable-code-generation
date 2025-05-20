//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

int main(){
    int rating;

    printf("Welcome to the Unique C Movie Rating System!\n\n");
    printf("Please rate the following movies from 1-10.\n\n");

    // Prompt user to rate the first movie
    printf("1. Avengers: Endgame - ");
    scanf("%d",&rating);

    if(rating < 1){
        printf("Invalid Rating. Please rate between 1-10.\n");
        return 0;
    }
    else if(rating <= 4){
        printf("Sorry to hear that. Thanks for rating Endgame!\n");
    }
    else if(rating <= 7){
        printf("Thanks for rating Endgame. We're glad you liked it!\n");
    }
    else{
        printf("Wow, you really enjoyed Endgame! Thanks for rating!\n");
    }

    // Prompt user to rate the second movie
    printf("\n2. The Shawshank Redemption - ");
    scanf("%d",&rating);

    if(rating < 1){
        printf("Invalid Rating. Please rate between 1-10.\n");
        return 0;
    }
    else if(rating <= 4){
        printf("Sorry to hear that. Thanks for rating The Shawshank Redemption!\n");
    }
    else if(rating <= 7){
        printf("Thanks for rating The Shawshank Redemption. We're glad you liked it!\n");
    }
    else{
        printf("Wow, you really enjoyed The Shawshank Redemption! Thanks for rating!\n");
    }

    // Prompt user to rate the third movie
    printf("\n3. Pulp Fiction - ");
    scanf("%d",&rating);

    if(rating < 1){
        printf("Invalid Rating. Please rate between 1-10.\n");
        return 0;
    }
    else if(rating <= 4){
        printf("Sorry to hear that. Thanks for rating Pulp Fiction!\n");
    }
    else if(rating <= 7){
        printf("Thanks for rating Pulp Fiction. We're glad you liked it!\n");
    }
    else{
        printf("Wow, you really enjoyed Pulp Fiction! Thanks for rating!\n");
    }

    // Prompt user to rate the fourth movie
    printf("\n4. Inception - ");
    scanf("%d",&rating);

    if(rating < 1){
        printf("Invalid Rating. Please rate between 1-10.\n");
        return 0;
    }
    else if(rating <= 4){
        printf("Sorry to hear that. Thanks for rating Inception!\n");
    }
    else if(rating <= 7){
        printf("Thanks for rating Inception. We're glad you liked it!\n");
    }
    else{
        printf("Wow, you really enjoyed Inception! Thanks for rating!\n");
    }

    // Prompt user to rate the fifth movie
    printf("\n5. The Dark Knight - ");
    scanf("%d",&rating);

    if(rating < 1){
        printf("Invalid Rating. Please rate between 1-10.\n");
        return 0;
    }
    else if(rating <= 4){
        printf("Sorry to hear that. Thanks for rating The Dark Knight!\n");
    }
    else if(rating <= 7){
        printf("Thanks for rating The Dark Knight. We're glad you liked it!\n");
    }
    else{
        printf("Wow, you really enjoyed The Dark Knight! Thanks for rating!\n");
    }

    printf("\nThanks for participating in the Unique C Movie Rating System!\n");

    return 0;
}