//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[100];
    int roll;
    float marks;
};

int main() {
    int choice, numOfStudents = 0, i;
    struct student st;

    // Create a dynamic array of students
    struct student* studentArray = NULL;
    studentArray = (struct student*) malloc(sizeof(struct student));

    while(1) {
        printf("Enter 1 to add a student record\n");
        printf("Enter 2 to display all student records\n");
        printf("Enter 3 to exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Adding a new student
                printf("Enter student name: ");
                scanf("%s", st.name);

                printf("Enter student roll number: ");
                scanf("%d", &st.roll);

                printf("Enter student marks: ");
                scanf("%f", &st.marks);

                // Adding the new student to the array
                studentArray = (struct student*) realloc(studentArray, sizeof(struct student)*(numOfStudents+1));
                studentArray[numOfStudents] = st;
                numOfStudents++;

                printf("Successfully added student record!\n\n");
                break;

            case 2:
                // Displaying all student records
                if(numOfStudents == 0) {
                    printf("No student records found!\n\n");
                    break;
                }
                printf("Student Records:\n");
                for(i=0; i<numOfStudents; i++) {
                    printf("Name: %s, Roll Number: %d, Marks: %f\n", studentArray[i].name, studentArray[i].roll, studentArray[i].marks);
                }
                printf("\n");
                break;

            case 3:
                // Exiting the program
                printf("Exiting the program!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    }

    // Freeing dynamic memory
    free(studentArray);
    studentArray = NULL;

    return 0;
}