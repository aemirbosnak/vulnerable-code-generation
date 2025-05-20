//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    float salary;
} Employee;

void print_error(const char *msg) {
    perror(msg);
    printf("\n");
}

int main() {
    FILE *file;
    Employee employees[10];
    int count = 0;

    file = fopen("employees.bin", "wb"); // Open the file in write binary mode

    if (file == NULL) {
        print_error("Error opening file for writing.");
        return 1;
    }

    printf("Enter data for up to 10 employees:\n");

    while (count < 10 && fscanf(stdin, "%s %d %f", employees[count].name, &employees[count].id, &employees[count].salary) != EOF) {
        fwrite(&employees[count], sizeof(Employee), 1, file); // Write data to file in binary format
        count++;
    }

    fclose(file); // Close the file

    printf("\nData written to file successfully.\n");

    file = fopen("employees.bin", "rb"); // Open the file in read binary mode

    if (file == NULL) {
        print_error("Error opening file for reading.");
        return 1;
    }

    while (count > 0) {
        fread(&employees[count - 1], sizeof(Employee), 1, file); // Read data from file in binary format

        printf("\nName: %s\nID: %d\nSalary: %.2f\n", employees[count - 1].name, employees[count - 1].id, employees[count - 1].salary);
        count--;
    }

    fclose(file); // Close the file

    printf("\nData read from file successfully.\n");

    return 0;
}