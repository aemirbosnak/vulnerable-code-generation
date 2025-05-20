//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures
typedef struct {
    char name[256];
    int score;
} Student;

typedef struct {
    char name[256];
    int question_number;
    int correct_answer;
    int selected_answer;
} Question;

// Functions
void print_menu();
void print_questions(Question *questions, int num_questions);
int get_correct_answer(Question *questions, int num_questions);
int get_selected_answer(Question *questions, int num_questions);
int calculate_score(int correct_answer, int selected_answer);
void print_results(Student *students, int num_students);

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Declare variables
    int num_students = 10;
    int num_questions = 10;
    Student *students = malloc(num_students * sizeof(Student));
    Question *questions = malloc(num_questions * sizeof(Question));

    // Initialize students and questions
    for (int i = 0; i < num_students; i++) {
        strcpy(students[i].name, "Student ");
        students[i].name[i + 1] = '1' + i;
    }
    for (int i = 0; i < num_questions; i++) {
        strcpy(questions[i].name, "Question ");
        questions[i].name[i + 1] = '1' + i;
        questions[i].question_number = i + 1;
        questions[i].correct_answer = rand() % 4 + 1;
        questions[i].selected_answer = 0;
    }

    // Print menu
    print_menu();

    // Print questions
    print_questions(questions, num_questions);

    // Get correct answers
    int correct_answer = get_correct_answer(questions, num_questions);

    // Get selected answers
    int selected_answer = get_selected_answer(questions, num_questions);

    // Calculate scores
    int score = calculate_score(correct_answer, selected_answer);

    // Print results
    print_results(students, num_students);

    // Free memory
    free(students);
    free(questions);

    return 0;
}

// Function definitions
void print_menu() {
    printf("-------------------------------------------------\n");
    printf("   C Online Examination System\n");
    printf("-------------------------------------------------\n");
    printf("1. Start Examination\n");
    printf("2. View Results\n");
    printf("3. Exit\n");
    printf("-------------------------------------------------\n");
}

void print_questions(Question *questions, int num_questions) {
    printf("-------------------------------------------------\n");
    printf("   Questions\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", questions[i].question_number, questions[i].name);
    }
    printf("-------------------------------------------------\n");
}

int get_correct_answer(Question *questions, int num_questions) {
    int correct_answer = 0;
    for (int i = 0; i < num_questions; i++) {
        correct_answer += questions[i].correct_answer;
    }
    return correct_answer;
}

int get_selected_answer(Question *questions, int num_questions) {
    int selected_answer = 0;
    for (int i = 0; i < num_questions; i++) {
        selected_answer += questions[i].selected_answer;
    }
    return selected_answer;
}

int calculate_score(int correct_answer, int selected_answer) {
    int score = (correct_answer / selected_answer) * 100;
    return score;
}

void print_results(Student *students, int num_students) {
    printf("-------------------------------------------------\n");
    printf("   Results\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d: %s\n", students[i].name, students[i].score);
    }
    printf("-------------------------------------------------\n");
}