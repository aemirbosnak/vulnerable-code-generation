//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct student {
    char name[20];
    int age;
    float marks;
};

typedef struct student student_t;

void add_student(student_t students[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached!\n");
        return;
    }
    
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    
    printf("Enter student age: ");
    scanf("%d", &students[*count].age);
    
    printf("Enter student marks: ");
    scanf("%f", &students[*count].marks);
    
    (*count)++;
    printf("Record added successfully!\n");
}

void display_all_students(student_t students[], int count) {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    
    printf("Name\tAge\tMarks\n");
    printf("----\t---\t-----\n");
    
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].marks);
    }
}

void search_student_by_name(student_t students[], int count) {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    
    char name[20];
    printf("Enter student name to search: ");
    scanf("%s", name);
    
    printf("Name\tAge\tMarks\n");
    printf("----\t---\t-----\n");
    
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].marks);
            return;
        }
    }
    
    printf("No record found with name '%s'!\n", name);
}

int main() {
    student_t students[MAX_RECORDS];
    int choice;
    int count = 0;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add student record\n");
        printf("2. Display all student records\n");
        printf("3. Search student record by name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student(students, &count);
                break;
                
            case 2:
                display_all_students(students, count);
                break;
                
            case 3:
                search_student_by_name(students, count);
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}