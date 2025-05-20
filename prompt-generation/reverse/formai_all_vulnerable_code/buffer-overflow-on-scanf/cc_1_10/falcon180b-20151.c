//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int id;
} Student;

void read_students(Student students[], int size) {
    FILE *file;
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(file, "%s %d\n", students[i].name, &students[i].id)!= EOF) {
        i++;
    }
    fclose(file);
}

void search_student(Student students[], int size, char name[]) {
    int i = 0;
    while (i < size) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found\n");
            printf("Name: %s\n", students[i].name);
            printf("ID: %d\n", students[i].id);
            return;
        }
        i++;
    }
    printf("Student not found\n");
}

int main() {
    Student students[MAX_SIZE];
    int size;
    char name[50];
    printf("Enter the number of students: ");
    scanf("%d", &size);
    read_students(students, size);
    printf("Enter the name of the student to search: ");
    scanf("%s", name);
    search_student(students, size, name);
    return 0;
}