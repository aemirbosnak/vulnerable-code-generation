//FormAI DATASET v1.0 Category: Database querying ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing information about a student
struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

// Function to read the student data from a file
void read_student_data(int id[], char name[][50], int age[], float gpa[]) {
    FILE *fp = fopen("students.dat", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%d %s %d %f", &id[i], name[i], &age[i], &gpa[i]) != EOF) {
        i++;
    }

    fclose(fp);
}

// Function to print the student data
void print_student_data(int id[], char name[][50], int age[], float gpa[], int count) {
    printf("ID\tName\t\tAge\tGPA\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", id[i], name[i], age[i], gpa[i]);
    }
}

// Function to sort the student data by ID
void sort_by_id(int id[], char name[][50], int age[], float gpa[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (id[i] > id[j]) {
                int temp_id = id[i];
                char temp_name[50];
                strcpy(temp_name, name[i]);
                int temp_age = age[i];
                float temp_gpa = gpa[i];

                id[i] = id[j];
                strcpy(name[i], name[j]);
                age[i] = age[j];
                gpa[i] = gpa[j];

                id[j] = temp_id;
                strcpy(name[j], temp_name);
                age[j] = temp_age;
                gpa[j] = temp_gpa;
            }
        }
    }
}

// Function to sort the student data by name
void sort_by_name(int id[], char name[][50], int age[], float gpa[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(name[i], name[j]) > 0) {
                int temp_id = id[i];
                char temp_name[50];
                strcpy(temp_name, name[i]);
                int temp_age = age[i];
                float temp_gpa = gpa[i];

                id[i] = id[j];
                strcpy(name[i], name[j]);
                age[i] = age[j];
                gpa[i] = gpa[j];

                id[j] = temp_id;
                strcpy(name[j], temp_name);
                age[j] = temp_age;
                gpa[j] = temp_gpa;
            }
        }
    }
}

int main() {
    int id[100], age[100], count;
    char name[100][50];
    float gpa[100];

    read_student_data(id, name, age, gpa);
    count = sizeof(id) / sizeof(id[0]);

    printf("Original data:\n");
    print_student_data(id, name, age, gpa, count);

    printf("\nData sorted by ID:\n");
    sort_by_id(id, name, age, gpa, count);
    print_student_data(id, name, age, gpa, count);

    printf("\nData sorted by name:\n");
    sort_by_name(id, name, age, gpa, count);
    print_student_data(id, name, age, gpa, count);

    return 0;
}