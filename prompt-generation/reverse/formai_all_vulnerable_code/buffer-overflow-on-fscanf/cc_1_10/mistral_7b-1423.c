//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Person {
    char name[50];
    int age;
} Person;

bool is_palindrome(const char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start++] != str[end--]) {
            return false;
        }
    }

    return true;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open input file\n");
        return 1;
    }

    Person *people = NULL;
    int num_people = 0;

    while (fscanf(file, "%[^,],%d\n", people[num_people].name, &people[num_people].age) != EOF) {
        people = realloc(people, sizeof(Person) * (num_people + 1));
        num_people++;
    }

    fclose(file);

    for (int i = 0; i < num_people; i++) {
        if (is_palindrome(people[i].name)) {
            printf("%s (%d years old)\n", people[i].name, people[i].age);
        }
    }

    free(people);

    return 0;
}