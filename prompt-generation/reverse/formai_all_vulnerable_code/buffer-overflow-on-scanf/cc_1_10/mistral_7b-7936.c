//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_CHAR 255

typedef struct {
    char question[MAX_CHAR];
    char options[MAX_OPTIONS][MAX_CHAR];
    char answer;
} Question;

Question ques[MAX_QUESTIONS];
int score = 0;
int qnum = 0;

void generate_questions() {
    int i;
    char str[MAX_CHAR];

    srand(time(NULL));

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question %d: ", i + 1);
        fgets(ques[i].question, MAX_CHAR, stdin);
        ques[i].question[strcspn(ques[i].question, "\n")] = '\0';

        printf("Enter option A for question %d: ", i + 1);
        fgets(ques[i].options[0], MAX_CHAR, stdin);
        ques[i].options[0][strcspn(ques[i].options[0], "\n")] = '\0';

        printf("Enter option B for question %d: ", i + 1);
        fgets(ques[i].options[1], MAX_CHAR, stdin);
        ques[i].options[1][strcspn(ques[i].options[1], "\n")] = '\0';

        printf("Enter option C for question %d: ", i + 1);
        fgets(ques[i].options[2], MAX_CHAR, stdin);
        ques[i].options[2][strcspn(ques[i].options[2], "\n")] = '\0';

        printf("Enter option D for question %d: ", i + 1);
        fgets(ques[i].options[3], MAX_CHAR, stdin);
        ques[i].options[3][strcspn(ques[i].options[3], "\n")] = '\0';

        printf("Enter the answer for question %d (A, B, C or D): ", i + 1);
        scanf("%c", &ques[i].answer);

        printf("\n");
    }
}

void display_question() {
    int i;

    printf("\nQuestion %d:\n%s\n", qnum + 1, ques[qnum].question);

    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("\n%c. %s", i + 'A', ques[qnum].options[i]);
    }

    printf("\nEnter your answer (A, B, C or D): ");
}

void check_answer() {
    int user_answer;
    scanf("%c", &user_answer);

    if (user_answer == ques[qnum].answer) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect! The correct answer was %c.\n", ques[qnum].answer);
    }

    printf("\n");
}

void start_exam() {
    int i;

    generate_questions();

    for (i = 0; i < MAX_QUESTIONS; i++) {
        display_question();
        check_answer();
        qnum++;
    }

    printf("Your exam is over. Your score is %d out of %d.\n", score, MAX_QUESTIONS);
}

int main() {
    start_exam();

    return 0;
}