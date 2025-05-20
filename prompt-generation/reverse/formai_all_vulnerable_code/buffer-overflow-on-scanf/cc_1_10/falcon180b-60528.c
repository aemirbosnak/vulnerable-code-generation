//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} person;

person *create_person(char *name, int age) {
    person *p = (person *) malloc(sizeof(person));
    if (p == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    p->name = (char *) malloc(strlen(name) + 1);
    if (p->name == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(p->name, name);
    p->age = age;
    return p;
}

void delete_person(person *p) {
    free(p->name);
    free(p);
}

void print_person(person *p) {
    printf("%s %d\n", p->name, p->age);
}

int compare_age(const void *a, const void *b) {
    person *p1 = *(person **) a;
    person *p2 = *(person **) b;
    return p1->age - p2->age;
}

int main() {
    int n;
    scanf("%d", &n);
    person **arr = (person **) malloc(n * sizeof(person *));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        char name[100];
        scanf("%s", name);
        int age;
        scanf("%d", &age);
        person *p = create_person(name, age);
        arr[i] = p;
    }
    qsort(arr, n, sizeof(person *), compare_age);
    for (int i = 0; i < n; i++) {
        print_person(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        delete_person(arr[i]);
    }
    free(arr);
    return 0;
}