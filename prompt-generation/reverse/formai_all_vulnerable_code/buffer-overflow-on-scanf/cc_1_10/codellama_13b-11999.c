//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: shocked
// A unique C Online Examination System example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a question
struct Question {
    int id;
    char* question;
    char* options[4];
    int correct_option;
};

// Structure to represent a student
struct Student {
    int id;
    char* name;
    char* email;
    int marks;
};

// Function to display the questions
void display_questions(struct Question* questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
    }
}

// Function to display the student information
void display_student_information(struct Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%d. %s (%s)\n", i + 1, students[i].name, students[i].email);
    }
}

// Function to display the results
void display_results(struct Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%d. %s (%s) - %d\n", i + 1, students[i].name, students[i].email, students[i].marks);
    }
}

int main() {
    // Initialize the questions
    struct Question questions[3] = {
        {1, "What is the capital of France?", {"Paris", "London", "Berlin", "Rome"}, 0},
        {2, "What is the largest planet in our solar system?", {"Earth", "Saturn", "Jupiter", "Mars"}, 2},
        {3, "What is the smallest country in the world?", {"Vatican City", "Monaco", "Switzerland", "Liechtenstein"}, 0}
    };

    // Initialize the students
    struct Student students[3] = {
        {1, "John", "john@example.com", 0},
        {2, "Jane", "jane@example.com", 0},
        {3, "Bob", "bob@example.com", 0}
    };

    // Display the questions
    display_questions(questions, 3);

    // Display the student information
    display_student_information(students, 3);

    // Ask the students to answer the questions
    for (int i = 0; i < 3; i++) {
        int answer;
        printf("Enter the answer for question %d: ", i + 1);
        scanf("%d", &answer);
        students[i].marks += answer == questions[i].correct_option ? 1 : 0;
    }

    // Display the results
    display_results(students, 3);

    return 0;
}