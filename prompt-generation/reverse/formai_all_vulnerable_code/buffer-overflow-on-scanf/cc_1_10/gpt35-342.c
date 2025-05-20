//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Student { 
    char name[20]; 
    int age; 
    float marks; 
}; 

int main() { 
    struct Student s[5]; 
    int n, i; 

    printf("Enter the number of students: "); 
    scanf("%d", &n); 

    for (i = 0; i < n; i++) { 
        printf("Enter the name of student %d: ", i+1); 
        scanf("%s", s[i].name); 

        printf("Enter the age of student %d: ", i+1); 
        scanf("%d", &s[i].age); 

        printf("Enter the marks of student %d: ", i+1); 
        scanf("%f", &s[i].marks); 
    } 

    FILE *fp; 
    fp = fopen("student.txt", "w"); 

    if (fp == NULL) { 
        printf("Error in file opening!\n"); 
        exit(1); 
    } 

    printf("Data successfully written to the file...\n"); 

    for (i = 0; i < n; i++) { 
        fprintf(fp, "%s %d %f\n", s[i].name, s[i].age, s[i].marks); 
    } 

    fclose(fp); 

    fp = fopen("student.txt", "r"); 

    if (fp == NULL) { 
        printf("Error in file opening!\n"); 
        exit(1); 
    } 

    printf("\nData reading from the file....\n"); 

    for (i = 0; i < n; i++) { 
        fscanf(fp, "%s %d %f\n", s[i].name, &s[i].age, &s[i].marks); 
        printf("Name: %s Age: %d Marks: %f\n", s[i].name, s[i].age, s[i].marks); 
    } 

    fclose(fp); 

    return 0; 
}