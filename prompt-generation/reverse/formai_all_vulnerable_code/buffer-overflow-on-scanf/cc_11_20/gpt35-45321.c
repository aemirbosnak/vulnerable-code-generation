//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100 // Maximum size of the database

struct Student {
    char name[30];
    int age;
    float marks;
};

int main() {
    struct Student database[MAX_SIZE]; // Creating the database
    int num_of_students = 0; // Number of students in the database

    while(1) {
        int choice;
        printf("\nWelcome to the Student Database\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                // Adding a student to the database
                if(num_of_students == MAX_SIZE) {
                    printf("\nDatabase is full!\n");
                    break;
                }
                struct Student st;
                printf("\nEnter details of student:\n");
                printf("Name: ");
                scanf("%s", st.name);
                printf("Age: ");
                scanf("%d", &st.age);
                printf("Marks: ");
                scanf("%f", &st.marks);
                database[num_of_students++] = st;
                printf("\nStudent added successfully!\n");
                break;
            }
            case 2: {
                // Searching for a student in the database
                char name[30];
                printf("\nEnter name of student to search: ");
                scanf("%s", name);
                int index = -1;
                for(int i = 0; i < num_of_students; i++) {
                    if(strcmp(database[i].name, name) == 0) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("\nStudent not found in database!\n");
                    break;
                }
                printf("\nDetails of student:\n");
                printf("Name: %s\n", database[index].name);
                printf("Age: %d\n", database[index].age);
                printf("Marks: %.2f\n", database[index].marks);
                break;
            }
            case 3: {
                // Displaying all students in the database
                if(num_of_students == 0) {
                    printf("\nDatabase is empty!\n");
                    break;
                }
                printf("\nDetails of all students in database:\n");
                for(int i = 0; i < num_of_students; i++) {
                    printf("Student %d:\n", i+1);
                    printf("Name: %s\n", database[i].name);
                    printf("Age: %d\n", database[i].age);
                    printf("Marks: %.2f\n\n", database[i].marks);
                }
                break;
            }
            case 4: {
                // Exiting the program
                printf("\nExiting program...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice!\n");
                break;
            }
        }
    }

    return 0;
}