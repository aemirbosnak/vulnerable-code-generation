//FormAI DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <string.h>

struct student {
   int id;
   char name[50];
   int age;
   float gpa;
};

void print_student(struct student s) {
    printf("\nID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("GPA: %f\n", s.gpa);
}

int main() {
    struct student students[3];

    // Get information for all students
    for (int i=0; i<3; i++) {
        printf("Enter information for student %d:\n", i+1);

        // Get ID
        printf("ID: ");
        scanf("%d", &students[i].id);

        // Get Name
        printf("Name: ");
        scanf("%s", students[i].name);

        // Get Age
        printf("Age: ");
        scanf("%d", &students[i].age);

        // Get GPA
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    // Print information for all students
    printf("\nInformation for all students:\n");
    for (int i=0; i<3; i++) {
        print_student(students[i]);
    }

    // Find student with highest GPA
    float highest_gpa = 0.0;
    int highest_gpa_index = 0;
    for (int i=0; i<3; i++) {
        if (students[i].gpa > highest_gpa) {
            highest_gpa = students[i].gpa;
            highest_gpa_index = i;
        }
    }

    // Print information for student with highest GPA
    printf("\nStudent with highest GPA:\n");
    print_student(students[highest_gpa_index]);

    return 0;
}