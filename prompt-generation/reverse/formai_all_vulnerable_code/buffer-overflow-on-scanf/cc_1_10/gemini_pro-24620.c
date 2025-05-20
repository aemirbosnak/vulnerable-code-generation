//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
// Where hearts entwined in ancient fray,
// A tale of love and online sway,
// A Romeo and Juliet e-quest,
// In bytes and code, their passion blessed.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our Montagues and Capulets, disguised in code,
// Students Romeo and Juliet, their knowledge bestowed.
typedef struct Student {
    char name[20];
    int roll;
    int marks;
} Student;

// Fair Verona, our server's embrace,
// Where questions and answers find their place.
typedef struct Question {
    char question[100];
    char options[4][50];
    int answer;
} Question;

// The Friar, our wise server, holds the key,
// To questions and answers, for all to see.
struct Server {
    Question questions[10];
    int num_questions;
};

// Our star-crossed lovers, their hearts aflame,
// Connect to the server, to play their game.
int connectToServer(struct Server *server) {
    printf("Enter server IP address: ");
    scanf("%s", server->questions);
    printf("Connection established.\n");
    return 1;
}

// The questions posed, a test of their might,
// True love's bond, tested by day and night.
int getQuestions(struct Server *server) {
    printf("Fetching questions...\n");
    for (int i = 0; i < server->num_questions; i++) {
        printf("Question %d: %s\n", i + 1, server->questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("\t%c. %s\n", 'A' + j, server->questions[i].options[j]);
        }
    }
    return 1;
}

// The lovers' answers, a dance of thought,
// Their knowledge displayed, their passion wrought.
int submitAnswers(struct Server *server) {
    printf("Submitting answers...\n");
    for (int i = 0; i < server->num_questions; i++) {
        char answer;
        printf("Answer for question %d: ", i + 1);
        scanf(" %c", &answer);
        server->questions[i].answer = answer - 'A';
    }
    return 1;
}

// The server's verdict, love's fate unfurled,
// A score of knowledge, their hearts entwined.
int getResults(struct Server *server) {
    printf("Fetching results...\n");
    int score = 0;
    for (int i = 0; i < server->num_questions; i++) {
        if (server->questions[i].answer == server->questions[i].answer) {
            score++;
        }
    }
    printf("Your score: %d out of %d\n", score, server->num_questions);
    return 1;
}

// Our tale's end, their love's eternal spark,
// In bytes and code, their bond won't break.
int main() {
    struct Server server;
    connectToServer(&server);
    getQuestions(&server);
    submitAnswers(&server);
    getResults(&server);
    printf("Exam complete. May your love forever glow.\n");
    return 0;
}