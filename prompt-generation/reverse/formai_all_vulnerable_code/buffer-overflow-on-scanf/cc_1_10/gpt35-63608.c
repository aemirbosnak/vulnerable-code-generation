//FormAI DATASET v1.0 Category: Online Examination System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
} s[100];

void main() {
    int n, i, j, choice;
    char password[20];

    // Login screen
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(password, "exam123") == 0) {
        printf("\nLogin Successful!\n");

        // Main Menu
        printf("\n1. Enter Student Details\n2. Display Student Details\n3. Search Student\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Enter Student Details
                printf("\nEnter the number of students: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("\nDetails of Student %d\n", i+1);
                    printf("Roll No: ");
                    scanf("%d", &s[i].roll_no);
                    printf("Name: ");
                    scanf("%s", s[i].name);
                    printf("Marks: ");
                    scanf("%f", &s[i].marks);
                }
                break;

            case 2:
                // Display Student Details
                printf("\n");

                for (i = 0; i < n; i++) {
                    printf("Details of Student %d\n", i+1);
                    printf("Roll No: %d\n", s[i].roll_no);
                    printf("Name: %s\n", s[i].name);
                    printf("Marks: %f\n\n", s[i].marks);
                }
                break;

            case 3:
                // Search Student
                printf("\nEnter the Roll No to search: ");
                int roll_no;
                scanf("%d", &roll_no);

                for (i = 0; i < n; i++) {
                    if (s[i].roll_no == roll_no) {
                        printf("\nDetails of Student with Roll No %d\n", roll_no);
                        printf("Name: %s\n", s[i].name);
                        printf("Marks: %f\n", s[i].marks);
                        break;
                    }
                }
                if (i == n) {
                    printf("\nStudent with Roll No %d not found!\n", roll_no);
                }
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    else {
        printf("\nLogin Failed!\n");
    }
}