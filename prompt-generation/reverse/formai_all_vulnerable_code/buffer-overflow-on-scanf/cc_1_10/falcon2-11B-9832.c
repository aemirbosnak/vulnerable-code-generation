//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_students, num_questions, total_marks, current_marks;
    char student_name[50], question[50];

    // Get number of students
    printf("Enter number of students: ");
    scanf("%d", &num_students);

    // Get number of questions
    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    // Get total marks
    printf("Enter total marks: ");
    scanf("%d", &total_marks);

    // Initialize current marks
    current_marks = 0;

    // Loop through each student
    for (int i = 0; i < num_students; i++) {
        printf("Enter student name: ");
        scanf("%s", student_name);

        // Loop through each question
        for (int j = 0; j < num_questions; j++) {
            printf("Enter question %d: ", j+1);
            scanf("%s", question);

            // Calculate marks
            if (strcmp(question, "Correct Answer") == 0) {
                current_marks += total_marks;
            } else {
                current_marks += 0;
            }

            // Print current marks
            printf("Current marks for student %s: %d\n", student_name, current_marks);
        }
    }

    // Print total marks
    printf("Total marks: %d\n", current_marks);

    return 0;
}