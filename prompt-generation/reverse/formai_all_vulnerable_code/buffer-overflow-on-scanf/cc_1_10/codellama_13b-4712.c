//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: genius
// genius_exam_system.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store exam details
struct Exam {
    int id;
    char name[20];
    char subject[20];
    int marks;
};

// function to display exam details
void displayExam(struct Exam exam) {
    printf("ID: %d\n", exam.id);
    printf("Name: %s\n", exam.name);
    printf("Subject: %s\n", exam.subject);
    printf("Marks: %d\n", exam.marks);
}

// function to add new exam
void addExam(struct Exam *exam) {
    printf("Enter ID: ");
    scanf("%d", &exam->id);
    printf("Enter name: ");
    scanf("%s", exam->name);
    printf("Enter subject: ");
    scanf("%s", exam->subject);
    printf("Enter marks: ");
    scanf("%d", &exam->marks);
}

// function to delete exam
void deleteExam(struct Exam *exam) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < 10; i++) {
        if (exam[i].id == id) {
            exam[i].id = -1;
            break;
        }
    }
}

// function to search exam
void searchExam(struct Exam *exam) {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < 10; i++) {
        if (exam[i].id == id) {
            displayExam(exam[i]);
            break;
        }
    }
}

// function to modify exam
void modifyExam(struct Exam *exam) {
    int id;
    printf("Enter ID to modify: ");
    scanf("%d", &id);
    for (int i = 0; i < 10; i++) {
        if (exam[i].id == id) {
            printf("Enter name: ");
            scanf("%s", exam[i].name);
            printf("Enter subject: ");
            scanf("%s", exam[i].subject);
            printf("Enter marks: ");
            scanf("%d", &exam[i].marks);
            break;
        }
    }
}

int main() {
    struct Exam exam[10];
    int choice;
    while (1) {
        printf("1. Add new exam\n");
        printf("2. Delete exam\n");
        printf("3. Search exam\n");
        printf("4. Modify exam\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addExam(&exam[0]);
            break;
        case 2:
            deleteExam(&exam[0]);
            break;
        case 3:
            searchExam(&exam[0]);
            break;
        case 4:
            modifyExam(&exam[0]);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}