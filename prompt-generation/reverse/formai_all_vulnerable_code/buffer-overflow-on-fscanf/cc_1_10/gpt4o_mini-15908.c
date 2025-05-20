//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LINE_LENGTH 256
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float salary;
} Record;

void read_data(const char *filename, Record records[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    
    *count = 0;
    while (*count < MAX_RECORDS && fgets(records[*count].name, NAME_LENGTH, file)) {
        strtok(records[*count].name, "\n"); // Remove newline character
        fscanf(file, "%d %f\n", &records[*count].age, &records[*count].salary);
        (*count)++;
    }
    
    fclose(file);
}

void display_data(Record records[], int count) {
    printf("%-20s %-5s %-10s\n", "Name", "Age", "Salary");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-5d %-10.2f\n", records[i].name, records[i].age, records[i].salary);
    }
}

void sort_data(Record records[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (records[i].salary < records[j].salary) {
                Record temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }
}

void filter_data(Record records[], int count, int min_age) {
    printf("\nFiltered data (age >= %d):\n", min_age);
    printf("%-20s %-5s %-10s\n", "Name", "Age", "Salary");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (records[i].age >= min_age) {
            printf("%-20s %-5d %-10.2f\n", records[i].name, records[i].age, records[i].salary);
        }
    }
}

void calculate_average_salary(Record records[], int count) {
    float total_salary = 0;
    for (int i = 0; i < count; i++) {
        total_salary += records[i].salary;
    }
    printf("\nAverage Salary: %.2f\n", total_salary / count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Record records[MAX_RECORDS];
    int count = 0;

    read_data(argv[1], records, &count);
    display_data(records, count);

    sort_data(records, count);
    printf("\nSorted by Salary:\n");
    display_data(records, count);

    int min_age;
    printf("Enter minimum age for filtering: ");
    scanf("%d", &min_age);
    filter_data(records, count, min_age);

    calculate_average_salary(records, count);

    return EXIT_SUCCESS;
}