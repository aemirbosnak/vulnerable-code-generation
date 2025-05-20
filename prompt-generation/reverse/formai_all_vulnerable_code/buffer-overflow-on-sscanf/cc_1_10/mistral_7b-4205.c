//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LEN 100
#define FILE_NAME "magicfile.txt"

typedef struct {
    char name[MAX_LEN];
    int age;
    float gpa;
} Student;

int main() {
    Student students[5];
    int i, fd;
    char str[MAX_LEN];

    srand(time(NULL));

    printf("Welcome to the Magical Enchanted School!\n");
    printf("Let's create 5 students with random names, ages, and GPAs.\n");

    for (i = 0; i < 5; i++) {
        students[i].age = rand() % 100 + 1;
        students[i].gpa = (float) rand() / RAND_MAX;

        sprintf(students[i].name, "Student %d", i + 1);

        printf("Student %d: Name: %s, Age: %d, GPA: %.2f\n", i + 1, students[i].name, students[i].age, students[i].gpa);
    }

    fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    printf("\nWriting students data to file %s...\n", FILE_NAME);

    for (i = 0; i < 5; i++) {
        sprintf(str, "%s:%d:%.2f\n", students[i].name, students[i].age, students[i].gpa);
        write(fd, str, strlen(str));
    }

    close(fd);

    printf("\nData written to file successfully!\n");

    printf("\nReading students data from file %s...\n", FILE_NAME);

    fd = open(FILE_NAME, O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    while (read(fd, str, MAX_LEN)) {
        sscanf(str, "%s:%d:%f", students[i].name, &students[i].age, &students[i].gpa);
        printf("Student %d: Name: %s, Age: %d, GPA: %.2f\n", i + 1, students[i].name, students[i].age, students[i].gpa);
        i++;
    }

    close(fd);

    printf("\nData read from file successfully!\n");

    return 0;
}