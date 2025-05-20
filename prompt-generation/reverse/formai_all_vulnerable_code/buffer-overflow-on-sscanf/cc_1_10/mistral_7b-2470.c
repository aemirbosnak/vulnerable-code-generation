//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char symbol[3];
    char name[20];
    int group;
    int period;
} Element;

void print_header() {
    printf("+------------------------------------------------+----------------+----------------+--------+--------+\n");
    printf("| Symbol | Name                                  | Group          | Period | Block  |\n");
    printf("+------------------------------------------------+----------------+----------------+--------+--------+\n");
}

void print_element(Element e) {
    int i;
    for (i = 0; i < 3 - strlen(e.symbol); i++)
        printf(" ");
    printf("| %-3s | %-20s | %-8d | %-5d | %-6s |\n", e.symbol, e.name, e.group, e.period,
           (e.group % 2 == 0 ? "Noble Gas" : "Metal"));
}

void print_table(Element table[]) {
    print_header();
    for (int i = 0; i < 18; i++)
        print_element(table[i]);
}

Element parse_line(char *line) {
    Element e;
    sscanf(line, "%2s %20s %d %d", e.symbol, e.name, &e.group, &e.period);
    return e;
}

int main() {
    FILE *fp;
    char line[100];
    Element table[18];

    if ((fp = fopen("periodic_table.txt", "r")) == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        Element e = parse_line(line);
        table[i++] = e;
    }

    fclose(fp);

    print_table(table);

    return 0;
}