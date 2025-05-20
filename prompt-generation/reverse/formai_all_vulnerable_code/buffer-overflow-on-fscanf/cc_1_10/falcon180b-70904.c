//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTION 100
#define MAX_ANSWER 100
#define MAX_SCORE 100
#define MAX_USER 100

typedef struct {
    char question[MAX_QUESTION];
    char answer[MAX_ANSWER];
    int score;
} Question;

typedef struct {
    char name[MAX_USER];
    int score;
} User;

int main() {
    int num_questions, num_users, i, j, k, score;
    char filename[MAX_USER];
    Question questions[MAX_QUESTION];
    User users[MAX_USER];

    // Read questions from file
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open questions file.\n");
        exit(1);
    }
    num_questions = 0;
    while (fscanf(fp, "%s %s %d\n", questions[num_questions].question, questions[num_questions].answer, &questions[num_questions].score)!= EOF) {
        num_questions++;
    }
    fclose(fp);

    // Read users from file
    printf("Enter filename of user list: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open user list file.\n");
        exit(1);
    }
    num_users = 0;
    while (fscanf(fp, "%s\n", users[num_users].name)!= EOF) {
        num_users++;
    }
    fclose(fp);

    // Conduct exam
    for (i = 0; i < num_users; i++) {
        printf("User %d, please answer the following questions:\n", i + 1);
        score = 0;
        for (j = 0; j < num_questions; j++) {
            printf("%s\n", questions[j].question);
            scanf("%s", users[i].name);
            k = strlen(users[i].name);
            if (k > 0 && tolower(users[i].name[k - 1]) == tolower(questions[j].answer[k - 1])) {
                score++;
            }
        }
        printf("Your score is %d out of %d.\n", score, num_questions);
    }

    return 0;
}