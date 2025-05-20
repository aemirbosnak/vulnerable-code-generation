//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    char name[256];
    char phone[256];
    char email[256];

    regex_t regex;
    int reti;
    regmatch_t pmatch[10];

    reti = regcomp(&regex, "(?<=Name: ).*", 0);
    if (reti) {
        perror("Error compiling regex");
        return EXIT_FAILURE;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        if (strstr(line, "Name: ")) {
            reti = regexec(&regex, line, 10, pmatch, 0);
            if (!reti) {
                strncpy(name, line + pmatch[0].rm_so, pmatch[0].rm_eo - pmatch[0].rm_so);
            }
        }
        else if (strstr(line, "Phone: ")) {
            reti = regexec(&regex, line, 10, pmatch, 0);
            if (!reti) {
                strncpy(phone, line + pmatch[0].rm_so, pmatch[0].rm_eo - pmatch[0].rm_so);
            }
        }
        else if (strstr(line, "Email: ")) {
            reti = regexec(&regex, line, 10, pmatch, 0);
            if (!reti) {
                strncpy(email, line + pmatch[0].rm_so, pmatch[0].rm_eo - pmatch[0].rm_so);
            }
        }
    }

    printf("Name: %s\n", name);
    printf("Phone: %s\n", phone);
    printf("Email: %s\n", email);

    free(line);
    fclose(file);
    regfree(&regex);

    return EXIT_SUCCESS;
}