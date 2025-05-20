//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum number of elements that can be stored in the array
#define MAX_SIZE 1000

// Define the structure of each element in the array
typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

// Function to compare two elements based on their age
int compare(const void *a, const void *b) {
    Employee *emp1 = (Employee *)a;
    Employee *emp2 = (Employee *)b;

    if(emp1->age < emp2->age)
        return -1;
    else if(emp1->age > emp2->age)
        return 1;
    else
        return 0;
}

// Function to search for an employee in the array
void search(Employee arr[], int size, char name[]) {
    Employee *result;
    int (*comparator)(const void *, const void *) = compare;

    // Perform the search using the qsort function
    result = bsearch(name, arr, size, sizeof(Employee), comparator);

    // Check if the search was successful
    if(result!= NULL) {
        printf("Employee found:\n");
        printf("Name: %s\n", result->name);
        printf("Age: %d\n", result->age);
        printf("Salary: $%.2f\n", result->salary);
    } else {
        printf("Employee not found.\n");
    }
}

// Function to read the employee data from a text file
void read_data(Employee arr[], int size, FILE *fp) {
    int i = 0;

    // Read each line from the file
    while(fscanf(fp, "%s %d %.2f", arr[i].name, &arr[i].age, &arr[i].salary)!= EOF) {
        i++;
    }
}

// Function to write the employee data to a text file
void write_data(Employee arr[], int size, FILE *fp) {
    int i;

    // Write each element to the file
    for(i=0; i<size; i++) {
        fprintf(fp, "%s %d %.2f\n", arr[i].name, arr[i].age, arr[i].salary);
    }
}

// Main function
int main() {
    Employee arr[MAX_SIZE];
    int size;
    char filename[50];

    // Read the employee data from the file
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    } else {
        size = 0;
        while(fscanf(fp, "%s %d %.2f", arr[size].name, &arr[size].age, &arr[size].salary)!= EOF) {
            size++;
        }
        fclose(fp);
    }

    // Sort the array based on age
    qsort(arr, size, sizeof(Employee), compare);

    // Prompt the user for the name of the employee to search for
    char search_name[50];
    printf("Enter the name of the employee to search for: ");
    scanf("%s", search_name);

    // Perform the search
    search(arr, size, search_name);

    // Write the sorted data to the output file
    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");

    if(fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    } else {
        write_data(arr, size, fp);
        fclose(fp);
    }

    return 0;
}