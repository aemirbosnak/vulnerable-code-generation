//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char question[256];
    char options[4][100];
    int answer; // Index of the correct answer (0-3)
} Question;

void displayQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int main() {
    int numQuestions, score = 0, selectedAnswer;
    Question *questions;

    printf("Welcome to the Online Examination System!\n");
    printf("Enter the number of questions you want in the quiz: ");
    scanf("%d", &numQuestions);

    // Dynamically allocating memory for questions
    questions = (Question *)malloc(numQuestions * sizeof(Question));
    if (questions == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Sample questions (typically you could load these from a file)
    for (int i = 0; i < numQuestions; i++) {
        printf("Enter question %d: ", i + 1);
        getchar(); // To consume the newline left by scanf
        fgets(questions[i].question, 256, stdin);
        questions[i].question[strcspn(questions[i].question, "\n")] = 0; // Remove newline

        for (int j = 0; j < 4; j++) {
            printf("Enter option %d: ", j + 1);
            fgets(questions[i].options[j], 100, stdin);
            questions[i].options[j][strcspn(questions[i].options[j], "\n")] = 0; // Remove newline
        }
        
        printf("Enter the correct answer (1-4): ");
        scanf("%d", &questions[i].answer);
        questions[i].answer--; // Adjusting index for 0-based indexing
    }

    // Start the quiz
    printf("\nStarting the quiz...\n");
    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questions[i]);
        printf("Your answer (1-4): ");
        scanf("%d", &selectedAnswer);
        selectedAnswer--; // Adjusting index for 0-based indexing

        if (selectedAnswer == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was: %d. %s\n", 
                   questions[i].answer + 1, questions[i].options[questions[i].answer]);
        }
        printf("\n");
    }

    // Display results
    printf("You scored %d out of %d.\n", score, numQuestions);
    
    // Freeing dynamically allocated memory
    free(questions);
    return 0;
}