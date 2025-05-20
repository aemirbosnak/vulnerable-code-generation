//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <regex.h>
#include <time.h>

#define MAX_LINE_SIZE 1024
#define MAX_PATTERN_SIZE 1024

typedef struct {
    char *pattern;
    regex_t regex;
} Pattern;

typedef struct {
    char *filename;
    int fd;
    time_t last_modified;
} File;

void init_pattern(Pattern *p, const char *pattern) {
    regcomp(&p->regex, pattern, REG_EXTENDED);
}

int match_pattern(Pattern *p, const char *line) {
    return regexec(&p->regex, line, 0, NULL, 0);
}

void init_file(File *f, const char *filename) {
    f->filename = strdup(filename);
    struct stat st;
    if (stat(filename, &st) == 0) {
        f->last_modified = st.st_mtime;
    } else {
        f->last_modified = 0;
    }
}

int main() {
    char line[MAX_LINE_SIZE];
    Pattern p;
    File f;

    init_pattern(&p, "^.*(root|admin).*$");
    init_file(&f, "/var/log/auth.log");

    FILE *fp = fopen("/var/log/auth.log", "r");
    if (fp == NULL) {
        printf("Error: could not open file /var/log/auth.log\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (match_pattern(&p, line)) {
            printf("Possible intrusion detected at %s\n", line);
        }
    }

    fclose(fp);
    return 0;
}