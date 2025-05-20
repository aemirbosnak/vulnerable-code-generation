//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void writeToFile(char* fileName) {
    FILE* filePointer;
    filePointer = fopen(fileName, "w");

    if (filePointer == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    char name[20];
    int age;
    float salary;

    printf("Enter your name: ");
    scanf("%s", name);
    fprintf(filePointer, "Name: %s\n", name);

    printf("Enter your age: ");
    scanf("%d", &age);
    fprintf(filePointer, "Age: %d\n", age);

    printf("Enter your salary: ");
    scanf("%f", &salary);
    fprintf(filePointer, "Salary: %.2f\n", salary);

    printf("Data written to file successfully!\n");

    fclose(filePointer);
}

void readFromFile(char* fileName) {
    FILE* filePointer;
    filePointer = fopen(fileName, "r");

    if (filePointer == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    char line[100];

    while (fgets(line, sizeof(line), filePointer)) {
        printf("%s", line);
    }

    fclose(filePointer);
}

int main() {
    char fileName[] = "employee.txt";

    writeToFile(fileName);

    readFromFile(fileName);

    return 0;
}