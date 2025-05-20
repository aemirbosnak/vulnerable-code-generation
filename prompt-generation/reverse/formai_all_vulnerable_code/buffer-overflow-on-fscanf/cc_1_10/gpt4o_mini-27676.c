//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_LENGTH 256

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int correct_option; // Index of the correct option (0-based)
} Question;

typedef struct {
    char name[MAX_LENGTH];
    int score;
} Participant;

Question questions[MAX_QUESTIONS];
int total_questions = 0;

void load_questions() {
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        perror("Unable to open questions file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%[^\n]\n", questions[total_questions].question) != EOF) {
        for (int i = 0; i < MAX_OPTIONS; i++) {
            fscanf(file, "%[^\n]\n", questions[total_questions].options[i]);
        }
        fscanf(file, "%d\n", &questions[total_questions].correct_option);
        total_questions++;
    }
    fclose(file);
}

void display_question(int index) {
    printf("\nQuestion %d: %s\n", index + 1, questions[index].question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[index].options[i]);
    }
}

int evaluate_answer(int question_index, int answer) {
    return (answer == questions[question_index].correct_option + 1);
}

void take_exam(Participant *participant) {
    for (int i = 0; i < total_questions; i++) {
        display_question(i);
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);

        if (evaluate_answer(i, answer)) {
            participant->score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer was: %d. %s\n", questions[i].correct_option + 1, questions[i].options[questions[i].correct_option]);
        }
    }
}

int main() {
    Participant participant;

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    fgets(participant.name, MAX_LENGTH, stdin);
    participant.name[strcspn(participant.name, "\n")] = 0; // Remove newline character

    participant.score = 0;

    load_questions();
    take_exam(&participant);

    printf("\nExam Complete! %s, your score is %d out of %d.\n", participant.name, participant.score, total_questions);

    return 0;
}