//FormAI DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

int main(){

    int num1, num2, result1, result2, result3, result4, answer1, answer2, answer3, answer4;
    char operator1 = '+', operator2 = '-', operator3 = '*', operator4 = '/';
    
    printf("In the year 2045, the world was sure to end. But you survived in a shelter.\n");
    printf("You always feared math, but now it's your chance to embrace it to calculate your survival probability.\n\n");

    printf("Challenge 1:\n");
    num1 = 6;
    num2 = 2;
    result1 = num1 * num2;
    printf("%d %c %d = ", num1, operator3, num2);
    scanf("%d", &answer1);

    if(answer1 == result1){
        printf("Correct! You gained 50% more food supply.\n\n");
    }else{
        printf("Wrong answer. You lost 10% of your food supply.\n\n");
    }

    printf("Challenge 2:\n");
    num1 = 78;
    num2 = 15;
    result2 = num1 / num2;
    printf("%d %c %d = ", num1, operator4, num2);
    scanf("%d", &answer2);

    if(answer2 == result2){
        printf("Correct! You gained a new weapon.\n\n");
    }else{
        printf("Wrong answer. You lost a weapon.\n\n");
    }

    printf("Challenge 3:\n");
    num1 = 14;
    num2 = 5;
    result3 = num1 + num2;
    printf("%d %c %d = ", num1, operator1, num2);
    scanf("%d", &answer3);

    if(answer3 == result3){
        printf("Correct! You gained access to a medical kit.\n\n");
    }else{
        printf("Wrong answer. You lost access to the medical kit.\n\n");
    }

    printf("Challenge 4:\n");
    num1 = 17;
    num2 = 4;
    result4 = num1 - num2;
    printf("%d %c %d = ", num1, operator2, num2);
    scanf("%d", &answer4);

    if(answer4 == result4){
        printf("Correct! You gained a map of the surrounding area.\n\n");
    }else{
        printf("Wrong answer. You lost the map.\n\n");
    }

return 0;
}