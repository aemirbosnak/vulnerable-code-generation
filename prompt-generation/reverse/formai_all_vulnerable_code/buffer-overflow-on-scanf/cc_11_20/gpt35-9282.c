//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char answer[5]; //to store user's answer
    int score=0;    //to keep track of user's score
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Please enter the symbol for each element that corresponds to the given number:\n\n");

    //question 1
    printf("1. Hydrogen - 1: ");
    scanf("%s",answer);
    if(strcmp(answer,"H")==0)
        score++;
    else
        printf("Incorrect. The correct answer is H.\n");

    //question 2
    printf("2. Carbon - 6: ");
    scanf("%s",answer);
    if(strcmp(answer,"C")==0)
        score++;
    else
        printf("Incorrect. The correct answer is C.\n");

    //question 3
    printf("3. Oxygen - 8: ");
    scanf("%s",answer);
    if(strcmp(answer,"O")==0)
        score++;
    else
        printf("Incorrect. The correct answer is O.\n");

    //question 4
    printf("4. Neon - 10: ");
    scanf("%s",answer);
    if(strcmp(answer,"Ne")==0)
        score++;
    else
        printf("Incorrect. The correct answer is Ne.\n");

    //question 5
    printf("5. Sodium - 11: ");
    scanf("%s",answer);
    if(strcmp(answer,"Na")==0)
        score++;
    else
        printf("Incorrect. The correct answer is Na.\n");

    //question 6
    printf("6. Chlorine - 17: ");
    scanf("%s",answer);
    if(strcmp(answer,"Cl")==0)
        score++;
    else
        printf("Incorrect. The correct answer is Cl.\n");

    //question 7
    printf("7. Calcium - 20: ");
    scanf("%s",answer);
    if(strcmp(answer,"Ca")==0)
        score++;
    else
        printf("Incorrect. The correct answer is Ca.\n");

    //question 8
    printf("8. Iron - 26: ");
    scanf("%s",answer);
    if(strcmp(answer,"Fe")==0)
        score++;
    else
        printf("Incorrect. The correct answer is Fe.\n");

    //question 9
    printf("9. Copper - 29: ");
    scanf("%s",answer);
    if(strcmp(answer,"Cu")==0)
        score++;
    else
        printf("Incorrect. The correct answer is Cu.\n");

    //question 10
    printf("10. Silver - 47: ");
    scanf("%s",answer);
    if(strcmp(answer,"Ag")==0){
        score++;
        printf("Correct! Amazing Job!\n\n");
        printf("Your total score is %d/10. Thanks for playing!\n", score);
    }
    else{
        printf("Incorrect. The correct answer is Ag.\n\n");
        printf("Your total score is %d/10. Thanks for playing!\n", score);
    }
    return 0;
}