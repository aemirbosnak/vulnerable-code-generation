//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    Line *lines = NULL;
    int num_lines = 0;
    char buf[MAX_LINE_LENGTH];
    while (fgets(buf, MAX_LINE_LENGTH, file)!= NULL) {
        int len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
            len--;
        }
        Line *new_line = malloc(sizeof(Line));
        new_line->text = strdup(buf);
        new_line->length = len;
        lines = realloc(lines, sizeof(Line) * (num_lines + 1));
        lines[num_lines] = *new_line;
        num_lines++;
    }
    fclose(file);

    printf("<html>\n<head>\n<title>%s</title>\n</head>\n<body>\n", argv[1]);
    for (int i = 0; i < num_lines; i++) {
        Line *line = &lines[i];
        printf("<p>%s</p>\n", line->text);
    }
    printf("</body>\n</html>");

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
        free(lines);
    }
    return 0;
}