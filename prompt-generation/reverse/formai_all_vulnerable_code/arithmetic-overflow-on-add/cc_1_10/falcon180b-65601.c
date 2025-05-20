//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_READERS 10
#define MAX_CHARS_PER_LINE 80
#define EBOOK_FILE "ebook.txt"

typedef struct {
    char name[20];
    int line_num;
} Reader;

void* read_ebook(void* arg) {
    Reader* reader = (Reader*) arg;
    FILE* ebook_file = fopen(EBOOK_FILE, "r");
    char line[MAX_CHARS_PER_LINE];
    int char_count = 0;

    if (ebook_file == NULL) {
        printf("Error: Could not open ebook file.\n");
        exit(1);
    }

    while (fgets(line, MAX_CHARS_PER_LINE, ebook_file)!= NULL) {
        char_count = 0;
        printf("%s: ", reader->name);
        for (int i = 0; line[i]!= '\0' && char_count < MAX_CHARS_PER_LINE; i++) {
            printf("%c", line[i]);
            char_count++;
        }
        printf("\n");
        reader->line_num++;
    }

    fclose(ebook_file);
    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_READERS];
    Reader readers[MAX_READERS];

    for (int i = 0; i < MAX_READERS; i++) {
        sprintf(readers[i].name, "Reader %d", i + 1);
        pthread_create(&threads[i], NULL, read_ebook, &readers[i]);
    }

    for (int i = 0; i < MAX_READERS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}