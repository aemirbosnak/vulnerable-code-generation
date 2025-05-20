//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student *ptr;
    ptr = (struct student *) malloc(n * sizeof(struct student));

    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", (ptr+i)->name);
        printf("Enter the roll number of student %d: ", i+1);
        scanf("%d", &(ptr+i)->roll);
        printf("Enter the marks of student %d: ", i+1);
        scanf("%f", &(ptr+i)->marks);
    }

    FILE *fptr;
    fptr = fopen("students.txt", "w");

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(fptr, "Name: %s\nRoll No: %d\nMarks: %.2f\n\n", (ptr+i)->name, (ptr+i)->roll, (ptr+i)->marks);
    }

    fclose(fptr);

    printf("Data written to file successfully!\n");

    fptr = fopen("students.txt", "r");

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    char c;
    while ((c = getc(fptr)) != EOF)
        printf("%c", c);

    fclose(fptr);

    free(ptr);
    return 0;
}