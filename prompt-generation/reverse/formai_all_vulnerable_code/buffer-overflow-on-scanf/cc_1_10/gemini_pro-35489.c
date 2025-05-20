//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char password[50];
    int score;
} Student;

typedef struct {
    int id;
    char question[500];
    char options[4][50];
    int correct_option;
} Question;

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create an array of students
    Student students[5] = {
        {1, "Alice", "password1", 0},
        {2, "Bob", "password2", 0},
        {3, "Carol", "password3", 0},
        {4, "Dave", "password4", 0},
        {5, "Eve", "password5", 0}
    };

    // Create an array of questions
    Question questions[10] = {
        {1, "What is the capital of France?", {"Paris", "London", "Rome", "Berlin"}, 1},
        {2, "What is the largest ocean in the world?", {"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"}, 2},
        {3, "What is the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, 1},
        {4, "What is the speed of light?", {"186,000 miles per second", "299,792 kilometers per second", "300,000 miles per second", "280,000 kilometers per second"}, 2},
        {5, "What is the name of the largest moon in the solar system?", {"Ganymede", "Titan", "Callisto", "Io"}, 1},
        {6, "What is the name of the dwarf planet that was once considered the ninth planet from the sun?", {"Pluto", "Eris", "Haumea", "Makemake"}, 1},
        {7, "What is the name of the largest desert in the world?", {"Sahara Desert", "Gobi Desert", "Atacama Desert", "Antarctic Polar Desert"}, 1},
        {8, "What is the name of the tallest mountain in the world?", {"Mount Everest", "K2", "Kangchenjunga", "Lhotse"}, 1},
        {9, "What is the name of the largest river in the world?", {"Nile River", "Amazon River", "Yangtze River", "Mississippi River"}, 1},
        {10, "What is the name of the largest country in the world by land area?", {"Russia", "Canada", "China", "United States"}, 1}
    };

    // Get the student's login information
    int student_id;
    char student_password[50];
    printf("Enter your student ID: ");
    scanf("%d", &student_id);
    printf("Enter your password: ");
    scanf("%s", student_password);

    // Verify the student's login information
    int student_index = -1;
    for (int i = 0; i < 5; i++) {
        if (students[i].id == student_id && strcmp(students[i].password, student_password) == 0) {
            student_index = i;
            break;
        }
    }

    // If the student's login information is invalid, exit the program
    if (student_index == -1) {
        printf("Invalid login information. Exiting program.\n");
        return 1;
    }

    // Get the number of questions the student wants to answer
    int num_questions;
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);

    // Generate a random set of questions for the student
    int *question_ids = malloc(num_questions * sizeof(int));
    for (int i = 0; i < num_questions; i++) {
        int question_id = rand() % 10 + 1;
        question_ids[i] = question_id;
    }

    // Ask the student the questions and record their answers
    int *answers = malloc(num_questions * sizeof(int));
    for (int i = 0; i < num_questions; i++) {
        Question question = questions[question_ids[i] - 1];
        printf("%d. %s\n", i + 1, question.question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, question.options[j]);
        }
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        answers[i] = answer;
    }

    // Grade the student's answers
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        Question question = questions[question_ids[i] - 1];
        if (answers[i] == question.correct_option) {
            score++;
        }
    }

    // Print the student's score
    printf("Your score is %d out of %d.\n", score, num_questions);

    // Free the dynamically allocated memory
    free(question_ids);
    free(answers);

    return 0;
}