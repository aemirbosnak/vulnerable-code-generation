//FormAI DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to store student and exam data
struct Student {
    char name[20];
    int age;
    char gender;
    char department[20];
};

struct Exam {
    char subject[30];
    int duration;
    int marks;
};

int main() {
    // Welcome message
    printf("Welcome to the Online Exam System!\n");

    // Prompt for student data
    struct Student student;

    printf("Please enter your name: ");
    scanf("%s", student.name);

    printf("Please enter your age: ");
    scanf("%d", &student.age);

    printf("Please enter your gender (M/F): ");
    scanf(" %c", &student.gender);

    printf("Please enter your department: ");
    scanf("%s", student.department);

    // Prompt for exam data
    struct Exam exam;

    printf("Please enter the subject: ");
    scanf("%s", exam.subject);

    printf("Please enter the duration of the exam (in minutes): ");
    scanf("%d", &exam.duration);

    printf("Please enter the maximum marks: ");
    scanf("%d", &exam.marks);

    // Start the exam
    printf("\n\nThe exam has started. Good luck!\n\n");

    // Simulate the exam time
    int time_left = exam.duration;
    while (time_left > 0) {
        printf("Time remaining: %d minutes\n", time_left);
        time_left--;
    }

    // Get the student's answers and calculate marks
    int marks_obtained = 0;
    printf("\n\nPlease enter your answers:\n");
    for (int i = 1; i <= 10; i++) {
        printf("Question %d: ", i);
        char answer;
        scanf(" %c", &answer);
        if (answer == 'a') {
            marks_obtained += 1;
        }
    }

    // Display the results
    printf("\n\nResults:\n\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Gender: %c\n", student.gender);
    printf("Department: %s\n", student.department);
    printf("Subject: %s\n", exam.subject);
    printf("Marks Obtained: %d/%d\n", marks_obtained, exam.marks);

    return 0;
}