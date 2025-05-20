//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>

int main() {
    printf("Welcome to the Introspective Game!\n");
    printf("You are faced with a series of questions that will reveal your innermost thoughts and fears.\n");
    
    char name[20];
    printf("First, what is your name?\n");
    scanf("%s", name);
    printf("Hello %s!\n", name);
    
    int age;
    printf("What is your age?\n");
    scanf("%d", &age);
    if (age < 18) {
        printf("You are too young to play this game!\n");
        return 0;
    }
    
    int answer1, answer2, answer3;
    printf("Question 1: On a scale of 1 to 10, how confident are you?\n");
    scanf("%d", &answer1);
    printf("Question 2: On a scale of 1 to 10, how afraid are you of failure?\n");
    scanf("%d", &answer2);
    printf("Question 3: On a scale of 1 to 10, how much do you trust others?\n");
    scanf("%d", &answer3);
    
    int total = answer1 + answer2 + answer3;
    
    if (total > 20) {
        printf("You have a high level of self-confidence.\n");
    } else {
        printf("You may have some self-doubt and insecurities.\n");
    }
    
    if (answer2 > 7) {
        printf("You may have a fear of failure that is holding you back.\n");
    } else {
        printf("You are not greatly held back by a fear of failure.\n");
    }
    
    if (answer3 < 4) {
        printf("You may have trust issues with others.\n");
    } else {
        printf("You are generally trusting of others.\n");
    }
    
    printf("Thank you for playing the Introspective Game!\n");
    return 0;
}