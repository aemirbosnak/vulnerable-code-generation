//FormAI DATASET v1.0 Category: Data mining ; Style: grateful
#include<stdio.h>

struct employees {
    int id;
    char name[20];
    int age;
    float salary;
};

struct performance {
    int id;
    char review[100];
    float rating;
};

void dataMining(struct employees e[], struct performance p[], int n) {
    float totalSalaries = 0, avgSalary;
    int count = 0;
    for(int i=0; i<n; i++) {
        totalSalaries += e[i].salary;
        for(int j=0; j<n; j++) {
            if(e[i].id == p[j].id && p[j].rating > 3) {
                printf("Employee %s received a positive review with a rating of %.2f\n", e[i].name, p[j].rating);
                count++;
                break;
            }
        }
    }
    avgSalary = totalSalaries / n;
    printf("\nThe average salary of the employees is %.2f\n", avgSalary);
    printf("The number of employees that received a positive review is %d\n", count);
}

int main() {
    int n;
    printf("Enter the number of employees in the company: ");
    scanf("%d", &n);
    struct employees e[n];
    struct performance p[n];
    for(int i=0; i<n; i++) {
        printf("\nEnter the details of employee %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &e[i].id);
        printf("Name: ");
        scanf("%s", e[i].name);
        printf("Age: ");
        scanf("%d", &e[i].age);
        printf("Salary: ");
        scanf("%f", &e[i].salary);
        printf("Review: ");
        scanf("%s", p[i].review);
        printf("Rating (out of 5): ");
        scanf("%f", &p[i].rating);
        p[i].id = e[i].id;
    }
    printf("\n-------- Data Mining Results --------\n");
    dataMining(e, p, n);
    return 0;
}