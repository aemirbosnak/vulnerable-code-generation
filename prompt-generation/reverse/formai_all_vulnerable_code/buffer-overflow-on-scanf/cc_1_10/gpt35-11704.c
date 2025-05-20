//FormAI DATASET v1.0 Category: Database Indexing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    int id;
    char name[MAX];
    int age;
    float salary;
} Employee;

typedef struct {
    int id;
    long offset;
} Index;

void readEmployees(FILE *f, Employee employees[], int *count);
void writeEmployees(FILE *f, Employee employees[], int count);
void createIndex(FILE *f, Index index[], int count);
int compare(const void *a, const void *b);
int binarySearch(Index index[], int count, int id);
void printEmployee(Employee e);
void printAllEmployees(Employee employees[], int count);

int main() {
    FILE *f;
    Employee employees[MAX];
    Index index[MAX];
    int count = 0, choice, id, pos;

    while(1) {
        printf("1. Read employees\n");
        printf("2. Write employees\n");
        printf("3. Create index\n");
        printf("4. Search employee by id\n");
        printf("5. Print all employees\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                if(f = fopen("employees.dat", "rb")) {
                    fread(&count, sizeof(count), 1, f);
                    readEmployees(f, employees, &count);
                    fclose(f);
                    printf("%d employees read from file.\n", count);
                } else {
                    printf("Error opening file.\n");
                }
                break;
            case 2:
                if(f = fopen("employees.dat", "wb")) {
                    fwrite(&count, sizeof(count), 1, f);
                    writeEmployees(f, employees, count);
                    fclose(f);
                    printf("%d employees written to file.\n", count);
                } else {
                    printf("Error opening file.\n");
                }
                break;
            case 3:
                createIndex(f, index, count);
                printf("Index created.\n");
                break;
            case 4:
                printf("Enter id to search: ");
                scanf("%d", &id);
                pos = binarySearch(index, count, id);
                if(pos == -1) {
                    printf("Employee with id %d not found.\n", id);
                } else {
                    printEmployee(employees[pos]);
                }
                break;
            case 5:
                printAllEmployees(employees, count);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }
}

void readEmployees(FILE *f, Employee employees[], int *count) {
    fseek(f, sizeof(*count), SEEK_SET);
    for(int i = 0; i < *count; i++) {
        fread(&employees[i], sizeof(Employee), 1, f);
    }
}

void writeEmployees(FILE *f, Employee employees[], int count) {
    fseek(f, sizeof(count), SEEK_SET);
    for(int i = 0; i < count; i++) {
        fwrite(&employees[i], sizeof(Employee), 1, f);
    }
}

void createIndex(FILE *f, Index index[], int count) {
    Employee employees[MAX];
    int i;

    if(f = fopen("employees.dat", "rb")) {
        readEmployees(f, employees, &count);
        fclose(f);
    } else {
        printf("Error opening file.\n");
        return;
    }

    for(i = 0; i < count; i++) {
        index[i].id = employees[i].id;
        index[i].offset = sizeof(int) + sizeof(Employee) * i;
    }

    qsort(index, count, sizeof(Index), compare);
}

int compare(const void *a, const void *b) {
    return ((Index *)a)->id - ((Index *)b)->id;
}

int binarySearch(Index index[], int count, int id) {
    int left = 0, right = count - 1, mid;

    while(left <= right) {
        mid = (left + right) / 2;

        if(index[mid].id == id) {
            FILE *f;
            Employee e;

            if(f = fopen("employees.dat", "rb")) {
                fseek(f, index[mid].offset, SEEK_SET);
                fread(&e, sizeof(Employee), 1, f);
                fclose(f);
                return mid;
            } else {
                printf("Error opening file.\n");
                return -1;
            }
        } else if(index[mid].id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void printEmployee(Employee e) {
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Age: %d\n", e.age);
    printf("Salary: %.2f\n", e.salary);
}

void printAllEmployees(Employee employees[], int count) {
    for(int i = 0; i < count; i++) {
        printEmployee(employees[i]);
        printf("\n");
    }
}