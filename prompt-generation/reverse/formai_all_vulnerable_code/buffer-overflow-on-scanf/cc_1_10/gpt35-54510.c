//FormAI DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

void instruction(){
    printf("Welcome to the online examination system\n");
    printf("You will be presented with multiple choice questions\n");
    printf("Please enter the corresponding letter of your answer\n");
}

int main(){

    int correct = 0;
    char answer;

    instruction();

    printf("Q1. What is 2+2?\n");
    printf("A. 1\n");
    printf("B. 2\n");
    printf("C. 3\n");
    printf("D. 4\n");
    scanf(" %c", &answer);

    if(answer == 'D'){
        correct++;
    }

    printf("Q2. Who is the founder of SpaceX?\n");
    printf("A. Elon Musk\n");
    printf("B. Jeff Bezos\n");
    printf("C. Bill Gates\n");
    printf("D. Mark Zuckerberg\n");
    scanf(" %c", &answer);

    if(answer == 'A'){
        correct++;
    }

    printf("Q3. What is the capital city of Japan?\n");
    printf("A. Tokyo\n");
    printf("B. Beijing\n");
    printf("C. Manila\n");
    printf("D. Seoul\n");
    scanf(" %c", &answer);

    if(answer == 'A'){
        correct++;
    }

    printf("Q4. What is the largest planet in the solar system?\n");
    printf("A. Earth\n");
    printf("B. Mars\n");
    printf("C. Jupiter\n");
    printf("D. Saturn\n");
    scanf(" %c", &answer);

    if(answer == 'C'){
        correct++;
    }

    printf("Q5. Who painted the Mona Lisa?\n");
    printf("A. Vincent van Gogh\n");
    printf("B. Pablo Picasso\n");
    printf("C. Leonardo da Vinci\n");
    printf("D. Claude Monet\n");
    scanf(" %c", &answer);

    if(answer == 'C'){
        correct++;
    }

    printf("You got %d out of 5 correct\n", correct);

    return 0;
}