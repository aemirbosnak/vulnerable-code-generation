//Falcon-180B DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>

// Define a structure to represent a student
typedef struct {
    char name[50];
    int age;
    float GPA;
} student_t;

// Function to read student data from a file
int read_students(FILE *fp, student_t students[]) {
    int count = 0;
    while (fscanf(fp, "%s %d %f", students[count].name, &students[count].age, &students[count].GPA) == 3) {
        count++;
    }
    return count;
}

// Function to write student data to a file
void write_students(FILE *fp, student_t students[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].GPA);
    }
}

// Function to sort students by GPA in descending order
void sort_students(student_t students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].GPA < students[j].GPA) {
                student_t temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Main function
int main() {
    FILE *input_file, *output_file;
    student_t students[100];
    int num_students;

    // Open input file
    input_file = fopen("students.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read student data from input file
    num_students = read_students(input_file, students);
    if (num_students == 0) {
        printf("No students found in input file.\n");
        fclose(input_file);
        return 1;
    }

    // Sort students by GPA in descending order
    sort_students(students, num_students);

    // Open output file
    output_file = fopen("sorted_students.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Write sorted student data to output file
    write_students(output_file, students, num_students);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Students sorted by GPA and saved to sorted_students.txt.\n");

    return 0;
}