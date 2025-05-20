//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 80

typedef struct {
    char *line;
    int line_num;
} Line;

int main() {
    char filename[MAX_LINE_LEN];
    FILE *file;
    int num_lines = 0;
    Line lines[MAX_LINES];

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(lines[num_lines].line, MAX_LINE_LEN, file)!= NULL) {
        num_lines++;
    }

    for (int i = 0; i < num_lines; i++) {
        lines[i].line[strcspn(lines[i].line, "\n")] = '\0';
        lines[i].line_num = i + 1;
    }

    fclose(file);

    printf("Enter the word to search for: ");
    char search_word[MAX_LINE_LEN];
    scanf("%s", search_word);

    for (int i = 0; i < num_lines; i++) {
        if (strstr(lines[i].line, search_word)!= NULL) {
            printf("Line %d contains the word '%s'.\n", lines[i].line_num, search_word);
        }
    }

    return 0;
}