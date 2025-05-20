//Falcon-180B DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

struct Line {
    char text[MAX_LINE_LENGTH];
    int length;
};

int main() {
    FILE* file;
    char filename[MAX_LINE_LENGTH];
    int num_lines = 0;
    struct Line lines[MAX_NUM_LINES];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(lines[num_lines].text, MAX_LINE_LENGTH, file)!= NULL) {
        lines[num_lines].length = strlen(lines[num_lines].text);
        num_lines++;
    }

    fclose(file);

    printf("Enter word to search for: ");
    char search_word[MAX_LINE_LENGTH];
    scanf("%s", search_word);

    int num_found = 0;
    for (int i = 0; i < num_lines; i++) {
        if (strstr(lines[i].text, search_word)!= NULL) {
            printf("%s\n", lines[i].text);
            num_found++;
        }
    }

    if (num_found == 0) {
        printf("No lines found with search word.\n");
    }

    return 0;
}