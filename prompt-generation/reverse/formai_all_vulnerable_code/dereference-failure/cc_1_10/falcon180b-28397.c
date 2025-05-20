//Falcon-180B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void *my_calloc(size_t count, size_t size) {
    void *ptr = calloc(count, size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void *my_realloc(void *ptr, size_t size) {
    void *new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return new_ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

int main() {
    Employee *employee = (Employee *)my_malloc(sizeof(Employee));
    employee->name = (char *)my_malloc(MAX_SIZE);
    strcpy(employee->name, "John Doe");
    employee->age = 30;
    employee->salary = 50000.50;

    printf("Name: %s\n", employee->name);
    printf("Age: %d\n", employee->age);
    printf("Salary: %.2f\n", employee->salary);

    my_free(employee->name);
    my_free(employee);

    return 0;
}