//FormAI DATASET v1.0 Category: Database querying ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Student {
    int id;
    char name[30];
    float score;
};

const char* FILE_NAME = "students.bin";
const int MAX_STUDENTS = 10;

void createData() {
    FILE *fp;
    int i = 0;
    int id[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char name[][30] = {"John", "Steve", "Mary", "Kate", "Lucy", "David", "Greg", "Sarah", "Alex", "Olivia"};
    float score[] = {85.4, 73.2, 92.5, 65.8, 76.7, 81.9, 69.5, 94.3, 88.2, 79.6};

    fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    for (i = 0; i < MAX_STUDENTS; i++) {
        fwrite(&id[i], sizeof(int), 1, fp);
        fwrite(name[i], sizeof(char), strlen(name[i])+1, fp);
        fwrite(&score[i], sizeof(float), 1, fp);
    }

    fclose(fp);
}

void queryData(char* name) {
    FILE *fp;
    struct Student student;
    int i;

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    while(fread(&student.id, sizeof(int), 1, fp)) {
        fread(student.name, sizeof(char), 30, fp);
        fread(&student.score, sizeof(float), 1, fp);

        if (strcmp(student.name, name) == 0) {
            printf("Student ID: %d\n", student.id);
            printf("Student Name: %s\n", student.name);
            printf("Student Score: %.2f\n", student.score);
        }
    }

    fclose(fp);
}

int main() {
    char search[30];

    createData();

    printf("Enter student name to search: ");
    scanf("%s", search);

    queryData(search);

    return 0;
}