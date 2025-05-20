//FormAI DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    int marks;
};

void addStudent() {
    struct Student s;
    FILE *fp;
    fp = fopen("students.data", "ab");

    printf("Enter student name: ");
    scanf("%s", s.name);

    printf("Enter student age: ");
    scanf("%d", &s.age);

    printf("Enter student marks: ");
    scanf("%d", &s.marks);

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);

    printf("Student added successfully!\n");
}

void listStudents() {
    FILE *fp;
    struct Student s;

    fp = fopen("students.data", "rb");

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Marks: %d\n", s.marks);
        printf("------------\n");
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp;
    struct Student s;
    char name[50];

    fp = fopen("students.data", "rb");
    printf("Enter student name: ");
    scanf("%s", name);

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (strcmp(s.name, name) == 0) {
            printf("Name: %s\n", s.name);
            printf("Age: %d\n", s.age);
            printf("Marks: %d\n", s.marks);
            printf("------------\n");
        }
    }
    fclose(fp);
}

void deleteStudent() {
    FILE *fp, *temp;
    struct Student s;
    char name[50];
    int found = 0;

    fp = fopen("students.data", "rb");
    temp = fopen("temp.data", "wb");

    printf("Enter student name: ");
    scanf("%s", name);

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (strcmp(s.name, name) != 0) {
            fwrite(&s, sizeof(struct Student), 1, temp);
        } else {
            found++;
            printf("Student deleted successfully!\n");
        }
    }
    fclose(fp);
    fclose(temp);

    if (found == 0) {
        printf("No student found with the name %s\n", name);
    }

    remove("students.data");
    rename("temp.data", "students.data");
}

int main() {
    int choice;

    while (1) {
        printf("1. Add student\n2. List all students\n3. Search student\n4. Delete student\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                listStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please select from the available options.\n");
        }
    }
    return 0;
}