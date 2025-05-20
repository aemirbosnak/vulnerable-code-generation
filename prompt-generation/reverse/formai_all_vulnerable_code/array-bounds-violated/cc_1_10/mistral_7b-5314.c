//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SIZE 100
#define MAGIC_NUMBER 42

typedef struct {
    int number;
    char name[20];
} Student;

void bubbleSort(Student arr[], int n) {
    int i, j, tempNumber, tempNameLength;
    char tempName[20];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].number > arr[j + 1].number) {
                tempNumber = arr[j].number;
                arr[j].number = arr[j + 1].number;
                arr[j + 1].number = tempNumber;

                // Swap names
                strcpy(tempName, arr[j].name);
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, tempName);
            }
        }
    }
}

void printArray(Student arr[], int size) {
    int i;

    printf("\n\n***** The Sorting Ceremony *****\n\n");
    printf("***** Welcome to Hogwarts Library *****\n\n");
    printf("Before Sorting:\n\n");

    for (i = 0; i < size; i++) {
        printf("%s: %d\n", arr[i].name, arr[i].number);
    }

    bubbleSort(arr, size);

    printf("\n\n***** The Sorting Ceremony *****\n\n");
    printf("***** Welcome to Hogwarts Library *****\n\n");
    printf("After Sorting:\n\n");

    for (i = 0; i < size; i++) {
        printf("%s: %d\n", arr[i].name, arr[i].number);
    }
}

int main() {
    Student students[MAX_SIZE];
    int i, n;
    clock_t start, end;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter the names and numbers of the students:\n");

    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%s %d", students[i].name, &students[i].number);

        // Add some randomness to names
        int nameLength = strlen(students[i].name);
        if (rand() % 2) {
            students[i].name[nameLength - 1] = toupper(students[i].name[nameLength - 1]);
        }
    }

    start = clock();
    printArray(students, n);
    end = clock();

    printf("\nThe sorting algorithm took %.6fs to execute.", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}