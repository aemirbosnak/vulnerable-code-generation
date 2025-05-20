//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student s1, s2;

    // Writing to a file
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    printf("Enter details of student 1:\n");
    printf("Name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = '\0';
    printf("Age: ");
    scanf("%d", &s1.age);
    printf("GPA: ");
    scanf("%f", &s1.gpa);

    printf("Enter details of student 2:\n");
    printf("Name: ");
    getchar(); // consume the '\n' character left over from previous scanf
    fgets(s2.name, sizeof(s2.name), stdin);
    s2.name[strcspn(s2.name, "\n")] = '\0';
    printf("Age: ");
    scanf("%d", &s2.age);
    printf("GPA: ");
    scanf("%f", &s2.gpa);

    fwrite(&s1, sizeof(struct Student), 1, fp);
    fwrite(&s2, sizeof(struct Student), 1, fp);

    fclose(fp);

    // Reading from a file
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    struct Student s_read;
    while (fread(&s_read, sizeof(struct Student), 1, fp) != 0) {
        printf("\nName: %s\nAge: %d\nGPA: %.2f\n", s_read.name, s_read.age, s_read.gpa);
    }

    fclose(fp);

    return 0;
}