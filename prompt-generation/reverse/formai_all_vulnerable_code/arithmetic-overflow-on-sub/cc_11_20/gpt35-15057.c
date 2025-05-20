//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_FILE_SIZE 100000
#define MAX_MATCHES 10

int main(int argc, char *argv[]) {
    FILE *fp;
    char *buffer;
    long file_size = 0;
    size_t result;
    regex_t regex;
    regmatch_t matches[MAX_MATCHES];
    const char *pattern = "([A-Za-z]+,[ ]*[A-Za-z]+)|([A-Za-z]+@[A-Za-z]+\\.[A-Za-z]+)|([A-Za-z ]+): ([A-Za-z0-9 ]+)";
    int reti, i;

    if (argc != 2) {
        printf("Usage: ./parser <filename>\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    if (file_size > MAX_FILE_SIZE) {
        printf("File size too large\n");
        return 1;
    }

    buffer = (char *) malloc (sizeof(char)*file_size);
    if (buffer == NULL) {
        printf("Memory error\n");
        return 1;
    }

    result = fread(buffer, 1, file_size, fp);
    if (result != file_size) {
        printf("Reading error\n");
        return 1;
    }

    fclose(fp);

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti != 0) {
        printf("Could not compile regex\n");
        return 1;
    }

    reti = regexec(&regex, buffer, MAX_MATCHES, matches, 0);
    if (reti == 0) {
        for (i = 0; i < MAX_MATCHES && matches[i].rm_so != -1; i++) {
            char *match_str = (char *) malloc (sizeof(char)*(matches[i].rm_eo - matches[i].rm_so + 1));
            strncpy(match_str, buffer + matches[i].rm_so, matches[i].rm_eo - matches[i].rm_so);
            match_str[matches[i].rm_eo - matches[i].rm_so] = '\0';
            printf("%s\n", match_str);
            free(match_str);
        }
    } else if (reti == REG_NOMATCH) {
        printf("No matches found\n");
    } else {
        printf("Regex match failed\n");
        return 1;
    }

    regfree(&regex);
    free(buffer);
    return 0;
}