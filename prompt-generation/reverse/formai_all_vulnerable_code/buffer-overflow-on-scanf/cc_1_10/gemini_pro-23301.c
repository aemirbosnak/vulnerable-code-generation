//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Question structure
typedef struct {
    char *question;
    char **options;
    int num_options;
    int correct_option;
} Question;

// Student structure
typedef struct {
    char *name;
    int score;
} Student;

// Array of questions
Question questions[] = {
    {
        "What is the capital of France?",
        {"Paris", "London", "Rome", "Berlin"},
        4,
        0
    },
    {
        "Who painted the Mona Lisa?",
        {"Leonardo da Vinci", "Michelangelo", "Vincent van Gogh", "Pablo Picasso"},
        4,
        0
    },
    {
        "What is the largest ocean in the world?",
        {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"},
        4,
        0
    },
    {
        "Who wrote the Harry Potter series?",
        {"J.K. Rowling", "Stephen King", "George R.R. Martin", "Suzanne Collins"},
        4,
        0
    },
    {
        "What is the chemical symbol for gold?",
        {"Au", "Ag", "Cu", "Fe"},
        4,
        0
    }
};

// Array of students
Student students[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0},
    {"Dave", 0},
    {"Eve", 0}
};

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Shuffle the questions
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        int j = rand() % (i + 1);
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }

    // Shuffle the students
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        int j = rand() % (i + 1);
        Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
    }

    // Print the welcome message
    printf("Welcome to the Super Fun Online Examination System!\n");

    // Loop through the students
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        // Get the student's name
        char *name = students[i].name;

        // Print the student's name
        printf("Student %s, please take your seat.\n", name);

        // Loop through the questions
        for (int j = 0; j < sizeof(questions) / sizeof(questions[0]); j++) {
            // Get the question
            Question question = questions[j];

            // Print the question
            printf("%s\n", question.question);

            // Loop through the options
            for (int k = 0; k < question.num_options; k++) {
                // Get the option
                char *option = question.options[k];

                // Print the option
                printf("%d. %s\n", k + 1, option);
            }

            // Get the student's answer
            int answer;
            printf("Enter your answer (1-%d): ", question.num_options);
            scanf("%d", &answer);

            // Check if the answer is correct
            if (answer == question.correct_option) {
                // Increment the student's score
                students[i].score++;

                // Print a happy message
                printf("Yay! You got it right!\n");
            } else {
                // Print a sad message
                printf("Aww, that's not quite right.\n");
            }
        }

        // Print the student's score
        printf("Your score is %d out of %d.\n", students[i].score, sizeof(questions) / sizeof(questions[0]));

        // Print a goodbye message
        printf("Thank you for taking the exam, %s!\n", name);
    }

    return 0;
}