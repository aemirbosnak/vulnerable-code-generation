//FormAI DATASET v1.0 Category: File handling ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
    char name[50];
    int roll_no;
    int marks;
} Student;

void displayMenu() {
    printf("Enter your choice: \n");
    printf("1. Add student record\n");
    printf("2. Display all student records\n");
    printf("3. Search for a student record\n");
    printf("4. Exit\n");
}

int main() {
    FILE *fp;
    int choice, i, n, found, roll_no;
    char temp_name[50];
    Student s;

    while(1) {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                fp = fopen("student_records.txt", "a");
                printf("Enter the number of students you want to add: ");
                scanf("%d", &n);
                for(i=0; i<n; i++) {
                    printf("Enter the name of student %d: ", i+1);
                    scanf("%s", s.name);
                    printf("Enter the roll number of student %d: ", i+1);
                    scanf("%d", &s.roll_no);
                    printf("Enter the marks of student %d: ", i+1);
                    scanf("%d", &s.marks);
                    fprintf(fp, "%s %d %d\n", s.name, s.roll_no, s.marks);
                }
                fclose(fp);
                break;

            case 2:
                fp = fopen("student_records.txt", "r");
                if(fp == NULL) {
                    printf("File does not exist\n");
                    break;
                }
                printf("Name\tRoll No\t\tMarks\n");
                while(fscanf(fp, "%s %d %d", s.name, &s.roll_no, &s.marks) != EOF) {
                    printf("%s\t%d\t\t%d\n", s.name, s.roll_no, s.marks);
                }
                fclose(fp);
                break;

            case 3:
                fp = fopen("student_records.txt", "r");
                if(fp == NULL) {
                    printf("File does not exist\n");
                    break;
                }
                found = 0;
                printf("Enter the name of the student you want to search for: ");
                scanf("%s", temp_name);
                while(fscanf(fp, "%s %d %d", s.name, &s.roll_no, &s.marks) != EOF) {
                    if(strcmp(temp_name, s.name) == 0) {
                        printf("Record found\n");
                        printf("Name\tRoll No\t\tMarks\n");
                        printf("%s\t%d\t\t%d\n", s.name, s.roll_no, s.marks);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Record not found\n");
                }
                fclose(fp);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }

    }

    return 0;
}