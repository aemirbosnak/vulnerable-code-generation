//FormAI DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int rollNumber;
    char name[50];
    int marks;
};

int main() {
    int numStudents;
    printf("How many students do you want to enter? ");
    scanf("%d", &numStudents);

    struct student* students = (struct student*)malloc(numStudents * sizeof(struct student));

    if(students == NULL) {
        printf("Oh no! Memory allocation failed!! Exiting program...\n");
        return 1;
    }

    printf("\nGreat! Let's add some students!\n");

    for(int i = 0; i < numStudents; i++) {
        printf("\nEnter details of student #%d:\n", i+1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    printf("\nAll students added! Here are the student details:\n");
    printf("=================================================\n");
    printf("| Roll Number |      Name      |     Marks      |\n");
    printf("=================================================\n");
    for(int i = 0; i < numStudents; i++) {
        printf("| %11d | %14s | %13d |\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
    printf("=================================================\n");

    int searchRollNo;
    printf("\nNow, let's search for a student. Enter the roll number of the student you are looking for: ");
    scanf("%d", &searchRollNo);
    
    int found = 0;
    for(int i = 0; i < numStudents; i++) {
        if(students[i].rollNumber == searchRollNo) {
            printf("\nFound the student with roll number %d!\n", searchRollNo);
            printf("Details:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %d\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nSorry, could not find a student with roll number %d.\n", searchRollNo);
    }

    free(students);

    return 0;
}