//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

typedef struct {
    char name[50];
    int age;
    float score;
} Student;

void initialize_students(Student students[], int count);
void display_students(const Student students[], int count);
void sort_students(Student students[], int count);
void swap(Student *a, Student *b);
void search_student(const Student students[], int count, const char *name);
void display_menu();

int main() {
    Student students[MAX_SIZE];
    int count = 0;
    int choice = 0;

    srand(time(NULL)); // Seed the random number generator
    printf("Welcome to the Student Management System!\n");

    while (choice != 6) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of students to initialize (Max %d): ", MAX_SIZE);
                scanf("%d", &count);
                if (count > MAX_SIZE) {
                    printf("Cannot initialize more than %d students.\n", MAX_SIZE);
                    count = MAX_SIZE;
                }
                initialize_students(students, count);
                break;
            case 2:
                display_students(students, count);
                break;
            case 3:
                sort_students(students, count);
                printf("Students sorted by score.\n");
                break;
            case 4: {
                char name[50];
                printf("Enter the name of the student to search: ");
                scanf("%s", name);
                search_student(students, count, name);
                break;
            }
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Initialize Students\n");
    printf("2. Display Students\n");
    printf("3. Sort Students\n");
    printf("4. Search Student\n");
    printf("5. Exit\n");
}

void initialize_students(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &students[i].age);
        students[i].score = (float)(rand() % 101); // Random score between 0 to 100
        printf("Initialized: %s, Age: %d, Score: %.2f\n", students[i].name, students[i].age, students[i].score);
    }
}

void display_students(const Student students[], int count) {
    printf("\nStudent List:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Score: %.2f\n", students[i].name, students[i].age, students[i].score);
    }
}

void sort_students(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void search_student(const Student students[], int count, const char *name) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student Found: Name: %s, Age: %d, Score: %.2f\n", students[i].name, students[i].age, students[i].score);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student %s not found.\n", name);
    }
}