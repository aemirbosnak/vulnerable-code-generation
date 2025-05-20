//Falcon-180B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

int main() {
    FILE *file;
    Employee emp[100];
    int count = 0;
    char choice;

    file = fopen("employee.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(file, "%s %d %f", emp[count].name, &emp[count].age, &emp[count].salary)!= EOF) {
        count++;
    }

    fclose(file);

    do {
        system("clear");
        printf("\nEmployee Details\n");
        printf("-----------------\n");
        for (int i = 0; i < count; i++) {
            printf("%d. Name: %s\n", i + 1, emp[i].name);
            printf("Age: %d\n", emp[i].age);
            printf("Salary: %.2f\n\n", emp[i].salary);
        }

        printf("Press any key to continue...\n");
        scanf(" %c", &choice);
        fflush(stdin);
    } while (choice!= 'q');

    file = fopen("employee.txt", "a");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("\nEnter employee details:\n");
    printf("Name: ");
    scanf("%s", emp[count].name);
    printf("Age: ");
    scanf("%d", &emp[count].age);
    printf("Salary: ");
    scanf("%f", &emp[count].salary);

    fprintf(file, "%s %d %.2f\n", emp[count].name, emp[count].age, emp[count].salary);

    fclose(file);

    printf("\nData saved successfully!\n");

    return 0;
}