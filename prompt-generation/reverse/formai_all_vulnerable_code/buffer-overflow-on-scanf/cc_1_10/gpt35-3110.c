//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 200

typedef struct {
    char *name;
    int experience;
    float salary;
} Employee;

void parseResume(FILE *filePointer, Employee employee);
int countWords(const char* string);
void printEmployee(Employee employee);

int main() {
    char fileName[MAX_STRING_LENGTH];
    printf("Enter the name of the resume file: ");
    scanf("%s", fileName);
    FILE *filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        printf("Error! File not found!");
        return 0;
    }
    Employee employee;
    parseResume(filePointer, employee);
    fclose(filePointer);
    return 0;
}

void parseResume(FILE *filePointer, Employee employee) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, filePointer)) != -1) {
        int numWords = countWords(line);
        char *words[numWords];
        int i = 0;
        char *token = strtok(line, " ");
        while( token != NULL ) {
            words[i++] = token;
            token = strtok(NULL, " ");
        }
        if (strcmp(words[0], "Name:") == 0) {
            employee.name = words[1];
        } else if (strcmp(words[0], "Experience:") == 0) {
            employee.experience = atoi(words[1]);
        } else if (strcmp(words[0], "Salary:") == 0) {
            employee.salary = atof(words[1]);
        }
    }
    printEmployee(employee);
}

int countWords(const char* string) {
    int count = 0;
    char c;
    for (int i = 0; i < strlen(string); i++) {
        c = string[i];
        if ((c == ' ') || (c == '\n') || (c == '\t')) {
            count++;
        }
    }
    return count;
}

void printEmployee(Employee employee) {
    printf("Name: %s\n", employee.name);
    printf("Experience: %d years\n", employee.experience);
    printf("Salary: $%.2f\n", employee.salary);
}