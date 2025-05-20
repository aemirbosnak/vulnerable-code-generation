//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: surprised
// Online Examination System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store student details
struct student {
    char name[50];
    char roll_no[10];
    int marks[5];
};

// Function to calculate total marks
int calculate_total_marks(struct student *s) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += s->marks[i];
    }
    return total;
}

// Function to calculate percentage
float calculate_percentage(struct student *s) {
    int total = calculate_total_marks(s);
    return (float)total / 5;
}

// Function to display student details
void display_student_details(struct student *s) {
    printf("Name: %s\n", s->name);
    printf("Roll No: %s\n", s->roll_no);
    for (int i = 0; i < 5; i++) {
        printf("Marks in subject %d: %d\n", i + 1, s->marks[i]);
    }
    printf("Total marks: %d\n", calculate_total_marks(s));
    printf("Percentage: %.2f\n", calculate_percentage(s));
}

int main() {
    struct student s;
    printf("Enter student details:\n");
    printf("Name: ");
    scanf("%s", s.name);
    printf("Roll No: ");
    scanf("%s", s.roll_no);
    for (int i = 0; i < 5; i++) {
        printf("Marks in subject %d: ", i + 1);
        scanf("%d", &s.marks[i]);
    }
    display_student_details(&s);
    return 0;
}