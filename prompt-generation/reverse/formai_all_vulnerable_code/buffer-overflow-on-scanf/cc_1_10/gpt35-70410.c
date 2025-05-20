//FormAI DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct student {
    int id;
    char name[SIZE];
    float gpa;
};

int main() {
    int option, id;
    float gpa;
    char name[SIZE];
    struct student s;
    FILE *file;

    do {
        printf("Please choose an option:\n");
        printf("1. Add student\n");
        printf("2. Search student by ID\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &s.id);
                printf("Enter student name: ");
                scanf("%s", s.name);
                printf("Enter student GPA: ");
                scanf("%f", &s.gpa);

                file = fopen("students.db", "ab");
                fwrite(&s, sizeof(s), 1, file);
                fclose(file);

                printf("Student added successfully.\n");
                break;
            case 2:
                printf("Enter student ID to search: ");
                scanf("%d", &id);

                file = fopen("students.db", "rb");

                while (fread(&s, sizeof(s), 1, file) == 1) {
                    if (s.id == id) {
                        printf("Student found:\n");
                        printf("ID: %d\n", s.id);
                        printf("Name: %s\n", s.name);
                        printf("GPA: %.2f\n", s.gpa);
                        break;
                    }
                }

                if (feof(file)) {
                    printf("Student not found.\n");
                }

                fclose(file);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 3);

    return 0;
}