//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *question;
    char **answers;
    int num_answers;
    int correct_answer;
} Question;

typedef struct {
    char *name;
    int score;
} Student;

int main() {
    // Create a question database
    Question questions[] = {
        {
            .question = "What is the capital of France?",
            .answers = {"Paris", "London", "Rome", "Berlin"},
            .num_answers = 4,
            .correct_answer = 0
        },
        {
            .question = "Who is the author of the book '1984'?",
            .answers = {"George Orwell", "Aldous Huxley", "Ray Bradbury", "Isaac Asimov"},
            .num_answers = 4,
            .correct_answer = 0
        },
        {
            .question = "What is the chemical symbol for gold?",
            .answers = {"Au", "Ag", "Cu", "Fe"},
            .num_answers = 4,
            .correct_answer = 0
        },
        {
            .question = "What is the largest planet in our solar system?",
            .answers = {"Jupiter", "Saturn", "Uranus", "Neptune"},
            .num_answers = 4,
            .correct_answer = 0
        },
        {
            .question = "What is the name of the largest ocean on Earth?",
            .answers = {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"},
            .num_answers = 4,
            .correct_answer = 0
        }
    };

    // Create a student database
    Student students[] = {
        {
            .name = "John Doe",
            .score = 0
        },
        {
            .name = "Jane Doe",
            .score = 0
        },
        {
            .name = "Peter Parker",
            .score = 0
        },
        {
            .name = "Mary Jane Watson",
            .score = 0
        },
        {
            .name = "Bruce Wayne",
            .score = 0
        }
    };

    // Start the examination
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    char name[256];
    scanf("%s", name);

    // Find the student in the database
    Student *student = NULL;
    for (int i = 0; i < sizeof(students) / sizeof(Student); i++) {
        if (strcmp(students[i].name, name) == 0) {
            student = &students[i];
            break;
        }
    }

    // If the student was not found, create a new student
    if (student == NULL) {
        student = malloc(sizeof(Student));
        student->name = strdup(name);
        student->score = 0;
    }

    // Ask the student questions
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < questions[i].num_answers; j++) {
            printf("%d. %s\n", j + 1, questions[i].answers[j]);
        }
        printf("Enter your answer: ");
        int answer;
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == questions[i].correct_answer) {
            student->score++;
        }
    }

    // Print the student's score
    printf("\nYour score is %d out of %d.\n", student->score, sizeof(questions) / sizeof(Question));

    // Free the memory allocated for the student
    free(student->name);
    free(student);

    return 0;
}