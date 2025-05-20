//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[MAX];
    int rollno;
    int age;
    char gender;
} Student;

void addStudent(Student *students, int numStudents) {
    printf("Enter name: ");
    scanf("%s", &((students+numStudents)->name));
    printf("Enter roll number: ");
    scanf("%d", &((students+numStudents)->rollno));
    printf("Enter age: ");
    scanf("%d", &((students+numStudents)->age));
    printf("Enter gender: ");
    scanf(" %c", &((students+numStudents)->gender));
    numStudents++;
}

void displayStudents(Student *students, int numStudents) {
    printf("\nName\tRoll No.\tAge\tGender\n");
    for(int i=0; i<numStudents; i++) {
        printf("%s\t%d\t%d\t%c\n", (students+i)->name, (students+i)->rollno, (students+i)->age, (students+i)->gender);
    }
}

void searchStudent(Student *students, int numStudents, char *name) {
    bool found = false;
    for(int i=0; i<numStudents; i++) {
        if(strcmp((students+i)->name, name) == 0) {
            printf("\nName: %s\nRoll No.: %d\nAge: %d\nGender: %c\n", (students+i)->name, (students+i)->rollno, (students+i)->age, (students+i)->gender);
            found = true;
            break;
        }
    }
    if(!found) {
        printf("Student not found.\n");
    }
}

int main() {
    Student students[MAX];
    int numStudents = 0;

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    printf("\nEnter details of students:\n");
    for(int i=0; i<numStudents; i++) {
        addStudent(students, numStudents);
    }

    printf("\nDisplaying details of all students:\n");
    displayStudents(students, numStudents);

    char name[MAX];
    printf("\nEnter name of student to search: ");
    scanf("%s", name);

    searchStudent(students, numStudents, name);

    return 0;
}