//FormAI DATASET v1.0 Category: Educational ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 20
#define MAX_ENROLLMENT 100

struct Student {
    char name[MAX_NAME_LEN];
    int roll_no;
    int marks;
};

int main() {
    struct Student students[MAX_ENROLLMENT];
    int n, i, j, option;
    char search_name[MAX_NAME_LEN];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Read the details of all students
    for(i=0; i<n; i++) {
        printf("\nEnter the details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    // Menu driven options
    do {
        printf("\n\nMenu\n");
        printf("1. Display all students\n");
        printf("2. Search for a student by name\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        // Display all students
        if(option == 1) {
            printf("\n\nAll Students:\n");
            for(i=0; i<n; i++) {
                printf("%d. %s\t%d\t%d\n", i+1, students[i].name, students[i].roll_no, students[i].marks);
            }
        }

        // Search for a student by name
        else if(option == 2) {
            printf("\nEnter the name of the student to search for: ");
            scanf("%s", search_name);

            for(i=0; i<n; i++) {
                if(strcmp(students[i].name, search_name) == 0) {
                    printf("\n\nDetails of student with name %s:\n", search_name);
                    printf("Name: %s\tRoll No: %d\tMarks: %d\n", students[i].name, students[i].roll_no, students[i].marks);
                    break;
                }
            }
            if(i == n) {
                printf("\n\nStudent with name %s not found!\n", search_name);
            }
        }

        // Exit
        else if(option == 3) {
            printf("\nExiting...\n");
        }

        // Invalid option
        else {
            printf("\nInvalid option! Try again.\n");
        }

        // Pressing enter to continue
        printf("\nPress enter to continue...");
        getchar();
        getchar();

    } while(option != 3);

    return 0;
}