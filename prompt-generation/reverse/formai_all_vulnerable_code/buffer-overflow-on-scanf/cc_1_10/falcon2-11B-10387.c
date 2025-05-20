//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: immersive
#include <stdio.h>

int main() {
    int i, j, score = 0, max_score = 0;
    char answer[10];
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("To play, enter 'yes' or 'y': ");
    scanf("%s", &answer);
    
    if (strcmp(answer, "yes") == 0 || strcmp(answer, "y") == 0) {
        printf("Let's begin!\n");
        printf("What is the atomic number of Hydrogen? ");
        scanf("%d", &i);
        if (i == 1) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is 1.\n");
        }
        
        printf("What is the atomic number of Helium? ");
        scanf("%d", &i);
        if (i == 2) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is 2.\n");
        }
        
        printf("What is the atomic number of Carbon? ");
        scanf("%d", &i);
        if (i == 6) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is 6.\n");
        }
        
        printf("What is the atomic number of Iron? ");
        scanf("%d", &i);
        if (i == 26) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is 26.\n");
        }
        
        printf("What is the atomic number of Gold? ");
        scanf("%d", &i);
        if (i == 79) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is 79.\n");
        }
        
        printf("Your final score is %d out of 5.\n", score);
        if (score >= max_score) {
            printf("Congratulations! You have scored the highest possible score.\n");
        } else {
            printf("Better luck next time.\n");
        }
    } else {
        printf("Exiting program...\n");
    }
    
    return 0;
}