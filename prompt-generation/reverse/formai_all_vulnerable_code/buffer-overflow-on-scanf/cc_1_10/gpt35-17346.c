//FormAI DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Open the file in write mode
    FILE *file = fopen("employee.txt", "w");

    // Check if file was properly opened
    if (file == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    // Get information about employee from user
    char name[30];
    int age;
    float salary;

    printf("Enter employee name: ");
    scanf("%[^\n]%*c", name); // %[^\n]%*c is used to read spaces in string
    printf("Enter employee age: ");
    scanf("%d", &age);
    printf("Enter employee salary: ");
    scanf("%f", &salary);

    // Write information to file
    fprintf(file, "Name: %s\n", name);
    fprintf(file, "Age: %d\n", age);
    fprintf(file, "Salary: %.2f\n", salary);

    // Close the file
    fclose(file);

    // Open the file in read mode
    file = fopen("employee.txt", "r");

    // Check if file was properly opened
    if (file == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    // Read information from file
    char line[100];
    printf("\nEmployee Information:\n");
    while (fgets(line, sizeof(line), file) != NULL) { // Read line by line
        printf("%s", line);
    }

    // Close the file
    fclose(file);

    return 0;
}