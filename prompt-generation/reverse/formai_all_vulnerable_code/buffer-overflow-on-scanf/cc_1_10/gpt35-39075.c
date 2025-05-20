//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int roll_no;
    float marks;
};

typedef struct student Student;

// function to display student details
void displayStudentDetails(Student s) {
    printf("\nName: %s", s.name);
    printf("\nRoll No: %d", s.roll_no);
    printf("\nMarks Obtained: %.2f\n", s.marks);
}

int main() {
    int num_of_students;
    printf("Welcome to Online Examination System!\n");
    printf("Please enter the number of students taking the exam: ");
    scanf("%d", &num_of_students);
    getchar(); // to clear the input buffer
    
    Student* students = malloc(num_of_students * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation error! Exiting program...\n");
        return 1;
    }
    
    // loop through each student and get their details
    for (int i = 0; i < num_of_students; i++) {
        printf("\nEnter the details for Student %d:\n", i + 1);
        printf("Name: ");
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // to remove trailing newline
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Marks Obtained: ");
        scanf("%f", &students[i].marks);
        getchar(); // to clear the input buffer
    }
    
    // display the details of each student
    printf("\n\nHere are the details of the students who took the exam:\n");
    for (int i = 0; i < num_of_students; i++) {
        printf("\nDetails for Student %d:\n", i + 1);
        displayStudentDetails(students[i]);
    }
    
    free(students);
    printf("\n\nThank you for using Online Examination System!\n");
    return 0;
}