//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_SIZE 1024

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

void readFile(char *filename, Student students[], int *numStudents) {
    int fd = open(filename, O_RDONLY);
    char line[MAX_SIZE];
    int index = 0;

    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_SIZE, fd) != NULL) {
        sscanf(line, "%d%s%f", &students[index].id, students[index].name, &students[index].gpa);
        index++;
        *numStudents = index;
    }

    close(fd);
}

void printStudents(Student students[], int numStudents) {
    printf("ID\tNAME\tGPA\n");

    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Student students[MAX_SIZE];
    int numStudents = 0;

    readFile(argv[1], students, &numStudents);
    printStudents(students, numStudents);

    return EXIT_SUCCESS;
}