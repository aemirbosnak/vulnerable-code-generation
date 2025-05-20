//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 10
#define DATA_FILE "students.dat"

typedef struct {
    char question[256];
    char options[4][100];
    char correct_answer;
} Question;

typedef struct {
    char name[50];
    int id;
    int score;
} Student;

void registerStudent(Student* students, int* studentCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }
    
    Student newStudent;
    printf("Enter your name: ");
    scanf("%s", newStudent.name);
    
    newStudent.id = *studentCount + 1;
    newStudent.score = 0;
    
    students[*studentCount] = newStudent;
    (*studentCount)++;
    
    printf("Registration successful! Your Student ID is: %d\n", newStudent.id);
}

void takeExam(Student* student, Question* questions) {
    printf("Starting exam for %s (ID: %d)\n", student->name, student->id);
    student->score = 0;
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%c. %s\n", 'A' + j, questions[i].options[j]);
        }
        
        char answer;
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        
        if (answer == questions[i].correct_answer) {
            printf("Correct!\n");
            student->score++;
        } else {
            printf("Incorrect! The correct answer is %c.\n", questions[i].correct_answer);
        }
    }
    
    printf("Exam finished! Your score: %d/%d\n", student->score, MAX_QUESTIONS);
}

void saveStudents(Student* students, int studentCount) {
    FILE* file = fopen(DATA_FILE, "wb");
    if (!file) {
        printf("Failed to open file for saving data.\n");
        return;
    }
    
    fwrite(students, sizeof(Student), studentCount, file);
    fclose(file);
    
    printf("Student data saved successfully!\n");
}

void loadStudents(Student* students, int* studentCount) {
    FILE* file = fopen(DATA_FILE, "rb");
    if (!file) {
        printf("No data file found. Starting fresh.\n");
        return;
    }
    
    *studentCount = fread(students, sizeof(Student), MAX_STUDENTS, file);
    fclose(file);
    
    printf("Loaded %d students from file.\n", *studentCount);
}

void displayAllStudents(Student* students, int studentCount) {
    printf("Registered Students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Score: %d\n", students[i].id, students[i].name, students[i].score);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    loadStudents(students, &studentCount);
    
    Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 'C'},
        {"What is 2 + 2?", {"3", "4", "5", "6"}, 'B'},
        {"What is the color of the sky?", {"Blue", "Red", "Green", "Yellow"}, 'A'},
        {"What is the largest planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 'C'},
        {"How many continents are there?", {"5", "6", "7", "8"}, 'C'},
        {"What is the boiling point of water?", {"90C", "100C", "110C", "120C"}, 'B'},
        {"Who wrote 'Hamlet'?", {"Shakespeare", "Hemingway", "Tolkien", "Orwell"}, 'A'},
        {"What is the fastest land animal?", {"Cheetah", "Lion", "Horse", "Rabbit"}, 'A'},
        {"What is the main ingredient in guacamole?", {"Tomato", "Lettuce", "Avocado", "Onion"}, 'C'},
        {"What is the chemical symbol for gold?", {"Au", "Ag", "Pb", "Fe"}, 'A'}
    };
    
    int choice;
    do {
        printf("\nOnline Examination System\n");
        printf("1. Register Student\n");
        printf("2. Take Exam\n");
        printf("3. Display All Students\n");
        printf("4. Save Data\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerStudent(students, &studentCount);
                break;
            case 2:
                if (studentCount == 0) {
                    printf("No registered students available!\n");
                } else {
                    int studentID;
                    printf("Enter your Student ID: ");
                    scanf("%d", &studentID);
                    if (studentID > 0 && studentID <= studentCount) {
                        takeExam(&students[studentID - 1], questions);
                    } else {
                        printf("Invalid Student ID!\n");
                    }
                }
                break;
            case 3:
                displayAllStudents(students, studentCount);
                break;
            case 4:
                saveStudents(students, studentCount);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}