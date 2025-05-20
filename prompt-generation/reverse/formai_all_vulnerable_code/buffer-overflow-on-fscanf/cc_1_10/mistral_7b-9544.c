//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random numbers
int random_number_generator(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Structure to represent a question
typedef struct {
    char question[100];
    int option1, option2, option3, option4, answer;
} Question;

// Function to load questions from a file
void load_questions(Question* questions, char* filename, int num_questions) {
    FILE* file = fopen(filename, "r");
    int i = 0;

    if (file == NULL) {
        printf("Error: Unable to open questions file.\n");
        exit(EXIT_FAILURE);
    }

    while (i < num_questions && fscanf(file, "%s %d %d %d %d", questions[i].question, &questions[i].option1, &questions[i].option2, &questions[i].option3, &questions[i].answer) == 5) {
        i++;
    }

    fclose(file);
}

// Function to display a question and take user input
int ask_question(Question question) {
    printf("\n%s\n", question.question);
    printf("1. %d\n", question.option1);
    printf("2. %d\n", question.option2);
    printf("3. %d\n", question.option3);

    int choice;
    scanf("%d", &choice);

    return choice;
}

// Function to check if user answered correctly
int check_answer(int user_answer, Question question) {
    return user_answer == question.answer;
}

// Function to generate and display a random question
void generate_question(Question question) {
    printf("\nQuestion %d:\n", random_number_generator(1, 10));
    printf("%s\n", question.question);
    printf("1. %d\n", question.option1);
    printf("2. %d\n", question.option2);
    printf("3. %d\n", question.option3);
}

// Function to start the examination
void start_examination(Question* questions, int num_questions) {
    srand(time(NULL));
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        generate_question(questions[i]);
        int user_answer = ask_question(questions[i]);
        if (check_answer(user_answer, questions[i])) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", questions[i].answer);
        }
    }

    printf("\nYour score is %d out of %d.\n", score, num_questions);
}

int main() {
    int num_questions = 10;
    Question questions[num_questions];

    char filename[50] = "questions.txt";
    load_questions(questions, filename, num_questions);

    start_examination(questions, num_questions);

    return 0;
}