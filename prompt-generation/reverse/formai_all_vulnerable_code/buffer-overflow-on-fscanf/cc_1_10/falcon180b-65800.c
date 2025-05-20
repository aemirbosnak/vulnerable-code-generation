//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person p1 = *(Person *)a;
    Person p2 = *(Person *)b;
    if (p1.age < p2.age) {
        return -1;
    } else if (p1.age > p2.age) {
        return 1;
    } else {
        return 0;
    }
}

int search(Person *people, int n, char *name) {
    qsort(people, n, sizeof(Person), compare);
    for (int i = 0; i < n; i++) {
        if (strcmp(people[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Person people[MAX_SIZE];
    int n = 0;

    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(file, "%s %d\n", people[n].name, &people[n].age)!= EOF) {
        n++;
        if (n >= MAX_SIZE) {
            printf("Maximum size exceeded\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    char name[MAX_SIZE];
    printf("Enter name to search: ");
    scanf("%s", name);

    int index = search(people, n, name);
    if (index == -1) {
        printf("Name not found\n");
    } else {
        printf("Name found at index %d\n", index);
        printf("Age: %d\n", people[index].age);
    }

    return 0;
}