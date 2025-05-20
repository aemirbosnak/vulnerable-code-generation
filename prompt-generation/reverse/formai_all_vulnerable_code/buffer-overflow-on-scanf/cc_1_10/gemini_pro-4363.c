//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of questions and choices
#define NUM_QUESTIONS 10
#define NUM_CHOICES 4

// Define the question and answer structure
typedef struct {
    char question[256];
    char choices[NUM_CHOICES][64];
    int answer;
} Question;

// Define the student structure
typedef struct {
    char name[64];
    int score;
} Student;

// Create an array of questions
Question questions[] = {
    {"What is the capital of France?", {"Paris", "London", "Rome", "Berlin"}, 0},
    {"What is the largest ocean in the world?", {"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"}, 1},
    {"What is the tallest mountain in the world?", {"Mount Everest", "Mount Kilimanjaro", "Mount Denali", "Mount Fuji"}, 0},
    {"What is the most populous country in the world?", {"China", "India", "United States", "Indonesia"}, 0},
    {"What is the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, 0},
    {"What is the name of the largest planet in our solar system?", {"Jupiter", "Saturn", "Uranus", "Neptune"}, 0},
    {"What is the name of the first person to walk on the moon?", {"Neil Armstrong", "Buzz Aldrin", "Alan Shepard", "Yuri Gagarin"}, 0},
    {"What is the name of the largest desert in the world?", {"Sahara Desert", "Gobi Desert", "Atacama Desert", "Antarctic Polar Desert"}, 0},
    {"What is the name of the longest river in the world?", {"Nile River", "Amazon River", "Yangtze River", "Mississippi River"}, 0},
    {"What is the name of the largest lake in the world?", {"Caspian Sea", "Lake Superior", "Lake Baikal", "Lake Victoria"}, 0}
};

// Create an array of students
Student students[] = {
    {"John Doe", 0},
    {"Jane Smith", 0},
    {"Bill Jones", 0},
    {"Mary Johnson", 0},
    {"Tom Brown", 0}
};

// Declare the main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the questions
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int j = rand() % NUM_QUESTIONS;
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }

    // Get the student's name
    printf("Enter your name: ");
    char name[64];
    scanf("%s", name);

    // Find the student in the array of students
    Student* student = NULL;
    for (int i = 0; i < sizeof(students) / sizeof(Student); i++) {
        if (strcmp(name, students[i].name) == 0) {
            student = &students[i];
            break;
        }
    }

    // If the student was not found, create a new student
    if (student == NULL) {
        student = malloc(sizeof(Student));
        strcpy(student->name, name);
        student->score = 0;
    }

    // Start the exam
    printf("Welcome to the online examination system!\n");
    printf("You will be asked %d questions. Each question has %d choices.\n", NUM_QUESTIONS, NUM_CHOICES);
    printf("Good luck!\n\n");

    // Loop through the questions
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Print the question
        printf("%d. %s\n", i + 1, questions[i].question);

        // Print the choices
        for (int j = 0; j < NUM_CHOICES; j++) {
            printf("    %d. %s\n", j + 1, questions[i].choices[j]);
        }

        // Get the student's answer
        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == questions[i].answer) {
            student->score++;
        }
    }

    // Print the student's score
    printf("\nYour score is %d out of %d.\n", student->score, NUM_QUESTIONS);

    // Congratulate the student if they passed the exam
    if (student->score >= NUM_QUESTIONS / 2) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }

    return 0;
}