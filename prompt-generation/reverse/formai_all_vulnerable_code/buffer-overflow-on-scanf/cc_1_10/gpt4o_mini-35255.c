//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][100];
    int answer; // Index of the correct answer
} Question;

typedef struct {
    char name[100];
    float score;
} Student;

void welcomeMessage() {
    printf("=================================================================\n");
    printf("              WELCOME TO THE ONLINE EXAMINATION SYSTEM!\n");
    printf("=================================================================\n");
}

void displayQuestions(Question questions[], int numQuestions) {
    printf("\nDisplaying Questions:\n");
    for (int i = 0; i < numQuestions; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("    %c: %s\n", 'A' + j, questions[i].options[j]);
        }
    }
}

void takeExam(Student *student, Question questions[], int numQuestions) {
    int answer, correct = 0;
    
    printf("\nStarting the exam for %s:\n", student->name);
    
    for (int i = 0; i < numQuestions; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("    %c: %s\n", 'A' + j, questions[i].options[j]);
        }
        printf("Your answer (A/B/C/D): ");
        
        char input[2];
        fgets(input, sizeof(input), stdin);
        answer = input[0] - 'A'; // Convert char to index

        if (answer == questions[i].answer) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect! The correct answer was %c.\n", 'A' + questions[i].answer);
        }
    }
    
    student->score = (float)correct / numQuestions * 100; // Calculate score
    printf("\nExam completed. Your score: %.2f%%\n", student->score);
}

int main() {
    welcomeMessage();

    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    // Sample test questions
    Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Lisbon"}, 2},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 1},
        {"What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Hippo"}, 1},
        {"Which gas do plants absorb?", {"Carbon Dioxide", "Oxygen", "Nitrogen", "Hydrogen"}, 0},
        {"What is the boiling point of water?", {"50C", "100C", "200C", "0C"}, 1},
        {"Which language is used for web development?", {"HTML", "CSS", "C++", "Python"}, 0},
        {"Which element has the chemical symbol 'O'?", {"Gold", "Oxygen", "Hydrogen", "Carbon"}, 1},
        {"Who wrote 'Romeo and Juliet'?", {"Charles Dickens", "Mark Twain", "William Shakespeare", "Jane Austen"}, 2},
        {"Which part of the cell contains the DNA?", {"Cytoplasm", "Nucleus", "Membrane", "Ribosome"}, 1},
        {"What is the largest desert in the world?", {"Sahara", "Arabian", "Gobi", "Antarctic"}, 3}
    };

    while (1) {
        printf("\n1. Register Student\n");
        printf("2. Start Exam\n");
        printf("3. Display Questions\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline
        switch (choice) {
            case 1:
                if (studentCount >= MAX_STUDENTS) {
                    printf("Maximum number of students reached!\n");
                } else {
                    printf("Enter student name: ");
                    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
                    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0; // Remove newline
                    students[studentCount].score = 0.0;
                    studentCount++;
                    printf("Student registered successfully!\n");
                }
                break;

            case 2:
                if (studentCount == 0) {
                    printf("No students registered yet!\n");
                } else {
                    for (int i = 0; i < studentCount; i++) {
                        printf("%d. %s\n", i + 1, students[i].name);
                    }
                    printf("Select student (1-%d): ", studentCount);
                    int studentIndex;
                    scanf("%d", &studentIndex);
                    getchar(); // Clear newline
                    if (studentIndex < 1 || studentIndex > studentCount) {
                        printf("Invalid selection!\n");
                    } else {
                        takeExam(&students[studentIndex - 1], questions, MAX_QUESTIONS);
                    }
                }
                break;

            case 3:
                displayQuestions(questions, MAX_QUESTIONS);
                break;

            case 4:
                printf("Exiting the exam system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}