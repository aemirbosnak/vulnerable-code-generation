//Falcon-180B DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

void *my_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr!= NULL) {
        free(ptr);
    }
}

void my_realloc(void *ptr, size_t size) {
    if (ptr!= NULL) {
        void *new_ptr = realloc(ptr, size);
        if (new_ptr == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }
        ptr = new_ptr;
    }
}

void my_calloc(void *ptr, size_t size) {
    if (size == 0) {
        return;
    }
    if (ptr!= NULL) {
        memset(ptr, 0, size);
    }
}

Employee *create_employee(char *name, int age, float salary) {
    Employee *emp = (Employee *) my_malloc(sizeof(Employee));
    emp->name = (char *) my_malloc(strlen(name) + 1);
    strcpy(emp->name, name);
    emp->age = age;
    emp->salary = salary;
    return emp;
}

void delete_employee(Employee *emp) {
    if (emp!= NULL) {
        if (emp->name!= NULL) {
            my_free(emp->name);
        }
        my_free(emp);
    }
}

int main() {
    Employee *emp1 = create_employee("John", 25, 5000.00);
    Employee *emp2 = create_employee("Jane", 30, 6000.00);
    Employee *emp3 = create_employee("Bob", 20, 4000.00);

    printf("Employee 1: %s, Age: %d, Salary: $%.2f\n", emp1->name, emp1->age, emp1->salary);
    printf("Employee 2: %s, Age: %d, Salary: $%.2f\n", emp2->name, emp2->age, emp2->salary);
    printf("Employee 3: %s, Age: %d, Salary: $%.2f\n", emp3->name, emp3->age, emp3->salary);

    delete_employee(emp1);
    delete_employee(emp2);
    delete_employee(emp3);

    return 0;
}