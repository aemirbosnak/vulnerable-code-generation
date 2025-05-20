//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_STRING_LENGTH 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
    char city[MAX_STRING_LENGTH];
    float salary;
} Person;

void loadData(Person *people, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%[^,],%d,%[^,],%f\n", people[*count].name, &people[*count].age, people[*count].city, &people[*count].salary) == 4) {
        (*count)++;
        if (*count >= MAX_RECORDS) {
            break;
        }
    }

    fclose(file);
}

void printPersonData(const Person *people, int count) {
    printf("Name\t\tAge\tCity\t\tSalary\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %d\t%-15s %.2f\n", people[i].name, people[i].age, people[i].city, people[i].salary);
    }
}

void filterByAge(const Person *people, int count, int ageThreshold) {
    printf("People older than %d:\n", ageThreshold);
    printf("Name\t\tAge\tCity\t\tSalary\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (people[i].age > ageThreshold) {
            printf("%-15s %d\t%-15s %.2f\n", people[i].name, people[i].age, people[i].city, people[i].salary);
        }
    }
}

void getAverageSalaryByCity(const Person *people, int count) {
    float salarySum[MAX_RECORDS] = {0};
    int cityCounts[MAX_RECORDS] = {0};
    char cities[MAX_RECORDS][MAX_STRING_LENGTH];
    int cityIndex = 0;

    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < cityIndex; j++) {
            if (strcmp(cities[j], people[i].city) == 0) {
                salarySum[j] += people[i].salary;
                cityCounts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(cities[cityIndex], people[i].city);
            salarySum[cityIndex] = people[i].salary;
            cityCounts[cityIndex] = 1;
            cityIndex++;
        }
    }

    printf("Average Salary by City:\n");
    printf("City\t\tAverage Salary\n");
    printf("----------------------------------\n");
    for (int i = 0; i < cityIndex; i++) {
        printf("%-15s %.2f\n", cities[i], salarySum[i] / cityCounts[i]);
    }
}

void saveFilteredData(const Person *people, int count, const char *filename, int ageThreshold) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        if (people[i].age > ageThreshold) {
            fprintf(file, "%s,%d,%s,%.2f\n", people[i].name, people[i].age, people[i].city, people[i].salary);
        }
    }

    fclose(file);
}

int main() {
    Person people[MAX_RECORDS];
    int count = 0;

    loadData(people, &count, "data.txt");

    printPersonData(people, count);
    filterByAge(people, count, 30);
    getAverageSalaryByCity(people, count);
    saveFilteredData(people, count, "filtered_data.txt", 30);

    return 0;
}