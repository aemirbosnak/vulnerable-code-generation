//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBERS 1000

typedef struct {
    char name[50];
    int count;
    int num[MAX_NUMBERS];
} Person;

void add_number(Person *p, int num) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (p->num[i] == num) {
            break;
        }
    }
    if (i == p->count) {
        p->num[p->count++] = num;
    }
}

int main() {
    int i, j, n;
    Person p;
    char line[100];

    printf("Enter your name: ");
    scanf("%s", p.name);

    while (fgets(line, sizeof(line), stdin)) {
        n = strlen(line) - 1;
        if (line[n] == '\n') {
            line[n] = '\0';
        }
        p.num[p.count++] = atoi(line);
    }

    printf("Name: %s\n", p.name);
    printf("Number of numbers: %d\n", p.count);
    printf("Numbers: ");
    for (i = 0; i < p.count; i++) {
        printf("%d ", p.num[i]);
    }
    printf("\n");

    return 0;
}