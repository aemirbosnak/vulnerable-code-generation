//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Cryptic
#include<stdio.h>
#include<string.h>

int main(){
    char answer[10];
    int score = 0;

    printf("Welcome to the Cryptic Periodic Table Quiz!\n\n");

    printf("1. Which element's symbol is derived from the Latin word 'stannum'?\n");
    scanf("%s", answer);
    if(strcmp(answer, "Sb") == 0){
        printf("Correct!\n");
        score++;
    }else{
        printf("Incorrect. The correct answer is Sb.\n");
    }

    printf("2. This yellow element shares its name with a Greek word meaning 'beam of the sun'. What's its symbol?\n");
    scanf("%s", answer);
    if(strcmp(answer, "Au") == 0){
        printf("Correct!\n");
        score++;
    }else{
        printf("Incorrect. The correct answer is Au.\n");
    }

    printf("3. This element's name originates from the Greek word 'kryptos', meaning 'hidden'. What's its symbol?\n");
    scanf("%s", answer);
    if(strcmp(answer, "Kr") == 0){
        printf("Correct!\n");
        score++;
    }else{
        printf("Incorrect. The correct answer is Kr.\n");
    }

    printf("4. Which element's symbol comes from the Greek word 'hydrargyros', which means 'liquid silver'?\n");
    scanf("%s", answer);
    if(strcmp(answer, "Hg") == 0){
        printf("Correct!\n");
        score++;
    }else{
        printf("Incorrect. The correct answer is Hg.\n");
    }

    printf("5. This element is named after the Norse god of thunder. What's its symbol?\n");
    scanf("%s", answer);
    if(strcmp(answer, "Th") == 0){
        printf("Correct!\n");
        score++;
    }else{
        printf("Incorrect. The correct answer is Th.\n");
    }

    printf("\nWell done! You've completed the quiz.\n\n");

    if(score == 5){
        printf("You got a perfect score! Congratulations!\n");
    }else{
        printf("Your score is %d out of 5. Keep studying!\n", score);
    }

    return 0;
}