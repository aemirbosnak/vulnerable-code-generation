//Falcon-180B DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int id;
} student_t;

int read_csv_file(const char *filename, student_t students[], int max_size) {
    FILE *fp;
    char line[MAX_SIZE];
    char *token;
    int i = 0;

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }

    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        if (i >= max_size) {
            fprintf(stderr, "Error: Maximum number of students exceeded\n");
            fclose(fp);
            return -1;
        }

        students[i].name = strdup(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Error: Invalid line format\n");
            fclose(fp);
            return -1;
        }

        students[i].age = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Error: Invalid line format\n");
            fclose(fp);
            return -1;
        }

        students[i].id = atoi(token);
        i++;
    }

    fclose(fp);
    return 0;
}

int write_csv_file(const char *filename, student_t students[], int num_students) {
    FILE *fp;
    int i;

    if ((fp = fopen(filename, "w")) == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }

    for (i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%d,%d\n", students[i].name, students[i].age, students[i].id);
    }

    fclose(fp);
    return 0;
}

int main() {
    student_t students[MAX_SIZE];
    int num_students = 0;

    if (read_csv_file("students.csv", students, MAX_SIZE)!= 0) {
        exit(1);
    }

    num_students = sizeof(students) / sizeof(students[0]);

    if (write_csv_file("output.csv", students, num_students)!= 0) {
        exit(1);
    }

    return 0;
}