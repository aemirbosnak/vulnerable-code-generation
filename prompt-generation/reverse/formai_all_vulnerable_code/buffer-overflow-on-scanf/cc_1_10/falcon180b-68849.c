//Falcon-180B DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_ROWS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float grade;
} Student;

int main() {
    FILE *fp;
    char filename[MAX_NAME_LENGTH];
    Student students[MAX_NUM_ROWS];
    int num_rows = 0;
    char query[MAX_NAME_LENGTH];

    printf("Enter the name of the database file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open the database file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %d %f", students[num_rows].name, &students[num_rows].age, &students[num_rows].grade)!= EOF) {
        num_rows++;
        if (num_rows >= MAX_NUM_ROWS) {
            printf("Error: too many rows in the database file.\n");
            return 2;
        }
    }

    fclose(fp);

    printf("Enter a SQL query:\n");
    scanf("%s", query);

    if (strcmp(query, "SELECT * FROM students") == 0) {
        for (int i = 0; i < num_rows; i++) {
            printf("%s %d %f\n", students[i].name, students[i].age, students[i].grade);
        }
    } else if (strcmp(query, "SELECT * FROM students WHERE age > 18") == 0) {
        for (int i = 0; i < num_rows; i++) {
            if (students[i].age > 18) {
                printf("%s %d %f\n", students[i].name, students[i].age, students[i].grade);
            }
        }
    } else {
        printf("Error: invalid SQL query.\n");
    }

    return 0;
}