//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int age;
} Person;

void read_data(Person* people, int size) {
    FILE* file;
    char line[100];
    int i = 0;

    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (i >= size) {
            printf("Error: Reached maximum capacity.\n");
            exit(1);
        }

        strcpy(people[i].name, strtok(line, ","));
        people[i].age = atoi(strtok(NULL, ","));
        i++;
    }

    fclose(file);
}

void display_data(Person* people, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }
}

void search_data(Person* people, int size, char* name) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("%s is %d years old.\n", people[i].name, people[i].age);
        }
    }
}

int main() {
    Person people[MAX_SIZE];
    int size;

    printf("Enter the number of people: ");
    scanf("%d", &size);

    read_data(people, size);
    display_data(people, size);

    printf("\nEnter a name to search for: ");
    scanf("%s", people[0].name);

    search_data(people, size, people[0].name);

    return 0;
}