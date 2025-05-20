//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define a struct to hold student information */
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    char filename[50];
    FILE *file;

    /* ask for file name */
    printf("Enter file name: ");
    scanf("%s", filename);

    /* open file for writing */
    file = fopen(filename, "w");

    /* write some student information to file */
    if (file != NULL) {
        Student s1 = {"John Doe", 20, 3.5};
        Student s2 = {"Jane Smith", 19, 3.9};
        Student s3 = {"Bob Johnson", 21, 3.2};

        fwrite(&s1, sizeof(Student), 1, file);
        fwrite(&s2, sizeof(Student), 1, file);
        fwrite(&s3, sizeof(Student), 1, file);

        fclose(file); /* close file */
    } else {
        printf("Error opening file.\n");
    }

    /* open file for reading */
    file = fopen(filename, "r");

    /* read and display student information from file */
    if (file != NULL) {
        Student tmp;
        printf("Student Information:\n");
        while (fread(&tmp, sizeof(Student), 1, file) == 1) {
            printf("Name: %s\n", tmp.name);
            printf("Age: %d\n", tmp.age);
            printf("GPA: %.2f\n", tmp.gpa);
            printf("\n");
        }

        fclose(file); /* close file */
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}