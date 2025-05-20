//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 500

typedef struct {
    char *name;
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;

    if (p1->age < p2->age)
        return -1;
    else if (p1->age > p2->age)
        return 1;
    else
        return 0;
}

void read_data(FILE *fp, Person *data, int *size) {
    char line[MAX_SIZE];
    char *token;

    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        token = strtok(line, ",");
        data[*size].name = strdup(token);
        token = strtok(NULL, ",");
        data[*size].age = atoi(token);
        (*size)++;
    }
}

void write_data(FILE *fp, Person *data, int size) {
    int i;

    for (i = 0; i < size; i++) {
        fprintf(fp, "%s,%d\n", data[i].name, data[i].age);
    }
}

void sort_data(Person *data, int size) {
    qsort(data, size, sizeof(Person), compare);
}

int binary_search(Person *data, int size, char *name) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (strcmp(data[mid].name, name) == 0)
            return mid;

        if (strcmp(data[mid].name, name) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    FILE *fp;
    Person *data;
    int size;

    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    size = 0;
    read_data(fp, data, &size);
    fclose(fp);

    sort_data(data, size);

    char name[MAX_SIZE];
    printf("Enter a name to search: ");
    scanf("%s", name);

    int index = binary_search(data, size, name);

    if (index == -1)
        printf("Name not found.\n");
    else
        printf("Name: %s, Age: %d\n", data[index].name, data[index].age);

    write_data("sorted_data.txt", data, size);

    return 0;
}