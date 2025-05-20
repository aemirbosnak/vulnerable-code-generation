//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <string.h>

struct csv_row {
    char *first_name;
    char *last_name;
    int age;
    double salary;
};

void print_csv_row(const struct csv_row *row) {
    printf("%s, %s, %d, %.2f\n", row->first_name, row->last_name, row->age, row->salary);
}

int main() {
    FILE *csv_file = fopen("example.csv", "r");
    if (csv_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    struct csv_row csv_row;
    char c;

    while ((c = fgetc(csv_file))!= EOF) {
        if (c == '\n') {
            print_csv_row(&csv_row);
            csv_row.first_name = NULL;
            csv_row.last_name = NULL;
            csv_row.age = 0;
            csv_row.salary = 0.0;
        }
        else if (c == ',') {
            csv_row.first_name = NULL;
            csv_row.last_name = NULL;
            csv_row.age = 0;
            csv_row.salary = 0.0;
        }
        else if (c == '\"') {
            if (csv_row.first_name == NULL) {
                csv_row.first_name = malloc(strlen(c) + 1);
                if (csv_row.first_name == NULL) {
                    fprintf(stderr, "Error allocating memory for first name\n");
                    return 1;
                }
                memcpy(csv_row.first_name, c, strlen(c));
                csv_row.first_name[strlen(c)] = '\0';
            }
            else if (csv_row.last_name == NULL) {
                csv_row.last_name = malloc(strlen(c) + 1);
                if (csv_row.last_name == NULL) {
                    fprintf(stderr, "Error allocating memory for last name\n");
                    return 1;
                }
                memcpy(csv_row.last_name, c, strlen(c));
                csv_row.last_name[strlen(c)] = '\0';
            }
            else if (csv_row.age == 0) {
                csv_row.age = atoi(c);
            }
            else if (csv_row.salary == 0.0) {
                csv_row.salary = atof(c);
            }
        }
        else {
            if (csv_row.first_name!= NULL) {
                csv_row.first_name = strcat(csv_row.first_name, c);
            }
            else if (csv_row.last_name!= NULL) {
                csv_row.last_name = strcat(csv_row.last_name, c);
            }
            else if (csv_row.age!= 0) {
                csv_row.age = csv_row.age * 10 + atoi(c);
            }
            else if (csv_row.salary!= 0.0) {
                csv_row.salary = csv_row.salary * 100 + atof(c);
            }
        }
    }

    fclose(csv_file);
    return 0;
}