//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[20];
    char name[20];
    int age;
    float salary;

    printf("Enter file name to create: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error creating file\n");
        exit(1);
    }

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter salary: ");
    scanf("%f", &salary);

    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Age: %d\n", age);
    fprintf(fp, "Salary: %.2f\n", salary);

    fclose(fp);

    printf("File created successfully.\n");

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[255];
    while (fgets(buffer, 255, fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}