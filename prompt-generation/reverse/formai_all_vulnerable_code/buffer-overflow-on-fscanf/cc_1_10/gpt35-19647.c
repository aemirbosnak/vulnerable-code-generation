//FormAI DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for students
struct Student {
    char name[50];
    int id;
    float marks;
    char grade;
};

int main() {
    //Initializing file pointer
    FILE *filePointer;

    //Opening file in read mode
    filePointer = fopen("studentData.txt", "r");

    //Checking if the file exists
    if (filePointer == NULL) {
        printf("File does not exist!\n");
        exit(1);
    }

    //Initializing an array of structures
    struct Student students[5];

    //Reading data from file and storing it in the array of structures
    for (int i = 0; i < 5; i++) {
        fscanf(filePointer, "%s %d %f %c", students[i].name, &students[i].id, &students[i].marks, &students[i].grade);
    }

    //Printing the data from the array of structures
    printf("Student Data from file:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, ID: %d, Marks: %.2f, Grade: %c\n", students[i].name, students[i].id, students[i].marks, students[i].grade);
    }

    //Closing the file
    fclose(filePointer);

    //Opening file in write mode
    filePointer = fopen("newStudentData.txt", "w");

    //Writing data to the new file
    fprintf(filePointer, "%-15s %-10s %-10s %-10s\n", "Name", "ID", "Marks", "Grade");
    for (int i = 0; i < 5; i++) {
        fprintf(filePointer, "%-15s %-10d %-10.2f %-10c\n", students[i].name, students[i].id, students[i].marks, students[i].grade);
    }

    //Closing the file
    fclose(filePointer);

    //Returning 0 to indicate successful execution of program
    return 0;
}