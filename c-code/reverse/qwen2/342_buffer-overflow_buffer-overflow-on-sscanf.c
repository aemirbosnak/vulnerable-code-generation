#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char query[10];
    char name[20];
    int age;

    printf("Enter query: ");
    scanf("%s", query);

    sscanf(query, "name=%[^&] &age=%d", name, &age);

    printf("Name: %s\nAge: %d\n", name, age);

    return 0;
}
