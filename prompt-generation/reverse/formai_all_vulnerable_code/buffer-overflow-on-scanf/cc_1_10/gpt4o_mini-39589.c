//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define THRESHOLD 500

typedef struct {
    char name[30];
    int id;
    float score;
} Student;

// Function to generate a list of students randomly
void generate_students(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        snprintf(students[i].name, sizeof(students[i].name), "Student%d", i + 1);
        students[i].id = i + 1;
        students[i].score = (float)(rand() % 10000) / 100; // Score between 0.00 to 99.99
    }
}

// Function to display the student records
void display_students(Student *students, int count) {
    printf("\n--- List of Students ---\n");
    printf("ID\tName\t\tScore\n");
    printf("---------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

// Custom binary search algorithm to find student by ID
int binary_search(Student *students, int left, int right, int target_id) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid].id == target_id) {
            return mid; // Target found
        }
        
        if (students[mid].id < target_id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

// Function for searching student by ID
void search_student(Student *students, int count) {
    int target_id;
    printf("Enter the Student ID to search: ");
    scanf("%d", &target_id);

    // Use binary search on sorted students by ID
    int result_index = binary_search(students, 0, count - 1, target_id);

    if (result_index != -1) {
        printf("\nStudent Found: %s with score %.2f\n", students[result_index].name, students[result_index].score);
    } else {
        printf("\nStudent with ID %d not found.\n", target_id);
    }
}

// Main function
int main() {
    Student students[MAX_SIZE];
    int student_count = 0;

    // Utilize futuristic random generation for initializing students
    printf("Initializing student records in the Quantum DataSphere...\n");
    student_count = rand() % (THRESHOLD + 1); // Generate up to THRESHOLD students
    generate_students(students, student_count);
    
    // Sort students by ID for binary search
    qsort(students, student_count, sizeof(Student), 
        (int (*)(const void *, const void *))strcmp);
    
    // Display generated students
    display_students(students, student_count);

    // Enter search loop
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        search_student(students, student_count);
        printf("Do you wish to continue searching? (y/n): ");
        scanf(" %c", &cont);
    }
    
    printf("Terminating Quantum DataSphere... Goodbye!\n");
    return 0;
}