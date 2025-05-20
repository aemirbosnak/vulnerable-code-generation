//FormAI DATASET v1.0 Category: Online Examination System ; Style: scientific
/* C Online Examination System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold information about a question */
struct Question {
    char *question;
    char *options[4];
    int answer;
};

/* Function to initialize a question */
void initQuestion(struct Question *q, char *question, char *option1, char *option2, char *option3, char *option4, int answer) {
    q->question = question;
    q->options[0] = option1;
    q->options[1] = option2;
    q->options[2] = option3;
    q->options[3] = option4;
    q->answer = answer;
}

/* Function to display a question */
void displayQuestion(struct Question *q) {
    printf("%s\n", q->question);
    for (int i = 0; i < 4; ++i) {
        printf("%d. %s\n", (i + 1), q->options[i]);
    }
}

/* Function to get user's response to a question */
int getResponse() {
    int response = -1;
    do {
        printf("Enter your answer: ");
        scanf("%d", &response);
    } while (response < 1 || response > 4);
    return response;
}

/* Function to check if user's response is correct */
int checkResponse(struct Question *q, int response) {
    return (response == q->answer);
}

int main() {
    /* Define questions */
    struct Question q1, q2, q3, q4, q5;
    initQuestion(&q1,
                 "What is the closest planet to the sun?",
                 "Venus", 
                 "Mercury", 
                 "Mars", 
                 "Jupiter",
                 2);
    initQuestion(&q2,
                 "What is the largest planet in our solar system?",
                 "Jupiter",
                 "Saturn",
                 "Mars",
                 "Pluto",
                 1);
    initQuestion(&q3,
                 "What gas makes up the majority of the Earth's atmosphere?",
                 "Carbon dioxide",
                 "Nitrogen",
                 "Oxygen",
                 "Methane",
                 2);
    initQuestion(&q4,
                 "Who discovered the laws of motion?",
                 "Isaac Newton",
                 "Albert Einstein",
                 "Galileo Galilei",
                 "Thomas Edison",
                 1);
    initQuestion(&q5,
                 "What is the chemical symbol for gold?",
                 "Au",
                 "Ag",
                 "Fe",
                 "Cu",
                 1);
    
    /* Ask questions and get responses */
    struct Question questions[5] = {q1, q2, q3, q4, q5};
    int responses[5];
    for (int i = 0; i < 5; ++i) {
        printf("Question %d:\n", (i + 1));
        displayQuestion(&questions[i]);
        responses[i] = getResponse();
    }
    
    /* Calculate score and display results */
    int score = 0;
    for (int i = 0; i < 5; ++i) {
        if (checkResponse(&questions[i], responses[i])) {
            ++score;
        }
    }
    printf("You scored %d out of 5.\n", score);
    
    return 0;
}