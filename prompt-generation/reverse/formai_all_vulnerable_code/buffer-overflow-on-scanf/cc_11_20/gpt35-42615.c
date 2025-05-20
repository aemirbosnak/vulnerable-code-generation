//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int score;
} Student;

enum {
    INSERT = 1,
    DELETE = 2,
    SEARCH = 3,
    DISPLAY = 4,
    QUIT = 5
};

int main() {
    int choice, numStudents = 0;
    Student *students = calloc(sizeof(Student), numStudents);

    printf("Welcome to the Student Database Simulation Program\n\n");

    while(1) {
        printf("What would you like to do?\n");
        printf("\t%d. Insert a new student\n", INSERT);
        printf("\t%d. Delete a student\n", DELETE);
        printf("\t%d. Search for a student\n", SEARCH);
        printf("\t%d. Display all students\n", DISPLAY);
        printf("\t%d. Quit\n", QUIT);

        scanf("%d", &choice);

        switch(choice) {
            case INSERT:
                numStudents++;
                students = realloc(students, sizeof(Student) * numStudents);

                printf("Enter student ID:\n");
                scanf("%d", &students[numStudents - 1].id);

                printf("Enter student name:\n");
                scanf("%s", students[numStudents - 1].name);

                printf("Enter student score:\n");
                scanf("%d", &students[numStudents - 1].score);

                break;
            case DELETE: {
                int idToDelete, indexToDelete = -1;

                printf("Enter student ID to delete: ");
                scanf("%d", &idToDelete);

                for(int i = 0; i < numStudents; i++) {
                    if(students[i].id == idToDelete) {
                        indexToDelete = i;
                        break;
                    }
                }

                if(indexToDelete == -1) {
                    printf("Student not found\n");
                    break;
                }

                for(int i = indexToDelete; i < numStudents - 1; i++) {
                    students[i] = students[i + 1];
                }

                numStudents--;
                students = realloc(students, sizeof(Student) * numStudents);

                printf("Student deleted successfully\n");

                break;
            }
            case SEARCH: {
                int idToSearch, indexToSearch = -1;

                printf("Enter student ID to search: ");
                scanf("%d", &idToSearch);

                for(int i = 0; i < numStudents; i++) {
                    if(students[i].id == idToSearch) {
                        indexToSearch = i;
                        break;
                    }
                }

                if(indexToSearch == -1) {
                    printf("Student not found\n");
                    break;
                }

                printf("ID: %d\n", students[indexToSearch].id);
                printf("Name: %s\n", students[indexToSearch].name);
                printf("Score: %d\n", students[indexToSearch].score);

                break;
            }
            case DISPLAY:
                printf("Student ID\tStudent Name\tStudent Score\n");

                for(int i = 0; i < numStudents; i++) {
                    printf("%d\t%s\t%d\n", students[i].id, students[i].name, students[i].score);
                }

                break;
            case QUIT:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    free(students);

    return 0;
}