//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define MAX_LINE_LENGTH 1024
#define MAX_POEMS 10

struct poem {
    char *title;
    char *text;
};

int main(void) {
    struct poem poems[MAX_POEMS];
    char line[MAX_LINE_LENGTH];
    int i;

    // Initialize poems array
    for (i = 0; i < MAX_POEMS; i++) {
        poems[i].title = NULL;
        poems[i].text = NULL;
    }

    // Read poems from file
    FILE *file = fopen("romantic_poems.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Check if line is a poem title
        if (strchr(line, ':') != NULL) {
            // Save title and text in poems array
            poems[i].title = line;
            i++;
            if (i >= MAX_POEMS) {
                break;
            }
            continue;
        }
        // Save text of current poem
        poems[i].text = line;
        i++;
    }
    fclose(file);

    // Mmap memory for poems array
    void *ptr = mmap(NULL, sizeof(struct poem) * i, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        perror("Failed to mmap memory");
        return 1;
    }

    // Print poems
    for (i = 0; i < MAX_POEMS; i++) {
        printf("%s\n", poems[i].title);
        printf("%s\n", poems[i].text);
    }

    // Unmap memory
    munmap(ptr, sizeof(struct poem) * i);

    return 0;
}