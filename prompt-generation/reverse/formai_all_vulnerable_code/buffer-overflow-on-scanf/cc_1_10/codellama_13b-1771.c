//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: rigorous
// Example program in a rigorous style for a C online examination system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Structures to store student information and question information
typedef struct {
    char name[50];
    int roll_no;
    int score;
} Student;

typedef struct {
    char question[50];
    int answer;
} Question;

// Function to generate a random question
void generate_question(Question *question) {
    int i, j;
    char temp;

    // Generate a random number between 1 and 10
    int random_number = rand() % 10 + 1;

    // Assign the random number to the question
    question->answer = random_number;

    // Generate a random string of letters
    for (i = 0; i < 50; i++) {
        question->question[i] = 'a' + rand() % 26;
    }

    // Shuffle the letters in the string
    for (i = 0; i < 50; i++) {
        j = rand() % 50;
        temp = question->question[i];
        question->question[i] = question->question[j];
        question->question[j] = temp;
    }
}

// Function to check the answer
int check_answer(Question *question, int answer) {
    if (question->answer == answer) {
        return 1;
    }
    else {
        return 0;
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the student and question structures
    Student student;
    Question question;

    // Get the student's name and roll number
    printf("Enter your name: ");
    scanf("%s", student.name);
    printf("Enter your roll number: ");
    scanf("%d", &student.roll_no);

    // Generate a random question
    generate_question(&question);

    // Print the question
    printf("Question: %s\n", question.question);

    // Get the student's answer
    printf("Enter your answer: ");
    scanf("%d", &student.score);

    // Check the answer
    if (check_answer(&question, student.score)) {
        printf("Correct answer!\n");
    }
    else {
        printf("Wrong answer!\n");
    }

    // Print the student's score
    printf("Your score is %d out of 100.\n", student.score);

    return 0;
}