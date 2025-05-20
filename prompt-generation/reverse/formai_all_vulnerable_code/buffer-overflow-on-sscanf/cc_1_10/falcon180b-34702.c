//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
#define SEARCH_SUCCESS 0
#define SEARCH_FAILURE 1
#define SEARCH_DUPLICATE 2

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

void readFile(FILE *file, Person *people, int *size) {
    Person person;
    char line[MAX_SIZE];
    int count = 0;

    while (fgets(line, MAX_SIZE, file)!= NULL) {
        sscanf(line, "%s %d", person.name, &person.age);
        strcpy(people[count].name, person.name);
        people[count].age = person.age;
        count++;
    }

    *size = count;
}

int binarySearch(Person *people, int size, char *name) {
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (strcmp(people[mid].name, name) == 0) {
            return SEARCH_SUCCESS;
        } else if (strcmp(people[mid].name, name) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return SEARCH_FAILURE;
}

int linearSearch(Person *people, int size, char *name) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(people[i].name, name) == 0) {
            return SEARCH_SUCCESS;
        }
    }

    return SEARCH_FAILURE;
}

int main() {
    FILE *file;
    Person people[MAX_SIZE];
    int size;

    file = fopen("people.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    readFile(file, people, &size);

    fclose(file);

    char name[MAX_SIZE];

    printf("Enter a name to search for: ");
    scanf("%s", name);

    int result = binarySearch(people, size, name);

    if (result == SEARCH_SUCCESS) {
        printf("Found %s!\n", name);
    } else if (result == SEARCH_FAILURE) {
        printf("Could not find %s.\n", name);
    } else {
        printf("Multiple people with name %s found.\n", name);
    }

    return 0;
}