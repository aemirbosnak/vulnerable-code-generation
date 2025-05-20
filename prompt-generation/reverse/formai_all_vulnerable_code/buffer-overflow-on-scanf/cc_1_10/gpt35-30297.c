//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold student information
typedef struct {
    char name[50];
    int roll_no;
    int marks;
} student;

// function to display the menu
void display_menu() {
    printf("*********** C Online Examination System ***********\n");
    printf("1. Register new student\n");
    printf("2. Display student information\n");
    printf("3. Enter marks\n");
    printf("4. View result\n");
    printf("5. Exit\n");
}

int main() {
    int choice = 0, num_students = 0, i, roll_no;
    student students[50]; // maximum 50 students
    char name[50];

    // loop for menu
    while (choice != 5) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // register new student
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter roll number: ");
                scanf("%d", &roll_no);
                students[num_students].roll_no = roll_no;
                strcpy(students[num_students].name, name);
                num_students++;
                break;
            case 2:
                // display student information
                printf("Enter roll number: ");
                scanf("%d", &roll_no);
                for (i = 0; i < num_students; i++) {
                    if (students[i].roll_no == roll_no) {
                        printf("Name: %s\nRoll number: %d\n", students[i].name, students[i].roll_no);
                    }
                }
                break;
            case 3:
                // enter marks for a student
                printf("Enter roll number: ");
                scanf("%d", &roll_no);
                for (i = 0; i < num_students; i++) {
                    if (students[i].roll_no == roll_no) {
                        printf("Enter marks: ");
                        scanf("%d", &students[i].marks);
                        printf("Marks added for %s\n", students[i].name);
                    }
                }
                break;
            case 4:
                // view result for all students
                printf("Roll number\tName\tMarks\n");
                for (i = 0; i < num_students; i++) {
                    printf("%d\t\t%s\t%d\n", students[i].roll_no, students[i].name, students[i].marks);
                }
                break;
            case 5:
                // exit
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}