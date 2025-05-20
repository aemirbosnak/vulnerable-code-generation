//FormAI DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 26

typedef struct {
    char name[20];
    int age;
    float salary;
} Person;

Person database[MAX_ROWS];
int current_row = 0;

int column_index(char col) {
    return toupper(col) - 'A';
}

int add_person(char *name, int age, float salary) {
    if (current_row >= MAX_ROWS) {
        return -1;
    }

    Person p;
    strcpy(p.name, name);
    p.age = age;
    p.salary = salary;
    database[current_row++] = p;

    return 0;
}

int find_person(char *name) {
    for (int i = 0; i < current_row; i++) {
        if (strcmp(database[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void print_person(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Salary: %.2f\n", p.salary);
}

int main() {
    int command;
    char line[100];

    while (1) {
        printf("Enter command: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &command);

        switch (command) {
            case 1: {
                char name[20];
                int age;
                float salary;

                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Enter age: ");
                fgets(line, sizeof(line), stdin);
                sscanf(line, "%d", &age);

                printf("Enter salary: ");
                fgets(line, sizeof(line), stdin);
                sscanf(line, "%f", &salary);

                if (add_person(name, age, salary) == 0) {
                    printf("Person added successfully.\n");
                } else {
                    printf("Too many people in database.\n");
                }

                break;
            }

            case 2: {
                char name[20];

                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                int index = find_person(name);

                if (index == -1) {
                    printf("Person not found.\n");
                } else {
                    print_person(database[index]);
                }

                break;
            }

            case 3: {
                char col;
                int row;

                printf("Enter column: ");
                fgets(line, sizeof(line), stdin);
                sscanf(line, "%c", &col);

                printf("Enter row: ");
                fgets(line, sizeof(line), stdin);
                sscanf(line, "%d", &row);

                int col_index = column_index(col);

                if (col_index >= MAX_COLS || row >= current_row) {
                    printf("Invalid cell.\n");
                } else {
                    switch (col) {
                        case 'A': printf("%s\n", database[row].name); break;
                        case 'B': printf("%d\n", database[row].age); break;
                        case 'C': printf("%.2f\n", database[row].salary); break;
                    }
                }

                break;
            }

            case 4: {
                for (int i = 0; i < current_row; i++) {
                    print_person(database[i]);
                    printf("\n");
                }

                break;
            }

            case 5: {
                printf("Goodbye!\n");
                exit(0);
            }

            default: {
                printf("Invalid command.\n");
                break;
            }
        }
    }

    return 0;
}