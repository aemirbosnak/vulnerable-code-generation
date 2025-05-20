//FormAI DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int score;
} Student;

void printMenu() {
    printf("Welcome to the Online Examination System!\n");
    printf("1. Add student\n");
    printf("2. Delete student\n");
    printf("3. View all students\n");
    printf("4. Take test\n");
    printf("5. View result\n");
    printf("6. Exit\n");
}

int main() {
    int numOfStudents = 0;
    Student* students = malloc(numOfStudents * sizeof(Student));
    int choice;

    while (1) {
        printMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                numOfStudents++;
                students = realloc(students, numOfStudents * sizeof(Student));
                Student student;
                student.name = malloc(40 * sizeof(char));
                printf("Please enter student name: ");
                scanf("%s", student.name);
                student.score = -1;
                students[numOfStudents - 1] = student;
                printf("Student added successfully!\n");
                break;
            }
            case 2: {
                char deleteName[40];
                printf("Please enter student name to delete: ");
                scanf("%s", deleteName);
                int deleteIndex = -1;
                for (int i = 0; i < numOfStudents; i++) {
                    if (strcmp(deleteName, students[i].name) == 0) {
                        deleteIndex = i;
                    }
                }
                if (deleteIndex != -1) {
                    for (int i = deleteIndex; i < numOfStudents - 1; i++) {
                        students[i] = students[i + 1];
                    }
                    numOfStudents--;
                    students = realloc(students, numOfStudents * sizeof(Student));
                    printf("Student deleted successfully!\n");
                } else {
                    printf("Student not found!\n");
                }
                break;
            }
            case 3: {
                printf("List of all students:\n");
                for (int i = 0; i < numOfStudents; i++) {
                    printf("%s\n", students[i].name);
                }
                break;
            }
            case 4: {
                char studentName[40];
                int studentIndex = -1;
                printf("Please enter your name: ");
                scanf("%s", studentName);
                for (int i = 0; i < numOfStudents; i++) {
                    if (strcmp(studentName, students[i].name) == 0) {
                        studentIndex = i;
                    }
                }
                if (studentIndex != -1) {
                    int score =  0;
                    printf("Please answer the following questions:\n");
                    printf("1. What is the capital of France?\n");
                    printf("a) London\n");
                    printf("b) Paris\n");
                    printf("c) Rome\n");
                    char answer1;
                    printf("Enter your answer: ");
                    scanf(" %c", &answer1);
                    if (answer1 == 'b') {
                        score++;
                    }
                    printf("2. Who is the founder of Microsoft?\n");
                    printf("a) Bill Gates\n");
                    printf("b) Steve Jobs\n");
                    printf("c) Jeff Bezos\n");
                    char answer2;
                    printf("Enter your answer: ");
                    scanf(" %c", &answer2);
                    if (answer2 == 'a') {
                        score++;
                    }
                    printf("3. What is the largest planet in our solar system?\n");
                    printf("a) Earth\n");
                    printf("b) Mars\n");
                    printf("c) Jupiter\n");
                    char answer3;
                    printf("Enter your answer: ");
                    scanf(" %c", &answer3);
                    if (answer3 == 'c') {
                        score++;
                    }
                    students[studentIndex].score = score;
                    printf("Test completed!\n");
                } else {
                    printf("Student not found!\n");
                }
                break;
            }
            case 5: {
                char studentName[40];
                printf("Please enter your name: ");
                scanf("%s", studentName);
                int studentIndex = -1;
                for (int i = 0; i < numOfStudents; i++) {
                    if (strcmp(studentName, students[i].name) == 0) {
                        studentIndex = i;
                    }
                }
                if (studentIndex != -1) {
                    if (students[studentIndex].score != -1) {
                        printf("Your score is %d\n", students[studentIndex].score);
                    } else {
                        printf("You have not taken the test yet!\n");
                    }
                } else {
                    printf("Student not found!\n");
                }
                break;
            }
            case 6: {
                printf("Goodbye!\n");
                for (int i = 0; i < numOfStudents; i++) {
                    free(students[i].name);
                }
                free(students);
                return 0;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }
}