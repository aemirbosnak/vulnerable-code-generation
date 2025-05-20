//Falcon-180B DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Structure for a student
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

// Function to read students from a file
void readStudents(FILE* file, Student students[], int* count) {
    *count = 0;
    while (fscanf(file, "%s %d %f", students[*count].name, &students[*count].age, &students[*count].grade) == 3) {
        (*count)++;
    }
}

// Function to write students to a file
void writeStudents(FILE* file, Student students[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }
}

// Function to sort students by grade
void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[j].grade < students[i].grade) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to calculate the average grade of students
float calculateAverageGrade(Student students[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += students[i].grade;
    }
    return sum / count;
}

int main() {
    FILE* inputFile = fopen("students.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* outputFile = fopen("sorted_students.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 2;
    }

    int studentCount;
    readStudents(inputFile, NULL, &studentCount);

    Student* students = (Student*) malloc(studentCount * sizeof(Student));
    if (students == NULL) {
        printf("Error allocating memory.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 3;
    }

    readStudents(inputFile, students, &studentCount);
    sortStudents(students, studentCount);

    float averageGrade = calculateAverageGrade(students, studentCount);

    writeStudents(outputFile, students, studentCount);

    printf("Average grade: %.2f\n", averageGrade);

    fclose(inputFile);
    fclose(outputFile);
    free(students);

    return 0;
}