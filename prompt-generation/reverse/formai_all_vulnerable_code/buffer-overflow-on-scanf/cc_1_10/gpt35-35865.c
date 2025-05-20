//FormAI DATASET v1.0 Category: Online Examination System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char *name;
    int id;
    int score;
};

int main() {

    struct student *students;

    int numStudents;
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    students = (struct student*) malloc(numStudents * sizeof(struct student));

    // Get information for each student
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter information for Student #%d:\n", i+1);

        char name[50];
        printf("- Name: ");
        scanf(" %[^\n]s", name);

        int id;
        printf("- ID: ");
        scanf("%d", &id);

        students[i].name = (char*) malloc(strlen(name) * sizeof(char));
        strcpy(students[i].name, name);

        students[i].id = id;

        students[i].score = 0;
    }

    // Display menu and options
    int choice = 0;
    while (choice != 3) {
        printf("\nPlease choose an option:\n");
        printf("1. Start Exam\n");
        printf("2. View Scores\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Start Exam
                printf("\nStarting Exam...\n\n");

                for (int i = 0; i < numStudents; i++) {
                    printf("Questions for %s (#%d):\n", students[i].name, students[i].id);

                    // TODO: Add questions and grading logic here
                    // Set score for each student based on their answers
                    students[i].score = rand() % 100;

                    printf("Exam score for %s (#%d): %d\n", students[i].name, students[i].id, students[i].score);
                }
                break;

            case 2:
                // View Scores
                printf("\nStudent Scores:\n\n");

                for (int i = 0; i < numStudents; i++) {
                    printf("%s (#%d): %d\n", students[i].name, students[i].id, students[i].score);
                }

                break;

            case 3:
                // Exit
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please choose again.\n");
                break;
        }
    }

    // Free memory
    for (int i = 0; i < numStudents; i++) {
        free(students[i].name);
    }

    free(students);

    return 0;
}