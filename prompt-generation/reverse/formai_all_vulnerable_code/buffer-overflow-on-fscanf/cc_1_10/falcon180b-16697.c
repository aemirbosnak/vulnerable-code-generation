//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER_LEN 80

struct question {
    char *text;
    char *answer;
};

int main() {
    int num_questions = 0;
    struct question questions[MAX_QUESTIONS];

    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        printf("Error opening questions file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s", questions[num_questions].text, questions[num_questions].answer)!= EOF) {
        num_questions++;
        if (num_questions >= MAX_QUESTIONS) {
            printf("Error: too many questions in file.\n");
            return 1;
        }
    }

    fclose(file);

    int num_correct = 0;
    int num_incorrect = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].text);
        char answer[MAX_ANSWER_LEN];
        fgets(answer, MAX_ANSWER_LEN, stdin);

        if (strcmp(answer, questions[i].answer) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }
    }

    printf("You got %d out of %d questions correct.\n", num_correct, num_questions);

    return 0;
}