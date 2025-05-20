//FormAI DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>

struct student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    FILE *fptr;
    fptr = fopen("students.txt", "w");

    if(fptr == NULL) {
        printf("File could not be created. Exiting...\n");
        return 1;
    }

    struct student s;
    printf("Enter name, roll number and marks of students. Enter '0' to stop.\n");

    while(1) {
        printf("Enter Name: ");
        scanf("%s", s.name);

        if(s.name[0] == '0') {
            break;
        }

        printf("Enter Roll Number: ");
        scanf("%d", &s.rollNumber);
        printf("Enter Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(struct student), 1, fptr);
    }

    fclose(fptr);

    fptr = fopen("students.txt", "r");

    if(fptr == NULL) {
        printf("File could not be opened. Exiting...\n");
        return 1;
    }

    printf("\n\n\n");
    printf("Name\t\tRol No.\t\tMarks\n");
    printf("--------------------------------------------------\n");

    while(fread(&s, sizeof(struct student), 1, fptr)) {
        printf("%s\t\t", s.name);
        printf("%d\t\t", s.rollNumber);
        printf("%.2f\n", s.marks);
    }

    fclose(fptr);
    return 0;
}