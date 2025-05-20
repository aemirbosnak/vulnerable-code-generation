//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    int age;
};

void printStudent(struct Student s) {
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("\n");
}

int main() {
    struct Student students[5];
    int choice, id, i;
    
    for (i = 0; i < 5; i++) {
        printf("Enter student ID: ");
        scanf("%d", &students[i].id);
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        printf("Enter student age: ");
        scanf("%d", &students[i].age);
        printf("\n");
    }
    
    do {
        printf("Enter 1 to view all students or 2 to search for a student by ID: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            for (i = 0; i < 5; i++) {
                printStudent(students[i]);
            }
        }
        else if (choice == 2) {
            printf("Enter student ID: ");
            scanf("%d", &id);
            
            for (i = 0; i < 5; i++) {
                if (students[i].id == id) {
                    printStudent(students[i]);
                    break;
                }
            }
            
            if (i == 5) {
                printf("Student not found.\n\n");
            }
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 1 && choice != 2);
    
    return 0;
}