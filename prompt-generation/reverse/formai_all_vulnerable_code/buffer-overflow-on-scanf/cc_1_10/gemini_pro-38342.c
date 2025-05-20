//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *question;
    char **options;
    int num_options;
    int correct_option;
} Question;

typedef struct {
    char *name;
    int score;
} Student;

int main() {
    // Initialize the questions
    Question questions[] = {
        {
            "What is the capital of France?",
            (char *[]){
                "Paris",
                "London",
                "Berlin",
                "Rome",
            },
            4,
            0
        },
        {
            "Who is the current president of the United States?",
            (char *[]){
                "Donald Trump",
                "Joe Biden",
                "Barack Obama",
                "George W. Bush",
            },
            4,
            1
        },
        {
            "What is the largest ocean in the world?",
            (char *[]){
                "Pacific Ocean",
                "Atlantic Ocean",
                "Indian Ocean",
                "Arctic Ocean",
            },
            4,
            0
        },
        {
            "What is the chemical symbol for gold?",
            (char *[]){
                "Au",
                "Ag",
                "Cu",
                "Fe",
            },
            4,
            0
        },
        {
            "What is the capital of Australia?",
            (char *[]){
                "Sydney",
                "Melbourne",
                "Perth",
                "Canberra",
            },
            4,
            3
        },
    };

    // Initialize the students
    Student students[] = {
        {
            "John Doe",
            0
        },
        {
            "Jane Doe",
            0
        },
        {
            "Peter Parker",
            0
        },
        {
            "Mary Jane",
            0
        },
        {
            "Bruce Wayne",
            0
        },
    };

    // Get the number of questions and students
    int num_questions = sizeof(questions) / sizeof(questions[0]);
    int num_students = sizeof(students) / sizeof(students[0]);

    // Loop over the students
    for (int i = 0; i < num_students; i++) {
        // Loop over the questions
        for (int j = 0; j < num_questions; j++) {
            // Print the question
            printf("%s\n", questions[j].question);

            // Loop over the options
            for (int k = 0; k < questions[j].num_options; k++) {
                // Print the option
                printf("%d. %s\n", k + 1, questions[j].options[k]);
            }

            // Get the student's answer
            int answer;
            scanf("%d", &answer);

            // Check if the answer is correct
            if (answer == questions[j].correct_option) {
                // Increment the student's score
                students[i].score++;
            }
        }
    }

    // Print the results
    printf("Results:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}