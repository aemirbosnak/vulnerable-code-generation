//FormAI DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[100];
    int marks;
    char option_a[50];
    char option_b[50];
    char option_c[50];
    char option_d[50];
    char answer[5];
};

struct User {
    char name[50];
    int score;
};

int displayMenu() {
    int choice;
    printf("\n\n");
    printf("********** MAIN MENU **********\n");
    printf("1. Take Exam\n");
    printf("2. View Scores\n");
    printf("3. Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int takeExam(struct Question *questions, int n, struct User *user) {
    int score = 0;
    printf("\n\n");
    printf("********** EXAM **********\n\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s (Marks: %d)\n", i+1, questions[i].question, questions[i].marks);
        printf("   a. %s\n", questions[i].option_a);
        printf("   b. %s\n", questions[i].option_b);
        printf("   c. %s\n", questions[i].option_c);
        printf("   d. %s\n", questions[i].option_d);
        printf("   Your Answer: ");
        char ans[5];
        scanf("%s", ans);
        if (strcmp(ans, questions[i].answer) == 0) {
            score += questions[i].marks;
        }
    }
    printf("\n\n");
    printf("********** RESULT **********\n");
    printf("Name: %s\n", user->name);
    printf("Score: %d\n", score);
    user->score = score;
}

void viewScores(struct User *users, int n) {
    printf("\n\n");
    printf("********** SCORES **********\n\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s: %d\n", i+1, users[i].name, users[i].score);
    }
}

int main() {
    struct Question questions[5] = {
        {"What is the capital of USA?", 2, "New York", "California", "Washington DC", "Texas", "c"},
        {"What is the currency of Japan?", 1, "Rupee", "Yen", "Dollar", "Euro", "b"},
        {"Which is the largest continent?", 3, "Africa", "Asia", "Australia", "Europe", "b"},
        {"What is the largest mammal?", 2, "Elephant", "Blue Whale", "Giraffe", "Rhinoceros", "b"},
        {"What is the smallest planet?", 1, "Mercury", "Venus", "Earth", "Mars", "a"}
    };
    struct User users[10];
    int num_users = 0;
    int choice;
    while ((choice = displayMenu()) != 3) {
        if (choice == 1) {
            struct User user;
            printf("\nEnter your name: ");
            scanf("%s", user.name);
            takeExam(questions, 5, &user);
            users[num_users] = user;
            num_users++;
        } else if (choice == 2) {
            viewScores(users, num_users);
        }
    }
    return 0;
}