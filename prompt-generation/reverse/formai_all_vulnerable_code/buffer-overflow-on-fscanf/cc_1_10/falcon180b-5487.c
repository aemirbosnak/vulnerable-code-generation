//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the struct for the array elements
typedef struct {
    char name[50];
    int id;
    float score;
} Student;

// Define the function to compare two elements
int compare(const void *a, const void *b) {
    Student *student1 = (Student *)a;
    Student *student2 = (Student *)b;

    if(student1->id < student2->id)
        return -1;
    else if(student1->id > student2->id)
        return 1;
    else
        return 0;
}

// Define the main function
int main() {

    // Initialize the array of students
    Student students[MAX_SIZE];

    // Initialize the number of students
    int num_students = 0;

    // Read the data from the input file
    FILE *fp = fopen("students.txt", "r");
    if(fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while(fscanf(fp, "%s %d %f\n", students[num_students].name, &students[num_students].id, &students[num_students].score)!= EOF) {
        num_students++;
    }

    // Sort the array of students
    qsort(students, num_students, sizeof(Student), compare);

    // Prompt the user for the search criteria
    char name[50];
    printf("Enter the name of the student to search for: ");
    scanf("%s", name);

    // Perform the search
    Student *result = bsearch(name, students, num_students, sizeof(Student), compare);

    // Print the search results
    if(result!= NULL) {
        printf("Student found:\n");
        printf("Name: %s\n", result->name);
        printf("ID: %d\n", result->id);
        printf("Score: %.2f\n", result->score);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}