//FormAI DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
#include<stdio.h>

#define MAX 100

// Struct for storing employee data
struct employee {
    int emp_id;
    char name[MAX];
    int age;
    float salary;
};

//Struct for Index Node
struct index_node {
    int emp_id;
    int index;
};

//Function to create index
void create_index(struct employee emp[], int size, struct index_node index[]) {
    for(int i=0;i<size;i++) {
        index[i].emp_id = emp[i].emp_id;
        index[i].index = i;
    }
}

//Function to search employee by id using index
void search_employee_by_id(struct employee emp[], int size, struct index_node index[]) {
    int emp_id,flag=0;
    printf("Enter Employee Id: ");
    scanf("%d",&emp_id);
    for(int i=0;i<size;i++) {
        if(index[i].emp_id==emp_id) {
            printf("Employee Found\n");
            printf("Employee Details: \n");
            printf("ID: %d\nName: %s\nAge: %d\nSalary: %f\n\n",emp[index[i].index].emp_id,emp[index[i].index].name,emp[index[i].index].age,emp[index[i].index].salary);
            flag = 1; //employee found
            break;
        }
    }
    if(flag==0)
        printf("Employee Not Found\n");
}

//Main function
int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d",&n);
    struct employee emp[n];
    struct index_node index[n];

    //Taking input employee data
    for(int i=0;i<n;i++) {
        printf("\nEnter employee %d details: \n",i+1);
        printf("Enter employee id: ");
        scanf("%d",&emp[i].emp_id);
        printf("Enter employee name: ");
        scanf("%s",emp[i].name);
        printf("Enter employee age: ");
        scanf("%d",&emp[i].age);
        printf("Enter employee salary: ");
        scanf("%f",&emp[i].salary);
    }

    //Creating index
    create_index(emp,n,index);

    //Searching by employee id
    search_employee_by_id(emp,n,index);

    return 0;
}