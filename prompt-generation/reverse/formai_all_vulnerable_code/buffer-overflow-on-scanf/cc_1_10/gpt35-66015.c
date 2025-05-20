//FormAI DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_of_questions = 0;
    int num_of_students = 0;
    int answer_key[100];
    int student_responses[100][100];
    float scores[100];

    printf("Welcome to the Online Examination System\n\n");
    printf("Please enter the number of questions: ");
    scanf("%d", &num_of_questions);

    printf("Please enter the answer key:\n");

    for(int i = 0; i < num_of_questions; i++) {
        scanf("%d", &answer_key[i]);
    }

    printf("Please enter the number of students: ");
    scanf("%d", &num_of_students);

    for(int i = 0; i < num_of_students; i++) {
        printf("Please enter the responses for student %d:\n", i+1);

        for(int j = 0; j < num_of_questions; j++) {
            scanf("%d", &student_responses[i][j]);
        }
    }

    printf("\nGrading...\n\n");

    for(int i = 0; i < num_of_students; i++) {
        int num_correct = 0;

        for(int j = 0; j < num_of_questions; j++) {
            if(student_responses[i][j] == answer_key[j]) {
                num_correct++;
            }
        }

        scores[i] = (float)num_correct/num_of_questions * 100;
    }

    printf("Results:\n\n");

    for(int i = 0; i < num_of_students; i++) {
        printf("Student %d: %.2f\n", i+1, scores[i]);
    }

    printf("\nThank you for using the Online Examination System!\n");

    return 0;
}