//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

// struct to store a line of text
typedef struct {
    char text[MAX_LINE_LENGTH];
    int length;
} Line;

// struct to store the ebook
typedef struct {
    int num_lines;
    Line lines[MAX_LINES];
} EBook;

// function to load the ebook from a file
EBook* load_ebook(const char* filename) {
    EBook* ebook = (EBook*) malloc(sizeof(EBook));
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open ebook file.\n");
        exit(1);
    }
    int num_lines = 0;
    while (fgets(ebook->lines[num_lines].text, MAX_LINE_LENGTH, file)!= NULL) {
        ebook->lines[num_lines].length = strlen(ebook->lines[num_lines].text);
        num_lines++;
    }
    ebook->num_lines = num_lines;
    fclose(file);
    return ebook;
}

// function to print the ebook
void print_ebook(EBook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i].text);
    }
}

// main function
int main() {
    EBook* ebook = load_ebook("ebook.txt");
    print_ebook(ebook);
    free(ebook);
    return 0;
}