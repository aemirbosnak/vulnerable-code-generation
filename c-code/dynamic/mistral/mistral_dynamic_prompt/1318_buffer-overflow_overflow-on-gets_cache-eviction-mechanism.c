#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[32];
    int age;
} Person;

Person people[10];
int size = 0;

void cache_evict() {
    memset(people, 0, sizeof(people));
    size = 0;
}

int main() {
    char buf[256];
    while (1) {
        printf("Enter person details (name age): ");
        gets(buf);
        if (size == 10) cache_evict();

        Person *p = &people[size];
        strcpy(p->name, buf);
        sscanf(strchr(buf, ' ')+1, "%d", &p->age);
        size++;
    }
    return 0;
}
