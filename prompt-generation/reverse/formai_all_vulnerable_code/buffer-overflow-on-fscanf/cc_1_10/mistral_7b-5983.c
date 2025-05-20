//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define BUF_SIZE 4096

typedef struct {
    char name[32];
    int age;
    char gender;
} Person;

void consume_whitespace(FILE *fp) {
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (!isspace((unsigned char)c)) break;
    }
}

void parse_field(FILE *fp, char *buffer, size_t size) {
    int c;
    size_t pos = 0;

    while ((c = fgetc(fp)) != EOF && pos < size - 1) {
        if (isspace((unsigned char)c)) {
            buffer[pos] = '\0';
            consume_whitespace(fp);
            return;
        }
        buffer[pos++] = (char)c;
    }

    fputc(c, stderr); // report error on stderr
    buffer[pos] = '\0';
}

Person read_person(FILE *fp) {
    Person p;
    char name[32];

    consume_whitespace(fp);
    parse_field(fp, name, sizeof(name));
    strcpy(p.name, name);

    consume_whitespace(fp);
    fscanf(fp, "%d%c", &p.age, name);

    consume_whitespace(fp);
    fscanf(fp, "%c%*[^\n]", &p.gender);

    return p;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Person people[MAX_FIELDS];
    size_t num_people = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (!feof(fp) && num_people < MAX_FIELDS) {
        Person p = read_person(fp);
        people[num_people++] = p;
    }

    fclose(fp);

    for (size_t i = 0; i < num_people; ++i) {
        printf("%s (%d years old, %c gender)\n", people[i].name, people[i].age, people[i].gender);
    }

    return EXIT_SUCCESS;
}