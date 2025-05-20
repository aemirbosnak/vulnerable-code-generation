//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXAMS 10
#define MAX_QUESTIONS 5
#define MAX_STUDENTS 50
#define MAX_STRING_LENGTH 100

typedef struct {
    char question[MAX_STRING_LENGTH];
    char options[4][MAX_STRING_LENGTH];
    char answer;
} Question;

typedef struct {
    char title[MAX_STRING_LENGTH];
    Question questions[MAX_QUESTIONS];
    int question_count;
} Exam;

typedef struct {
    char name[MAX_STRING_LENGTH];
    int score;
} Student;

Exam exams[MAX_EXAMS];
Student students[MAX_STUDENTS];
int exam_count = 0;
int student_count = 0;

void create_exam() {
    if (exam_count >= MAX_EXAMS) {
        printf("Maximum number of exams reached.\n");
        return;
    }
    
    Exam new_exam;
    printf("Enter exam title: ");
    getchar(); // To clear the newline from previous input
    fgets(new_exam.title, MAX_STRING_LENGTH, stdin);
    new_exam.title[strcspn(new_exam.title, "\n")] = 0; // Remove newline character
    new_exam.question_count = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question %d (or type 'done' to finish): ", i + 1);
        fgets(new_exam.questions[i].question, MAX_STRING_LENGTH, stdin);
        new_exam.questions[i].question[strcspn(new_exam.questions[i].question, "\n")] = 0;

        if (strcmp(new_exam.questions[i].question, "done") == 0) {
            new_exam.question_count = i;
            break;
        }

        printf("Enter option A: ");
        fgets(new_exam.questions[i].options[0], MAX_STRING_LENGTH, stdin);
        printf("Enter option B: ");
        fgets(new_exam.questions[i].options[1], MAX_STRING_LENGTH, stdin);
        printf("Enter option C: ");
        fgets(new_exam.questions[i].options[2], MAX_STRING_LENGTH, stdin);
        printf("Enter option D: ");
        fgets(new_exam.questions[i].options[3], MAX_STRING_LENGTH, stdin);
        printf("Enter correct answer (A/B/C/D): ");
        scanf(" %c", &new_exam.questions[i].answer);
        getchar(); // To clear the newline from the buffer

        new_exam.question_count++;
    }

    exams[exam_count++] = new_exam;

    printf("Exam '%s' created successfully!\n", new_exam.title);
}

void take_exam() {
    if (exam_count == 0) {
        printf("No exams available.\n");
        return;
    }

    printf("Available exams:\n");
    for (int i = 0; i < exam_count; i++) {
        printf("%d. %s\n", i + 1, exams[i].title);
    }

    int choice;
    printf("Select an exam number to take: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > exam_count) {
        printf("Invalid exam selection.\n");
        return;
    }

    choice--; // Adjust for 0-based index
    Exam selected_exam = exams[choice];
    
    printf("You are taking the exam: %s\n", selected_exam.title);
    int score = 0;

    for (int i = 0; i < selected_exam.question_count; i++) {
        printf("Q%d: %s\n", i + 1, selected_exam.questions[i].question);
        printf("A: %s", selected_exam.questions[i].options[0]);
        printf("B: %s", selected_exam.questions[i].options[1]);
        printf("C: %s", selected_exam.questions[i].options[2]);
        printf("D: %s", selected_exam.questions[i].options[3]);
        
        char answer;
        printf("Your answer: ");
        scanf(" %c", &answer);

        if (answer == selected_exam.questions[i].answer) {
            score++;
        }
    }

    printf("Your final score is: %d out of %d\n", score, selected_exam.question_count);
    printf("Do you want to save your result? (yes/no): ");
    char response[MAX_STRING_LENGTH];
    scanf("%s", response);

    if (strcmp(response, "yes") == 0) {
        if (student_count >= MAX_STUDENTS) {
            printf("Maximum number of students reached. Cannot save result.\n");
            return;
        }
        printf("Enter your name: ");
        getchar(); // Clear newline
        fgets(students[student_count].name, MAX_STRING_LENGTH, stdin);
        students[student_count].name[strcspn(students[student_count].name, "\n")] = 0; // Remove newline

        students[student_count].score = score;
        student_count++;
        printf("Result saved successfully!\n");
    }
}

void view_results() {
    if (student_count == 0) {
        printf("No results available.\n");
        return;
    }

    printf("Student Results:\n");
    for (int i = 0; i < student_count; i++) {
        printf("Name: %s, Score: %d\n", students[i].name, students[i].score);
    }
}

int main() {
    int option;
    while (1) {
        printf("Welcome to the Online Examination System\n");
        printf("1. Create Exam\n");
        printf("2. Take Exam\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                create_exam();
                break;
            case 2:
                take_exam();
                break;
            case 3:
                view_results();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}