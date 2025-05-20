//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_USERS 100

typedef struct {
    int id;
    char question[256];
    char answer[4][256];
    int correct_answer;
} Question;

typedef struct {
    int id;
    char name[256];
    char username[256];
    char password[256];
    int score;
} User;

Question questions[MAX_QUESTIONS];
User users[MAX_USERS];

void init_questions() {
    // Initialize questions here
}

void init_users() {
    // Initialize users here
}

void print_menu() {
    printf("1. Add question\n");
    printf("2. Delete question\n");
    printf("3. Edit question\n");
    printf("4. Take exam\n");
    printf("5. View results\n");
    printf("6. Exit\n");
}

void add_question() {
    printf("Enter question: ");
    scanf("%255s", questions[MAX_QUESTIONS].question);
    printf("Enter answer 1: ");
    scanf("%255s", questions[MAX_QUESTIONS].answer[0]);
    printf("Enter answer 2: ");
    scanf("%255s", questions[MAX_QUESTIONS].answer[1]);
    printf("Enter answer 3: ");
    scanf("%255s", questions[MAX_QUESTIONS].answer[2]);
    printf("Enter answer 4: ");
    scanf("%255s", questions[MAX_QUESTIONS].answer[3]);
    printf("Enter correct answer: ");
    scanf("%d", &questions[MAX_QUESTIONS].correct_answer);
}

void delete_question() {
    int id;
    printf("Enter question ID: ");
    scanf("%d", &id);
    for (int i = id; i < MAX_QUESTIONS; i++) {
        questions[i] = questions[i + 1];
    }
}

void edit_question() {
    int id;
    printf("Enter question ID: ");
    scanf("%d", &id);
    printf("Enter new question: ");
    scanf("%255s", questions[id].question);
    printf("Enter new answer 1: ");
    scanf("%255s", questions[id].answer[0]);
    printf("Enter new answer 2: ");
    scanf("%255s", questions[id].answer[1]);
    printf("Enter new answer 3: ");
    scanf("%255s", questions[id].answer[2]);
    printf("Enter new answer 4: ");
    scanf("%255s", questions[id].answer[3]);
    printf("Enter new correct answer: ");
    scanf("%d", &questions[id].correct_answer);
}

void take_exam() {
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int answer;
        printf("%s", questions[i].question);
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%d. %s\n", j + 1, questions[i].answer[j]);
        }
        scanf("%d", &answer);
        if (answer == questions[i].correct_answer) {
            score++;
        }
    }
    printf("Your score is %d out of %d\n", score, MAX_QUESTIONS);
}

void view_results() {
    for (int i = 0; i < MAX_USERS; i++) {
        printf("%s: %d\n", users[i].name, users[i].score);
    }
}

int main() {
    srand(time(NULL));
    init_questions();
    init_users();
    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_question();
                break;
            case 2:
                delete_question();
                break;
            case 3:
                edit_question();
                break;
            case 4:
                take_exam();
                break;
            case 5:
                view_results();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}