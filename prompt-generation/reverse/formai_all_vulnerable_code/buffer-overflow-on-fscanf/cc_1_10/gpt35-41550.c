//FormAI DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int num_students, score;
    float avg_score = 0;
    char name[20];

    // Open file for writing
    FILE *file = fopen("scores.txt", "w");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Ask user for number of students
    printf("Enter number of students: ");
    scanf("%d", &num_students);

    // Loop through each student
    for (int i = 0; i < num_students; i++) {
        // Ask user for student name and score
        printf("Enter name and score for student %d: ", i+1);
        scanf("%s %d", &name, &score);

        // Write student name and score to file
        fprintf(file, "%s %d\n", name, score);

        // Calculate average score
        avg_score += score;
    }

    // Close the file
    fclose(file);

    // Calculate average score
    avg_score /= num_students;

    // Open file for reading
    file = fopen("scores.txt", "r");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Loop through each line of file
    while (!feof(file)) {
        // Read name and score from file
        fscanf(file, "%s %d", &name, &score);

        // Print name and score
        printf("%s scored %d\n", name, score);
    }

    // Close the file
    fclose(file);

    // Print average score
    printf("Average score: %.2f\n", avg_score);

    return 0;
}