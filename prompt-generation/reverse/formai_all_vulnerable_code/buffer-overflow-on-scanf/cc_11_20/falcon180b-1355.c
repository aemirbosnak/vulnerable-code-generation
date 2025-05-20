//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    printf("Welcome to the Shape-Shifting Space Adventure!\n");
    printf("You are a space traveler who can transform into any shape.\n");
    printf("Your mission is to explore the universe and encounter various challenges.\n");
    printf("Choose your difficulty level: \n1. Easy\n2. Medium\n3. Hard\n");
    scanf("%d", &choice);
    int lives = 3;
    int score = 0;
    char shape[50];
    switch(choice) {
        case 1:
            strcpy(shape, "sphere");
            break;
        case 2:
            strcpy(shape, "cube");
            break;
        case 3:
            strcpy(shape, "cylinder");
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            return 0;
    }
    printf("You have chosen the %s shape.\n", shape);
    while(lives > 0 && score < 10) {
        int random = rand() % 3;
        switch(random) {
            case 0:
                printf("You encounter a meteor shower. Transform into a %s to avoid damage.\n", shape);
                if(strcmp(shape, "sphere") == 0) {
                    printf("You successfully avoid the meteors.\n");
                    score++;
                } else {
                    printf("You take damage and lose a life.\n");
                    lives--;
                }
                break;
            case 1:
                printf("You approach a black hole. Transform into a %s to escape its gravitational pull.\n", shape);
                if(strcmp(shape, "cylinder") == 0) {
                    printf("You successfully escape the black hole.\n");
                    score++;
                } else {
                    printf("You get sucked in and lose a life.\n");
                    lives--;
                }
                break;
            case 2:
                printf("You land on an alien planet. Transform into a %s to communicate with the aliens.\n", shape);
                if(strcmp(shape, "cube") == 0) {
                    printf("You successfully communicate with the aliens and gain valuable information.\n");
                    score++;
                } else {
                    printf("You fail to communicate and miss out on valuable information.\n");
                }
                break;
        }
    }
    if(score >= 10) {
        printf("Congratulations! You have completed the Shape-Shifting Space Adventure with a score of %d.\n", score);
    } else {
        printf("Game Over. Your final score is %d.\n", score);
    }
    return 0;
}