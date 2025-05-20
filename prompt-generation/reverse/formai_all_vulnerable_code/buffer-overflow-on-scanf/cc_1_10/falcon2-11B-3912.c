//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: scalable
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 10

struct Student {
    char name[MAX_NAME_LENGTH];
    int age;
};

void addStudent(struct Student* students, int size) {
    char name[MAX_NAME_LENGTH];
    int age;
    
    printf("Enter name: ");
    scanf("%s", name);
    
    printf("Enter age: ");
    scanf("%d", &age);
    
    if (size < MAX_STUDENTS) {
        strcpy(students[size].name, name);
        students[size].age = age;
        size++;
    } else {
        printf("Too many students. Cannot add more.\n");
    }
}

void displayStudents(struct Student* students, int size) {
    int i;
    
    printf("Students:\n");
    for (i = 0; i < size; i++) {
        printf("Name: %s\nAge: %d\n", students[i].name, students[i].age);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int size = 0;
    
    while (1) {
        printf("\n1. Add student\n2. Display students\n3. Quit\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(students, size);
                break;
                
            case 2:
                displayStudents(students, size);
                break;
                
            case 3:
                return 0;
                
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}