//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} person;

person data[MAX_SIZE];
int size = 0;

void add_person() {
    printf("Enter name: ");
    scanf("%s", data[size].name);
    printf("Enter age: ");
    scanf("%d", &data[size].age);
    size++;
}

void display_data() {
    printf("Name\tAge\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\n", data[i].name, data[i].age);
    }
}

void search_data(char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(data[i].name, name) == 0) {
            printf("Name: %s\nAge: %d\n", data[i].name, data[i].age);
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add person\n2. Display data\n3. Search data\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_person();
                break;
            case 2:
                display_data();
                break;
            case 3:
                printf("Enter name to search: ");
                char name[MAX_SIZE];
                scanf("%s", name);
                search_data(name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}