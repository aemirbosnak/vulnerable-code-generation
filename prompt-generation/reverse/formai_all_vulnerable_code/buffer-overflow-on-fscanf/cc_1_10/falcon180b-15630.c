//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int id;
} Student;

int main() {
    int n, searchId;
    FILE *file;
    Student students[MAX_SIZE];

    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    n = 0;
    while (fscanf(file, "%s %d", students[n].name, &students[n].id)!= EOF) {
        n++;
        if (n == MAX_SIZE) {
            printf("Maximum number of students reached!\n");
            exit(1);
        }
    }

    fclose(file);

    printf("Enter the student ID to search for: ");
    scanf("%d", &searchId);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].id == searchId) {
            printf("Student found: %s (%d)\n", students[i].name, searchId);
            found = 1;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }

    return 0;
}

/* Sample input/output:

Enter the student ID to search for: 123
Student found: John (123)

Enter the student ID to search for: 456
Student not found!

Enter the student ID to search for: 789
Student not found!

*/