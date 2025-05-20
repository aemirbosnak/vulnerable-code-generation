//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_RESUME_LENGTH 10000
#define MAX_KEYWORDS 50

typedef struct {
    char keyword[MAX_KEYWORDS][32];
    int count[MAX_KEYWORDS];
} Resume;

int main() {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    char *token;
    int line_number = 0;
    Resume resume = {{"", "", "", "", "", "", "", "", "", ""}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_number++;

        // Remove leading/trailing whitespace
        char *trimmed_line = line;
        while (isspace(*trimmed_line)) {
            trimmed_line++;
        }
        int length = strlen(trimmed_line);
        while (isspace(trimmed_line[length - 1])) {
            trimmed_line[length - 1] = '\0';
            length--;
        }

        // Tokenize line
        token = strtok(trimmed_line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < MAX_KEYWORDS; i++) {
                if (strcmp(token, resume.keyword[i]) == 0) {
                    resume.count[i]++;
                    break;
                }
            }
            if (i == MAX_KEYWORDS) {
                // Add new keyword if not found
                strcpy(resume.keyword[i], token);
                resume.count[i] = 1;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(input_file);

    printf("Resume Parsing Results:\n");
    printf("-------------------------\n");
    printf("Keywords:\n");
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (resume.count[i] > 0) {
            printf("%s: %d\n", resume.keyword[i], resume.count[i]);
        }
    }

    return 0;
}