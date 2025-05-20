//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    char position[50];
    int salary;
    int years_of_experience;
};

struct Company {
    char name[50];
    char industry[50];
    int num_employees;
};

struct Resume {
    struct Employee employee;
    struct Company company;
};

struct Resume parse_resume(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct Resume resume;

    fscanf(file, "%s %s %d %d",
            resume.employee.name,
            resume.employee.position,
            &resume.employee.salary,
            &resume.employee.years_of_experience);

    fscanf(file, "%s %s %d",
            resume.company.name,
            resume.company.industry,
            &resume.company.num_employees);

    fclose(file);

    return resume;
}

int main() {
    struct Resume resume = parse_resume("resume.txt");

    printf("Name: %s\n", resume.employee.name);
    printf("Position: %s\n", resume.employee.position);
    printf("Salary: %d\n", resume.employee.salary);
    printf("Years of Experience: %d\n\n", resume.employee.years_of_experience);

    printf("Company Name: %s\n", resume.company.name);
    printf("Industry: %s\n", resume.company.industry);
    printf("Number of Employees: %d\n\n", resume.company.num_employees);

    return 0;
}