//FormAI DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the menu for the system
void displayMenu() {
    printf("\n****** Online Examination System ******\n\n");
    printf("1. Register as student\n");
    printf("2. Register as teacher\n");
    printf("3. Login as student\n");
    printf("4. Login as teacher\n");
    printf("5. Take an exam\n");
    printf("6. Exit\n");
    printf("\n**************************************\n\n");
}

// Student registration function
void registerStudent(char **studentList, int *studentCount) {
    printf("\n****** Student Registration ******\n\n");
    char studentName[50];
    printf("Enter student name: ");
    scanf("%s", studentName);
    studentList[*studentCount] = (char*)malloc(sizeof(char) * strlen(studentName));
    strcpy(studentList[*studentCount], studentName);
    printf("%s successfully registered as student!\n", studentName);
    (*studentCount)++;
}

// Teacher registration function
void registerTeacher(char **teacherList, int *teacherCount) {
    printf("\n****** Teacher Registration ******\n\n");
    char teacherName[50];
    printf("Enter teacher name: ");
    scanf("%s", teacherName);
    teacherList[*teacherCount] = (char*)malloc(sizeof(char) * strlen(teacherName));
    strcpy(teacherList[*teacherCount], teacherName);
    printf("%s successfully registered as teacher!\n", teacherName);
    (*teacherCount)++;
}

// Student login function
int loginStudent(char **studentList, int studentCount) {
    printf("\n****** Student Login ******\n\n");
    char studentName[50];
    printf("Enter student name: ");
    scanf("%s", studentName);
    for (int i=0; i<studentCount; i++) {
        if (strcmp(studentList[i], studentName) == 0) {
            printf("%s logged in successfully!\n", studentName);
            return i;
        }
    }
    printf("%s is not registered as student!\n", studentName);
    return -1;
}

// Teacher login function
int loginTeacher(char **teacherList, int teacherCount) {
    printf("\n****** Teacher Login ******\n\n");
    char teacherName[50];
    printf("Enter teacher name: ");
    scanf("%s", teacherName);
    for (int i=0; i<teacherCount; i++) {
        if (strcmp(teacherList[i], teacherName) == 0) {
            printf("%s logged in successfully!\n", teacherName);
            return i;
        }
    }
    printf("%s is not registered as teacher!\n", teacherName);
    return -1;
}

// Function to display the available exams
void displayExams(char **examList, int examCount) {
    printf("\n****** Available Exams ******\n\n");
    for (int i=0; i<examCount; i++) {
        printf("%d. %s\n", i+1, examList[i]);
    }
}

// Function to take the exam
void takeExam(char **examList, int examCount) {
    printf("\n****** Take Exam ******\n\n");
    displayExams(examList, examCount);
    int examIndex;
    printf("\nEnter exam index to take: ");
    scanf("%d", &examIndex);
    if (examIndex > 0 && examIndex <= examCount) {
        printf("\nTaking exam: %s\n", examList[examIndex-1]);
        // Code to take the exam goes here
    }
    else {
        printf("\nInvalid exam index!\n");
    }
}

// Main function of the system
int main() {
    char *studentList[50];
    char *teacherList[50];
    char *examList[50] = {"C Programming Basics", "Data Structures and Algorithms", "Database Management Systems"};
    int studentCount = 0;
    int teacherCount = 0;
    int choice;
    int loggedStudentIndex = -1;
    int loggedTeacherIndex = -1;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerStudent(studentList, &studentCount);
                break;
            case 2:
                registerTeacher(teacherList, &teacherCount);
                break;
            case 3:
                loggedStudentIndex = loginStudent(studentList, studentCount);
                break;
            case 4:
                loggedTeacherIndex = loginTeacher(teacherList, teacherCount);
                break;
            case 5:
                if (loggedStudentIndex == -1) {
                    printf("\nPlease login as student first!\n");
                }
                else {
                    takeExam(examList, 3);
                }
                break;
            case 6:
                printf("\nExiting the program.\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                break;
        }

    } while(choice != 6);

    return 0;
}