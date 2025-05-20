//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a question
typedef struct {
    char *question;
    char *options[4];
    int correct_option;
} Question;

// Data structure to store a student's answer
typedef struct {
    int question_id;
    int answer;
} Answer;

// Function to create a new question
Question *create_question(char *question, char *option1, char *option2, char *option3, char *option4, int correct_option) {
    Question *new_question = malloc(sizeof(Question));
    new_question->question = strdup(question);
    new_question->options[0] = strdup(option1);
    new_question->options[1] = strdup(option2);
    new_question->options[2] = strdup(option3);
    new_question->options[3] = strdup(option4);
    new_question->correct_option = correct_option;
    return new_question;
}

// Function to free the memory allocated to a question
void free_question(Question *question) {
    free(question->question);
    for (int i = 0; i < 4; i++) {
        free(question->options[i]);
    }
    free(question);
}

// Function to create a new answer
Answer *create_answer(int question_id, int answer) {
    Answer *new_answer = malloc(sizeof(Answer));
    new_answer->question_id = question_id;
    new_answer->answer = answer;
    return new_answer;
}

// Function to free the memory allocated to an answer
void free_answer(Answer *answer) {
    free(answer);
}

// Function to load questions from a file
Question **load_questions(char *filename, int *num_questions) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the number of questions from the file
    fscanf(fp, "%d", num_questions);

    // Allocate memory for the questions
    Question **questions = malloc(*num_questions * sizeof(Question *));

    // Read each question from the file
    for (int i = 0; i < *num_questions; i++) {
        char question[1024];
        char options[4][1024];
        int correct_option;

        // Read the question
        fgets(question, 1024, fp);

        // Read the options
        for (int j = 0; j < 4; j++) {
            fgets(options[j], 1024, fp);
        }

        // Read the correct option
        fscanf(fp, "%d", &correct_option);

        // Create the question
        questions[i] = create_question(question, options[0], options[1], options[2], options[3], correct_option);
    }

    // Close the file
    fclose(fp);

    return questions;
}

// Function to free the memory allocated to the questions
void free_questions(Question **questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        free_question(questions[i]);
    }
    free(questions);
}

// Function to load answers from a file
Answer **load_answers(char *filename, int *num_answers) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the number of answers from the file
    fscanf(fp, "%d", num_answers);

    // Allocate memory for the answers
    Answer **answers = malloc(*num_answers * sizeof(Answer *));

    // Read each answer from the file
    for (int i = 0; i < *num_answers; i++) {
        int question_id;
        int answer;

        // Read the question ID
        fscanf(fp, "%d", &question_id);

        // Read the answer
        fscanf(fp, "%d", &answer);

        // Create the answer
        answers[i] = create_answer(question_id, answer);
    }

    // Close the file
    fclose(fp);

    return answers;
}

// Function to free the memory allocated to the answers
void free_answers(Answer **answers, int num_answers) {
    for (int i = 0; i < num_answers; i++) {
        free_answer(answers[i]);
    }
    free(answers);
}

// Function to administer the exam
int administer_exam(Question **questions, int num_questions, Answer **answers, int num_answers) {
    // Print the instructions
    printf("Welcome to the online exam!\n");
    printf("You will be given %d questions.\n", num_questions);
    printf("Each question has 4 options.\n");
    printf("Choose the best answer for each question.\n");
    printf("Enter your answer as a number (1-4).\n");

    // Loop through the questions
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        // Print the question
        printf("\nQuestion %d:\n", i + 1);
        printf("%s", questions[i]->question);

        // Print the options
        for (int j = 0; j < 4; j++) {
            printf("%d. %s", j + 1, questions[i]->options[j]);
        }

        // Get the student's answer
        int answer;
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == questions[i]->correct_option) {
            score++;
        }
    }

    // Print the score
    printf("\nYour score is %d out of %d.\n", score, num_questions);

    return score;
}

int main() {
    // Load the questions and answers from files
    int num_questions;
    Question **questions = load_questions("questions.txt", &num_questions);

    int num_answers;
    Answer **answers = load_answers("answers.txt", &num_answers);

    // Administer the exam
    int score = administer_exam(questions, num_questions, answers, num_answers);

    // Free the memory allocated to the questions and answers
    free_questions(questions, num_questions);
    free_answers(answers, num_answers);

    return 0;
}