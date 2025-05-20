//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    float salary;
} record_t;

record_t *create_record(char *name, int age, float salary) {
    record_t *rec = (record_t *)malloc(sizeof(record_t));
    rec->name = strdup(name);
    rec->age = age;
    rec->salary = salary;
    return rec;
}

void print_record(record_t *rec) {
    printf("Name: %s, Age: %d, Salary: %.2f\n", rec->name, rec->age, rec->salary);
}

int main() {
    record_t *records[MAX_ROWS];
    int num_rows = 0;
    int choice;

    do {
        printf("1. Add record\n");
        printf("2. Print records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_rows >= MAX_ROWS) {
                    printf("Maximum number of records reached.\n");
                } else {
                    char name[50];
                    int age;
                    float salary;
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter age: ");
                    scanf("%d", &age);
                    printf("Enter salary: ");
                    scanf("%f", &salary);
                    records[num_rows] = create_record(name, age, salary);
                    num_rows++;
                }
                break;

            case 2:
                for(int i=0; i<num_rows; i++) {
                    print_record(records[i]);
                }
                break;

            case 3:
                for(int i=0; i<num_rows; i++) {
                    free(records[i]->name);
                    free(records[i]);
                }
                exit(0);

            default:
                printf("Invalid choice.\n");
        }

    } while(1);

    return 0;
}