//FormAI DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Record {
    char name[MAX_SIZE];
    int age;
    float salary;
};

int main() {
    struct Record database[MAX_SIZE];

    int option;
    int num_records = 0;

    while (1) {
        printf("\n1. Add Record\n2. Display Records\n3. Search Records by Name\n4. Search Records by Age\n5. Search Records by Salary\n6. Exit\nEnter Option (1-6) > ");
        scanf("%d", &option);

        if (option == 1) {
            printf("\nEnter Name > ");
            scanf(" %[^\n]s", database[num_records].name);
            printf("Enter Age > ");
            scanf("%d", &database[num_records].age);
            printf("Enter Salary > ");
            scanf("%f", &database[num_records].salary);
            num_records++;
        } else if (option == 2) {
            printf("\nName\tAge\tSalary\n");
            for (int i = 0; i < num_records; i++) {
                printf("%s\t%d\t%.2f\n", database[i].name, database[i].age, database[i].salary);
            }
        } else if (option == 3) {
            char name[MAX_SIZE];
            printf("\nEnter Name to Search > ");
            scanf(" %[^\n]s", name);

            int found = 0;
            for (int i = 0; i < num_records; i++) {
                if (strcmp(database[i].name, name) == 0) {
                    printf("\nName\tAge\tSalary\n");
                    printf("%s\t%d\t%.2f\n", database[i].name, database[i].age, database[i].salary);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nRecord not found.\n");
            }
        } else if (option == 4) {
            int age;
            printf("\nEnter Age to Search > ");
            scanf("%d", &age);

            int found = 0;
            for (int i = 0; i < num_records; i++) {
                if (database[i].age == age) {
                    printf("\nName\tAge\tSalary\n");
                    printf("%s\t%d\t%.2f\n", database[i].name, database[i].age, database[i].salary);
                    found = 1;
                }
            }

            if (!found) {
                printf("\nRecord not found.\n");
            }
        } else if (option == 5) {
            float salary;
            printf("\nEnter Salary to Search > ");
            scanf("%f", &salary);

            int found = 0;
            for (int i = 0; i < num_records; i++) {
                if (database[i].salary == salary) {
                    printf("\nName\tAge\tSalary\n");
                    printf("%s\t%d\t%.2f\n", database[i].name, database[i].age, database[i].salary);
                    found = 1;
                }
            }

            if (!found) {
                printf("\nRecord not found.\n");
            }
        } else if (option == 6) {
            printf("\nExiting...\n");
            break;
        } else {
            printf("\nInvalid option.\n");
        }
    }

    return 0;
}