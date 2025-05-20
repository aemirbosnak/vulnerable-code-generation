//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    system("clear");

    // Student information
    char name[20];
    int rollNo;
    float marks[MAX];

    // Exam information
    char subject[20];
    int paperNo;
    int marksObtained;

    // Menu options
    int choice;

    // Initializing marks
    for (int i = 0; i < MAX; i++)
    {
        marks[i] = 0;
    }

    // Main loop
    do
    {
        // Displaying menu options
        printf("\n1. Register Student\n");
        printf("2. View Student Marks\n");
        printf("3. Exit\n");

        // Getting user input
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Register student
                printf("Enter student name: ");
                scanf("%s", name);

                printf("Enter student roll no: ");
                scanf("%d", &rollNo);

                // Get student marks
                printf("Enter marks obtained in each subject: ");
                for (int i = 0; i < MAX; i++)
                {
                    scanf("%f", &marks[i]);
                }

                break;

            case 2:
                // View student marks
                printf("Student name: %s\n", name);
                printf("Roll no: %d\n", rollNo);

                printf("Marks obtained in each subject: ");
                for (int i = 0; i < MAX; i++)
                {
                    printf("%f ", marks[i]);
                }

                break;

            case 3:
                // Exit
                printf("Thank you for using the system. Goodbye!\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}