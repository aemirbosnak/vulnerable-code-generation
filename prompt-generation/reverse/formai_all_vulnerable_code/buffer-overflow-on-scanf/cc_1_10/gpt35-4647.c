//FormAI DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>

#define MAX_STUDENTS 100

// Student structure to hold information of each student  
struct Student {
    char name[20];
    int age;
    char gender;
    float gpa;
};

// Function declaration for sorting students by name
void sortByName(struct Student students[], int count);

// Function declaration for sorting students by GPA
void sortByGpa(struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;

    // Read in student information from user input
    printf("Enter student name, age, gender, and GPA (separated by spaces or newlines). Enter 'done' when finished.\n");
    while (count < MAX_STUDENTS) {
        scanf("%s", students[count].name);
        if (strcmp(students[count].name, "done") == 0) {
            break;
        }
        scanf("%d %c %f", &students[count].age, &students[count].gender, &students[count].gpa);
        count++;
    }

    // Sort the array of students by name and print out the sorted list
    sortByName(students, count);
    printf("\nStudents sorted by name:\n");
    printf("Name\t\tAge\tGender\tGPA\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s\t%d\t%c\t%.2f\n", students[i].name, students[i].age, students[i].gender, students[i].gpa);
    }

    // Sort the array of students by GPA and print out the sorted list
    sortByGpa(students, count);
    printf("\nStudents sorted by GPA:\n");
    printf("Name\t\tAge\tGender\tGPA\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s\t%d\t%c\t%.2f\n", students[i].name, students[i].age, students[i].gender, students[i].gpa);
    }

    return 0;
}

void sortByName(struct Student students[], int count) {
    // Bubble sort algorithm to sort students by name
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].name, students[j+1].name) > 0) {
                // Swap students
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

void sortByGpa(struct Student students[], int count) {
    // Selection sort algorithm to sort students by GPA
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (students[j].gpa < students[minIndex].gpa) {
                minIndex = j;
            }
        }
        // Swap students
        struct Student temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }
}