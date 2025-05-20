//FormAI DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Defining global variables*/
int score=0;
int question_number=0;

/*Defining the structure for holding the questions and answers*/
struct Question{
    char question[1000];
    char option1[1000];
    char option2[1000];
    char option3[1000];
    char option4[1000];
    char answer[1000];
};

/*Function for displaying questions and options*/
void Display_Questions(struct Question q)
{
    printf("\n\nQuestion No. %d: \n\n", question_number);
    printf("%s\n", q.question);
    printf("a. %s\n", q.option1);
    printf("b. %s\n", q.option2);
    printf("c. %s\n", q.option3);
    printf("d. %s\n", q.option4);
}

/*Function for grading the answers*/
void Grade_Answers(char answer[], struct Question q)
{
    if (strcmp(answer, q.answer)==0)
    {
        score++;
        printf("Your answer is correct! Current score: %d\n", score);
    }
    else{
        printf("Your answer was incorrect. The correct answer is %s. Current score: %d\n", q.answer, score);
    }
}

/*Main Function*/
int main()
{
    /*Initializing the Question structure*/
    struct Question exam[5]=
    {
        {
            "What is the capital city of the United States of America?",
            "New York",
            "Texas",
            "Washington D.C.",
            "California",
            "c"
        },

        {
            "Which country is located in the Middle East?",
            "India",
            "Saudi Arabia",
            "Mexico",
            "Canada",
            "b"
        },

        {
            "What is the currency of Japan?",
            "Won",
            "Yen",
            "Dollar",
            "Euro",
            "b"
        },

        {
            "What is the most spoken language in the world?",
            "English",
            "Mandarin",
            "Spanish",
            "French",
            "b"
        },

        {
            "What is the largest organ in the human body?",
            "Lungs",
            "Brain",
            "Intestines",
            "Skin",
            "d"
        }

    };

    /*Welcome messages and instructions*/
    printf("Welcome to the Online Examination System!\n");
    printf("You will have to answer 5 multiple-choice questions.\n");
    printf("Please select the correct answer by entering the corresponding letter.\n\n");

    /*Loop for displaying and grading the questions*/
    for (int i=0; i<5; i++)
    {
        question_number++;
        Display_Questions(exam[i]);

        char answer[1000];
        printf("\nEnter your answer: ");
        scanf("%s", answer);

        /*Error message when an invalid answer is entered*/
        if (strcmp(answer, "a")!=0 && strcmp(answer, "b")!=0 && strcmp(answer, "c")!=0 && strcmp(answer, "d")!=0)
        {
            printf("Invalid input. Please enter a letter from 'a' to 'd'.\n");
            i--;
            question_number--;
        }
        /*Grade the answers if they're valid*/
        else {
            Grade_Answers(answer, exam[i]);
        }

    }
    /*Display the final score*/
    printf("\n\nQuiz completed. Final score: %d/5\n", score);

    return 0;
}