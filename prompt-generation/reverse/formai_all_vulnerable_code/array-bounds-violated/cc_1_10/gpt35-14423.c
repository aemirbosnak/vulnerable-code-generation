//FormAI DATASET v1.0 Category: Database querying ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ID_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char id[MAX_ID_LEN];
    int age;
} Student;

int main() {
    FILE *fp;
    Student students[5];
    char search_id[MAX_ID_LEN];
    int i, found = 0;

    // open file for reading
    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // read data from file
    fread(students, sizeof(Student), 5, fp);

    // prompt user for student id to search
    printf("Enter student id to search: ");
    fgets(search_id, MAX_ID_LEN, stdin);
    search_id[strlen(search_id) - 1] = '\0'; // remove newline character

    // search for student with given id
    for (i = 0; i < 5; i++) {
        if (strcmp(students[i].id, search_id) == 0) {
            found = 1;
            break;
        }
    }

    // print results
    if (found) {
        printf("Student found:\n");
        printf("Name: %s\n", students[i].name);
        printf("ID: %s\n", students[i].id);
        printf("Age: %d\n", students[i].age);
    } else {
        printf("Student not found.\n");
    }

    // close file
    fclose(fp);

    return 0;
}