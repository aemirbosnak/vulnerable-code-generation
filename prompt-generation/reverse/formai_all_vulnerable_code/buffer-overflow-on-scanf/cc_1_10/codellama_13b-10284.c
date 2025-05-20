//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: irregular
// Program to create an online examination system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// structure to store the exam information
struct Exam {
    int id;
    char name[100];
    char description[100];
    int duration;
    int total_questions;
    int marks_per_question;
};

// structure to store the question information
struct Question {
    int id;
    char question[100];
    char answer[100];
};

// structure to store the user information
struct User {
    int id;
    char name[100];
    char email[100];
    char password[100];
};

// structure to store the exam result
struct ExamResult {
    int id;
    int exam_id;
    int user_id;
    int marks;
};

// function to generate a random exam ID
int generate_exam_id() {
    srand(time(0));
    return rand() % 100000 + 1;
}

// function to generate a random question ID
int generate_question_id() {
    srand(time(0));
    return rand() % 100000 + 1;
}

// function to generate a random user ID
int generate_user_id() {
    srand(time(0));
    return rand() % 100000 + 1;
}

// function to generate a random exam result
int generate_exam_result(int exam_id, int user_id) {
    srand(time(0));
    return rand() % 100 + 1;
}

// function to create a new exam
void create_exam(struct Exam *exam) {
    exam->id = generate_exam_id();
    printf("Enter exam name: ");
    scanf("%s", exam->name);
    printf("Enter exam description: ");
    scanf("%s", exam->description);
    printf("Enter exam duration: ");
    scanf("%d", &exam->duration);
    printf("Enter total number of questions: ");
    scanf("%d", &exam->total_questions);
    printf("Enter marks per question: ");
    scanf("%d", &exam->marks_per_question);
}

// function to create a new question
void create_question(struct Question *question) {
    question->id = generate_question_id();
    printf("Enter question: ");
    scanf("%s", question->question);
    printf("Enter answer: ");
    scanf("%s", question->answer);
}

// function to create a new user
void create_user(struct User *user) {
    user->id = generate_user_id();
    printf("Enter user name: ");
    scanf("%s", user->name);
    printf("Enter user email: ");
    scanf("%s", user->email);
    printf("Enter user password: ");
    scanf("%s", user->password);
}

// function to display exam information
void display_exam_info(struct Exam *exam) {
    printf("Exam ID: %d\n", exam->id);
    printf("Exam name: %s\n", exam->name);
    printf("Exam description: %s\n", exam->description);
    printf("Exam duration: %d\n", exam->duration);
    printf("Total number of questions: %d\n", exam->total_questions);
    printf("Marks per question: %d\n", exam->marks_per_question);
}

// function to display question information
void display_question_info(struct Question *question) {
    printf("Question ID: %d\n", question->id);
    printf("Question: %s\n", question->question);
    printf("Answer: %s\n", question->answer);
}

// function to display user information
void display_user_info(struct User *user) {
    printf("User ID: %d\n", user->id);
    printf("User name: %s\n", user->name);
    printf("User email: %s\n", user->email);
    printf("User password: %s\n", user->password);
}

// function to display exam result
void display_exam_result(struct ExamResult *result) {
    printf("Exam ID: %d\n", result->id);
    printf("Exam result: %d\n", result->marks);
}

// main function
int main() {
    struct Exam exam;
    struct Question question;
    struct User user;
    struct ExamResult result;

    // create a new exam
    create_exam(&exam);

    // create a new question
    create_question(&question);

    // create a new user
    create_user(&user);

    // display exam information
    display_exam_info(&exam);

    // display question information
    display_question_info(&question);

    // display user information
    display_user_info(&user);

    // generate exam result
    result.id = generate_exam_result(exam.id, user.id);

    // display exam result
    display_exam_result(&result);

    return 0;
}