//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 10

// Structure to hold student information
typedef struct {
    char name[50];
    char rollNumber[15];
    int answers[MAX_QUESTIONS];
} Student;

// Structure to hold question information
typedef struct {
    char questionText[256];
    char options[4][100];
    int correctOption;
} Question;

// Function declarations
void registerStudent(Student* student);
void conductExam(Student* student, Question* questions);
void displayResults(Student* student, Question* questions);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
        {"2 + 2 = ?", {"3", "4", "5", "6"}, 1},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 1},
        {"What is the largest ocean on Earth?", {"Indian", "Pacific", "Atlantic", "Arctic"}, 1},
        {"Where is the Great Pyramid of Giza located?", {"Egypt", "Greece", "Mexico", "China"}, 0},
        {"Which element has the chemical symbol O?", {"Gold", "Oxygen", "Silver", "Iron"}, 1},
        {"Who wrote 'Romeo and Juliet'?", {"Mark Twain", "J.K. Rowling", "William Shakespeare", "Charles Dickens"}, 2},
        {"What is the speed of light?", {"300,000 km/s", "150,000 km/s", "1,000,000 km/s", "400,000 km/s"}, 0},
        {"Which is the hardest natural substance?", {"Gold", "Iron", "Diamond", "Graphite"}, 2},
        {"What is the powerhouse of the cell?", {"Nucleus", "Mitochondria", "Ribosome", "Golgi apparatus"}, 1},
    };

    printf("Online Examination System\n");
    
    // Register new students
    while (studentCount < MAX_STUDENTS) {
        printf("\nRegistering Student %d\n", studentCount + 1);
        registerStudent(&students[studentCount]);
        int takeExam;
        printf("Would you like to take the exam? (1 for Yes, 0 for No): ");
        scanf("%d", &takeExam);
        if (takeExam) {
            conductExam(&students[studentCount], questions);
            displayResults(&students[studentCount], questions);
        }
        studentCount++;
        char moreStudents;
        printf("Register another student? (y/n): ");
        scanf(" %c", &moreStudents);
        if (moreStudents != 'y') {
            break;
        }
    }

    printf("\nThank you for using the Online Examination System!\n");

    return 0;
}

void registerStudent(Student* student) {
    printf("Enter student name: ");
    scanf(" %[^\n]%*c", student->name);
    printf("Enter roll number: ");
    scanf("%s", student->rollNumber);
}

void conductExam(Student* student, Question* questions) {
    printf("\nStarting the exam for %s...\n", student->name);
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].questionText);
        for (int j = 0; j < 4; j++) {
            printf("   %c) %s\n", 'A' + j, questions[i].options[j]);
        }
        printf("Your answer (A/B/C/D): ");
        char answer;
        scanf(" %c", &answer);
        student->answers[i] = (answer - 'A');
    }
}

void displayResults(Student* student, Question* questions) {
    int score = 0;
    printf("\nResults for %s (Roll No: %s)\n", student->name, student->rollNumber);
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].questionText);
        printf("   Your Answer: %c\n", 'A' + student->answers[i]);
        if (student->answers[i] == questions[i].correctOption) {
            score++;
            printf("   Result: Correct!\n");
        } else {
            printf("   Result: Wrong! Correct answer: %c\n", 'A' + questions[i].correctOption);
        }
    }
    printf("Total Score: %d out of %d\n", score, MAX_QUESTIONS);
}