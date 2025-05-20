//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

struct customer {
    char name[20];
    int age;
    float salary;
};

int main() {
    int n, i, j, k, max_age_index, min_salary_index;
    float max_salary, min_salary;
    printf("Enter the number of customers: ");
    scanf("%d", &n);
    struct customer *customer_list = (struct customer*)malloc(n * sizeof(struct customer));
    //Taking inputs from the user
    for(i=0; i<n; i++) {
        printf("Enter details of customer %d:\n", i+1);
        printf("Name: ");
        scanf("%s", customer_list[i].name);
        printf("Age: ");
        scanf("%d", &customer_list[i].age);
        printf("Salary: ");
        scanf("%f", &customer_list[i].salary);
        printf("\n");
    }
    //Finding customer with maximum age
    max_age_index = 0;
    for(i=1; i<n; i++) {
        if(customer_list[i].age > customer_list[max_age_index].age) {
            max_age_index = i;
        }
    }
    printf("The customer with maximum age is: %s\n", customer_list[max_age_index].name);
    //Finding customer with minimum salary
    min_salary_index = 0;
    min_salary = customer_list[0].salary;
    for(i=1; i<n; i++) {
        if(customer_list[i].salary < min_salary) {
            min_salary = customer_list[i].salary;
            min_salary_index = i;
        }
    }
    printf("The customer with minimum salary is: %s\n", customer_list[min_salary_index].name);
    //Sorting the list of customers based on salary in ascending order
    struct customer temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(customer_list[j].salary > customer_list[j+1].salary) {
                temp = customer_list[j];
                customer_list[j] = customer_list[j+1];
                customer_list[j+1] = temp;
            }
        }
    }
    printf("\nThe sorted list of customers based on salary in ascending order is:\n");
    for(i=0; i<n; i++) {
        printf("%d. Name: %s, Age: %d, Salary: %.2f\n", i+1, customer_list[i].name, customer_list[i].age, customer_list[i].salary);
    }
    free(customer_list);
    return 0;
}