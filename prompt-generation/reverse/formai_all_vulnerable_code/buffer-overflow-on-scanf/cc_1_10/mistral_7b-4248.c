//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
} Student;

void print_students(Student students[], int n) {
    printf("\n--------- THE CLASSROOM --------- \n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s %d\n", i + 1, students[i].name, students[i].id);
    }
}

int is_valid_name(const char *name) {
    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        if (!isalnum(name[i])) {
            return 0;
        }
    }
    return 1;
}

void read_students(Student students[], int *n) {
    printf("\n---- Welcome to BubbaSort! ----\n");
    printf("Enter the number of students: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("\nEnter student %d's name: ", i + 1);
        scanf("%s", students[i].name);
        while (getchar() != '\n') {
            getchar();
        }
        if (!is_valid_name(students[i].name)) {
            printf("\nInvalid name! Please try again.\n");
            i--;
            continue;
        }
        printf("Enter student %d's ID: ", i + 1);
        scanf("%d", &students[i].id);
    }
}

void bubble_sort(Student students[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    Student students[MAX];
    int n;

    srand(time(NULL));

    read_students(students, &n);
    bubble_sort(students, n);
    print_students(students, n);

    printf("\n---- BubbaSort has spoken! ----\n");

    return 0;
}