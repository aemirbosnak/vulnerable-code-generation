//FormAI DATASET v1.0 Category: Online Examination System ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct questions{
    char question[100];
    char option1[50], option2[50], option3[50], option4[50];
    int correctAns;
    float marks;
};

int score = 0;
int qNumber = 0;

struct questions qSet[5] = {
    {"What is the capital of India?", "Mumbai", "New Delhi", "Kolkata", "Chennai", 2, 2.5},
    {"Who is the CEO of Microsoft?", "Satya Nadella", "Steve Jobs", "Bill Gates", "Mark Zuckerberg", 1, 3},
    {"Which is the largest continent in the world?", "Asia", "Europe", "North America", "South America", 1, 2},
    {"What is the full form of RAM?", "Random Area Memory", "Random Access Memo", "Random Access Memory", "Rapid Access Memory", 3, 5},
    {"What does HTML stand for?", "Hyper Text Markup Language", "High Tech Markup Language", "Hyperlinks and Text Markup Language", "Hyperlinks and Text Makeup Language", 1, 5.5}
};

void displayQuestion(){
    printf("\nQ%d) %s\n", qNumber+1, qSet[qNumber].question);
    printf("A) %s\nB) %s\nC) %s\nD) %s\n", qSet[qNumber].option1, qSet[qNumber].option2, qSet[qNumber].option3, qSet[qNumber].option4);
}

void startTest(){
    printf("\n\t\t Welcome to Online Examination System\n\n");
    printf("\nEnter your name: ");
    char name[100];
    scanf("%[^\n]%*c", name);
    printf("\nInstructions:");
    printf("\n1. There are a total of 5 multiple choice questions.");
    printf("\n2. Each question carries a different weightage of marks.");
    printf("\n3. You cannot change your answer once submitted.\n\n");
    printf("Good luck, %s! The test will begin shortly.\n\n", name);
}

void displayScore(){
    printf("\n\n\t\tReport Card\n\n");
    printf("Total Questions Attempted: %d\nTotal Score: %d\n", qNumber, score);
}

int main(){

    startTest();

    while(qNumber < 5){
        displayQuestion();
        printf("\nPlease enter your answer: ");
        char ans;
        scanf(" %c", &ans);
        ans = toupper(ans);

        if(ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D'){
            if(ans-64 == qSet[qNumber].correctAns){
                score += qSet[qNumber].marks;
                printf("\nCorrect Answer! Marked %0.2f\n", qSet[qNumber].marks);
            } else {
                printf("\nIncorrect Answer! The correct option was %c\n", qSet[qNumber].correctAns+64);
            }
            qNumber++;
        } else {
            printf("\nInvalid input. Please try again.\n");
        }
    }

    displayScore();

    return 0;
}