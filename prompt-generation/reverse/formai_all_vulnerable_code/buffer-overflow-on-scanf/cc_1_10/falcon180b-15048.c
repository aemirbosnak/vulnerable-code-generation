//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10000

typedef struct {
    int id;
    char name[20];
} Person;

int main() {
    int n;
    scanf("%d", &n);

    Person *people = malloc(n * sizeof(Person));

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &people[i].id, people[i].name);
    }

    int m;
    scanf("%d", &m);

    int *queries = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d", &queries[i]);
    }

    for (int i = 0; i < m; i++) {
        int target = queries[i];
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (people[j].id == target) {
                printf("%s\n", people[j].name);
                count++;
            }
        }

        if (count == 0) {
            printf("Not found\n");
        }
    }

    free(people);
    free(queries);

    return 0;
}