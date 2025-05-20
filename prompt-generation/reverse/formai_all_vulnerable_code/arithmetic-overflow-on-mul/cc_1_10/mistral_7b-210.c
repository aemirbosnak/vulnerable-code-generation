//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char pos[20];
    int exp;
    int sal;
} Person;

void parse_line(char *line, Person *pers) {
    int i = 0, j = 0;
    char temp[50];

    while (line[i] != '|' && i < 100) i++;
    strncpy(pers->name, line, i);
    pers->name[i] = '\0';

    j = i + 1;
    while (line[j] != '|' && line[j] != '\0') j++;
    strncpy(pers->pos, &line[i + 1], j - i - 1);
    pers->pos[j - i - 1] = '\0';

    i = j;
    while (line[i] != ':' && i < 100) i++;
    i++;

    while (isdigit(line[i])) {
        pers->exp *= 10;
        pers->exp += line[i] - '0';
        i++;
    }

    while (line[i] != ':' && i < 100) i++;
    i++;

    while (isdigit(line[i])) {
        pers->sal *= 10;
        pers->sal += line[i] - '0';
        i++;
    }
}

int main() {
    char str[1024];
    Person people[100];
    int i = 0, cnt = 0;

    while (fgets(str, sizeof(str), stdin) != NULL) {
        if (str[0] == '%') continue;
        parse_line(str, &people[cnt]);
        cnt++;
    }

    for (i = 0; i < cnt; i++) {
        printf("%s, %s, %d years of experience, %d dollars salary\n",
               people[i].name, people[i].pos, people[i].exp, people[i].sal);
    }

    return 0;
}