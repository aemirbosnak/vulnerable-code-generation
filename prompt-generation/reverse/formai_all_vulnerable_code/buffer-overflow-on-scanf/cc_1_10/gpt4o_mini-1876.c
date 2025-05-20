//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_CITY_LENGTH 50
#define AGE_RANGE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char city[MAX_CITY_LENGTH];
} Person;

void generateRandomData(Person people[], int count);
void filterByAge(const Person people[], int count, int min_age, int max_age);
void filterByCity(const Person people[], int count, const char *city);
void sortByAge(Person people[], int count);
void printPeople(const Person people[], int count);
void displayStatistics(const Person people[], int count);

int main() {
    srand(time(0));
    
    Person people[MAX_RECORDS];
    int numberOfPeople;

    printf("Enter the number of people to generate (max %d): ", MAX_RECORDS);
    scanf("%d", &numberOfPeople);
    
    if (numberOfPeople > MAX_RECORDS) {
        printf("Cannot generate more than %d records.\n", MAX_RECORDS);
        return 1;
    }

    generateRandomData(people, numberOfPeople);
    printf("\nGenerated People Data:\n");
    printPeople(people, numberOfPeople);
    
    printf("\nStatistics:\n");
    displayStatistics(people, numberOfPeople);

    int minAge, maxAge;
    printf("\nFilter by age range:\nEnter minimum age: ");
    scanf("%d", &minAge);
    printf("Enter maximum age: ");
    scanf("%d", &maxAge);
    filterByAge(people, numberOfPeople, minAge, maxAge);

    char city[MAX_CITY_LENGTH];
    printf("\nFilter by city:\nEnter city name: ");
    scanf("%s", city);
    filterByCity(people, numberOfPeople, city);

    printf("\nSorting data by age...\n");
    sortByAge(people, numberOfPeople);
    printf("People sorted by age:\n");
    printPeople(people, numberOfPeople);

    return 0;
}

void generateRandomData(Person people[], int count) {
    const char *names[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack"};
    const char *cities[] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix"};

    for (int i = 0; i < count; i++) {
        int nameIndex = rand() % (sizeof(names) / sizeof(names[0]));
        int cityIndex = rand() % (sizeof(cities) / sizeof(cities[0]));

        strcpy(people[i].name, names[nameIndex]);
        people[i].age = rand() % AGE_RANGE;
        strcpy(people[i].city, cities[cityIndex]);
    }
}

void filterByAge(const Person people[], int count, int min_age, int max_age) {
    printf("People aged between %d and %d:\n", min_age, max_age);
    for (int i = 0; i < count; i++) {
        if (people[i].age >= min_age && people[i].age <= max_age) {
            printf("Name: %s, Age: %d, City: %s\n", people[i].name, people[i].age, people[i].city);
        }
    }
}

void filterByCity(const Person people[], int count, const char *city) {
    printf("People living in %s:\n", city);
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].city, city) == 0) {
            printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
        }
    }
}

void sortByAge(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (people[j].age > people[j + 1].age) {
                // Swap
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

void printPeople(const Person people[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, City: %s\n", people[i].name, people[i].age, people[i].city);
    }
}

void displayStatistics(const Person people[], int count) {
    int minAge = people[0].age;
    int maxAge = people[0].age;
    double totalAge = 0.0;

    for (int i = 0; i < count; i++) {
        if (people[i].age < minAge) minAge = people[i].age;
        if (people[i].age > maxAge) maxAge = people[i].age;
        totalAge += people[i].age;
    }
    
    double averageAge = totalAge / count;
    printf("Min Age: %d, Max Age: %d, Average Age: %.2f\n", minAge, maxAge, averageAge);
}