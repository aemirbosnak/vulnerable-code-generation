//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>

/* Constants */
#define STUDENTS 3
#define TESTS 4
#define MAX_NAME_LENGTH 20

/* Function prototypes */
void read_grades(int num_students, int num_tests, int grades[][num_tests], char names[][MAX_NAME_LENGTH]);
void print_grades(int num_students, int num_tests, int grades[][num_tests], char names[][MAX_NAME_LENGTH]);
void write_to_file(int num_students, int num_tests, int grades[][num_tests], char names[][MAX_NAME_LENGTH]);

int main() {
    /* Initialize variables */
    int grades[STUDENTS][TESTS];
    char names[STUDENTS][MAX_NAME_LENGTH];
    
    /* Read grades from user input */
    read_grades(STUDENTS, TESTS, grades, names);
    
    /* Print grades to console */
    printf("Grades:\n");
    print_grades(STUDENTS, TESTS, grades, names);
    
    /* Write grades to file */
    printf("Writing grades to file...\n");
    write_to_file(STUDENTS, TESTS, grades, names);
    
    return 0;
}

/* Reads grades from user input */
void read_grades(int num_students, int num_tests, int grades[][num_tests], char names[][MAX_NAME_LENGTH]) {
    /* Loop through each student and test */
    for(int i = 0; i < num_students; i++) {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", names[i]);
        for(int j = 0; j < num_tests; j++) {
            printf("Enter grade for %s in test %d: ", names[i], j+1);
            scanf("%d", &grades[i][j]);
        }
    }
}

/* Prints grades to console */
void print_grades(int num_students, int num_tests, int grades[][num_tests], char names[][MAX_NAME_LENGTH]) {
    /* Print header*/
    printf("%-20s", "Name");
    for(int i = 0; i < num_tests; i++) {
        printf("Test %d\t", i+1);
    }
    printf("\n");
    /* Loop through each student */
    for(int i = 0; i < num_students; i++) {
        /* Print name */
        printf("%-20s", names[i]);
        /* Print grades */
        for(int j = 0; j < num_tests; j++) {
            printf("%d\t", grades[i][j]);
        }
        printf("\n");
    }
}

/* Writes grades to file */
void write_to_file(int num_students, int num_tests, int grades[][num_tests], char names[][MAX_NAME_LENGTH]) {
    FILE *file;
    /* Open file for writing */
    file = fopen("grades.txt", "w");
    /* Loop through each student */
    for(int i = 0; i < num_students; i++) {
        /* Write name to file */
        fprintf(file, "%s\t", names[i]);
        /* Write grades to file */
        for(int j = 0; j < num_tests; j++) {
            fprintf(file, "%d\t", grades[i][j]);
        }
        fprintf(file, "\n");
    }
    /* Close file */
    fclose(file);
    printf("Grades written to grades.txt.\n");
}