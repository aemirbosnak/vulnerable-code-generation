//FormAI DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    float gpa;
} Student;

int main() {
    int choice, index, id;
    char name[50];
    float gpa;
    Student *students = NULL;
    int num_students = 0;
    
    do {
        // Display menu
        printf("Menu:\n");
        printf("1. Add student\n");
        printf("2. Remove student\n");
        printf("3. Display student information\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Add student
                printf("Enter student id: ");
                scanf("%d", &id);
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter student GPA: ");
                scanf("%f", &gpa);
                
                // Add student to array
                num_students++;
                students = realloc(students, num_students * sizeof(Student));
                students[num_students-1].id = id;
                strcpy(students[num_students-1].name, name);
                students[num_students-1].gpa = gpa;
                
                printf("Student added.\n");
                break;
            case 2: // Remove student
                printf("Enter student id to remove: ");
                scanf("%d", &id);
                
                // Find student index
                index = -1;
                for (int i = 0; i < num_students; i++) {
                    if (students[i].id == id) {
                        index = i;
                        break;
                    }
                }
                
                // Remove student from array
                if (index != -1) {
                    for (int i = index; i < num_students-1; i++) {
                        students[i] = students[i+1];
                    }
                    num_students--;
                    students = realloc(students, num_students * sizeof(Student));
                    printf("Student removed.\n");
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 3: // Display student information
                printf("Enter student id to display: ");
                scanf("%d", &id);
                
                // Find student index
                index = -1;
                for (int i = 0; i < num_students; i++) {
                    if (students[i].id == id) {
                        index = i;
                        break;
                    }
                }
                
                // Display student information
                if (index != -1) {
                    printf("Student id: %d\n", students[index].id);
                    printf("Student name: %s\n", students[index].name);
                    printf("Student GPA: %.2f\n", students[index].gpa);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 4: // Quit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    free(students);
    
    return 0;
}