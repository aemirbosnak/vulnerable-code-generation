//FormAI DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char *question;
    char *options[4];
    int answer;
};

void printInstructions() {
    printf("Welcome to the Online Examination System!\n");
    printf("You will be presented with a series of questions.\n");
    printf("Select the correct answer (1-4) and press enter to proceed to the next question.\n");
    printf("Good luck!\n");
}

void retrieveQuestions(struct Question *questionBank) {
    questionBank[0].question = "What is the capital of Japan?";
    questionBank[0].options[0] = "1) Tokyo";
    questionBank[0].options[1] = "2) Shanghai";
    questionBank[0].options[2] = "3) Seoul";
    questionBank[0].options[3] = "4) Beijing";
    questionBank[0].answer = 1;
    
    questionBank[1].question = "What is the highest mountain in the world?";
    questionBank[1].options[0] = "1) Kilimanjaro";
    questionBank[1].options[1] = "2) Denali";
    questionBank[1].options[2] = "3) Mount Everest";
    questionBank[1].options[3] = "4) Mount Vinson";
    questionBank[1].answer = 3;
    
    questionBank[2].question = "Which is the largest ocean on earth?";
    questionBank[2].options[0] = "1) Indian Ocean";
    questionBank[2].options[1] = "2) Arctic Ocean";
    questionBank[2].options[2] = "3) Atlantic Ocean";
    questionBank[2].options[3] = "4) Pacific Ocean";
    questionBank[2].answer = 4;
    
    questionBank[3].question = "What is the capital of Russia";
    questionBank[3].options[0] = "1) Moscow";
    questionBank[3].options[1] = "2) St. Petersburg";
    questionBank[3].options[2] = "3) Kazan";
    questionBank[3].options[3] = "4) Volgograd";
    questionBank[3].answer = 1;
}

void presentQuestions(struct Question *questionBank) {
    int score = 0;
    for (int i=0; i<4; i++) {
        printf("Question %d: %s\n", i+1, questionBank[i].question);
        for (int j=0; j<4; j++) {
            printf("%s\n", questionBank[i].options[j]);
        }
        printf("Answer: ");
        int userAnswer;
        scanf("%d", &userAnswer);
        if (userAnswer == questionBank[i].answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect.\n\n");
        }
    }
    printf("You scored %d out of 4.\n", score);
}

int main() {
    struct Question questionBank[4];
    retrieveQuestions(questionBank);
    printInstructions();
    presentQuestions(questionBank);
    return 0;
}