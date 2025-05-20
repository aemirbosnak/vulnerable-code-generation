//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>

/*
This program reads data from a file containing student records (name, age, and GPA)
and performs some basic data mining operations to extract useful information.
First, it calculates the average age and GPA of all students.
Then, it finds the student with the highest and lowest GPA and prints out their names.
Finally, it determines the number of students whose age is under 20 and GPA is over 3.0.
*/

struct student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    FILE *fptr;
    fptr = fopen("students.dat", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // read in all student records
    struct student records[100];
    int num_students = 0;
    while (fscanf(fptr, "%s %d %f", records[num_students].name, &records[num_students].age, &records[num_students].gpa) != EOF) {
        num_students++;
    }

    // calculate average age and gpa
    float total_age = 0, total_gpa = 0;
    for (int i = 0; i < num_students; i++) {
        total_age += records[i].age;
        total_gpa += records[i].gpa;
    }
    float avg_age = total_age / num_students;
    float avg_gpa = total_gpa / num_students;
    printf("Average age: %.2f\n", avg_age);
    printf("Average GPA: %.2f\n", avg_gpa);

    // find student with highest and lowest GPA
    float highest_gpa = 0, lowest_gpa = 4;
    int highest_index = 0, lowest_index = 0;
    for (int i = 0; i < num_students; i++) {
        if (records[i].gpa > highest_gpa) {
            highest_gpa = records[i].gpa;
            highest_index = i;
        }
        if (records[i].gpa < lowest_gpa) {
            lowest_gpa = records[i].gpa;
            lowest_index = i;
        }
    }
    printf("Student with highest GPA: %s\n", records[highest_index].name);
    printf("Student with lowest GPA: %s\n", records[lowest_index].name);

    // count number of students under 20 with GPA over 3.0
    int count = 0;
    for (int i = 0; i < num_students; i++) {
        if (records[i].age < 20 && records[i].gpa > 3.0) {
            count++;
        }
    }
    printf("Number of students under 20 with GPA over 3.0: %d\n", count);

    fclose(fptr);
    return 0;
}