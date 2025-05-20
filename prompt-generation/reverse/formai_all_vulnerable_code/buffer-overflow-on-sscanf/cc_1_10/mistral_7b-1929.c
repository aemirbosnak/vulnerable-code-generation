//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_WORDS 50
#define MAX_LENGTH 100

typedef struct {
    char question[MAX_LENGTH];
    char *answer;
} Question;

Question questions[MAX_QUESTIONS];

void load_questions(FILE *fp);
int ask_question(Question question);
void generate_answer(Question question);

int main() {
    int i;
    srand(time(NULL));

    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open questions file.\n");
        return 1;
    }

    load_questions(fp);
    fclose(fp);

    for (i = 0; i < MAX_QUESTIONS; i++) {
        Question current_question = questions[i];
        int answer = ask_question(current_question);
        generate_answer(current_question);

        if (answer == 1) {
            printf("Correct! The answer is: %s\n", current_question.answer);
        } else {
            printf("Incorrect. The answer is: %s\n", current_question.answer);
        }
    }

    return 0;
}

void load_questions(FILE *fp) {
    int i = 0;
    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        sscanf(line, "%s %s", questions[i].question, &questions[i].answer);
        i++;
    }
}

int ask_question(Question question) {
    int answer;
    printf("%s", question.question);
    scanf("%d", &answer);

    return answer;
}

void generate_answer(Question question) {
    char *answer_copy = (char *) malloc(strlen(question.answer) * sizeof(char) + 1);

    strcpy(answer_copy, question.answer);

    // Add your fortune telling code here

    printf("Your fortune is: %s\n", answer_copy);
    free(answer_copy);
}