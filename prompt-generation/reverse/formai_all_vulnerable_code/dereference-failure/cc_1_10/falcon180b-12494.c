//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

int compare_by_age(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return (*p1).age - (*p2).age;
}

int compare_by_name(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return strcmp((*p1).name, (*p2).name);
}

int compare_by_gender(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return strcmp((*p1).gender, (*p2).gender);
}

void print_person(void *ptr) {
    Person *p = (Person *)ptr;
    printf("%s %d %s\n", p->name, p->age, p->gender);
}

int main() {
    int n;
    scanf("%d", &n);
    Person *data = (Person *)malloc(n * sizeof(Person));
    for (int i = 0; i < n; i++) {
        data[i].name = (char *)malloc(100 * sizeof(char));
        data[i].gender = (char *)malloc(10 * sizeof(char));
        scanf("%s %d %s", data[i].name, &data[i].age, data[i].gender);
    }
    qsort(data, n, sizeof(Person), compare_by_age);
    for (int i = 0; i < n; i++) {
        print_person(data + i);
    }
    qsort(data, n, sizeof(Person), compare_by_name);
    for (int i = 0; i < n; i++) {
        print_person(data + i);
    }
    qsort(data, n, sizeof(Person), compare_by_gender);
    for (int i = 0; i < n; i++) {
        print_person(data + i);
    }
    return 0;
}