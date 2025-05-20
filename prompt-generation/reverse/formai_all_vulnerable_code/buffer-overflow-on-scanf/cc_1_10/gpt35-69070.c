//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of a single line in the CSV file

struct Student {
    int id; 
    char name[50]; 
    float gpa;
};

// Function to parse a single line of CSV file and return a Student object
struct Student parse_csv_line(char *line) {
    struct Student student;
    char *token;
    int token_number = 0;
  
    token = strtok(line, ",");
    while (token) {
        switch(token_number) {
            case 0:
                student.id = atoi(token);
                break;
            case 1:
                strcpy(student.name, token);
                break;
            case 2:
                student.gpa = atof(token);
                break;
            default:
                break;
        }
        token = strtok(NULL, ",");
        token_number++;
    }
    return student;
}

int main() {
    char filename[50];
    printf("Enter CSV filename (including extension): ");
    scanf("%s", filename);
    FILE *file_pointer = fopen(filename, "r");
  
    if (file_pointer == NULL) {
        perror("Error opening file");
        return -1;
    }
  
    char line[MAX_LINE_LENGTH];
    struct Student student_list[100];
    int student_count = 0;

    fgets(line, MAX_LINE_LENGTH, file_pointer); // Read and discard the header line
  
    while (fgets(line, MAX_LINE_LENGTH, file_pointer)) {
        struct Student student = parse_csv_line(line);
        student_list[student_count++] = student;
    }

    fclose(file_pointer);
  
    for (int i = 0; i < student_count; i++) {
        printf("%d, %s, %f\n", student_list[i].id, student_list[i].name, student_list[i].gpa);
    }
    return 0;
}