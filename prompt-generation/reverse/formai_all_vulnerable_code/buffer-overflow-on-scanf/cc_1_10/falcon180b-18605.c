//Falcon-180B DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// structure for a student record
struct student {
    char name[50];
    int age;
    float gpa;
};

// function to read data from a file and store in an array of structures
void read_file(FILE *fp, struct student students[], int n) {
    int i = 0;
    while (fscanf(fp, "%s %d %f", students[i].name, &students[i].age, &students[i].gpa)!= EOF) {
        i++;
    }
    n = i;
}

// function to write data to a file from an array of structures
void write_file(FILE *fp, struct student students[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

// function to sort an array of structures by GPA in descending order
void sort_students(struct student students[], int n) {
    int i, j;
    struct student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (students[j].gpa > students[i].gpa) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// main function
int main() {
    FILE *fp;
    char filename[50];
    int n, i;
    struct student students[100];

    // get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // read data from file
    read_file(fp, students, n);

    // close file
    fclose(fp);

    // sort students by GPA in descending order
    sort_students(students, n);

    // open file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // write sorted data to file
    write_file(fp, students, n);

    // close file
    fclose(fp);

    printf("Data sorted and written to file.\n");

    return 0;
}