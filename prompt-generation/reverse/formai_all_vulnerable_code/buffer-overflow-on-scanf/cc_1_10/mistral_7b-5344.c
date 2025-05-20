//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 100

typedef struct {
    char name[20];
    int age;
} Person;

void print_menu() {
    printf("\n============== MENU ==============\n");
    printf("1. Input data\n");
    printf("2. Sort data\n");
    printf("3. Display data\n");
    printf("4. Exit\n");
    printf("============== MENU ==============\n");
}

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_data(Person data[]) {
    for (int i = 0; i < MAX; i++) {
        strcpy(data[i].name, "Person");
        data[i].age = random_number(1, 100);
    }
}

int compare(const void *a, const void *b) {
    Person *x = (Person *)a;
    Person *y = (Person *)b;
    if (x->age > y->age)
        return 1;
    else if (x->age < y->age)
        return -1;
    return strcmp(x->name, y->name);
}

void sort_data(Person data[]) {
    qsort(data, MAX, sizeof(Person), compare);
}

void display_data(Person data[]) {
    printf("\n============== DATA ==============\n");
    for (int i = 0; i < MAX; i++) {
        printf("%s (%d)\n", data[i].name, data[i].age);
    }
    printf("============== DATA ==============\n");
}

int main() {
    srand(time(NULL));
    Person data[MAX];

    print_menu();
    int choice = 0;

    while (choice != 4) {
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            generate_data(data);
            break;
        case 2:
            sort_data(data);
            break;
        case 3:
            display_data(data);
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
            print_menu();
        }
    }

    return 0;
}