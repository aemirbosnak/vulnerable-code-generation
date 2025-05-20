//FormAI DATASET v1.0 Category: Database querying ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct student {
    int roll;
    char name[30];
    float marks;
}students[100];

int count = 0;

void insert_student(int roll, char* name, float marks) {
    students[count].roll = roll;
    strcpy(students[count].name, name);
    students[count].marks = marks;
    count++;
}

void display_all_students() {
    if(count==0) {
        printf("No students data available.\n");
        return;
    }
    printf("Roll\tName\t\tMarks\n");
    for(int i=0;i<count;i++) {
        printf("%d\t%s\t\t%f\n", students[i].roll, students[i].name, students[i].marks);
    }
}

void search_student() {
    int roll;
    printf("Enter the Roll No. of the student: ");
    scanf("%d", &roll);
    bool found = false;
    for(int i=0;i<count;i++) {
        if(students[i].roll==roll) {
            printf("Roll\tName\t\tMarks\n");
            printf("%d\t%s\t\t%f\n", students[i].roll, students[i].name, students[i].marks);
            found = true;
            break;
        }
    }
    if(!found) {
        printf("Student with Roll No. %d not found.\n", roll);
    }
}

int main() {
    int choice, roll;
    char name[30];
    float marks;

    while(1) {
        printf(" Choose:\n1. Insert Student Data\n2. Display All Students Data\n3. Search Student Data\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter the Roll No. of the student: ");
                scanf("%d", &roll);
                printf("Enter the Name of the student: ");
                scanf("%s", name);
                printf("Enter the Marks of the student: ");
                scanf("%f", &marks);
                insert_student(roll, name, marks);
                break;
            case 2:
                display_all_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}