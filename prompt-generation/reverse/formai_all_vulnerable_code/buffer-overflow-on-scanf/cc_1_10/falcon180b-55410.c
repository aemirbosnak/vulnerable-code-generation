//Falcon-180B DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a student
typedef struct {
    char name[50];
    int age;
    float GPA;
} Student;

// Function to read a CSV file and populate an array of students
Student* readCSV(char* filename, int* numStudents) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    char line[100];
    Student* students = (Student*)malloc(sizeof(Student));
    int count = 0;
    
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char* token = strtok(line, ",");
        strcpy(students[count].name, token);
        token = strtok(NULL, ",");
        students[count].age = atoi(token);
        token = strtok(NULL, ",");
        students[count].GPA = atof(token);
        count++;
        if (count == *numStudents) {
            break;
        }
    }
    
    if (count < *numStudents) {
        printf("Error reading file %s\n", filename);
        exit(1);
    }
    
    fclose(fp);
    return students;
}

// Function to sort an array of students by GPA
void sortStudents(Student* students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].GPA < students[j].GPA) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to print an array of students
void printStudents(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", students[i].name, students[i].age, students[i].GPA);
    }
}

// Main function
int main() {
    char filename[50];
    int numStudents;
    
    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);
    
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    Student* students = readCSV(filename, &numStudents);
    sortStudents(students, numStudents);
    printStudents(students, numStudents);
    
    free(students);
    return 0;
}