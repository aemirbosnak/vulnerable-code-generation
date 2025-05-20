//Falcon-180B DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_students, i, j;
    char name[50], subject[50];
    float grade;
    struct tm current_time;
    time_t now;

    // Get the current time
    now = time(NULL);
    localtime_r(&now, &current_time);

    // Get the number of students from the user
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Create an array to store the students' names
    char *students[num_students];

    // Get the names of the students from the user
    for (i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i]);
    }

    // Create an array to store the students' grades
    float grades[num_students];

    // Get the grades of the students from the user
    for (i = 0; i < num_students; i++) {
        printf("Enter the grade for %s in subject 1: ", students[i]);
        scanf("%f", &grades[i]);
        printf("Enter the grade for %s in subject 2: ", students[i]);
        scanf("%f", &grades[i]);
        printf("Enter the grade for %s in subject 3: ", students[i]);
        scanf("%f", &grades[i]);
    }

    // Calculate the average grade for each student
    for (i = 0; i < num_students; i++) {
        grade = (grades[i] + grades[i + 1] + grades[i + 2]) / 3;
        printf("%s's average grade is %.2f\n", students[i], grade);
    }

    // Sort the students by their average grades
    for (i = 0; i < num_students; i++) {
        for (j = i + 1; j < num_students; j++) {
            if (grades[j] > grades[i]) {
                char temp_name[50];
                float temp_grade;
                strcpy(temp_name, students[i]);
                strcpy(students[i], students[j]);
                strcpy(students[j], temp_name);
                temp_grade = grades[i];
                grades[i] = grades[j];
                grades[j] = temp_grade;
            }
        }
    }

    // Print the sorted list of students
    printf("\nSorted by average grade:\n");
    for (i = 0; i < num_students; i++) {
        printf("%s: %.2f\n", students[i], grades[i]);
    }

    return 0;
}