//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

typedef struct {
    char* text;
    int position;
} eBook;

void init_eBook(eBook* ebook) {
    ebook->text = NULL;
    ebook->position = 0;
}

void load_eBook(eBook* ebook, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char* word = strtok(line, " ");
        while (word!= NULL) {
            if (strlen(word) > MAX_WORD_SIZE) {
                printf("Error: word %s is too long\n", word);
                exit(1);
            }
            ebook->text = realloc(ebook->text, ebook->position + strlen(word) + 1);
            strcat(ebook->text, word);
            strcat(ebook->text, " ");
            ebook->position += strlen(word) + 1;
            word = strtok(NULL, " ");
        }
    }

    fclose(file);
}

void display_eBook(eBook* ebook, int start_position, int num_words) {
    int end_position = start_position + num_words;
    if (end_position > ebook->position) {
        end_position = ebook->position;
    }

    printf("%s", ebook->text + start_position);
}

int main() {
    eBook ebook;
    init_eBook(&ebook);

    load_eBook(&ebook, "example.txt");

    int start_position = 0;
    int num_words = 10;
    display_eBook(&ebook, start_position, num_words);

    return 0;
}