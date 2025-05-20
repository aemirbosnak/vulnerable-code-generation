//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store student details
struct student {
    int roll;
    char name[20];
    int marks;
};

int main() {
    int choice;
    int num_of_students = 0;
    struct student *students = NULL;
    
    // Display main menu
    printf("Welcome to the Online Examination System!\n");
    printf("1. Register a student\n");
    printf("2. Display all students\n");
    printf("3. Grade a student\n");
    printf("4. Exit\n");
    
    // Handle user input
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Register a student
                num_of_students++;
                students = (struct student*)realloc(students, num_of_students * sizeof(struct student));
                printf("Enter the student's roll number: ");
                scanf("%d", &students[num_of_students-1].roll);
                printf("Enter the student's name: ");
                scanf("%s", students[num_of_students-1].name);
                printf("Student registered successfully!\n");
                break;
            case 2:
                // Display all students
                if (num_of_students == 0) {
                    printf("No students registered yet.\n");
                } else {
                    printf("Roll\tName\n");
                    for (int i = 0; i < num_of_students; i++) {
                        printf("%d\t%s\n", students[i].roll, students[i].name);
                    }
                }
                break;
            case 3:
                // Grade a student
                if (num_of_students == 0) {
                    printf("No students registered yet.\n");
                } else {
                    int roll_num;
                    printf("Enter the student's roll number: ");
                    scanf("%d", &roll_num);
                    
                    for (int i = 0; i < num_of_students; i++) {
                        if (students[i].roll == roll_num) {
                            printf("Enter the student's marks: ");
                            scanf("%d", &students[i].marks);
                            printf("Marks graded successfully!\n");
                            break;
                        } else if (i == num_of_students-1) {
                            printf("Student with this roll number does not exist.\n");
                        }
                    }
                }
                break;
            case 4:
                // Exit the program
                printf("Thank you for using the Online Examination System!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    
    // Free memory
    free(students);
    
    return 0;
}