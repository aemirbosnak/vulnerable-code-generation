//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} person;

void create_person(person *p) {
    p->name = malloc(100 * sizeof(char));
    printf("Enter name: ");
    scanf("%s", p->name);

    printf("Enter age: ");
    scanf("%d", &p->age);
}

void print_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

void delete_person(person *p) {
    free(p->name);
    free(p);
}

void read_file(char *filename, void (*process_line)(void *data, char *line)) {
    FILE *file;
    char line[1000];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        process_line(NULL, line);
    }

    fclose(file);
}

void process_line(void *data, char *line) {
    person *p = data;
    char delimiter = ',';
    char *token = strtok(line, &delimiter);

    while (token!= NULL) {
        if (strcmp(token, "name") == 0) {
            token = strtok(NULL, &delimiter);
            strcpy(p->name, token);
        } else if (strcmp(token, "age") == 0) {
            token = strtok(NULL, &delimiter);
            p->age = atoi(token);
        }

        token = strtok(NULL, &delimiter);
    }
}

int main() {
    person p;
    create_person(&p);

    char filename[] = "data.txt";
    read_file(filename, process_line);

    print_person(p);

    delete_person(&p);

    return 0;
}