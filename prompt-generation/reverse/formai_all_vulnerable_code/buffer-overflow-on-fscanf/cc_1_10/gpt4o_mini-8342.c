//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char city[MAX_NAME_LENGTH];
} Person;

void readDataFromFile(const char *filename, Person *people, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (*count < MAX_RECORDS && fgets(people[*count].name, sizeof(people[*count].name), file)) {
        // Remove newline character
        size_t len = strlen(people[*count].name);
        if (len > 0 && people[*count].name[len - 1] == '\n') {
            people[*count].name[len - 1] = '\0';
        }
        fscanf(file, "%d\n", &people[*count].age);
        fgets(people[*count].city, sizeof(people[*count].city), file);
        len = strlen(people[*count].city);
        if (len > 0 && people[*count].city[len - 1] == '\n') {
            people[*count].city[len - 1] = '\0';
        }
        (*count)++;
    }
    fclose(file);
}

void printData(const Person *people, int count) {
    printf("\nList of People:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, City: %s\n", people[i].name, people[i].age, people[i].city);
    }
    printf("\n");
}

void findAverageAge(const Person *people, int count) {
    if (count == 0) {
        printf("No data available to calculate average age.\n");
        return;
    }
    
    int totalAge = 0;
    for (int i = 0; i < count; i++) {
        totalAge += people[i].age;
    }
    printf("Average Age: %.2f\n", (float)totalAge / count);
}

void findMostCommonCity(const Person *people, int count) {
    if (count == 0) {
        printf("No data available to find the most common city.\n");
        return;
    }
    
    char cities[MAX_RECORDS][MAX_NAME_LENGTH];
    int frequency[MAX_RECORDS] = {0};
    int uniqueCount = 0;

    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(cities[j], people[i].city) == 0) {
                frequency[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(cities[uniqueCount], people[i].city);
            frequency[uniqueCount]++;
            uniqueCount++;
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < uniqueCount; i++) {
        if (frequency[i] > frequency[maxIndex]) {
            maxIndex = i;
        }
    }

    printf("Most Common City: %s (Appears %d times)\n", cities[maxIndex], frequency[maxIndex]);
}

int main() {
    Person people[MAX_RECORDS];
    int count = 0;

    readDataFromFile("data.txt", people, &count);
    printData(people, count);
    findAverageAge(people, count);
    findMostCommonCity(people, count);

    return 0;
}