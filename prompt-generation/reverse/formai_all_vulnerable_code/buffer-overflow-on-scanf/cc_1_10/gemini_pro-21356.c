//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Question {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;

typedef struct Student {
    char name[64];
    int score;
} Student;

Question questions[] = {
    {"What is the capital of India?", {"Delhi", "Mumbai", "Chennai", "Kolkata"}, 1},
    {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
    {"What is the currency of India?", {"Rupee", "Dollar", "Euro", "Pound"}, 1},
    {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Leopard"}, 1},
    {"What is the national bird of India?", {"Peacock", "Eagle", "Owl", "Parrot"}, 1}
};

int num_questions = sizeof(questions) / sizeof(Question);

Student students[100];
int num_students = 0;

void add_student(char *name) {
    strcpy(students[num_students].name, name);
    students[num_students].score = 0;
    num_students++;
}

void take_exam(Student *student) {
    int i;
    for (i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        if (answer == questions[i].correct_option) {
            student->score++;
        }
    }
}

void print_results() {
    int i;
    for (i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add student\n2. Take exam\n3. Print results\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char name[64];
                printf("Enter student name: ");
                scanf("%s", name);
                add_student(name);
                break;
            }
            case 2: {
                char name[64];
                printf("Enter student name: ");
                scanf("%s", name);
                Student *student = NULL;
                int i;
                for (i = 0; i < num_students; i++) {
                    if (strcmp(students[i].name, name) == 0) {
                        student = &students[i];
                        break;
                    }
                }
                if (student == NULL) {
                    printf("Student not found\n");
                } else {
                    take_exam(student);
                }
                break;
            }
            case 3: {
                print_results();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}