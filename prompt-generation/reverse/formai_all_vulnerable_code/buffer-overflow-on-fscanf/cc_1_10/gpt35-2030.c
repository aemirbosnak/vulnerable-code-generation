//FormAI DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>

struct Student {
    char name[50];
    int rollNo;
    char grade;
};

int main() {
    // Creating and initializing an array of two Student structures
    struct Student students[2] = {{"John", 1, 'A'}, {"Sarah", 2, 'B'}};

    // Opening the file for writing
    FILE *fp = fopen("students.txt", "w");

    // Checking if the file opened successfully
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Writing the array of Student structures to the file
    for (int i = 0; i < 2; i++) {
        fprintf(fp, "%d %c %s\n", students[i].rollNo, students[i].grade, students[i].name);
    }

    // Closing the file
    fclose(fp);

    // Opening the file for reading
    fp = fopen("students.txt", "r");

    // Checking if the file opened successfully
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Reading the contents of the file and printing them to the console
    printf("Contents of the file:\n");
    while (!feof(fp)) {
        char name[50];
        int rollNo;
        char grade;
        fscanf(fp, "%d %c %s\n", &rollNo, &grade, name);
        printf("%d %c %s\n", rollNo, grade, name);
    }

    // Closing the file
    fclose(fp);

    return 0;
}