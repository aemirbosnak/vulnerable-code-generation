//FormAI DATASET v1.0 Category: System boot optimizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This program optimizes the system boot process by sorting and organizing the 
  startup programs according to priority level and removing unnecessary programs.
*/

// define maximum number of programs
#define MAX_PROGRAMS 100

// struct to hold information about each program
typedef struct Program {
    char name[50];
    int priority;
    char description[100];
} Program;

// function to sort programs by priority level
void sortByPriority(Program programs[], int numPrograms) {
    int i, j;
    Program temp;
    for (i = 0; i < numPrograms; i++) {
        for (j = i + 1; j < numPrograms; j++) {
            if (programs[i].priority < programs[j].priority) {
                // swap programs
                temp = programs[i];
                programs[i] = programs[j];
                programs[j] = temp;
            }
        }
    }
}

int main() {
    int numPrograms;
    Program programs[MAX_PROGRAMS];

    // get number of programs from user
    printf("Enter the number of programs to be optimized: ");
    scanf("%d", &numPrograms);

    // get information about each program from user
    for (int i = 0; i < numPrograms; i++) {
        printf("Enter information about program %d:\n", i+1);
        printf("Name: ");
        scanf("%s", programs[i].name);
        printf("Priority (1-10): ");
        scanf("%d", &programs[i].priority);
        printf("Description: ");
        scanf("%s", programs[i].description);
    }

    // sort programs by priority level
    sortByPriority(programs, numPrograms);

    // display optimized list of programs
    printf("Optimized program list:\n");
    printf("Program Name | Priority | Description\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < numPrograms; i++) {
        printf("%-12s | %-8d | %s\n", programs[i].name, programs[i].priority, programs[i].description);
    }

    return 0;
}