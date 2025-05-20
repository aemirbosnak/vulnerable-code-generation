//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA 1000
#define MAX_INPUT 50

typedef struct {
    int id;
    char name[MAX_INPUT];
    float age;
    float salary;
} Record;

typedef struct {
    Record data[MAX_DATA];
    int size;
} Database;

void load_data(Database *db, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%d %s %f %f", &db->data[db->size].id, db->data[db->size].name, &db->data[db->size].age, &db->data[db->size].salary) != EOF) {
        db->size++;
    }
    fclose(file);
}

void print_data(const Database *db) {
    printf("ID\tName\t\tAge\tSalary\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < db->size; i++) {
        printf("%d\t%-10s\t%.2f\t%.2f\n", db->data[i].id, db->data[i].name, db->data[i].age, db->data[i].salary);
    }
}

float calculate_average_salary(const Database *db) {
    float total = 0;
    for (int i = 0; i < db->size; i++) {
        total += db->data[i].salary;
    }
    return total / db->size;
}

void find_above_average(const Database *db, float avg) {
    printf("\nRecords with salary above average (%.2f):\n", avg);
    for (int i = 0; i < db->size; i++) {
        if (db->data[i].salary > avg) {
            printf("%d\t%-10s\t%.2f\t%.2f\n", db->data[i].id, db->data[i].name, db->data[i].age, db->data[i].salary);
        }
    }
}

void sort_records_by_salary(Database *db) {
    for (int i = 0; i < db->size - 1; i++) {
        for (int j = i + 1; j < db->size; j++) {
            if (db->data[i].salary > db->data[j].salary) {
                Record temp = db->data[i];
                db->data[i] = db->data[j];
                db->data[j] = temp;
            }
        }
    }
}

void save_report(const Database *db, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "ID\tName\t\tAge\tSalary\n");
    fprintf(file, "---------------------------------------\n");
    for (int i = 0; i < db->size; i++) {
        fprintf(file, "%d\t%-10s\t%.2f\t%.2f\n", db->data[i].id, db->data[i].name, db->data[i].age, db->data[i].salary);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    Database db;
    db.size = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_report>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_data(&db, argv[1]);
    print_data(&db);

    float avg_salary = calculate_average_salary(&db);
    printf("\nAverage Salary: %.2f\n", avg_salary);

    find_above_average(&db, avg_salary);
    
    sort_records_by_salary(&db);
    printf("\nSorted records by salary:\n");
    print_data(&db);

    save_report(&db, argv[2]);
    printf("\nReport saved to %s\n", argv[2]);

    return EXIT_SUCCESS;
}