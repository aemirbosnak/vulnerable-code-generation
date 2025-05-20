//Falcon-180B DATASET v1.0 Category: Sorting ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Structure to hold student information
struct student {
    char name[50];
    int age;
    float grade;
};

// Function to compare two students based on their grades
int compare(const void* a, const void* b) {
    struct student* studentA = (struct student*)a;
    struct student* studentB = (struct student*)b;

    if (studentA->grade > studentB->grade) {
        return 1;
    } else if (studentA->grade < studentB->grade) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the sorted list of students
void printList(struct student* list, int numStudents) {
    printf("Sorted list of students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s (%d years old) - Grade: %.2f\n", list[i].name, list[i].age, list[i].grade);
    }
}

// Main function
int main() {
    int numStudents;

    // Get the number of students from the user
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for the list of students
    struct student* list = (struct student*)malloc(numStudents * sizeof(struct student));

    // Get the information for each student from the user
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", list[i].name);

        printf("Enter the age of student %s: ", list[i].name);
        scanf("%d", &list[i].age);

        printf("Enter the grade of student %s: ", list[i].name);
        scanf("%f", &list[i].grade);
    }

    // Sort the list of students based on their grades
    qsort(list, numStudents, sizeof(struct student), compare);

    // Print the sorted list of students
    printList(list, numStudents);

    // Free the dynamically allocated memory
    free(list);

    return 0;
}