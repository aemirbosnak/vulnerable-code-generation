//MISTRAL-7B DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define LOG_FILE "system.log"
#define LOG_SIZE 1024
#define NUM_RULES 5

typedef struct {
    char *rule;
    int len;
} Rule;

Rule rules[NUM_RULES] = {
    {"FAILED login attempt from untrusted IP:", 23},
    {"ACCESS denied for user \"root\":", 22},
    {"Unable to open file \"/etc/passwd\": Permission denied:", 35},
    {"Unknown command \"execme\":", 10},
    {"Connection closed by remote host:", 18}
};

int log_parse(char *log_line, int *matches) {
    int i;
    for (i = 0; i < NUM_RULES; i++) {
        if (strncmp(log_line, rules[i].rule, rules[i].len) == 0) {
            matches[i]++;
            return 1;
        }
    }
    return 0;
}

int main() {
    int fd, i, matches[NUM_RULES] = {0};
    char log_line[LOG_SIZE];
    struct stat st;

    fd = open(LOG_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open log file");
        return 1;
    }

    if (fstat(fd, &st) < 0) {
        perror("Failed to get log file size");
        close(fd);
        return 1;
    }

    if (lseek(fd, st.st_size - 1, SEEK_SET) < 0) {
        perror("Failed to seek to end of file");
        close(fd);
        return 1;
    }

    while (read(fd, log_line, LOG_SIZE) > 0) {
        if (log_line[strlen(log_line) - 1] != '\n') {
            printf("Log line too long: %s\n", log_line);
            continue;
        }

        if (log_parse(log_line, matches)) {
            for (i = 0; i < NUM_RULES; i++) {
                if (matches[i] > 0) {
                    printf("Rule matched: %s\n", rules[i].rule);
                    break;
                }
            }
        }
    }

    close(fd);
    return 0;
}