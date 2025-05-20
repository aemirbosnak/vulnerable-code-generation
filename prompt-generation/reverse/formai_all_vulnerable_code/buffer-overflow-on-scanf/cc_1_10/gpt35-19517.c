//FormAI DATASET v1.0 Category: Database querying ; Style: Dennis Ritchie
#include <stdio.h> 

struct employee {
    int emp_id;
    char name[20];
    char job_title[20];
    int salary;
};

void print_data(struct employee emp[], int n);

void search_by_job(struct employee emp[], int n);

void sort_by_salary(struct employee emp[], int n);

int main() {
    struct employee emp[5] = {
        {100, "John", "Manager", 50000},
        {200, "Mary", "Developer", 40000},
        {300, "Bob", "Analyst", 35000},
        {400, "Jenny", "Designer", 45000},
        {500, "Jake", "Programmer", 42000}
    };
    int n = sizeof(emp) / sizeof(emp[0]);
    
    printf("\n====Employee Data====\n");
    print_data(emp, n);
    
    printf("\n====Search by Job Title====\n");
    search_by_job(emp, n);
    
    printf("\n====Sort by Salary====\n");
    sort_by_salary(emp, n);
    print_data(emp, n);
    
    return 0;
}

void print_data(struct employee emp[], int n) {
    printf("Emp ID\tName\tJob Title\tSalary\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%s\t%s\t\t%d\n", emp[i].emp_id, emp[i].name, emp[i].job_title, emp[i].salary);
    }
}

void search_by_job(struct employee emp[], int n) {
    char job[20];
    printf("Enter job title: ");
    scanf("%s", job);
    printf("Emp ID\tName\tJob Title\tSalary\n");
    for(int i=0; i<n; i++) {
        if (strcmp(job, emp[i].job_title) == 0) {
            printf("%d\t%s\t%s\t\t%d\n", emp[i].emp_id, emp[i].name, emp[i].job_title, emp[i].salary);
        }
    }
}

void sort_by_salary(struct employee emp[], int n) {
    int i, j;
    struct employee temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(emp[j].salary > emp[j+1].salary) {
                temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;
            }
        }
    }
}