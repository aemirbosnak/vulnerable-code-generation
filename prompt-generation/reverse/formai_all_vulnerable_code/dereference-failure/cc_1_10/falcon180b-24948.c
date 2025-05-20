//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *name;
    int id;
} Person;

Person *search(Person *list, int size, char *name) {
    Person *result = NULL;
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            result = &list[i];
            break;
        }
    }

    return result;
}

int main() {
    Person *list = NULL;
    int size = 0;
    char *name;
    int id;
    FILE *file;

    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %d", name, &id)!= EOF) {
        list = realloc(list, sizeof(Person) * ++size);
        list[size - 1].name = strdup(name);
        list[size - 1].id = id;
    }

    fclose(file);

    char *search_name;
    while (1) {
        printf("Enter name to search: ");
        scanf("%s", search_name);

        Person *result = search(list, size, search_name);

        if (result == NULL) {
            printf("Person not found.\n");
        } else {
            printf("Name: %s\nID: %d\n", result->name, result->id);
        }

        printf("Search again? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'n') {
            break;
        }
    }

    free(list);
    return 0;
}