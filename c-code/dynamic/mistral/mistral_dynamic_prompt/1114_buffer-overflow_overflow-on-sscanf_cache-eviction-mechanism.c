#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    char age[4];
    char address[128];
} Person;

void cache_evict(Person *people, size_t count) {
    size_t i;
    for (i = 0; i < count; ++i) {
        char buffer[256];
        size_t read = sscanf(people[i].name, "%255s", buffer);
        if (read == 1) {
            strcpy(people[i].name, buffer);
            strcpy(people[i].age, "");
            strcpy(people[i].address, "");
        }
    }
}

int main(int argc, char *argv[]) {
    Person people[1024];
    size_t i;
    for (i = 0; i < 1024; ++i) {
        sprintf(people[i].name, "Name%zu", i);
        sprintf(people[i].age, "%d", i * 10);
        sprintf(people[i].address, "Address%zu", i);
    }

    char input[1024];
    printf("Enter names to evict (Ctrl+D to stop):\n");
    for (;;) {
        fgets(input, sizeof(input), stdin);
        size_t n = strlen(input);
        if (n == 0 || (input[n - 1] == '\n' && input[n - 2] == '\r')) {
            break;
        }
        cache_evict(people, 1024);
    }
    return 0;
}
