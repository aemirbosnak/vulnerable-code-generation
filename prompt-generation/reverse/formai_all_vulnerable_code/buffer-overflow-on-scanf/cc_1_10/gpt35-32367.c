//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    char text[100];
    char options[4][30];
    int correct_option;
};

void admin_add_question(struct question q[], int index) {
    printf("Enter question: ");
    fgets(q[index].text, 100, stdin);
    for (int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i+1);
        fgets(q[index].options[i], 30, stdin);
    }
    printf("Enter correct option (1-4): ");
    scanf("%d", &q[index].correct_option);
    getchar();  // Consume newline character
}

void start_exam(struct question q[], int n) {
    int score = 0;
    for (int i = 0; i < n; i++) {
        printf("Question %d:\n%s", i+1, q[i].text);
        for (int j = 0; j < 4; j++) {
            printf("%d) %s", j+1, q[i].options[j]);
        }
        printf("Your answer (1-4): ");
        int answer;
        scanf("%d", &answer);
        if (answer == q[i].correct_option) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Wrong answer.\n");
        }
    }
    printf("Your final score is %d out of %d.\n", score, n);
}

int main() {
    printf("Welcome to the Online Examination System!\n");
    printf("Are you an admin or a student? (a/s): ");
    char choice;
    scanf("%c", &choice);
    getchar();  // Consume newline character
    int num_questions = 0;
    struct question questions[50];
    if (choice == 'a') {
        printf("Enter number of questions you want to add: ");
        scanf("%d", &num_questions);
        getchar();  // Consume newline character
        for (int i = 0; i < num_questions; i++) {
            admin_add_question(questions, i);
        }
    } else if (choice == 's') {
        start_exam(questions, num_questions);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }
    printf("Thank you for using the Online Examination System!\n");
    return 0;
}