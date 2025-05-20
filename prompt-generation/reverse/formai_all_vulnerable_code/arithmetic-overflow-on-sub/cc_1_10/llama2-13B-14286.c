//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent a student
struct Student {
    char name[20];
    int age;
    double score;
};

// Define a function to swap two students
void swap_students(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Define a function to sort students by score
void sort_students_by_score(struct Student *array, int size) {
    int i, j, min_index;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (array[j].score > array[min_index].score) {
                min_index = j;
            }
        }
        swap_students(&array[min_index], &array[i]);
    }
}

// Define a function to print the sorted students
void print_students(struct Student *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s %d %f\n", array[i].name, array[i].age, array[i].score);
    }
}

int main() {
    int size;
    struct Student *array;

    // Ask the user for the number of students
    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Allocate memory for the array of students
    array = calloc(size, sizeof(struct Student));

    // Ask the user for the students' information
    for (int i = 0; i < size; i++) {
        printf("Enter student %d's name: ", i + 1);
        fgets(array[i].name, 20, stdin);
        printf("Enter student %d's age: ", i + 1);
        scanf("%d", &array[i].age);
        printf("Enter student %d's score: ", i + 1);
        scanf("%lf", &array[i].score);
    }

    // Sort the students by score
    sort_students_by_score(array, size);

    // Print the sorted students
    print_students(array, size);

    // Free the memory for the array of students
    free(array);

    return 0;
}