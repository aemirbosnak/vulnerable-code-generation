//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[128];
    int age;
    float marks;
} Student;

int main() {

    FILE* fp;
    char filename[128];
    char buffer[1024];
    char* token;

    printf("Enter CSV filename (e.g. data.csv): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s", filename);
        return 1;
    }

    Student students[100]; // assuming max 100 students for now
    int num_students = 0;

    while (fgets(buffer, 1024, fp)) {

        token = strtok(buffer, ","); // get first token (name)
        strcpy(students[num_students].name, token);

        token = strtok(NULL, ","); // get second token (age)
        students[num_students].age = atoi(token);

        token = strtok(NULL, ","); // get third token (marks)
        students[num_students].marks = atof(token);

        num_students++;
    }

    fclose(fp);

    printf("Students in file:\n");

    for (int i = 0; i < num_students; i++) {
        printf("%s is %d years old and has scored %f marks\n", students[i].name, students[i].age, students[i].marks);
    }

    return 0;
}