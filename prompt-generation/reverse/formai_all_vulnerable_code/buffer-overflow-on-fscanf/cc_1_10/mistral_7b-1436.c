//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 1000
#define MAX_ID_LENGTH 10
#define MAX_PASS_LENGTH 8

// Structure to store student details
typedef struct {
    char id[MAX_ID_LENGTH + 1];
    char password[MAX_PASS_LENGTH + 1];
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void load_students() {
    FILE *file = fopen("students.db", "r");

    if (file == NULL) {
        printf("Error: Unable to open students database.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s", students[student_count].id, students[student_count].password) != EOF) {
        student_count++;
    }

    fclose(file);
}

int authenticate(char id[], char password[]) {
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0 && strcmp(students[i].password, password) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    load_students();

    char student_id[MAX_ID_LENGTH + 1];
    char student_password[MAX_PASS_LENGTH + 1];

    printf("Enter your student ID: ");
    scanf("%s", student_id);

    printf("Enter your password: ");
    scanf("%s", student_password);
    getchar(); // Consume newline character left in the buffer

    int index = authenticate(student_id, student_password);

    if (index >= 0) {
        printf("Authentication successful! Welcome, %s.\n", students[index].id);

        // Here you can call functions to start the exam
        // For example, you can call a function 'start_exam()'
        // and pass the index of the authenticated student as an argument.

    } else {
        printf("Authentication failed! Please try again.\n");
    }

    return 0;
}