//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int roll;
    float marks;
};

int main() {

    struct student s[5];
    FILE *fptr;
    int i;

    fptr = fopen("students.txt", "wb");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (i = 0; i < 5; i++) {
        printf("Enter student name, roll no. and marks:\n");
        scanf("%s %d %f", s[i].name, &s[i].roll, &s[i].marks);

        fwrite(&s[i], sizeof(struct student), 1, fptr);
    }

    fclose(fptr);

    // Read file and display data 
    fptr = fopen("students.txt", "rb");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\nData from file:\n");
    printf("Name\tRoll\tMarks\n");
    for (i = 0; i < 5; i++) {
        fread(&s[i], sizeof(struct student), 1, fptr);

        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll, s[i].marks);
    }

    fclose(fptr);

    return 0;
}