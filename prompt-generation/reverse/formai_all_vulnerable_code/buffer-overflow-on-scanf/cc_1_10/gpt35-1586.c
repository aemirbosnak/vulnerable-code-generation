//FormAI DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void readFromFile(const char *fileName);
void writeToFile(const char *fileName);

typedef struct student {
    char name[50];
    int age;
    char desc[BUFFER_SIZE];
} Student;

int main() {
    char fileName[] = "students.txt";
    writeToFile(fileName);
    readFromFile(fileName);
    return 0;
}

void readFromFile(const char *fileName) {
    FILE *fp;
    Student s;
    fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Error opening file %s", fileName);
        exit(1);
    }
    printf("\nRead Student Information from File:\n");
    printf("%-20s%-10s%s\n", "Name", "Age", "Description");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("%-20s%-10d%s\n", s.name, s.age, s.desc);
    }
    fclose(fp);
}

void writeToFile(const char *fileName) {
    FILE *fp;
    Student s;
    fp = fopen(fileName, "wb");
    if (fp == NULL) {
        printf("Error opening file %s", fileName);
        exit(1);
    }
    printf("Enter Student Information:\n");
    printf("Name: ");
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    printf("Age: ");
    scanf("%d", &s.age);
    getchar();
    printf("Description: ");
    fgets(s.desc, BUFFER_SIZE, stdin);
    s.desc[strcspn(s.desc, "\n")] = 0;
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
}