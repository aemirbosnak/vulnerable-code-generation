//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: careful
/*
 * A unique C Online Examination System example program
 * in a careful style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store student information
struct student {
    char name[50];
    int roll_no;
    int age;
    int marks;
};

// function to calculate average marks
float calculate_average(struct student s[]) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += s[i].marks;
    }
    return total / 5.0;
}

int main() {
    struct student students[5];

    // take input from user
    for (int i = 0; i < 5; i++) {
        printf("Enter student %d's name: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter student %d's roll no: ", i + 1);
        scanf("%d", &students[i].roll_no);

        printf("Enter student %d's age: ", i + 1);
        scanf("%d", &students[i].age);

        printf("Enter student %d's marks: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    // calculate average marks
    float avg = calculate_average(students);

    // display average marks
    printf("Average marks: %.2f\n", avg);

    return 0;
}